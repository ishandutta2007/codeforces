#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

const int N = 1010;
const int K = 12;
char s[N], p[N];
int n, m;
int k;
int dp[N][N][K][2];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	scanf(" %s ", s);
	scanf(" %s ", p);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int h = 0; h <= k; h++)
				for (int z = 0; z < 2; z++)
					dp[i][j][h][z] = -((int)1e8);
	dp[0][0][0][0] = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int h = 0; h <= k; h++)
			{
				dp[i][j][h][1] = max(dp[i][j][h][0], dp[i][j][h][1]);
				dp[i][j][h + 1][0] = max(dp[i][j][h + 1][0], dp[i][j][h][1]);

				if (i < n)
					dp[i + 1][j][h][0] = max(dp[i + 1][j][h][0], dp[i][j][h][0]);
				if (j < m)
					dp[i][j + 1][h][0] = max(dp[i][j + 1][h][0], dp[i][j][h][0]);

				if (i < n && j < m && s[i] == p[j])
					dp[i + 1][j + 1][h][1] = max(dp[i + 1][j + 1][h][1], dp[i][j][h][1] + 1);
			}
	printf("%d\n", dp[n][m][k][0]);

	return 0;
}