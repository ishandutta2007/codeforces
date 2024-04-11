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
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int q, d;
ll t[3][maxn * 4], tag[maxn * 4];
inline void work(int x, ll v)
{
	tag[x] += v;
	t[2][x] += (t[0][x] * v * (v - 1) + 2 * v * t[1][x]) / 2;
	t[1][x] += v * t[0][x];
}
inline void pushdown(int x)
{
	work(lc(x), tag[x]), work(rc(x), tag[x]), tag[x] = 0;
}
inline void pushup(int x)
{
	ru(i, 0, 2) t[i][x] = t[i][lc(x)] + t[i][rc(x)];
}
inline int que(int x, int l, int r, int a, int b)
{
	if(b < 1) return 0;
	if(a <= l && r <= b) return t[0][x];
	pushdown(x);
	if(b <= mid) return que(lc(x), l, mid, a, b);
	if(a > mid) return que(rc(x), mid + 1, r, a, b);
	return que(lc(x), l, mid, a, b) + que(rc(x), mid + 1, r, a, b); 
}
int modify(int x, int l, int r, int pos)
{
	if(l == r)
	{
		if(!t[0][x]) 
		{
			t[0][x] = 1;
			t[1][x] = que(1, 1, maxn - 1, pos - d, pos - 1);
			t[2][x] = t[1][x] * (t[1][x] - 1) / 2;
			return 1;
		}
		else
		{
			t[0][x] = t[1][x] = t[2][x] = 0;
			return -1;
		}
	}
	pushdown(x);
	int res = 0;
	if(pos <= mid) res = modify(lc(x), l, mid, pos);
	else res = modify(rc(x), mid + 1, r, pos);
	pushup(x);
	return res;
}
void upd(int x, int l, int r, int a, int b, int v)
{
	if(a <= l && r <= b) {work(x, v); return;}
	pushdown(x);
	if(a <= mid) upd(lc(x), l, mid, a, b, v);
	if(b > mid) upd(rc(x), mid + 1, r, a, b, v);
	pushup(x);
}
int main()
{
	q = read(), d = read();
	ru(i, 1, q) 
	{
		int a = read();
		upd(1, 1, maxn - 1, a + 1, a + d, modify(1, 1, maxn - 1, a));
		printf("%lld\n", t[2][1]);
	}
	return 0;
}