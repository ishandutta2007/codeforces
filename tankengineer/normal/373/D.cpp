#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m, q;
const int N = 40 + 1;
char map[N][N];

int sum[N][N], sum1[N][N][N][N], sum2[N][N][N][N];

int getsum(int x1, int y1, int x2, int y2) {
	return sum[x2 + 1][y2 + 1] - sum[x2 + 1][y1] - sum[x1][y2 + 1] + sum[x1][y1];
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%s", map[i]);
	}
	memset(sum, 0, sizeof(sum));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + (map[i][j] - '0');
		}
	}
	memset(sum1, 0, sizeof(sum1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int u = i; u >= 0; --u) {
				for (int v = j; v >= 0; --v) {
					sum1[i][j][u][v] = getsum(u, v, i, j) == 0;
					if (u < i) {
						sum1[i][j][u][v] += sum1[i][j][u + 1][v];
					}
					if (v < j) {
						sum1[i][j][u][v] += sum1[i][j][u][v + 1];
					}
					if (u < i && v < j) {
						sum1[i][j][u][v] -= sum1[i][j][u + 1][v + 1];
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int u = i; u < n; ++u) {
				for (int v = j; v < m; ++v) {
					sum2[i][j][u][v] = sum1[u][v][i][j];			
					if (u > i) {
						sum2[i][j][u][v] += sum2[i][j][u - 1][v];
					}
					if (v > j) {
						sum2[i][j][u][v] += sum2[i][j][u][v - 1];
					}
					if (u > i && v > j) {
						sum2[i][j][u][v] -= sum2[i][j][u - 1][v - 1];
					}
				}
			}
		}
	}
	while (q--) {
		int i, j, u, v;
		scanf("%d%d%d%d", &i, &j, &u, &v);
		--i, --j, --u, --v;
		printf("%d\n", sum2[i][j][u][v]);
	}
	return 0;
}