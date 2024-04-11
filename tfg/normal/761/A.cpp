#include <iostream>
#include <cstdlib>

int main()
{
	int a, b;
	std::cin >> a >> b;
	if(abs(a-b)<=1 && a+b>0)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}