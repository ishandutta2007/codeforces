#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, n, a, b, p[N + 1];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &a, &b);
		for (int i = 1; i <= n; ++i) scanf("%d", p + i);
		long long ans = ~((long long)1 << 63), ri = 0;
		for (int i = n; i >= 0; --i) {
			ans = std::min(ans, ri * b + (long long)(a + b) * p[i]);
			if (i) ri += (long long)(p[i] - p[i - 1]) * (n - i + 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}