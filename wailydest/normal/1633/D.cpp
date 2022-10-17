#include <cstdio>
#include <algorithm>

const int N = 1005;
const int M = 50000;
int t, n, k, d[N], b[N], f[M], c[N];

int main() 
{
	for (int i = 2; i < N; ++i) d[i] = ~(1 << 31);
	for (int i = 1; i < N; ++i) for (int j = 1; j <= i; ++j) if (i + i / j < N) d[i + i / j] = std::min(d[i + i / j], d[i] + 1);
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d", b + i);
			b[i] = d[b[i]];
		}
		for (int i = 0; i < M; ++i) f[i] = 0;
		k = std::min(k, M - 1);
		for (int i = 0; i < n; ++i) {
			scanf("%d", c + i);
			for (int j = M - 1; j >= b[i]; --j) f[j] = std::max(f[j], f[j - b[i]] + c[i]);
		}
		int ans = 0;
		for (int i = 0; i <= k; ++i) ans = std::max(ans, f[i]);
		printf("%d\n", ans);
	}
	return 0;
}