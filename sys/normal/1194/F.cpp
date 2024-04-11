#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005, p = 1e9 + 7;
int n, x_now, y_now, a[Maxn];
long long T, ans, now = 1, result = 1, sum, fac[Maxn], inv[Maxn];
long long get_inv(long long x)
{
	if (x <= 1) return 1;
	return (p - p / x) * get_inv(p % x) % p;
}
long long C(int x, int y)
{
	return fac[x] * inv[y] % p * inv[x - y] % p;
}
long long Csum(int x, int y)
{
	while (x > x_now) (result = result * 2 + p - C(x_now, y_now)) %= p, x_now++;
	while (y < y_now) (result = result + p - C(x_now, y_now)) %= p, y_now--;
	while (y > y_now) y_now++, (result = result + C(x_now, y_now)) %= p;
	return result;
}
int main()
{
	scanf("%d%lld", &n, &T);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % p;
	inv[n] = get_inv(fac[n]);
	for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % p;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		(now *= (p + 1) / 2) %= p;
		sum += a[i];
		if (sum > T) break;
		(ans += now * Csum(i, min((long long) i, T - sum))) %= p;
	}
	printf("%lld", ans);
	return 0;
}