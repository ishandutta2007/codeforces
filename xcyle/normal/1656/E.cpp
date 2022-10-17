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
#define maxn 100005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn];
vector<int> G[maxn];
void dfs(int x, int fa, int tp)
{
	if(tp == 1) a[x] = 1 + G[x].size() - 1;
	else a[x] = - 1 - G[x].size() + 1;
	for (auto V: G[x])
	{
		if(V == fa) continue;
		dfs(V, x, tp ^ 1);
	}
}
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) G[i].clear();
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	a[1] = -G[1].size();
	for (auto V: G[1])
	{
		dfs(V, 1, 1);
	}
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	printf("\n");
}
int main()
{
	int T = read();
	while(T--) solve(); 
	return 0;
}