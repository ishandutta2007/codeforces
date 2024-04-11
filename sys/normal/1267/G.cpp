#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
int n, sum, c[Maxn];
double x, ans, f[Maxn][Maxn * Maxn];
int main()
{
	scanf("%d%lf", &n, &x), x /= 2;
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]), sum += c[i];
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = i - 1; j >= 0; j--)
			for (int k = c[i]; k <= sum; k++)
				f[j + 1][k] += f[j][k - c[i]] * (j + 1) / (double) (n - j);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= sum; j++)
			ans += f[i][j] * min((n / (double) i + 1) * x, j / (double) i);
	printf("%.10lf", ans);
	return 0;
}