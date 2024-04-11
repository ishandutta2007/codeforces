#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
	int n;
	std::cin >> n;
	std::string str[2];
	std::cin >> str[0] >> str[1];
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans += std::min(abs(str[0][i] - str[1][i]), 10 - abs(str[0][i] - str[1][i]));
	}
	std::cout << ans << "\n";
}