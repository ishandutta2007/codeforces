#include <iostream>
#include <string>

int dp[12783][2];
int n, m;
int left[12387];
int right[12736];

int main()
{
	std::cin >> n >> m;
	dp[0][1] = 28196345;
	int to = 0;
	for(int i = 1; i <= n; i++)
	{
		std::string floor;
		std::cin >> floor;
		int l = -1, r = -1;
		for(int j = 1; j <= m; j++)
		{
			if(floor[j] == '0')
				continue;
			if(l == -1)
				l = j;
			r = j;
		}
		left[n - i + 1] = l;
		right[n - i + 1] = r;
		if(l != -1 && to == 0)
			to = n - i + 1;
	}
	//std::cout << "to is " << to << '\n';
	for(int i = 1; i < to; i++)
	{
		if(left[i] != -1)
		{
			dp[i][0] = std::min(dp[i - 1][0] + 2 * right[i] + 1, dp[i - 1][1] + m + 2);
			dp[i][1] = std::min(dp[i - 1][1] + 2 * (m - left[i] + 1) + 1, dp[i - 1][0] + m + 2);
		}
		else
		{
			dp[i][0] = std::min(dp[i - 1][0] + 1, dp[i - 1][1] + m + 2);
			dp[i][1] = std::min(dp[i - 1][1] + 1, dp[i - 1][0] + m + 2);
		}
		//std::cout << i << ": (" << dp[i][0] << ", " << dp[i][1] << ")\n";
	}
	if(to == 0)
		std::cout << "0\n";
	else
		std::cout << std::min(dp[to - 1][0] + right[to], dp[to - 1][1] + (m - left[to] + 1)) << '\n';
}