#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005, p = 1e9 + 7;
int n, m;
long long ans, fac[Maxn], inv[Maxn], f[Maxn][Maxn][2][2];
long long get_inv(int x)
{
	return x <= 1 ? 1 : (p - p / x) * get_inv(p % x) % p;
}
long long C(int x, int y)
{
	return fac[x] * inv[y] % p * inv[x - y] % p;
}
int main()
{
	scanf("%d%d", &n, &m);
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % p, inv[i] = get_inv(fac[i]);
	f[1][0][0][0] = f[1][1][0][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= i; j++)
		{
			(f[i][j][0][0] += f[i - 1][j][0][0] + f[i - 1][j][1][0]) %= p;
			(f[i][j][1][0] += f[i - 1][j][0][1] + f[i - 1][j][1][1]) %= p;
			(f[i][j + 1][0][1] += f[i - 1][j][0][0] + f[i - 1][j][1][0]) %= p;
			(f[i][j + 1][1][1] += f[i - 1][j][0][1] + f[i - 1][j][1][1]) %= p;
			(f[i][j + 1][0][0] += f[i - 1][j][0][0]) %= p;
			(f[i][j + 1][1][0] += f[i - 1][j][0][1]) %= p;
		}
	for (int i = m; i <= n; i++)
		(ans += (((i - m) & 1) ? p - 1 : 1) * (f[n][i][0][0] + f[n][i][1][0]) % p * C(i, m) % p * fac[n - i]) %= p;
	printf("%lld", ans);
	return 0;
}