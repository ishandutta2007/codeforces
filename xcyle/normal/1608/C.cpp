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
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int t, n, rk[100005], ans[100005], fa[100005];
struct node 
{
	int d, id;
	inline int friend operator < (node aa, node bb)
	{
		return aa.d < bb.d;
	}
}p[2][100005];
inline int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p[0][i].d);
		p[0][i].id = i;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p[1][i].d);
		p[1][i].id = i;
	}
	sort(p[0] + 1, p[0] + n + 1);
	sort(p[1] + 1, p[1] + n + 1);
	for (int i = 1; i <= n; i++) rk[p[0][i].id] = i;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 2; i <= n; i++)
	{
		if(rk[p[1][i - 1].id] < rk[p[1][i].id]) continue;
		int now = rk[p[1][i].id];
		int tmp = find(rk[p[1][i - 1].id]);
		while(now < tmp)
		{
			int haha = find(now) + 1;
			fa[find(now)] = tmp;
			now = haha;
		} 
	}
	for (int i = 1; i <= n; i++) ans[i] = 0;
	for (int i = n; i >= 1; i--) if(find(i) == n) ans[p[0][i].id] = 1;
	for (int i = 1; i <= n; i++) printf("%d", ans[i]);
	printf("\n");
}
int main()
{
	scanf("%d", &t);
	while(t--) solve(); 
	return 0;
}