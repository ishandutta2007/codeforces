#include <iostream>
#include <cstring>

typedef long long ll;

const int ms = 151;
const int mi = 76 * 75 / 2 + 76 * 76 + 20;

int dp[ms][mi];

int main()
{
	memset(dp, 0x3f, sizeof dp);
	int n, kk, s;
	std::cin >> n >> kk >> s;
	s = std::min(s, mi - 1);
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++)
	{
		int cost;
		std::cin >> cost;
		for(int j = i; j > 0; j--)
		{
			for(int k = s; k >= i - j; k--)
			{
				dp[j][k] = std::min(dp[j][k], dp[j - 1][k - (i - j)] + cost);
			}
		}
	}
	int ans = 0x3f3f3f3f;
	for(int i = 0; i <= s; i++)
		ans = std::min(ans, dp[kk][i]);
	std::cout << ans << '\n';
}