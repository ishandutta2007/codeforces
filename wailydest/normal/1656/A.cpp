#include <cstdio>
#include <algorithm>

int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		std::pair<int, int> mn, mx;
		mn.first = ~(1 << 31);
		mx.first = 1 << 31;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			mn = std::min(mn, std::make_pair(x, i + 1));
			mx = std::max(mx, std::make_pair(x, i + 1));
		}
		printf("%d %d\n", mn.second, mx.second);
	}
	return 0;
}