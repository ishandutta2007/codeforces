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
#define maxn 250005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], dis[maxn];
int sta1[maxn], top1;
int sta2[maxn], top2;
int t[2][4 * maxn];
void change(int tp, int x, int l, int r, int pos, int v)
{
	if(l == r) {t[tp][x] = v; return;}
	if(pos <= mid) change(tp, lc(x), l, mid, pos, v);
	else change(tp, rc(x), mid + 1, r, pos, v);
	t[tp][x] = min(t[tp][lc(x)], t[tp][rc(x)]);
}
int que(int tp, int x, int l, int r, int a, int b)
{
	if(a > b) return n + 1;
	if(a <= l && r <= b) return t[tp][x];
	if(b <= mid) return que(tp, lc(x), l, mid, a, b);
	if(a > mid) return que(tp, rc(x), mid + 1, r, a, b);
	return min(que(tp, lc(x), l, mid, a, b), que(tp, rc(x), mid + 1, r, a, b));
}
void solve()
{
	n = read();
	ru(i, 1, n) a[i] = read();
	ru(i, 1, 4 * n) t[0][i] = t[1][i] = n + 1;
	change(0, 1, 1, n, 1, 0);
	change(1, 1, 1, n, 1, 0);
	top1 = top2 = 1;
	sta1[1] = sta2[1] = 1;
	ru(i, 2, n)
	{
		while(top1 && a[sta1[top1]] > a[i]) change(0, 1, 1, n, sta1[top1], n + 1), top1--;
		while(top2 && a[sta2[top2]] < a[i]) change(1, 1, 1, n, sta2[top2], n + 1), top2--;
		dis[i] = que(0, 1, 1, n, sta2[top2] + 1, i - 1);
		dis[i] = min(dis[i], que(1, 1, 1, n, sta1[top1] + 1, i - 1));
		dis[i]++;
//		printf("%d %d %d %d\n", i, sta1[top1], sta2[top2], dis[i]);
		sta1[++top1] = sta2[++top2] = i;
		change(0, 1, 1, n, i, dis[i]);
		change(1, 1, 1, n, i, dis[i]);
	}
	printf("%d\n", dis[n]);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}