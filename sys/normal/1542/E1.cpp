#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
int n, p, shift;
long long ans, f[Maxn][Maxn * Maxn], fac[Maxn], C[Maxn][Maxn];
int main()
{
	scanf("%d%d", &n, &p);
	shift = n * (n - 1) / 2;
	C[0][0] = fac[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		fac[i] = fac[i - 1] * i % p;
		C[i][0] = 1;
		for (int j = 1; j <= n; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
	}
	f[0][shift] = 1;
	for (int i = 1; i <= n; i++)
		for (int k = -i * (i - 1) / 2; k <= i * (i - 1) / 2; k++)
			for (int j = -i; j <= i; j++)
				(f[i][shift + k + j] += f[i - 1][shift + k] * (i - abs(j))) %= p;
	for (int i = 1; i <= n; i++)
		for (int j = n * (n - 1) / 2; j >= 0; j--)
			(f[i][shift + j] += f[i][shift + j + 1]) %= p;
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= n - i; j++)
			for (int k = j + 1; k <= n - i; k++)
				(ans += C[n][i] * fac[i] % p * f[n - i - 1][shift + k - j + 1]) %= p;
	printf("%lld", ans);
	return 0;
}