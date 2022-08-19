#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;
ll s, x;
const int N = 50;
ll dp[N][2];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%lld%lld", &s, &x);
	dp[N - 1][0] = 1;
	for (int i = N - 2; i >= 0; i--)
	{
		for (int j = 0; j < 2; j++)
		{
			ll p = s & ((1LL << (i + 1)) - 1);
			if (j == 1)
				p += 1LL << (i + 1);
			if (x & (1LL << i))
			{
				if (p < (1LL << i)) continue;
				p -= 1LL << i;
				if ((p >> i) >= 2) continue;
				dp[i][p >> i] += dp[i + 1][j] * 2;
			}
			else
			{
				if (p < (1LL << (i + 1)))
				{
					dp[i][p >> i] += dp[i + 1][j];
				}
				else
				{
					p -= 1LL << (i + 1);
					dp[i][p >> i] += dp[i + 1][j];
				}
			}
		}
	}
	ll ans = dp[0][0];
	if (x == s) ans -= 2;
	printf("%lld\n", max(0LL, ans));

	return 0;
}