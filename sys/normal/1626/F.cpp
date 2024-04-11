#include <bits/stdc++.h>
using namespace std;

const int p = 998244353, Maxn = 10000005;
int n, x, y, k, M, L = 1, a[Maxn], f[Maxn], g[Maxn];
long long ans, fn[19];
int main()
{
	scanf("%d%d%d%d%d%d", &n, &a[0], &x, &y, &k, &M), fn[0] = 1;
	for (int i = 1; i < k; i++) L = L / __gcd(L, i) * i, fn[i] = fn[i - 1] * n % p;
	for (int i = 1; i < n; i++) a[i] = (1LL * a[i - 1] * x + y) % M;
	for (int i = 0; i < n; i++) f[a[i] % L]++, (ans += 1LL * (a[i] / L) * L % p * k % p * fn[k - 1]) %= p;
	for (int i = 1; i <= k; i++)
	{
		memcpy(g, f, sizeof(int[L])), memset(f, 0, sizeof(int[L]));
		for (int j = 0; j < L; j++)
		{
			if (i != k) (f[j] += g[j] * (n - 1LL) % p) %= p, (f[j - j % i] += g[j]) %= p;
			(ans += 1LL * g[j] * j % p * fn[k - i]) %= p;
		}
	}
	printf("%lld", ans);
	return 0;
}