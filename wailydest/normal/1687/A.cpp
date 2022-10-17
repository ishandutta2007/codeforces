#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, n, k;
long long a[N + 1];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", a + i);
			a[i] += a[i - 1];
		}
		if (k <= n) {
			long long ans = 0;
			for (int i = k; i <= n; ++i) ans = std::max(ans, a[i] - a[i - k]);
			printf("%lld\n", ans + (long long)k * (k - 1) / 2);
		} else printf("%lld\n", a[n] + (long long)n * k - (long long)n * (n + 1) / 2);
	}
	return 0;
}