#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 205
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, k, p;
int f[maxn][maxn][maxn];//ijk 
int g[maxn];
int c[maxn][maxn];
int main()
{ 
	scanf("%d%d%d%d", &n, &m, &k, &p);
	c[0][0] = 1;
	for (int i = 1; i <= n + 1; i++)
	{
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
		}
	}
	f[0][0][1] = 1;
	for (int i = 1; i <= n; i++) f[0][i][0] = 1;
	g[0] = 1;
	for (int i = 1; i <= n + 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			g[i] = (g[i] + (ll)g[j] * g[i - 1 - j] % p * c[i - 1][j] % p) % p;
		}
		f[i][0][1] = g[i];
		for (int j = i + 1; j <= n; j++) f[i][j][0] = g[i];
		for (int j = 1; j <= i; j++)
		{
			for (int ls = 0; ls < i; ls++)
			{
				for (int lcnt = 0; lcnt <= 1 + ls; lcnt++)
				{
					if(!f[ls][j - 1][lcnt]) continue;
					for (register int rcnt = 0; rcnt <= i - 1 - ls + 1; rcnt++)
					{
						f[i][j][lcnt + rcnt] = (f[i][j][lcnt + rcnt] + (ll)f[ls][j - 1][lcnt] * f[i - 1 - ls][j - 1][rcnt] % p * c[i - 1][ls] % p) % p;
//						printf("%d %d %d %d %d %d\n", i, j, ls, lcnt, rcnt, f[i][j][lcnt + rcnt]);
					}
				}
			}
		} 
	}
	printf("%d", f[n][m][2 * k]);
	return 0;
}