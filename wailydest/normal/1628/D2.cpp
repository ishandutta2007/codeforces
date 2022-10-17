#include <cstdio>

const int md = 1000000007;
const int inv2 = 500000004;

inline int add(int a, int b) 
{
	a += b;
	if (a >= md) a -= md;
	return a;
}
inline int sub(int a, int b) 
{
	a -= b;
	if (a < 0) a += md;
	return a;
}
inline int mul(int a, int b) 
{
	return (long long)a * b % md;
}
int po(int a, int b) 
{
	int r = 1;
	while (b) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}
inline int inv(int a) 
{
	return po(a, md - 2);
}
inline int di(int a, int b) 
{
	return mul(a, inv(b));
}

const int N = 1000005;
int t, n, m, k, fact[N];

int nCr(int n, int r) 
{
	return di(fact[n], mul(fact[r], fact[n - r]));
}

int main() 
{
	fact[0] = 1;
	for (int i = 1; i < N; ++i) fact[i] = mul(fact[i - 1], i);
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		if (n == m) printf("%d\n", mul(n, k));
		else {
			int ans = 0, val = 0;
			for (int i = 1; i <= m; ++i) {
				val = add(val, k);
				ans = add(ans, mul(mul(po(2, i - 1), val), nCr(n - i - 1, m - i)));
			}
			printf("%d\n", di(ans, po(2, n - 1)));
		}
	}
	return 0;
}