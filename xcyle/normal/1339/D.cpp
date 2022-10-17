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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
vector<int> G[100005];
int cnt[100005], vis[2];
void dfs(int x, int fa, int dep)
{
	if(G[x].size() == 1) vis[dep]++, cnt[fa]++;
	for (auto V: G[x]) if(V ^ fa) dfs(V, x, dep ^ 1);
}
int main()
{
	n = read();
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if(G[i].size() != 1){dfs(i, i, 0); break;}
	}
	if(!vis[1] || !vis[0]) printf("1 ");
	else printf("3 ");
	int ans = n - 1;
	for (int i = 1; i <= n; i++) if(cnt[i]) ans -= cnt[i] - 1;
	printf("%d\n", ans);
	return 0;
}