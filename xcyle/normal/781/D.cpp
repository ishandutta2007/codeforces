/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <bitset>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define mid ((l + r) >> 1)
#define maxn 505
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, k;
bitset<maxn> f[2][62][2][maxn];
int vis[62][maxn];
int main()
{
	n = read(), m = read();
	for (int i = 1; i <= m; i++)
	{
		int x = read(), y = read(), t = read();
		f[t][0][0][x][y] = 1;
		f[t][0][1][y][x] = 1;
	}
	for (int i = 1; i <= 61; i++)
	{
		for (int tp = 0; tp < 2; tp++)
		{
			for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++)
			{
				f[tp][i][0][j][k] = f[tp][i][1][k][j] = (f[tp][i - 1][0][j] & f[tp ^ 1][i - 1][1][k]).any();
			}
		}
	}
	int tp = 0;
	vis[61][1] = 1;
	ll ans = 0;
	for (int i = 60; i >= 0; i--)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++) vis[i][k] |= (vis[i + 1][j] & f[tp][i][0][j][k]);
		}
		int fl = 0; for (int j = 1; j <= n; j++) fl |= vis[i][j];
		if(fl) ans += (1ll << i), tp ^= 1;
		else
		{
			for (int j = 1; j <= n; j++) vis[i][j] = vis[i + 1][j];
		}
	}
	if(ans > 1e18) printf("-1");
	else printf("%lld\n", ans);
	return 0;
}