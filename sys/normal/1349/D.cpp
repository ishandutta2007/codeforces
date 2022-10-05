#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005, p = 998244353;
int n, m, a[Maxn];
long long ans, val[Maxn];
struct linear
{
	long long k, b;
	linear operator + (const linear &A) const
	{
		return (linear){(k + A.k) % p, (b + A.b) % p};
	}
	linear operator - (const linear &A) const
	{
		return (linear){(p + k - A.k) % p, (p + b - A.b) % p};
	}
	linear operator * (const long long &x) const
	{
		return (linear){k * x % p, b * x % p};
	}
} f[Maxn];
long long get_inv(int x)
{
	if (x <= 1) return 1;
	return (p - p / x) * get_inv(p % x) % p;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), m += a[i];
	f[m] = (linear){1, 0};
	for (int i = m - 1; i >= 1; i--)
	{
		long long val1 = (m - i) * get_inv(m * (n - 1LL) % p) % p, val2 = (m - i) * (n - 2LL) % p * get_inv(m * (n - 1LL) % p) % p, val3 = m * get_inv(i) % p;
		f[i - 1] = (f[i] - f[i] * val2 - f[i + 1] * val1) * val3;
		(f[i - 1].b += p - 1) %= p;
	}
	val[m] = (f[1].b - f[0].b + p) * get_inv((f[0].k - f[1].k + p) % p) % p;
	for (int i = 0; i < m; i++)
		val[i] = (val[m] * f[i].k + f[i].b) % p;
	for (int i = 1; i <= n; i++)
		(ans += val[a[i]]) %= p;
	(ans += 2 * p - (n - 1) * val[0] % p - val[m]) %= p;
	printf("%lld", ans);
	return 0;
}