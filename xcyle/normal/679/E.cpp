/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define maxn 100005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, q, tot;
ll v[maxn], mn[maxn * 4], tag[maxn * 4], add[maxn * 4];
inline ll foo(ll x) {return v[upper_bound(v + 1, v + tot + 1, x) - v] - x;}
inline void pushdown(int x)
{
	if(tag[x])
	{
		tag[lc(x)] = tag[rc(x)] = tag[x];
		add[lc(x)] = add[rc(x)] = add[x];
		mn[lc(x)] = mn[rc(x)] = mn[x];
		tag[x] = add[x] = 0;
		return;
	}
	add[lc(x)] += add[x], add[rc(x)] += add[x];
	mn[lc(x)] -= add[x], mn[rc(x)] -= add[x];
	add[x] = 0;
}
void change(int x, int l, int r, int a, int b, ll c)
{
	if(a <= l && r <= b) {tag[x] = c, add[x] = 0, mn[x] = foo(c); return;}
	pushdown(x);
	if(a <= mid) change(lc(x), l, mid, a, b, c);
	if(b > mid) change(rc(x), mid + 1, r, a, b, c);
	mn[x] = min(mn[lc(x)], mn[rc(x)]);
}
int cnt = 0;
int modify(int x, int l, int r, int a, int b, ll c)
{
	if(a <= l && r <= b)
	{
		cnt++, assert(cnt <= 100000000);
		if(mn[x] > c) 
		{
			add[x] += c, mn[x] -= c;
			return 0;
		}
		if(tag[x])
		{
			add[x] += c, mn[x] = foo(tag[x] + add[x]);
			return 41ll * (tag[x] + add[x]) == mn[x];
		}
	}
	pushdown(x);
	int fl = 0;
	if(a <= mid) fl |= modify(lc(x), l, mid, a, b, c);
	if(b > mid) fl |= modify(rc(x), mid + 1, r, a, b, c);
	mn[x] = min(mn[lc(x)], mn[rc(x)]);
	return fl;
}
ll que(int x, int l, int r, int pos)
{
	if(l == r) return tag[x] + add[x];
	pushdown(x);
	if(pos <= mid) return que(lc(x), l, mid, pos);
	else return que(rc(x), mid + 1, r, pos);
}
int main()
{
	n = read(), q = read();
	ll now = 42;
	while(now <= 1e17) v[++tot] = now, now *= 42;
	ru(i, 1, n) change(1, 1, n, i, i, read());
	while(q--)
	{
		int tp = read();
		if(tp == 1) printf("%lld\n", que(1, 1, n, read()));
		else 
		{
			int l = read(), r = read(), x = read();
			if(tp == 2) change(1, 1, n, l, r, x);
			else while(modify(1, 1, n, l, r, x));
		}
	}
	return 0;
}