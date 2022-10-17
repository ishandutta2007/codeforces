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
#define maxn 400005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, k, vis[maxn];
vector<int> G[maxn];
int sta[maxn], top;
void dfs(int x)
{
	vis[x] = 1;
	sta[++top] = x;
	for (auto V: G[x]) if(!vis[V])
	{
		dfs(V);
		sta[++top] = x;
	}
}
int main()
{
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs(1);
	int tot = 0;
	for (int i = 1; i <= top; i++)
	{
		if(i % ((2 * n + k - 1) / k) == 1) tot++, printf("%d ", min((2 * n + k - 1) / k, top - i + 1));
		printf("%d ", sta[i]);
		if(i % ((2 * n + k - 1) / k) == 0) printf("\n");
	}
	for (int i = tot + 1; i <= k; i++) printf("\n1 1");
	return 0;
}