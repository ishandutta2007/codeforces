#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, n, x, a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &x);
		int mn = ~(1 << 31), mx = 0, ans = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			mn = std::min(mn, a[i]);
			mx = std::max(mx, a[i]);
			if (mx - mn > x * 2) {
				mn = mx = a[i];
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}