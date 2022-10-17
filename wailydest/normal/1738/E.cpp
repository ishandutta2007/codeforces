#include <cstdio>
#include <algorithm>

const int md = 998244353;

inline int add(int a, int b) {
	return a + b < md ? a + b : a + b - md;
}
inline int mul(int a, int b) {
	return (long long)a * b % md;
}
int po(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}
inline int inv(int a) {
	return po(a, md - 2);
}

const int N = 100005;
int t, n, fact[N];
long long a[N];

int ncr(int n, int r) {
	return mul(fact[n], inv(mul(fact[r], fact[n - r])));
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < N; ++i) fact[i] = mul(fact[i - 1], i);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", a + i);
			a[i] += a[i - 1];
		}
		int ans = 1;
		for (int i = 1, j = n - 1; i < n && a[i] * 2 < a[n];) {
			while (j >= 0 && a[j] + a[i] > a[n]) --j;
			int cntj = 0;
			while (j >= 0 && a[j] + a[i] == a[n]) {
				--j;
				++cntj;
			}
			int cnti = 0;
			do {
				++cnti;
				++i;
			} while (i < n && a[i] == a[i - 1]);
			int cur = 1;
			for (int k = 1; k <= std::min(cnti, cntj); ++k) cur = add(cur, mul(ncr(cnti, k), ncr(cntj, k)));
			ans = mul(ans, cur);
		}
		int half = 0;
		for (int i = 1; i < n; ++i) half += a[i] * 2 == a[n];
		ans = mul(ans, po(2, half));
		printf("%d\n", ans);
	}
	return 0;
}