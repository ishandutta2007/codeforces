#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 105;
int t, n, a[N], b[N];
bool d[N][N * N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int s = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			s += a[i];
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", b + i);
			s += b[i];
		}
		if (n == 1) printf("0\n");
		else {
			memset(*d, 0, (n + 1) * N * N);
			d[0][0] = 1;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j <= i * N; ++j) if (d[i][j]) {
					d[i + 1][j + a[i]] = 1;
					d[i + 1][j + b[i]] = 1;
				}
			}
			int ans = ~(1 << 31);
			for (int i = 0; i < N * N; ++i) if (d[n][i]) ans = std::min(ans, i * i + (s - i) * (s - i));
			for (int i = 0; i < n; ++i) ans += (a[i] * a[i] + b[i] * b[i]) * (n - 2);
			printf("%d\n", ans);
		}
	}
	return 0;
}