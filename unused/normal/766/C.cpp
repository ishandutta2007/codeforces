#include <bits/stdc++.h>
using namespace std;

int dp[1005];
char str[1005];
int lim[26];
int pre[1005][1005];
int n;

int fenwick[1005];

constexpr int MOD = 1000000007;

bool can(int l, int r)
{
	return r - l + 1 <= pre[l][r];
}

int D(int b)
{
	if (b == 0) return 1;
	if (dp[b] == -1)
	{
		dp[b] = 0;

		for (int i = b; i >= 1; i--)
		{
			if (can(i, b) == false) break;
			dp[b] = (dp[b] + D(i - 1)) % MOD;
		}
	}
	return dp[b];
}

int main()
{
	scanf("%d%s", &n, str + 1);
	for (int i = 0; i < 26; i++) scanf("%d", &lim[i]);
	for (int i = 0; i <= n; i++) dp[i] = -1;

	for (int i = 1; i <= n; i++)
	{
		int val = 1e9;
		for (int j = i; j <= n; j++)
		{
			val = min(val, lim[str[j] - 'a']);
			pre[i][j] = val;
		}
	}

	printf("%d\n", D(n));

	int maxlen = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (can(i, j)) maxlen = max(maxlen, j - i + 1);
		}
	}

	printf("%d\n", maxlen);

	int mincnt = 0;
	for (int i = 1; i <= n;)
	{
		mincnt++;
		int j;
		for (j = i; j <= n && can(i, j); j++);
		i = j;
	}

	printf("%d\n", mincnt);
}