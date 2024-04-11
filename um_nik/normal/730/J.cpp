#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INF = (int)1e6;
const int N = 103;
const int M = N * N;
int n;
int a[N];
int b[N];
int dp[N][M];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < M; j++)
			dp[i][j] = INF;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j >= 0; j--)
			for (int x = 0; x < M; x++)
			{
				if (dp[j][x] == INF) continue;
				dp[j + 1][x + a[i]] = min(dp[j + 1][x + a[i]], dp[j][x] + b[i]);
			}
	int k = n, t = 0;
	int S = 0;
	for (int i = 0; i < n; i++)
		S += b[i] - a[i];
	for (int i = 0; i <= n; i++)
		for (int x = 0; x < M; x++)
		{
			if (dp[i][x] <= S)
			{
				int nk = n - i, nt = x;
				if (nk < k || (nk == k && nt < t))
				{
					k = nk;
					t = nt;
				}
			}
		}
	printf("%d %d\n", k, t);

	return 0;
}