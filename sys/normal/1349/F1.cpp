#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005, p = 998244353;
int n;
long long E[Maxn][Maxn], fac[Maxn], inv[Maxn], ans[Maxn];
long long get_inv(int x)
{
	if (x <= 1) return 1;
	return (p - p / x) * get_inv(p % x) % p;
}
int main()
{
	scanf("%d", &n);
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % p, inv[i] = get_inv(fac[i]);
	for (int i = 0; i <= n; i++)
	{
		E[i][0] = 1;
		for (int j = 1; j < i; j++)
			E[i][j] = (E[i - 1][j] * (j + 1) + E[i - 1][j - 1] * (i - j)) % p;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			(ans[j] += E[i][j - 1] * fac[n] % p * inv[i]) %= p;
	for (int i = 1; i <= n; i++)
		printf("%lld ", ans[i]);
	return 0;
}