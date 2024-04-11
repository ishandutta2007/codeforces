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
#define ll long long
#define lc(x) ((x) << 1)
#define db double
#define rc(x) ((x) << 1 | 1)
#define maxn 2005
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, f[maxn][maxn], n, m, k;
db g[maxn][maxn];
int inv2 = (mo + 1) / 2;
void solve()
{
	scanf("%d%d%d", &n, &m, &k);
	f[0][0] = 0;
	g[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		f[i][0] = 0;
		g[i][0] = 0;
		for (int j = 1; j < i; j++)
		{
			if(g[i - 1][j] < g[i - 1][j - 1])
			{
				g[i][j] = g[i - 1][j];
				f[i][j] = f[i - 1][j];
			} 
			db tmp = (g[i - 1][j] - g[i - 1][j - 1]);
			if(tmp > 2 * k)
			{
				g[i][j] = g[i - 1][j - 1] + k;
				f[i][j] = (f[i - 1][j - 1] + k) % mo;
			}
			f[i][j] = (ll)(f[i - 1][j] + f[i - 1][j - 1]) * inv2 % mo;
			g[i][j] = (g[i - 1][j] + g[i - 1][j - 1]) / 2;
		}
		f[i][i] = (ll)k * i % mo;
		g[i][i] = k * i;
	}
	printf("%d\n", f[n][m]);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}