#include <cstdio>

const int md = 998244353;
inline int add(int a, int b) {
	a += b;
	if (a >= md) a -= md;
	return a;
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
inline int di(int a, int b) {
	return mul(a, inv(b));
}

const int N = 255;
int n, k, d[N], fact[N];

int f(int i) {
	return i * (i - 1) / 2;
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < N; ++i) fact[i] = mul(fact[i - 1], i);
	scanf("%d%d", &n, &k);
	d[0] = 1;
	for (int i = 0; i < k; ++i) {
		int amt = k - i;
		for (int j = n - 1; j > 0; --j) {
			for (int k = 1; k <= j; ++k) {
				d[j] = add(d[j], di(mul(po(amt, f(j) - f(j - k)), d[j - k]), fact[k]));
			}
		}
	}
	printf("%d\n", mul(fact[n - 1], d[n - 1]));
	return 0;
}