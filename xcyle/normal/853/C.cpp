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
#define mp make_pair
#define se second
#define fi first
using namespace std;
const ll INF = 5e12;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, q, s[maxn], sf[maxn], l[maxn], r[maxn], d[maxn], u[maxn];
vector<pair<int, int> > que[maxn];
int t[maxn]; ll ans[maxn];
inline void add(int x)
{
	for (; x <= n; x += x & (-x)) t[x]++;
}
inline int query(int x)
{
	int res = 0;
	for (; x; x -= x & (-x)) res += t[x];
	return res;
}
inline ll val(int x)
{
	return (ll)x * (x - 1) / 2;
}
int main()
{
	n = read(), q = read();
	ru(i, 1, n) s[sf[i] = read()] = i;
	ru(i, 1, q) 
	{
		l[i] = read(), d[i] = read(), r[i] = read(), u[i] = read();
		ans[i] = val(l[i] - 1) + val(n - r[i]) + val(d[i] - 1) + val(n - u[i]);
//		printf("%lld\n", ans[i]);
	}
	ru(i, 1, q) que[d[i] - 1].push_back(mp(l[i] - 1, i));
	ru(i, 1, n)
	{
		add(s[i]);
		for (auto x: que[i]) ans[x.se] -= val(query(x.fi));
	}
	memset(t, 0, sizeof(t));
	ru(i, 1, n) que[i].clear();
	ru(i, 1, q) que[d[i] - 1].push_back(mp(n - r[i], i));
	ru(i, 1, n)
	{
		add(n - s[i] + 1);
		for (auto x: que[i]) ans[x.se] -= val(query(x.fi));
	}
	memset(t, 0, sizeof(t));
	ru(i, 1, n) que[i].clear();
//	ru(i, 1, q) printf("%lld\n", ans[i]);
	
	ru(i, 1, q) que[u[i] + 1].push_back(mp(l[i] - 1, i));
	rd(i, n, 1)
	{
		add(s[i]);
		for (auto x: que[i]) ans[x.se] -= val(query(x.fi));
	}
	memset(t, 0, sizeof(t));
//	ru(i, 1, q) printf("%lld\n", ans[i]);
	ru(i, 1, n) que[i].clear();
	ru(i, 1, q) que[u[i] + 1].push_back(mp(n - r[i], i));
	rd(i, n, 1)
	{
		add(n - s[i] + 1);
		for (auto x: que[i]) ans[x.se] -= val(query(x.fi));
	}
	memset(t, 0, sizeof(t));
//	ru(i, 1, q) printf("%lld\n", ans[i]);
	ru(i, 1, q) printf("%lld\n", val(n) - ans[i]);
	return 0;
}