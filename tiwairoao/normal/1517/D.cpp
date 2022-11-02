#include <bits/stdc++.h>

int a[505][505], b[505][505], n, m, k;

int f[505][505];

void solve() {
	static int g[505][505];
	for (int i = 1; i <= n; i++) g[i][0] = g[i][m + 1] = (1 << 30);
	for (int j = 1; j <= m; j++) g[0][j] = g[n + 1][j] = (1 << 30);
	for (int t = 1; t <= k; t++) {
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) g[i][j] = f[i][j];
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
			f[i][j] = std::min(
				std::min(g[i - 1][j] + b[i - 1][j], g[i + 1][j] + b[i][j]),
				std::min(g[i][j - 1] + a[i][j - 1], g[i][j + 1] + a[i][j])
			);
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) for (int j = 1; j < m; j++) scanf("%d", &a[i][j]);
	for (int i = 1; i < n; i++) for (int j = 1; j <= m; j++) scanf("%d", &b[i][j]);

	if (k & 1) {
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
			printf("-1%c", j == m ? '\n' : ' ');
	} else {
		k >>= 1, solve();
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
			printf("%d%c", f[i][j] << 1, j == m ? '\n' : ' ');
	}
}