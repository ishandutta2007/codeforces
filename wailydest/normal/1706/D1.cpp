#include <cstdio>
#include <algorithm>

const int N = 100005;
int tc, n, k, a[N];
long long t[N];

void update(int i, long long x) {
	for (i += n, t[i] = x; i > 0; i >>= 1) t[i >> 1] = std::max(t[i], t[i ^ 1]);
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &k);
		int mn = N;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			mn = std::min(mn, a[i]);
			update(i, (long long)a[i] << 32 | i);
		}
		int ans = ~(1 << 31);
		while (true) {
			int val = t[1] >> 32, ind = t[1] & ~(1 << 31);
			ans = std::min(ans, val - mn);
			if (!val) break;
			int next = (a[ind] / val + 1);
			if (next > k) break;
			val = a[ind] / next;
			mn = std::min(mn, val);
			update(ind, (long long)val << 32 | ind);
		}
		printf("%d\n", ans);
	}
	return 0;
}