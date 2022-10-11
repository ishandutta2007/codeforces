#include <iostream>

int n;

long long int a=0,b=0,t;

int main()
{
	std::cin >> n;
	for(int i=0;i<n;i++)
	{
		std::cin >> t;
		a|=t;
	}
	for(int i=0;i<n;i++)
	{
		std::cin >> t;
		b|=t;
	}
	std::cout << a+b;
}