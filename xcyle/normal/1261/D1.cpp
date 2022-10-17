#include <iostream>
#include <cstdio>
#define ll long long
#define maxn 2005
using namespace std;
const int mo = 998244353;
int n, k, f[maxn][maxn * 2], h[maxn];
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
	f[0][n] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 2 * n; j++)
		{
			if(h[i] == h[i % n + 1])
			{
				f[i][j] = (ll)f[i - 1][j] * k % mo;
			}
			else 
			{
				if(j != 0) f[i][j] = (f[i - 1][j - 1] + f[i][j]) % mo;
				if(j != 2 * n) f[i][j] = (f[i - 1][j + 1] + f[i][j]) % mo;
				f[i][j] = (f[i][j] + (ll)(k - 2) * f[i - 1][j] % mo) % mo;
			}
//			printf("%d %d %d\n", i, j, f[i][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = (ans + f[n][n + i]) % mo;
	}
	printf("%d\n", ans);
	return 0;
}