#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005, p = 1e9 + 7;
int T, n, m, k;
long long inv2[Maxn], fac[Maxn], inv[Maxn];
long long get_inv(int x)
{
	return x <= 1 ? 1 : (p - p / x) * get_inv(p % x) % p;
}
long long C(int x, int y)
{
	if (x < y) return 0;
	return fac[x] * inv[y] % p * inv[x - y] % p;
}
int main()
{
	scanf("%d", &T);
	inv2[0] = fac[0] = inv[0] = 1;
	for (int i = 1; i <= 1000000; i++)
	{
		inv2[i] = inv2[i - 1] * (p + 1) / 2 % p;
		fac[i] = fac[i - 1] * i % p;
		inv[i] = get_inv(fac[i]);
	}
	while (T--)
	{
		long long ans = 0;
		scanf("%d%d%d", &n, &m, &k);
		if (n == m)
		{
			printf("%lld\n", 1LL * n * k % p);
			continue;
		}
		for (int i = 1; i <= m; i++)
			(ans += C(n - i - 1, m - i) * i % p * inv2[n - i]) %= p;
		printf("%lld\n", ans * k % p);
	}
	return 0;
}