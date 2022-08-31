#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 16;
const int M = (1 << N) + 7;
const int K = 130;
int n;
int a[N][3];
int dp[M][K];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char c;
		scanf(" %c %d%d", &c, &a[i][1], &a[i][2]);
		if (c == 'R')
			a[i][0] = 0;
		else
			a[i][0] = 1;
	}
	for (int mask = 0; mask < (1 << n); mask++)
		for (int i = 0; i < K; i++)
			dp[mask][i] = -1;
	dp[0][0] = 0;
	for (int mask = 0; mask < (1 << n) - 1; mask++)
		for (int x = 0; x < K; x++)
		{
			if (dp[mask][x] == -1) continue;
			int y = 0, z = 0;
			for (int i = 0; i < n; i++)
			{
				if (((mask >> i) & 1) == 0) continue;
				if (a[i][0] == 0)
					y++;
				else
					z++;
			}
			for (int i = 0; i < n; i++)
			{
				if ((mask >> i) & 1) continue;
				int yy = min(y, a[i][1]), zz = min(z, a[i][2]);
				dp[mask | (1 << i)][x + yy] = max(dp[mask | (1 << i)][x + yy], dp[mask][x] + zz);
			}
		}
	int ans = (int)1e9;
	int sumX = 0, sumY = 0;
	for (int i = 0; i < n; i++)
	{
		sumX += a[i][1];
		sumY += a[i][2];
	}
	for (int x = 0; x < K; x++)
	{
		if (dp[(1 << n) - 1][x] == -1) continue;
		ans = min(ans, max(sumX - x, sumY - dp[(1 << n) - 1][x]));
	}
	ans += n;
	printf("%d\n", ans);

	return 0;
}