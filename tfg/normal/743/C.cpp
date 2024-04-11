#include <iostream>

int n;

int main()
{
	std::cin >> n;
	if(n==1)
		std::cout << "-1\n";
	else
		std::cout << n << ' ' << n+1 << ' ' << (n+1)*n << '\n';
}