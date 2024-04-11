#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 40;
int n, m, dp[N][N][N][N], cost[N][N][N][N], sum[N + 1][N + 1];
char s[N + 5];

int getsum(int x1, int y1, int x2, int y2) {
	return sum[x2 + 1][y2 + 1] - sum[x2 + 1][y1] - sum[x1][y2 + 1] + sum[x1][y1];
}

int main() {
	int q;
	scanf("%d%d", &n, &m);
	scanf("%d", &q);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		for (int j = 0; j < m; ++j) {
			sum[i + 1][j + 1] = (s[j] - '0') + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			//cal cost[u][v][i][j]
			for (int u = i; u >= 0; --u) {
				for (int v = j; v >= 0; --v) {
					cost[u][v][i][j] = (getsum(u, v, i, j) == 0);
					if (u < i) {
						cost[u][v][i][j] += cost[u + 1][v][i][j];
					}
					if (v < j) {
						cost[u][v][i][j] += cost[u][v + 1][i][j];
					}
					if (u < i && v < j) {
						cost[u][v][i][j] -= cost[u + 1][v + 1][i][j];
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = i; k < n; ++k) {
				for (int l = j; l < m; ++l) {
					dp[i][j][k][l] = cost[i][j][k][l];
					if (k > i) {
						dp[i][j][k][l] += dp[i][j][k - 1][l];
					}
					if (l > j) {
						dp[i][j][k][l] += dp[i][j][k][l - 1];
					}
					if (k > i && l > j) {
						dp[i][j][k][l] -= dp[i][j][k - 1][l - 1];
					}
				}
			}
		}
	}
	while (q--) {
		int x1, y1, x2, y2;	
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		--x1, --y1, --x2, --y2;
		printf("%d\n", dp[x1][y1][x2][y2]);
	}
	return 0;
}