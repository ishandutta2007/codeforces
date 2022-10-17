#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 500005;
int tt, n, amt;
long long a[N], d[N], t[N << 1], val[N];

void set(int i, long long x) {
	for (i += amt, t[i] = std::max(t[i], x); i > 1; i >>= 1) t[i >> 1] = std::max(t[i], t[i ^ 1]);
}

long long get(int l, int r) {
	long long res = ((long long)1 << 63) >> 2;
	for (l += amt, r += amt; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = std::max(res, t[l++]);
		if (r & 1) res = std::max(res, t[--r]);
	}
	return res;
}

int main() {
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d", &n);
		val[0] = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", a + i);
			a[i] += a[i - 1];
			val[i] = a[i];
		}
		std::sort(val, val + n + 1);
		amt = std::unique(val, val + n + 1) - val;
		long long prev = 0;
		memset(d, 0xc3, amt << 3);
		memset(t, 0xc3, amt << 4);
		for (int i = 0; i <= n; ++i) {
			int pos = std::lower_bound(val, val + amt, a[i]) - val;
			long long res;
			if (i) res = std::max(std::max(get(0, pos) + i, prev - 1), d[pos]);
			else res = 0;
			d[pos] = std::max(d[pos], res);
			set(pos, res - i);
			prev = res;
		}
		printf("%lld\n", prev);
	}
	return 0;
}