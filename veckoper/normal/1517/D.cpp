#include <bits/stdc++.h>
using namespace std;
const int N = 502, K = 11;
int n, m, k, a[N][N], b[N][N], f[N][N][K];
inline void U(int &x, int y) {
	x = (x < y ? x : y);
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < m; ++j)
			scanf("%d", &a[i][j]);
	for (int i = 1; i < n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &b[i][j]);
	if (k & 1) {
		for (int i = 1; i <= n; puts(""), ++i)
			for (int j = 1; j <= m; ++j) 
				printf("%d ", -1);
		return 0;
	}
	k >>= 1;
	for (int t = 1; t <= k; ++t) {
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				f[i][j][t] = 1e9;
				if (i > 1) U(f[i][j][t], f[i - 1][j][t - 1] + b[i - 1][j]);
				if (j > 1) U(f[i][j][t], f[i][j - 1][t - 1] + a[i][j - 1]);
				if (i < n) U(f[i][j][t], f[i + 1][j][t - 1] + b[i][j]);
				if (j < m) U(f[i][j][t], f[i][j + 1][t - 1] + a[i][j]);
			}
	}
	for (int i = 1; i <= n; puts(""), ++i)
		for (int j = 1; j <= m; ++j)
			printf("%d ", f[i][j][k] * 2);
	return 0;
}