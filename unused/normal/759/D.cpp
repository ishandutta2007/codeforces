#include <bits/stdc++.h>
using namespace std;

int n;
char str[5555];
int dp[2][5001];
int sum[5001];
int forbidden[26][5001];
constexpr int MOD = 1000000007;

int main()
{
	scanf("%d%s", &n, str);

	int ans = 0;

	int *d1 = dp[0], *d2 = dp[1];
	d1[0] = sum[0] = 1;

	for (int i = 0; i < n; i++)
	{
		d2[0] = 0;

		for (int j = 1; j <= n; j++)
		{
			d2[j] = (sum[j - 1] + d2[j - 1]) % MOD;
			d2[j] = (d2[j] + MOD - forbidden[str[i] - 'a'][j]) % MOD;
		}

		for (int j = 1; j <= n; j++)
		{
			forbidden[str[i] - 'a'][j] = (forbidden[str[i] - 'a'][j] + d2[j]) % MOD;
		}

		for (int j = 0; j <= n; j++)
		{
			sum[j] = (sum[j] + d2[j]) % MOD;
		}

		swap(d1, d2);
	}

	printf("%d", sum[n]);
}