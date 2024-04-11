#include <bits/stdc++.h>
using namespace std;

const int Maxn = 55, p = 1e9 + 7;
int n, m;
long long inv[Maxn], f[Maxn][Maxn], g[Maxn][Maxn], sum[Maxn][Maxn];
long long get_inv(int x)
{
	return x <= 1 ? 1 : (p - p / x) * get_inv(p % x) % p;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		inv[i] = get_inv(i);
	f[0][1] = sum[0][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i + 1; j++)
			for (int k = 1; k <= i; k++)
				(g[i][j] += sum[k - 1][j] * sum[i - k][j]) %= p;
		for (int j = 1; j <= i + 1; j++)
		{
			(g[i][j] += p - g[i][j + 1]) %= p;
			for (int a = n; a >= 0; a--)
				for (int b = n + 1; b >= 0; b--)
				{
					long long now = 1;
					for (int d = 1; i * d <= a && j * d <= b; d++)
					{
						(now *= inv[d] * (g[i][j] + d - 1 + p) % p) %= p;
						(f[a][b] += now * f[a - i * d][b - j * d]) %= p;
					}
				}
		}
		for (int j = i + 1; j >= 1; j--)
			sum[i][j] = (sum[i][j + 1] + f[i][j]) % p;
	}
	printf("%lld", f[n][m]);
	return 0;
}