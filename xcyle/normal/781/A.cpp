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
#define mid ((l + r) >> 1)
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, col[maxn], cnt = 2;
vector<int> G[maxn];
void dfs(int x, int fa)
{
	int now = 1;
	for (auto V: G[x]) if(V ^ fa) 
	{
		while(col[x] == now || col[fa] == now) now++;
		col[V] = now++;
		dfs(V, x);
	}
}
int main()
{
	n = read();
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) cnt = max(cnt, (int)G[i].size() + 1);
	col[1] = cnt;
	for (int i = 0; i < G[1].size(); i++) col[G[1][i]] = i + 1, dfs(G[1][i], 1);
	printf("%d\n", cnt); for (int i = 1; i <= n; i++) printf("%d ", col[i]);
	return 0;
}