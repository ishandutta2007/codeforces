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
#define pii pair<int, int>
#define mp make_pair
#define maxn 500005 
#define w(x) (tp ? n - (x) + 1 : x)
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, p[maxn], pf[maxn];
set<int> chn[2];
set<int>::iterator it;
struct fwt
{
	int t[maxn];
	inline void add(int x, int val) {for (; x <= n; x += x & (-x)) t[x] += val;}
	inline int que(int x){int res = 0; for (; x; x -= x & (-x)) res += t[x]; return res;}
}a, b, tmp;
struct segt
{
	pii t[maxn * 4]; int tag[maxn * 4];
	inline void pushdown(int x)
	{
		if(!tag[x]) return;
		t[lc(x)].first += tag[x], t[rc(x)].first += tag[x];
		tag[lc(x)] += tag[x], tag[rc(x)] += tag[x], tag[x] = 0;
	}
	inline pii query(int x, int l, int r, int a, int b)
	{
		if(a > b) return mp(0, 0);
		if(a <= l && r <= b) return t[x];
		pushdown(x); pii res = mp(0, 0);
		if(a <= mid) res = max(res, query(lc(x), l, mid, a, b));
		if(b > mid) res = max(res, query(rc(x), mid + 1, r, a, b));
		return res;
	}
	inline void modify(int x, int l, int r, int a, int b)
	{
		if(a > b) return;
		if(a <= l && r <= b) {tag[x]++; t[x].first++; return;}
		pushdown(x);
		if(a <= mid) modify(lc(x), l, mid, a, b);
		if(b > mid) modify(rc(x), mid + 1, r, a, b);
		t[x] = max(t[lc(x)], t[rc(x)]);
	}
	inline void change(int x, int l, int r, int pos, int val)
	{
		if(l == r) {t[x] = mp(val, pos); return;}
		pushdown(x);
		if(pos <= mid) change(lc(x), l, mid, pos, val);
		else change(rc(x), mid + 1, r, pos, val);
		t[x] = max(t[lc(x)], t[rc(x)]);
	}
}t1[2], t2[2];
inline int calcval(int pos){return abs(a.que(pos - 1) - b.que(p[pos] - 1));}
inline void pop(int tp, int x)
{
//	printf("add %d %d\n", tp, w(x)); fflush(stdout);
	chn[tp].insert(w(p[w(x)]));
	t2[tp].change(1, 1, n, x, 2 * n - calcval(w(x)));
}
inline void ins(int tp, int x, int y)
{
	t1[tp].change(1, 1, n, x, n + 1 - y);
	if((*chn[tp].begin()) > y) pop(tp, x); 
}
inline void del(int tp, int x)
{
//	printf("del %d %d\n", tp, w(x));
	int pos = w(x);
	a.add(pos, -1), b.add(p[pos], -1);
	t1[tp].change(1, 1, n, x, 0), t2[tp].change(1, 1, n, x, 0);
	tp ^= 1; 
	int tmp = w(p[pos]); pos = w(pos);
	t2[tp].modify(1, 1, n, w(pf[w(*chn[tp].lower_bound(tmp))]), pos);
	pos = w(pos);
	tp ^= 1; 
	it = chn[tp].find(w(p[pos])); it--; int pre = w(pf[w((*it))]);
	it = chn[tp].find(w(p[pos])); it++; int lim = (*it);
//	it = chn[tp].end(); it--; printf("??????? %d\n", (*it));
	chn[tp].erase(w(p[pos]));
	while(1)
	{
		pii now = t1[tp].query(1, 1, n, pre + 1, x - 1);
//		printf("chn: %d %d  ", pos, w(p[pos]));
//		for (auto x: chn[tp]) printf("%d ", x);
//		printf("\n");
//		printf("%d %d %d %d %d %d %d\n", lim, w(p[pos]), tp, pre + 1, x - 1, now.first, now.second);
		if(n + 1 - now.first >= lim) break;
		pop(tp, pre = now.second);
	}
}
int main()
{
	n = read();
	pf[n + 1] = p[n + 1] = n + 1;
	ru(i, 0, 1) chn[i].insert(n + 1);
	ru(i, 1, n) pf[p[i] = read()] = i, a.add(i, 1), b.add(p[i], 1);
	ru(i, 1, n) if(i >= p[i]) ins(1, n - i + 1, n - p[i] + 1);
	rd(i, n, 1) if(i < p[i]) ins(0, i, p[i]);
	ru(i, 0, 1) chn[i].insert(0);
	int ans = 0;
	ru(i, 1, n)
	{
//		int tp = 0;
//		for (auto x: chn[0]) printf("%d ", w(x)); printf("\n");
//		tp = 1;
//		for (auto x: chn[1]) printf("%d ", w(x)); printf("\n");
		pii r[2] = {t2[0].t[1], t2[1].t[1]};
//		printf("%d %d %d %d\n", 2 * n - r[0].first, 2 * n -  r[1].first, r[0].second, n - r[1].second + 1);
		if(r[0].first > r[1].first)
		{
			ans = max(ans, 2 * n - r[0].first);
			del(0, r[0].second);
		}
		else
		{
			ans = max(ans, 2 * n - r[1].first);
			del(1, r[1].second);
		}
	}
	printf("%d\n", ans);
	return 0;
}