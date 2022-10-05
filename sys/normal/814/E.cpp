#include <bits/stdc++.h>
using namespace std;

const int Maxn = 55, p = 1e9 + 7;
int n, d[Maxn], cnt2[Maxn], cnt3[Maxn];
long long ans, fac[Maxn], val[Maxn], C[Maxn][Maxn], f[Maxn][Maxn], g[Maxn][Maxn][Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &d[i]), cnt2[i] = cnt2[i - 1] + (d[i] == 2), cnt3[i] = cnt3[i - 1] + (d[i] == 3);
	g[0][0][0] = C[0][0] = fac[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		fac[i] = fac[i - 1] * i % p;
		C[i][0] = 1;
		if (i > 2) val[i] = fac[i - 1] * (p + 1) / 2 % p;
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 2; j < i; j++)
			(g[0][0][i] += g[0][0][i - j - 1] * C[i - 1][j] % p * val[j + 1]) %= p;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k <= n; k++)
			{
				if (!i && !j) continue;
				if (!i) g[i][j][k] = ((j >= 2 ? g[i][j - 2][k] * (j - 1) : 0) + k * g[i][j][k - 1]) % p;
				else g[i][j][k] = (j * g[i - 1][j - 1][k] + k * g[i - 1][j + 1][k - 1]) % p;
			}
	f[d[1] + 1][d[1]] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			for (int k = 1; k <= i - j; k++)
				(f[i][j] += f[i - j][k] * g[j][cnt2[i - j] - cnt2[i - j - k]][cnt3[i - j] - cnt3[i - j - k]]) %= p;
	for (int i = 0; i <= n; i++)
		(ans += f[n][i] * g[0][cnt2[n] - cnt2[n - i]][cnt3[n] - cnt3[n - i]]) %= p;
	printf("%lld", ans);
	return 0;
}