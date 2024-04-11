#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;

ll dp[5050][4];
ll a[5050];

int main()
{
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++)
		std::cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(j % 2 == 0)
				dp[i][j] = dp[i - 1][j] + a[i];
			else
				dp[i][j] = dp[i - 1][j] - a[i];
		}
		for(int j = 1; j < 4; j++)
			dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);
	}
	std::vector<int> ans;
	for(int on = n, pos = 3; on > 0; on--)
	{
		while(pos > 0 && dp[on][pos] == dp[on][pos - 1])
		{
			ans.push_back(on);
			pos--;
		}
	}
	while(ans.size() < 3)
		ans.push_back(0);
	std::reverse(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++)
	{
		if(i)
			std::cout << ' ';
		std::cout << ans[i];
	}
	std::cout << '\n';
}