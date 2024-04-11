#include <iostream>

typedef long long ll;

const int ms = 100100;
const ll INF = 8e18;

ll dp[4][ms];
ll a[ms];
ll val[4];

int main()
{
	int n;
	std::cin >> n;
	for(int i = 0; i < 3; i++)
	{
		std::cin >> val[i];
		dp[i][0] = -INF;
	}
	dp[3][0] = -INF;
	for(int i = 1; i <= n; i++)
	{
		std::cin >> a[i];
		dp[0][i] = a[i] * val[0];
	}
	for(int j = 1; j < 4; j++)
	{
		for(int i = 1; i <= n; i++)
		{
			dp[j - 1][i] = std::max(dp[j - 1][i], dp[j - 1][i - 1]);
			dp[j][i] = a[i] * val[j] + dp[j - 1][i];
		}
	}
	std::cout << dp[3][n] << '\n';
}