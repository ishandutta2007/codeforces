#include <cstdio>
#include <algorithm>

const int N = 500;
const int M = 250000;
int t, n, m, a[M], b[M], c[M], w[N][N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) w[i][j] = ~(1 << 31) >> 2;
		for (int i = 0; i < n; ++i) w[i][i] = 0;
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", a + i, b + i, c + i);
			--a[i];
			--b[i];
			if (a[i] != b[i]) {
				w[a[i]][b[i]] = 1;
				w[b[i]][a[i]] = 1;
			}
		}
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) w[j][k] = std::min(w[j][k], w[j][i] + w[i][k]);
		long long ans = ~((long long)1 << 63);
		for (int i = 0; i < m; ++i) ans = std::min(ans, (long long)c[i] * std::min(w[a[i]][0] + w[b[i]][n - 1], w[a[i]][n - 1] + w[b[i]][0]) + c[i]);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) ans = std::min(ans, (long long)c[i] * (w[j][0] + w[j][n - 1] + std::min(w[a[i]][j], w[b[i]][j])) + c[i] + c[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}