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
#define mid ((l + r + 1) >> 1)
#define maxn 300005
using namespace std;
const int INF = 1e9;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, a[maxn], b[maxn], tmp[maxn], len;
struct seg {int l, r, id; bool operator < (const seg &a) const {return l == a.l ? r < a.r : l < a.l;}};
struct node {int id, val;};
vector<node> las[maxn], nxt[maxn];
set<seg> t;
set<seg>::iterator it, it2;
void split(int pos)
{
	it = --t.lower_bound({pos + 1, 0, 0});
	if((*it).l < pos)
	{
		t.insert({(*it).l, pos - 1, (*it).id});
		t.insert({pos, (*it).r, (*it).id});
		t.erase(it);
	}
}
ll check(int x)
{
	ll res = 0; int tmp = 0;
	for (int i = 1, j = 0; i <= n; i++)
	{
		while(tmp < x && j <= n) 
		{
			j++;
			for (auto x: las[j]) if(x.id < i) tmp += x.val;
		}
		res += n - j + 1;
		for (auto x: nxt[i]) if(j < x.id) tmp -= x.val;
	}
	return res;
}
struct fwt
{
	ll t[maxn];
	inline void add(int x, ll val) {for (; x <= n; x += x & (-x)) t[x] += val;}
	inline ll que(int x) {ll res = 0; for (; x; x -= x & (-x)) res += t[x]; return res;}
}t1, t2;
ll calc(int x)
{
	ll res = 0; int tmp = 0;
	for (int i = 1, j = 0; i <= n; i++)
	{
		while(tmp < x && j <= n) 
		{
			j++;
			for (auto x: las[j]) if(x.id < i) tmp += x.val;
		}
		t1.add(j, 1), t2.add(j, j);
		for (auto x: nxt[i]) 
		{
			if(j < x.id) tmp -= x.val;
			res += (t1.que(x.id - 1) * x.id - t2.que(x.id - 1)) * x.val;
		}
		int x = t1.que(i); t1.add(i, -x), t2.add(i, (ll)-x * i);
		t1.add(i + 1, x), t2.add(i + 1, (ll)x * (i + 1));
//		printf("%d %d %d\n", i, j, x);
	}
	return res;
}
int main()
{
	n = read(), k = read();
	ru(i, 1, n) a[i] = read(), b[i] = read() - 1;
	t.insert({1, INF, 0});
	ru(i, 1, n)
	{
		split(a[i]), split(b[i] + 1);
		seg o = {a[i], b[i], i};
		for (it = t.lower_bound({a[i], 0, i}); assert(it != t.end()), (*it).r <= b[i]; it = it2)
		{
			it2 = it; it2++;
//			printf("%d %d %d\n", (*it).l, (*it).r, (*it).id);
			las[i].push_back({(*it).id, (*it).r - (*it).l + 1}), t.erase(it);
		}
		t.insert(o);
	}
	t.clear(); t.insert({1, INF, n + 1});
	rd(i, n, 1)
	{
		split(a[i]), split(b[i] + 1);
		seg o = {a[i], b[i], i};
		for (it = t.lower_bound({a[i], 0, i}); assert(it != t.end()), (*it).r <= b[i]; it = it2)
		{
			it2 = it; it2++;
			nxt[i].push_back({(*it).id, (*it).r - (*it).l + 1}), t.erase(it);
		}
		t.insert(o);
	}
//	ru(i, 1, n)
//	{
//		for (auto x: las[i]) printf("%d %d  ", x.val, x.id); printf("\n");
//		for (auto x: nxt[i]) printf("%d %d  ", x.val, x.id); printf("\n");
//	}
	int l = 0, r = INF;
	while(l < r) check(mid) >= k ? l = mid : r = mid - 1;
	printf("%lld\n", calc(l) - (ll)l * (check(l) - k));
	return 0;
}