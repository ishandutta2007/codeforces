#include <cstdio>
#include <algorithm>

const int N = 100000;
int t, n, h[N];
long long d[N], d1[N];

void calc(long long *d) {
	for (int i = 1; i + 1 < n; i += 2) d[i] = (i > 1 ? d[i - 2] : 0) + std::max(0, std::max(h[i - 1], h[i + 1]) - h[i] + 1);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", h + i);
		calc(d);
		if (n & 1) printf("%lld\n", d[n - 2]);
		else {
			std::reverse(h, h + n);
			calc(d1);
			long long ans = ~((long long)1 << 63);
			for (int i = -1; i + 1 < n; i += 2) ans = std::min(ans, (i >= 0 ? d[i] : 0) + (i != n - 3 ? d1[n - (i + 3) - 1] : 0));
			printf("%lld\n", ans);
		}
	}
	return 0;
}