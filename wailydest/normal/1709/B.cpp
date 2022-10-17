#include <cstdio>
#include <algorithm>

const int N = 100000;
int n, m, a[N];
long long s[N], s1[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 1; i < n; ++i) {
		s[i] = std::max(a[i - 1] - a[i], 0) + s[i - 1];
		s1[i] = std::max(a[i] - a[i - 1], 0) + s1[i - 1];
	}
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x;
		--y;
		if (x < y) printf("%lld\n", s[y] - s[x]);
		else printf("%lld\n", s1[x] - s1[y]);
	}
	return 0;
}