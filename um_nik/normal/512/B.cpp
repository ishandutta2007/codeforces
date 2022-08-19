#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 333;
const int INF = (int)1e9;
int a[N];
int c[N];
int ans = INF;
int p[N];
int sz;
int b[N];
int dp[1 << 11];
int n;

void getP(int x)
{
	sz = 0;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i != 0) continue;
		p[sz++] = i;
		while(x % i == 0) x /= i;
	}
	if (x > 1)
		p[sz++] = x;
	return;
}

int solve(int val)
{
	getP(val);
	for (int i = 0; i < n; i++)
	{
		b[i] = 0;
		for (int j = 0; j < sz; j++)
			if (a[i] % p[j] != 0)
				b[i] |= (1 << j);
	}
	for (int i = 0; i < (1 << sz); i++)
		dp[i] = INF;
	dp[0] = 0;
	for (int mask = 0; mask < (1 << sz); mask++)
	{
		if (dp[mask] == INF) continue;
		for (int i = 0; i < n; i++)
		{
			int nmask = mask | b[i];
			dp[nmask] = min(dp[nmask], dp[mask] + c[i]);
		}
	}
	return dp[(1 << sz) - 1];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < n; i++)
		ans = min(ans, c[i] + solve(a[i]));
	if (ans == INF)
		printf("-1\n");
	else
		printf("%d\n", ans);

	return 0;
}