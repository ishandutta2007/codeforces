#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 1010;
const int K = 8;
const int M = (1 << K) + 5;
int a[N];
int b[K][N];
int n;
int dp[M][K + 1];

int findPos(int v, int val)
{
	if (b[v][n] < val) return -1;
	return lower_bound(b[v], b[v] + n + 1, val) - b[v];
}

bool solve(int X)
{
	int Y = X / K;
	for (int mask = 0; mask < (1 << K); mask++)
		for (int i = 0; i <= K; i++)
			dp[mask][i] = n + 1;
	dp[0][0] = 0;
	for (int mask = 0; mask < (1 << K) - 1; mask++)
		for (int curSum = 0; curSum <= K; curSum++)
		{
			if (dp[mask][curSum] > n) continue;
			for (int v = 0; v < K; v++)
			{
				if ((mask >> v) & 1) continue;
				for (int x = 0; x < 2; x++)
				{
					int p = findPos(v, b[v][dp[mask][curSum]] + Y + x);
					if (p == -1) continue;
					dp[mask ^ (1 << v)][curSum + x] = min(dp[mask ^ (1 << v)][curSum + x], p);
				}
			}
		}
	return dp[(1 << K) - 1][X % K] <= n;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		a[i]--;
		for (int j = 0; j < K; j++)
			b[j][i + 1] = b[j][i];
		b[a[i]][i + 1]++;
	}

	int l = 0, r = n + 1;
	while(r - l > 1)
	{
		int x = (l + r) / 2;
		if (solve(x))
			l = x;
		else
			r = x;
	}
	printf("%d\n", l);

	return 0;
}