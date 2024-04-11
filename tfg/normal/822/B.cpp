#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string s, t;
	int n, m;
	std::cin >> n >> m;
	std::cin >> s >> t;
	std::vector<int> ans(n + 2, 0);
	for(int i = 0; i + n <= m; i++)
	{
		std::vector<int> cur;
		for(int j = 0; j < n; j++)
		{
			if(t[i + j] != s[j])
				cur.push_back(j + 1);
		}
		if(cur.size() < ans.size())
			ans = cur;
	}
	std::cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
	{
		if(i)
			std::cout << ' ';
		std::cout << ans[i];
	}
	std::cout << '\n';
}