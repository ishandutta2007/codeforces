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
#define maxn 2005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
char s[maxn];
vector<int> G[maxn], val[maxn]; 
inline void add(int x, int y, int z)
{
	G[x].push_back(y);
	val[x].push_back(z);
	G[y].push_back(x);
	val[y].push_back(z);
}
int dep[maxn], vis[maxn];
void dfs(int x, int c)
{
	vis[x] = 1;
	dep[x] = c;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(vis[V]) continue;
		dfs(V, (c ^ val[x][i]));
	}
}
int main()
{
	scanf("%s", s + 1);
	int ans = 0;
	int n = strlen(s + 1);
	for (int i = 1; i <= n / 2; i++) swap(s[i], s[n - i + 1]);
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j <= 2 * n; j++) G[j].clear(), val[j].clear(), vis[j] = 0;
		for (int j = 1; j <= n; j++) add(j, n - j + 1, 0);
		for (int j = 1; j <= i; j++) add(n + j, n + i - j + 1, 0);
		for (int j = 1; j <= i; j++)
		{
			if(s[j] != '?') add(j, n + j, s[j] - '0');
		}
		for (int j = i + 1; j <= n; j++)
		{
			if(s[j] != '?') add(j, 0, s[j] - '0');
		}
		add(n + 1, 0, 1);
		int tmp = 1;
		for (int j = 0; j <= n + i; j++)
		{
			if(vis[j]) continue;
			dfs(j, 0);
			if(j != 0) tmp = (ll)tmp * 2 % mo;
		}
		int fl = 1;
		for (int j = 0; j <= n + i; j++)
		{
			for (int k = 0; k < G[j].size(); k++)
			{
				int V = G[j][k];
				if((dep[V] ^ dep[j]) != val[j][k]) fl = 0;
			}
		}
		if(fl) ans = (ans + tmp) % mo;
	}
	printf("%d", ans);
	return 0;
}