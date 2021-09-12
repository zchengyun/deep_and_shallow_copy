#include <iostream>  

class Student
{
private:
	int num;
	char* name;
public:
	Student();
	Student(const Student& s);
	~Student();
	
};

Student::Student()
{
	name = new char(20);
	std::cout << "Student" << std::endl;
}
Student::Student(const Student& s) {
	num = s.num;
	name = new char(20);
	memcpy(name, s.name, strlen(s.name));
	std::cout << "copy Student" << std::endl;
}

Student::~Student()
{
	std::cout << "~Student " << (int)name << std::endl;
	delete name;
	name = NULL;
}

int main()
{
	//浅拷贝，构造函数调用一次，析构函数调用两次,两个指针指向同一片内存
	/*{
		Student s1();
		Student s2(s1);
	}*/

	{
		Student s1;
		Student s2(s1);
	}

	system("pause");
	return 0;
}
