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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
vector<int> G[100005];
int n, fa[100005];
double f[100005];
int siz[100005];
void work(int x)
{
	siz[x] = 1;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		work(V);
		siz[x] += siz[V];
	}
}
void dfs(int x)
{
	f[x]++;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		f[V] = (f[x] + (double)(siz[x] - 1 - siz[V]) / 2.0);
		dfs(V);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		scanf("%d", &fa[i]);
		G[fa[i]].push_back(i);
	}
	work(1);
	dfs(1);
	for (int i = 1; i <= n; i++) printf("%.6f ", f[i]);
	return 0;
}