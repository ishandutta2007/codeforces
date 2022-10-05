#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, m, k;
long double ans, fac[Maxn];
void init(void)
{
	for (int i = 1; i <= m; i++)
		fac[i] = fac[i - 1] + log2(i);
}
long double C(int x, int y)
{
	return fac[x] - fac[y] - fac[x - y];
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	init();
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			if (k >= i * n + j * n - i * j)
			{
				ans += pow(2, C(n, i) + C(n, j) + C(m - i * n - j * n + i * j, k - i * n - j * n + i * j) - C(m, k));
				if (ans >= 1e99)
				{
					puts("1e99");
					return 0;
				}
			}
	printf("%.10lf", (double) ans);
	return 0;
}