#include <cstdio>

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

const int N = 300010;
int t, n, fact[N], f[N], g[N];

int ncr(int n, int r) {
	return mul(fact[n], inv(mul(fact[r], fact[n - r])));
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < N; ++i) fact[i] = mul(fact[i - 1], i);
	f[0] = 1;
	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i < N; ++i) f[i] = add(f[i - 1], mul(i - 1, f[i - 2]));
	g[1] = 1;
	for (int i = 3; i < N; ++i) g[i] = mul(g[i - 2], i - 2);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int ans = 0;
		for (int i = 0; i * 4 <= n; ++i) 
			ans = add(ans, mul(po(2, i), mul(f[n - i * 4], mul(ncr(n - i * 2, i * 2), g[2 * i + 1]))));
		printf("%d\n", ans);
	}
	return 0;
}