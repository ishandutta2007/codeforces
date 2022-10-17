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
using namespace std;
const ll INF = 5e12;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, k;
ll l[maxn], r[maxn], ansl[maxn], ansr[maxn];
vector<pair<int, int> > L[maxn], R[maxn];
int main()
{
	n = read(), m = read(), k = read();
	ru(i, 1, m)
	{
		int d = read(), f = read(), t = read(), c = read();
		if(!t) L[d].push_back(make_pair(f, c));
		else R[d].push_back(make_pair(t, c));
	}
	ru(i, 1, n) l[i] = r[i] = INF, ansl[0] += INF, ansr[maxn - 1] += INF;
	ru(i, 0, maxn - 2)
	{
		ansl[i + 1] = ansl[i];
		for (auto x: L[i])
		{
			int pos = x.first; ll c = x.second;
			ansl[i + 1] -= l[pos];
			l[pos] = min(l[pos], c);
			ansl[i + 1] += l[pos];
		}
	}
	rd(i, maxn - 1, 1)
	{
		ansr[i - 1] = ansr[i];
		for (auto x: R[i])
		{
			int pos = x.first; ll c = x.second;
			ansr[i - 1] -= r[pos];
			r[pos] = min(r[pos], c);
			ansr[i - 1] += r[pos];
		}
	}
	ll res = INF;
	ru(i, 1, maxn - 1 - k + 1)
	{
//		printf("%lld %lld\n", ansl[i], ansr[i + k - 1]);
		res = min(res, ansl[i] + ansr[i + k - 1]);
	}
	if(res == INF) printf("-1");
	else printf("%lld\n", res);
	return 0;
}