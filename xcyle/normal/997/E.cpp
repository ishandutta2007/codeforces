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
#define mid ((l + r) >> 1)
#define maxn 120005
#define N 480005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, q, p[maxn];
vector<pair<int, int> > que[maxn];
int sta[2][maxn], top[2];
ll ans[maxn], num[N];
int hismn[N], mn[N], cnt[N], histag[N], tagnum[N], tag[N];
inline void pushup(int x)
{
	mn[x] = min(mn[lc(x)], mn[rc(x)]), hismn[x] = min(hismn[lc(x)], hismn[rc(x)]), num[x] = cnt[x] = 0;
	if(mn[x] == mn[lc(x)]) cnt[x] += cnt[lc(x)];
	if(mn[x] == mn[rc(x)]) cnt[x] += cnt[rc(x)];
	if(hismn[x] == hismn[lc(x)]) num[x] += num[lc(x)];
	if(hismn[x] == hismn[rc(x)]) num[x] += num[rc(x)];
}
inline void work(int x, int val, int tim)
{
	tag[x] += val;
	if(tag[x] < histag[x]) histag[x] = tag[x], tagnum[x] = tim;
	else if(tag[x] == histag[x]) tagnum[x] += tim; 
	mn[x] += val;
	if(mn[x] < hismn[x]) hismn[x] = mn[x], num[x] = (ll)tim * cnt[x];
	else if(mn[x] == hismn[x]) num[x] += (ll)tim * cnt[x];
}
inline void pushdown(int x)
{
	work(lc(x), histag[x], tagnum[x]), work(lc(x), tag[x] - histag[x], 0);
	work(rc(x), histag[x], tagnum[x]), work(rc(x), tag[x] - histag[x], 0);
	tag[x] = histag[x] = tagnum[x] = 0;
}
inline void build(int x, int l, int r)
{
	if(l == r){hismn[x] = mn[x] = n + 1 - l, cnt[x] = 1; return;}
	build(lc(x), l, mid), build(rc(x), mid + 1, r); pushup(x);
}
inline void add(int x, int l, int r, int a, int b, int d)
{
	if(a > b) return;
	if(a <= l && r <= b) {work(x, d, 0); return;} pushdown(x);
	if(a <= mid) add(lc(x), l, mid, a, b, d);
	if(b > mid) add(rc(x), mid + 1, r, a, b, d);
	pushup(x);
}
inline pair<int, ll> query(int x, int l, int r, int a, int b)
{
	if(a <= l && r <= b) return make_pair(hismn[x], num[x]); pushdown(x);
	pair<int, ll> res = make_pair(1, 0ll), tx, ty;
	if(a <= mid)
	{
		tx = res, ty = query(lc(x), l, mid, a, b);
		res.first = min(tx.first, ty.first); res.second = 0;
		if(res.first == tx.first) res.second += tx.second;
		if(res.first == ty.first) res.second += ty.second;
	}
	if(b > mid)
	{
		tx = res, ty = query(rc(x), mid + 1, r, a, b);
		res.first = min(tx.first, ty.first); res.second = 0;
		if(res.first == tx.first) res.second += tx.second;
		if(res.first == ty.first) res.second += ty.second;
	}
	return res;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++) p[i] = read();
	q = read();
	for (int i = 1; i <= q; i++) 
	{
		int l = read(), r = read();
		que[l].push_back(make_pair(r, i));
	}
	sta[0][0] = sta[1][0] = n + 1;
	build(1, 1, n);
	for (int i = n; i >= 1; i--)
	{
		while(top[0] && p[sta[0][top[0]]] >= p[i])
		{
//			printf("%d %d %d\n", sta[0][top[0]], sta[0][top[0] - 1] - 1, p[sta[0][top[0]]] - p[i]);
			add(1, 1, n, sta[0][top[0]], sta[0][top[0] - 1] - 1, p[sta[0][top[0]]] - p[i]);
			top[0]--;
		}
//		printf("!!!%d %d\n", mn[1], hismn[1]);
		sta[0][++top[0]] = i;
		while(top[1] && p[sta[1][top[1]]] <= p[i])
		{
//			printf("%d %d %d\n", sta[1][top[1]], sta[1][top[1] - 1] - 1, p[i] - p[sta[1][top[1]]]);
			add(1, 1, n, sta[1][top[1]], sta[1][top[1] - 1] - 1, p[i] - p[sta[1][top[1]]]);
			top[1]--;
		}
		sta[1][++top[1]] = i;
		work(1, -1, 1);
		for (auto x: que[i])
		{
			pair<int, ll> res = query(1, 1, n, i, x.first);
//			printf("%d %d\n", res.first, res.second);
			if(res.first == 0) ans[x.second] = res.second;
		}
	}
	for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
	return 0;
}