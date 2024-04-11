#include <string>
#include <iostream>

int n;
std::string str;

int main()
{
	std::cin >> n >> str;
	int d=0;
	int a=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='A')
			a++;
		else
			d++;

	}
	if(a>d)
		std::cout << "Anton\n";
	else if(d>a)
		std::cout << "Danik\n";
	else
		std::cout << "Friendship\n";
}