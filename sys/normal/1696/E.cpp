#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005, p = 1e9 + 7;
int n, a[Maxn];
long long ans, fac[Maxn], inv[Maxn];
long long get_inv(int x)
{
	return x <= 1 ? 1 : (p - p / x) * get_inv(p % x) % p;
}
long long C(int x, int y)
{
	if (x < y) return 0;
	return fac[x] * inv[y] % p * inv[x - y] % p;
}
int f[20][20];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		scanf("%d", &a[i]);
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= a[0] + n; i++)
		fac[i] = fac[i - 1] * i % p, inv[i] = get_inv(fac[i]);
	for (int i = 0; i <= n; i++)
		(ans += C(i + a[i], i + 1)) %= p;
	printf("%lld", ans);
	return 0;
}