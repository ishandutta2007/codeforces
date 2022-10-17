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
#define fi first
#define se second
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, q, a[maxn];
multiset<ll> t;
void solve()
{
	n = read(), q = read();
	ru(i, 1, n) a[i] = read();
	t.clear();
	vector<pair<int, vector<ll> > > d;
	int tt = n;
	ru(i, 2, n) if(tt % i == 0) 
	{
		int j = n / i;
		vector<ll> tmp; tmp.resize(j, 0);
		d.push_back(mp(j, tmp));
		while(tt % i == 0) tt /= i;
	}
	ru(i, 1, n) for (auto &x: d)
	{
		x.se[i % x.fi] += (ll)x.fi * a[i];
	}
	for (auto x: d) for (auto val: x.se) t.insert(val);
	printf("%lld\n", *(--t.end()));
	while(q--)
	{
		int pos = read(), v = read(); 
		for (auto &x: d)
		{
			t.erase(t.find(x.se[pos % x.fi]));
			x.se[pos % x.fi] += (ll)x.fi * (v - a[pos]);
			t.insert(x.se[pos % x.fi]);
		}
		a[pos] = v;
		printf("%lld\n", *(--t.end()));
	}
} 
int main()
{
	int T = read();
	while(T--) solve(); 
	return 0;
}