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
#define maxn 500005
using namespace std;
const ll INF = 1e17;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m;
ll a[maxn], b[maxn], c[maxn], f[maxn], ans = -INF;
int l[maxn], r[maxn], k[maxn];
vector<int> p[maxn];
struct node
{
	ll mx1, mx2, res;
	inline node friend operator + (node aa, node bb){return (node){max(aa.mx1, bb.mx1), max(aa.mx2, bb.mx2), max(max(aa.res, bb.res), aa.mx1 + bb.mx2)};};
}t[maxn * 4];
multiset<ll> leaf[maxn];
void ins(int tp, int x, int l, int r, int pos, ll d)
{
	if(l == r)
	{
		if(tp == 2) t[x].mx2 = d;
		if(tp == 1)
		{
			leaf[pos].insert(-d);
			t[x].mx1 = -(*leaf[pos].begin());
		}
		if(tp == 3)
		{
			leaf[pos].erase(leaf[pos].find(-d));
			t[x].mx1 = -(*leaf[pos].begin());
		}
		t[x].res = t[x].mx1 + t[x].mx2;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) ins(tp, lc(x), l, mid, pos, d);
	else ins(tp, rc(x), mid + 1, r, pos, d);
	t[x] = t[lc(x)] + t[rc(x)];
}
node que(int x, int l, int r, int a, int b)
{
	if(a <= l && r <= b) return t[x];
	int mid = (l + r) >> 1;
	node res = {-INF, -INF, -INF};
	if(a > b) return res;
	if(a <= mid) res = res + que(lc(x), l, mid, a, b);
	if(b > mid) res = res + que(rc(x), mid + 1, r, a, b);
	return res;
}
int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = (ll)read() + a[i - 1];
	for (int i = 1; i <= n; i++) b[i] = (ll)read() + b[i - 1], a[i] -= b[i - 1];
	for (int i = 1; i <= n; i++) c[i] = (ll)read();
	for (int i = n; i >= 1; i--) c[i] += c[i + 1];
	for (int i = 1; i <= n; i++) c[i] += b[i];
//	for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
//	printf("\n");
//	for (int i = 1; i <= n; i++) printf("%lld ", c[i]);
//	printf("\n");
	for (int i = 1; i <= 4 * n; i++) t[i] = {-INF, -INF, -INF};
	for (int i = 1; i <= m; i++)
	{
		l[i] = read(), r[i] = read() + 1, k[i] = -read();
		p[l[i]].push_back(i), p[r[i] + 1].push_back(i);
	}
	for (int i = 1; i <= n; i++) leaf[i].insert(INF);
	for (int i = 1; i <= n + 1; i++)
 	{
 		for (auto x: p[i])
 		{
 			if(l[x] == i) ins(1, 1, 1, n, l[x], k[x]);
 			else ins(3, 1, 1, n, l[x], k[x]);
		}
 		if(i != 1) ans = max(ans, que(1, 1, n, 1, i - 1).res + c[i - 1]);
 		f[i] = max(que(1, 1, n, 1, i - 1).res, a[i]);
 		ins(2, 1, 1, n, i, f[i]);
	}
	printf("%lld", ans);
	return 0;
}