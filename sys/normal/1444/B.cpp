#include <bits/stdc++.h>
using namespace std;

const int p = 998244353, Maxn = 300005;
int n, a[Maxn];
long long ans, fac = 1, inv = 1;
long long get_inv(long long x)
{
	if (x <= 1) return 1;
	return (p - p / x) * get_inv(p % x) % p;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + 2 * n);
	for (int i = 1; i <= n; i++)
		(ans -= a[i]) %= p;
	for (int i = n + 1; i <= 2 * n; i++)
		(ans += a[i]) %= p;
	for (int i = 1; i <= 2 * n; i++)
		(fac *= i) %= p;
	for (int i = 1; i <= n; i++)
		(inv *= i) %= p;
	inv = get_inv(inv);
	printf("%lld", ans * fac % p * inv % p * inv % p);
	return 0;
}