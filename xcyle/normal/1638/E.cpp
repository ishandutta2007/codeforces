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
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
char s[10];
int n, q;
struct node
{
	int l, r, c;
	inline bool friend operator < (node aa, node bb)
	{
		return aa.r < bb.r;
	}
};
set<node> pos;
ll val[maxn], t[2][maxn * 4];
inline void pushdown(int x)
{
	t[0][lc(x)] += t[0][x];
	t[1][lc(x)] += t[1][x];
	t[0][rc(x)] += t[0][x];
	t[1][rc(x)] += t[1][x];
	t[0][x] = t[1][x] = 0;
}
void add(int x, int l, int r, int a, int b, ll d0, ll d1)
{
	if(a <= l && r <= b)
	{
		t[0][x] += d0;
		t[1][x] += d1;
		return;
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if(a <= mid) add(lc(x), l, mid, a, b, d0, d1);
	if(b > mid) add(rc(x), mid + 1, r, a, b, d0, d1);
}
ll que(int x, int l, int r, int aim)
{
	if(l == r) return val[t[0][x]] + t[1][x];
	pushdown(x);
	int mid = (l + r) >> 1;
	if(aim <= mid) return que(lc(x), l, mid, aim);
	else return que(rc(x), mid + 1, r, aim);
}
int main()
{
	scanf("%d%d", &n, &q);
	pos.insert({1, n, 1});
	add(1, 1, n, 1, n, 1, 0);
	while(q--)
	{
		scanf("%s", s);
		if(s[0] == 'C')
		{
			int l = read(), r = read(), c = read();
			node tmp = *(pos.lower_bound({l, l, 1}));
			pos.erase(tmp);
			if(tmp.l < l) pos.insert({tmp.l, l - 1, tmp.c});
			pos.insert({l, tmp.r, tmp.c});
			tmp = *(pos.lower_bound({r, r, 1}));
			pos.erase(tmp);
			pos.insert({tmp.l, r, tmp.c});
			if(r < tmp.r)pos.insert({r + 1, tmp.r, tmp.c});
			for (int now = l; now <= r;)
			{
				tmp = *(pos.lower_bound({now, now, 1}));
//				printf("%d %d %d\n", tmp.l, tmp.r, tmp.c);
				pos.erase(tmp);
				add(1, 1, n, tmp.l, tmp.r, -tmp.c, val[tmp.c]);
				now = tmp.r + 1;
			}
			pos.insert({l, r, c});
			add(1, 1, n, l, r, c, -val[c]);
		}
		if(s[0] == 'A')
		{
			int c = read(), x = read();
			val[c] += x;
		}
		if(s[0] == 'Q')
		{
			int pos = read();
			printf("%lld\n", que(1, 1, n, pos));
		}
	}
	return 0;
}