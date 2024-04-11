#include <bits/stdc++.h>
using namespace std;

int dp[105][105];
int dat[105];

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &dat[i]);
		dp[i][0] = i;
	}

	for (int i = 1; i <= 100; i++)
	{
		for (int j = 0; j < t; j++)
		{
			dp[j][i] = dat[dp[j][i - 1]] - 1;
		}
	}

	long long ans = 0;

	for (int i = 0; i < t; i++)
	{
		int j;
		for (j = 1; j <= 100; j++)
		{
			if (dp[dp[i][j]][j] == i)
			{
				if (ans == 0) ans = j;
				else ans = ans * j / gcd(ans, j);
				break;
			}
		}
		if (j == 101) {
			printf("-1"); return 0;
		}
	}
	printf("%lld", ans);
}