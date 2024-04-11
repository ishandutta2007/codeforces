#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005, p = 1e9 + 7;
int n, k;
long long sum, fac[Maxn], inv[Maxn];
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}
void init(void)
{
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % p;
	inv[n] = fast_pow(fac[n], p - 2);
	for (int i = n - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % p;
}
long long S(int x, int y)
{
	long long tmp = 0;
	for (int i = 0; i <= y; i++)
		(tmp += ((y - i) & 1 ? p - 1 : 1) * inv[i] % p * inv[y - i] % p * fast_pow(i, x) % p) %= p;
	return tmp;
}
int main()
{
	scanf("%d%d", &n, &k);
	init();
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x), (sum += x) %= p;
	}
	printf("%lld\n", sum * (S(n, k) + (n - 1) * S(n - 1, k) % p) % p);
	return 0;
}