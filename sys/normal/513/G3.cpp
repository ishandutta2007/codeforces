#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
int n, k, p[Maxn], D[Maxn][Maxn];
double ans, f[Maxn][Maxn], suma[Maxn][Maxn], sumb[Maxn][Maxn], sumlen[Maxn][Maxn];
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			D[i][j] = (i - 1) * i / 2 + (n - j) * (n - j + 1) / 2 + (j - i - 1) * (j - i) / 2;
	k = min(k, 1000);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = (p[i] > p[j]);
	double P = 2.0 / (n * (n + 1));
	while (k--)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				suma[i][j] = sumb[i][j] = sumlen[i][j] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				suma[i][j] += f[i][j];
				sumb[i][j] += f[j][i];
				if (i > j) sumlen[i - j][j] += f[i][j];
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				suma[i][j] += suma[i][j - 1];
				sumb[i][j] += sumb[i][j - 1];
				sumlen[i][j] += sumlen[i][j - 1];
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				suma[i][j] += suma[i][j - 1];
				sumb[i][j] += sumb[i][j - 1];
				sumlen[i][j] += sumlen[i][j - 1];
			}
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
			{
				f[i][j] = f[i][j] * P * D[i][j];
				f[i][j] += P * (sumb[j][j - 1] - sumb[j][j - i - 1] - sumb[j][i - 1]);
				f[i][j] += P * (sumlen[j - i][i + n - j] - sumlen[j - i][n - j] - sumlen[j - i][i - 1]);
				f[i][j] += P * (suma[i][n] - suma[i][i + n - j] - suma[i][j - 1] + suma[i][i - 1]);
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j < i; j++)
				f[i][j] = 1 - f[j][i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			ans += f[i][j];
	printf("%.10lf", ans);
	return 0;
}