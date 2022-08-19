#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 33000;
const int M = 300;
const int Z = 350;
int n, d;
int a[N];
int dp[N][2 * Z];
int ans;

void read()
{
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	n = 30010;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2 * Z; j++)
			dp[i][j] = -1;
	dp[d][Z] = a[d];
	return;
}

void solve()
{
	for (int i = 0; i < n; i++)
		for (int j = -M; j <= M; j++)
		{
			if (dp[i][Z + j] == -1) continue;
			ans = max(ans, dp[i][Z + j]);
			int td = d + j;
			for (int nd = td - 1; nd <= td + 1; nd++)
			{
				if (nd <= 0) continue;
				if (i + nd > n) break;
				dp[i + nd][Z + nd - d] = max(dp[i + nd][Z + nd - d], dp[i][Z + j] + a[i + nd]);
			}
		}
	printf("%d\n", ans);
	return;
}

int main()
{
	read();
	solve();

	return 0;
}