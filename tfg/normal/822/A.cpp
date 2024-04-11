#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;
	int c = std::min(a, b);
	long long ans = 1;
	for(int i = 2; i <= c; i++)
		ans *= i;
	std::cout << ans << '\n';
}