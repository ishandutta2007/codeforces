#include <iostream>
#include <string>

int main()
{
	int n;
	std::cin >> n;
	int ans = 0;
	std::string str;
	while(std::cin >> str)
	{
		int cur_ans = 0;
		for(int i = 0; i < str.size(); i++)
			cur_ans += str[i] >= 'A' && str[i] <= 'Z' ? 1 : 0;
		ans = std::max(ans, cur_ans);
	}
	std::cout << ans << '\n';
}