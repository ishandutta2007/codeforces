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
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int s[maxn], n, fl = 1, dep[maxn], fa[maxn];
vector<int> G[maxn];
int main()
{
	scanf("%d", &n);
	dep[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		scanf("%d", &fa[i]);
		G[fa[i]].push_back(i);
		dep[i] = dep[fa[i]] ^ 1;
	}
	for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
	ll ans = s[1];
	for (int i = 1; i <= n; i++)
	{
		if(dep[i]) continue;
		int mn = 1e9 + 1;
		for (int j = 0; j < G[i].size(); j++)
		{
			mn = min(mn, s[G[i][j]]);
		}
		if(mn < s[fa[i]]) 
		{
			printf("-1\n");
			return 0;
		}
		ll tmp = mn - s[fa[i]];
		if(G[i].size()) ans += tmp;
		for (int j = 0; j < G[i].size(); j++) ans += (s[G[i][j]] - mn);
//		printf("%d %lld\n", i, ans);
	}
	printf("%lld", ans);
	return 0;
}