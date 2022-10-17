#include <cstdio>
#include <algorithm>
#include <cstring>

const int md = 998244353;

inline int add(int a, int b) {
	a += b;
	if (a >= md) a -= md;
	return a;
}
inline int sub(int a, int b) {
	a -= b;
	if (a < 0) a += md;
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

const int N = 1000005;
int t, n, a[N], d[N], dtotal[N], fact[N], factinv[N];

inline int nCr(int n, int r) {
	return mul(fact[n], mul(factinv[r], factinv[n - r]));
}

int main() {
	fact[0] = factinv[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = mul(fact[i - 1], i);
		factinv[i] = di(factinv[i - 1], i);
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(a, 0, n << 2);
		bool same = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			--x;
			++a[x];
			if (a[x] == n) same = 1;
		}
		if (same) printf("1\n");
		else {
			for (int i = 1; i <= n; ++i) if (!(n % i)) {
				bool ok = 1;
				int cnt = n / i, prod = 1;
				for (int j = 0; j < n && ok; ++j) if (a[j]) {
					if (a[j] % i) ok = 0;
					else prod = mul(prod, factinv[a[j] / i]);
				}
				dtotal[i] = 0;
				if (ok) {
					d[i] = mul(prod, fact[cnt]);
					if (cnt > 1) prod = mul(prod, fact[cnt - 2]);
					if (d[i]) for (int j = 0; j < n; ++j) if (a[j] / i > 1) dtotal[i] = add(dtotal[i], mul(prod, mul(a[j] / i, a[j] / i - 1)));
				} else d[i] = 0;
			}
			int amt = 0, total = 0;
			for (int i = 0; i < n; ++i) {
				int g = std::__gcd(i, n);
				amt = add(amt, d[n / g]);
				total = add(total, dtotal[n / g]);
			}
			total = sub(amt, total);
			amt = di(amt, n);
			printf("%d\n", di(total, amt));
		}
	}
	return 0;
}