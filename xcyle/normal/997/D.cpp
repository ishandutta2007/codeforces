/*

_/      _/      _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/     _/      _/     _/    _/     _/           _/
  _/  _/      _/              _/  _/      _/           _/
   _/_/       _/                _/        _/           _/_/_/_/
  _/  _/      _/                _/        _/           _/
 _/    _/     _/      _/        _/        _/           _/
_/      _/      _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <cstdlib>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 4005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n[2], len, a, b, fa[2][maxn];
vector<int> G[2][maxn];
void dfs(int tp, int x, int fat)
{
	fa[tp][x] = fat;
	for (int i = 0; i < G[tp][x].size(); i++)
	{
		int V = G[tp][x][i];
		if(V == fat) continue;
		dfs(tp, V, x);
	}
}
int f[2][maxn][80], g[2][maxn][80];
void work(int tp)
{
	for (int i = 1; i <= n[tp]; i++) f[tp][i][0] = 1;
	for (int i = 2; i <= n[tp]; i++) g[tp][i][0] = 1;
	for (int i = 1; i <= len; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 1; k <= n[tp]; k++)
			{
				int tmp = g[tp][k][i - j - 1];
				for (int son = 0; son < G[tp][k].size(); son++)
				{
					int V = G[tp][k][son];
					if(V == fa[tp][k]) continue;
					f[tp][k][i] = (f[tp][k][i] + (ll)f[tp][k][j] * f[tp][V][i - j - 1] % mo) % mo;
					tmp = (tmp + f[tp][V][i - j - 1]) % mo;
				}
				for (int son = 0; son < G[tp][k].size(); son++)
				{
					int V = G[tp][k][son];
					if(V == fa[tp][k]) continue;
					g[tp][V][i] = (g[tp][V][i] + (ll)g[tp][V][j] * (tmp + mo - f[tp][V][i - j - 1]) % mo) % mo;
				}
			}
		}
	}
}
int res[2][80], h[maxn][80], H[80];
void calc(int tp)
{
	for (int i = 1; i <= n[tp]; i++)
	{
		for (int k = 0; k <= len; k++)
		{
			h[i][k] = 0;
			for (int j = 0; j < G[tp][i].size(); j++)
			{
				int V = G[tp][i][j];
				if(V == fa[tp][i]) continue;
				h[i][k] = (h[i][k] + f[tp][V][k]) % mo;
			}
		}
	}
	for (int i = 1; i <= n[tp]; i++)
	{
		H[0] = 1;
		for (int j = 1; j <= len; j++)
		{
			H[j] = 0;
			for (int k = 0; k < j; k++)
			{
				int tmp = (h[i][j - k - 1] + g[tp][i][j - k - 1]) % mo;
				H[j] = (H[j] + (ll)H[k] * tmp % mo) % mo;
			}
		}
//		for (int j = 0; j <= len; j++) printf("%d ", H[j]);
//		printf("\n");
		for (int j = 0; j <= len; j++) res[tp][j] = (res[tp][j] + H[j]) % mo;
	}
}
int c[80][80];
int main()
{
	scanf("%d%d%d", &n[0], &n[1], &len);
	if(len & 1)
	{
		printf("0\n");
		return 0;
	}
	len >>= 1;
	for (int i = 1; i < n[0]; i++)
	{
		a = read(), b = read();
		G[0][a].push_back(b);
		G[0][b].push_back(a);
	}
	for (int i = 1; i < n[1]; i++)
	{
		a = read(), b = read();
		G[1][a].push_back(b);
		G[1][b].push_back(a);
	}
	dfs(0, 1, 0), dfs(1, 1, 0);
	work(0), work(1);
	calc(0), calc(1);
	c[0][0] = 1;
	for (int i = 1; i < 80; i++)
	{
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mo;
		}
	}
	int ans = 0;
	for (int i = 0; i <= len; i++) ans = (ans + (ll)res[0][i] * res[1][len - i] % mo * c[len * 2][i * 2] % mo) % mo;
	printf("%d", ans);
	return 0;
}