#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

typedef std::pair<int, int> ii;
typedef std::pair<ii, ii> i3;

const int ms = 102;
const int mt = 2020;

i3 a[ms];
int dp[ms][mt];

int main()
{
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++)
	{
		std::cin >> a[i].second.first >> a[i].first.first >> a[i].second.second;
		a[i].first.second = i;
	}
	std::sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		//std::cout << "including (" << a[i].first.first << ", " << a[i].second.first << ", " << a[i].second.second << ")\n";
		for(int j = a[i].first.first - 1; j >= a[i].second.first; j--)
		{
			dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - a[i].second.first] + a[i].second.second);
		}
		for(int j = 1; j < mt; j++)
		{
			dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);
			dp[i][j] = std::max(dp[i - 1][j], dp[i][j]);
		}
	}
	std::cout << dp[n][mt - 1] << '\n';
	std::vector<int> ans;
	for(int i = n, t = mt - 1; i > 0; i--)
	{
		while(t && dp[i][t] == dp[i][t - 1])
			t--;
		if(t < a[i].first.first && t >= a[i].second.first && dp[i - 1][t - a[i].second.first] + a[i].second.second == dp[i][t])
		{
			ans.push_back(a[i].first.second);
			t -= a[i].second.first;
		}
	}
	std::reverse(ans.begin(), ans.end());
	std::cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
	{
		if(i)
			std::cout << ' ';
		std::cout << ans[i];
	}
	std::cout << '\n';
}