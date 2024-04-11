#include <cstdio>
#include <algorithm>

const int N = 2000;
int t, n, a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		int ans = a[n - 1] - a[0];
		if (n > 1) {
			for (int i = 0; i + 1 < n; ++i) ans = std::max(ans, a[i] - a[i + 1]);
			int mx = 0;
			for (int i = 1; i < n; ++i) mx = std::max(mx, a[i]);
			ans = std::max(ans, mx - a[0]);
			mx = ~(1 << 31);
			for (int i = 0; i + 1 < n; ++i) mx = std::min(mx, a[i]);
			ans = std::max(ans, a[n - 1] - mx);
		}
		printf("%d\n", ans);
	}
	return 0;
}