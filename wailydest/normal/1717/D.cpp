#include <cstdio>
#include <algorithm>

const int md = 1000000007;

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

const int N = 100005;
int n, k, fact[N];

int ncr(int n, int r) {
	return mul(fact[n], po(mul(fact[r], fact[n - r]), md - 2));
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < N; ++i) fact[i] = mul(fact[i - 1], i);
	scanf("%d%d", &n, &k);
	k = std::min(k, n);
	int ans = 0;
	for (int i = 0; i <= k; ++i) ans = add(ans, ncr(n, i));
	printf("%d\n", ans);
	return 0;
}