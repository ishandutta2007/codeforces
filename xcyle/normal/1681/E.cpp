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
const ll INF = 1e16;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, l[maxn], r[maxn], d[maxn][2][2];
struct mat
{
	ll v[2][2];
	inline mat operator + (const mat &a) const
	{
		mat tmp;
		ru(i, 0, 1) ru(j, 0, 1) tmp.v[i][j] = min(v[i][0] + a.v[0][j], v[i][1] + a.v[1][j]);
		return tmp;
	}
};
mat t[maxn * 4];
inline int dis(int xa, int ya, int xb, int yb)
{
	return abs(xa - xb) + abs(ya - yb);
}
void build(int x, int l, int r)
{
	if(l == r)
	{
		if(l & 1)
		{
			l = (l + 1) / 2;
			ru(i, 0, 1) ru(j, 0, 1) t[x].v[i][j] = dis(d[l][i][0], d[l][i][1], d[l][j][0], d[l][j][1]) + 1 + (i ^ j);
		}
		else
		{
			l /= 2;
			ru(i, 0, 1) ru(j, 0, 1) t[x].v[i][j] = dis(d[l][i][0] + (i == 0), d[l][i][1] + (i == 1), d[l + 1][j][0], d[l + 1][j][1]);
		}
		return;
	}
	build(lc(x), l, mid), build(rc(x), mid + 1, r);
	t[x] = t[lc(x)] + t[rc(x)];
}
mat query(int x, int l, int r, int a, int b)
{
	if(a <= l && r <= b) return t[x];
	if(b <= mid) return query(lc(x), l, mid, a, b);
	if(a > mid) return query(rc(x), mid + 1, r, a, b);
	return query(lc(x), l, mid, a, b) + query(rc(x), mid + 1, r, a, b);
}
int main()
{
	n = read();
	ru(i, 1, n - 1) ru(j, 0, 1) ru(k, 0, 1) d[i][j][k] = read();
	build(1, 1, 2 * n - 3);
	int m = read();
	while(m--)
	{
		int xa = read(), ya = read(), xb = read(), yb = read();
		if(max(xa, ya) == max(xb, yb)) {printf("%d\n", dis(xa, ya, xb, yb)); continue;}
		if(max(xa, ya) > max(xb, yb)) swap(xa, xb), swap(ya, yb);
		mat tmp = query(1, 1, 2 * n - 3, 2 * max(xa, ya) - 1, 2 * max(xb, yb) - 3);
		ll ans = INF;
		ru(i, 0, 1) ru(j, 0, 1)
		{
			ans = min(ans, tmp.v[i][j] + dis(d[max(xa, ya)][i][0], d[max(xa, ya)][i][1], xa, ya) + dis(d[max(xb, yb) - 1][j][0] + (j == 0), d[max(xb, yb) - 1][j][1] + (j == 1), xb, yb));
//			printf("%d %d %d\n", tmp.v[i][j], dis(d[max(xa, ya)][i][0], d[max(xa, ya)][i][1], xa, ya), dis(d[max(xb, yb)][j][0], d[max(xb, yb)][j][1], xb, yb));
		}
		printf("%lld\n", ans);
	}
	return 0;
}