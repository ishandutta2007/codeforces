#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2000005, p = 998244353;
int n, m;
long long ans1, ans2, tot, f[Maxn], fac[Maxn], inv[Maxn];
long long get_inv(int x)
{
	if (x <= 1) return 1;
	return (p - p / x) * get_inv(p % x) % p;
}
long long C(int x, int y)
{
	return fac[x] * inv[y] % p * inv[x - y] % p;
}
int main()
{
	scanf("%d%d", &n, &m);
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % p;
	inv[n] = get_inv(fac[n]);
	for (int i = n - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % p;
	for (int i = 1; i <= n; i++)
		(ans1 += C(n, i) * ((i & 1) ? 1 : p - 1) % p * (i + m) % p * get_inv(i)) %= p;
	for (int i = 1; i <= n + 1; i++)
		f[i] = (1 - tot + p) * m % p * get_inv(m + n - i + 1) % p, (tot += f[i]) %= p, (ans2 += i * f[i]) %= p;
	printf("%lld", ans1 * ans2 % p);
	return 0;
}