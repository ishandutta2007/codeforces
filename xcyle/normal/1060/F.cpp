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
#define rc(x) ((x) << 1 | 1)
#define maxn 52
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, siz[maxn];
vector<int> G[maxn];
double f[maxn][maxn], g[maxn][maxn];
ll c[maxn][maxn];
void dfs(int x, int fa)
{
	for (int i = 0; i <= siz[x]; i++) g[x][i] = f[x][i] = 0;
	siz[x] = 0;
	g[x][0] = 1.0;
	for (auto V: G[x]) if(V ^ fa)
	{
		dfs(V, x);
		for (int j = siz[x]; j >= 0; j--)
		{
			double tmp = g[x][j];
			for (int nj = siz[V]; nj >= 0; nj--)
			{
				g[x][j + nj] += g[x][j] * f[V][nj] * ((double)c[j + nj][j] * c[siz[x] + siz[V] - j - nj][siz[x] - j] / c[siz[x] + siz[V]][siz[x]]);
			}
			g[x][j] -= tmp;
		}
		siz[x] += siz[V];
	}
	siz[x]++;
	for (int i = 0; i <= siz[x]; i++)
	{
		for (int j = 1; j <= i; j++) f[x][i] += g[x][i - 1];
		for (int j = i + 1; j <= siz[x]; j++) f[x][i] += g[x][j - 1] / 2.0;
		f[x][i] /= siz[x];
	}
}
int main()
{
	c[0][0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
	n = read();
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		dfs(i, 0);
		printf("%.9f\n", g[i][0]);
	}
	return 0;
}