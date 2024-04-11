#include <iostream>
#include <algorithm>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	int total=std::min(a, std::min(b/2, c/4));
	std::cout << total*7 << '\n';
}