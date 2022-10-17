#include <iostream>
#include <cstdio>
#define ll long long
#define maxn 5005
using namespace std;
const int mo = 1e9 + 7;
int n, k, q, pos, data, a[maxn];
int f[maxn][maxn];
int x[maxn];
int main()
{
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int j = 1; j <= n; j++)
	{
		f[0][j] = 1;
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(j != 1) f[i][j] += f[i - 1][j - 1];
			if(j != n) f[i][j] += f[i - 1][j + 1];
			f[i][j] %= mo;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			x[i] = (x[i] + (ll)f[j][i] * f[k - j][i] % mo) % mo;	
		}
		ans = (ans + (ll)x[i] * a[i] % mo) % mo;
	}
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d", &pos, &data);
		ans = (ans - (ll)x[pos] * a[pos] % mo + mo) % mo;
		a[pos] = data;
		ans = (ans + (ll)x[pos] * a[pos]) % mo;
		printf("%d\n", ans);
	}
	return 0;
}