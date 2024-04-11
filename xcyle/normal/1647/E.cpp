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
#define len ((int)link.size())
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, fa[maxn][40], a[maxn], d[maxn], tot;
int mn[maxn];
set<int> id;
set<int>::iterator it;
int ans[maxn];
int main()
{
	n = read();
	for (int i = 1; i <= n; i++) d[fa[i][0] = read()]++;
	for (int i = 1; i <= n; i++) a[i] = read(), tot = max(a[i], tot);
	int cnt = 0; for (int i = 1; i <= n; i++) cnt += d[i] == 0;
	tot = (tot - n) / cnt;
	for (int i = 1; i <= 30; i++) for (int j = 1; j <= n; j++) fa[j][i] = fa[fa[j][i - 1]][i - 1];
	for (int i = 1; i <= n; i++)
	{
		mn[i] = i;
		for (int j = 0; j <= 30; j++) if((tot >> j) & 1) mn[i] = fa[mn[i]][j];
		mn[i] = a[mn[i]];
	}
	for (int i = 1; i <= n; i++) id.insert(i);
	for (int i = 1; i <= n; i++) if(id.find(mn[i]) != id.end()) ans[i] = mn[i], id.erase(mn[i]);
	for (int i = 1; i <= n; i++)
	{
		if(ans[i]) continue;
		it = id.lower_bound(mn[i]);
		ans[i] = (*it);
		id.erase(it);
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}