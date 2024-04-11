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
#define maxn 1000005
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, q, p[maxn], pos[maxn];
int sta[maxn], top, l[maxn], r[maxn];
vector<int> d[maxn];
vector<pii> seg, tmp;
struct node {int l, r, val;};
vector<node> add[maxn];
vector<pii> que[maxn];
ll ans[maxn];
ll t[maxn], hist[maxn], histag[maxn], tag[maxn], tim[maxn];
inline void work(int x, ll a, ll b, ll c, int l, int r)
{
	hist[x] += t[x] * a + b * (r - l + 1);
	t[x] += c * (r - l + 1);
	histag[x] += tag[x] * a + b;
	tag[x] += c;
	tim[x] += a;
} 
inline void pushdown(int x, int l, int r)
{
//	if(!tim[x] && !histag[x] && !tag[x]) return;
	work(lc(x), tim[x], histag[x], tag[x], l, mid), work(rc(x), tim[x], histag[x], tag[x], mid + 1, r);
	tim[x] = histag[x] = tag[x] = 0;
}
void modify(int x, int l, int r, int a, int b, int val)
{
	if(a <= l && r <= b) {work(x, 0, 0, val, l, r); return;}
	pushdown(x, l, r);
	if(a <= mid) modify(lc(x), l, mid, a, b, val);
	if(b > mid) modify(rc(x), mid + 1, r, a, b, val);
	t[x] = t[lc(x)] + t[rc(x)];
	hist[x] = hist[lc(x)] + hist[rc(x)];
}
ll query(int x, int l, int r, int a, int b)
{
	if(a <= l && r <= b) {/*printf("%d %d %d %lld\n", x, l, r, hist[x]);*/ return hist[x];}
	pushdown(x, l, r); ll res = 0;
	if(a <= mid) res += query(lc(x), l, mid, a, b);
	if(b > mid) res += query(rc(x), mid + 1, r, a, b);
	return res;
}
int main()
{
	n = read(), q = read();
	ru(i, 1, n) pos[p[i] = read()] = i;
	top = 0;
	ru(i, 1, n)
	{
		while(top && p[sta[top]] < p[i]) top--;
		l[i] = sta[top];
		sta[++top] = i;
	}
	sta[top = 0] = n + 1;
	rd(i, n, 1)
	{
		while(top && p[sta[top]] < p[i]) top--;
		r[i] = sta[top];
		sta[++top] = i;
	}
	ru(i, 1, n) ru(j, 1, n / i) if(pos[i] < pos[j]) d[i * j].push_back(i);
	ru(i, 1, n)
	{
		seg.clear();
		for (auto x: d[p[i]])
		{
			int L = pos[x], R = pos[p[i] / x];
			if(L <= l[i] || L >= r[i] || R <= l[i] || R >= r[i]) continue;
			L = min(L, i), R = max(R, i);
			seg.push_back(mp(L, R));
		}
		sort(seg.begin(), seg.end());
		tmp = seg, seg.clear();
		int mn = n + 1;
		for (int j = tmp.size() - 1; j >= 0; j--)
		{
			if(tmp[j].se > mn) continue;
			seg.push_back(tmp[j]);
			mn = tmp[j].se; 
		}
		sort(seg.begin(), seg.end());
		int las = l[i];
		for (auto x: seg)
		{
			add[x.fi].push_back({x.se, r[i] - 1, 1});
			add[las].push_back({x.se, r[i] - 1, -1});
//			printf("%d %d %d %d %d\n", i, las + 1, x.fi, x.se, r[i] - 1);
			las = x.fi;
		}
	}
	ru(i, 1, q) {int l = read(), r = read(); que[l].push_back(mp(r, i));}
	rd(i, n, 1)
	{
		for (auto x: add[i]) modify(1, 1, n, x.l, x.r, x.val);
		work(1, 1, 0, 0, 1, n);
		for (auto x: que[i]) ans[x.se] = query(1, 1, n, i, x.fi);
	}
	ru(i, 1, q) printf("%lld\n", ans[i]);
	return 0;
}