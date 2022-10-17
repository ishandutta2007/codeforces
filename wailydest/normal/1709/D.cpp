#include <cstdio>
#include <algorithm>

const int N = 200000;
int n, m, q, a[N * 2];

int get(int l, int r) {
	int mx = 0;
	if (l > r) std::swap(l, r);
	++r;
	for (l += m, r += m; l < r; l >>= 1, r >>= 1) {
		if (l & 1) mx = std::max(mx, a[l++]);
		if (r & 1) mx = std::max(mx, a[--r]);
	}
	return mx;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) scanf("%d", a + m + i);
	for (int i = m - 1; i > 0; --i) a[i] = std::max(a[i << 1], a[i << 1 | 1]);
	scanf("%d", &q);
	while (q--) {
		int xs, ys, xf, yf, k;
		scanf("%d%d%d%d%d", &xs, &ys, &xf, &yf, &k);
		--ys;
		--yf;
		bool ok = 1;
		if ((xs - xf) % k || (ys - yf) % k) ok = 0;
		int lvl = (n - xs % k) / k * k + xs % k;
		if (get(ys, yf) >= lvl) ok = 0;
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}