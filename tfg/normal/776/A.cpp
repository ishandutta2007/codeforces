#include <iostream>
#include <algorithm>


int main()
{
	std::string a, b, str;
	std::cin >> a >> b;
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++)
	{
		std::cout << a << " " << b << "\n";
		std::cin >> str;
		if(str==b)
		{
			//std::cout << "case 1\n";
			std::cin >> str;
			std::swap(a, b);
		}
		else
		{
			//std::cout << "case 2\n";
			a=str;
			std::cin >> str;
		}
		a=str;
	}
	std::cout << a << " " << b << "\n";
}