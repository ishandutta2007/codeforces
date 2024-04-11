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
#define maxn 500005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, d;
struct node
{
	int s, a, tp;
	inline bool friend operator < (node aa, node bb)
	{
		return aa.s == bb.s ? aa.a < bb.a : aa.s < bb.s;
	}
}p[maxn];
int cntp, cntt;
int cnt;
int vis[maxn];
int main()
{
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++)
	{
		cntp++;
		scanf("%d%d", &p[cntp].s, &p[cntp].a);
		if(p[cntp].s >= p[cntp].a)
		{
			p[cntp].tp = 1;
			swap(p[cntp].s, p[cntp].a);
		}
	}
//	for (int i = 1; i <= n; i++) printf("%d %d\n", p[i].s, p[i].a);
	sort(p + 1, p + cntp + 1);
	int mn = 0x3f3f3f3f, ans = 0;
	for (int i = cntp; i >= 1; i--)
	{
//		printf("%d %d\n", p[i].s, p[i].a);
		if(!p[i].tp && mn < p[i].a)
		{
			 vis[i] = 1;
//			 printf("%d\n", i);
		}
		mn = min(mn, p[i].a);
	}
	int now = d;
	for (int i = 1; i <= cntp; i++)
	{
		if(vis[i]) continue;
//		printf("%d %d\n", p[i].s, p[i].a);
		if((p[i].tp && p[i].a >= d) || now <= p[i].s) ans++;
		if(!p[i].tp && now <= p[i].s) now = max(now, p[i].a);
	}
	printf("%d\n", ans);
	return 0;
}