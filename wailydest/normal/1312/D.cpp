#include <cstdio>
using namespace std;

const int md = 998244353;

inline int sum(int a, int b) 
{
	a += b;
	return a < md ? a : a - md;
}
inline int mul(int a, int b) 
{
	return (int)((long long)a * b % md);
}
inline int po(int a, int b) 
{
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}
inline int inv(int a) 
{
	return po(a, md - 2);
}
inline int di(int a, int b) 
{
	return mul(inv(b), a);
}
inline int fact(int a) 
{
	int res = 1;
	for (int i = 2; i <= a; ++i) res = mul(res, i);
	return res;
}
inline int c(int n, int k) 
{
	return di(fact(n), mul(fact(k), fact(n - k)));
}

int main() 
{
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d\n", n == 2 ? 0 : mul(mul(c(m, n - 1), n - 2), po(2, n - 3)));
	return 0;
}