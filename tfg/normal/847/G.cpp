#include <iostream>
#include <string>

int freq[7];

int main()
{
	int n;
	std::cin >> n;
	while(n--)
	{
		std::string str;
		std::cin >> str;
		for(int i = 0; i < 7; i++)
			freq[i] += str[i] - '0';
	}
	int ans = 0;
	for(int i = 0; i < 7; i++)
		ans = std::max(ans, freq[i]);
	std::cout << ans << '\n';
}