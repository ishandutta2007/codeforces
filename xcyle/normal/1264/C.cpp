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
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, q, p[maxn], spro[maxn], sum[maxn];
set<int> pos;
set<int>::iterator it, it2;
inline int qpow(int x, int step)
{
	int res = 1;
	for (; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
inline int calc(int l, int r)
{
	int a = (ll)spro[l] * qpow(spro[r + 1], mo - 2) % mo;
	int b = (mo + sum[l] - (ll)sum[r + 1] * a % mo) % mo;
//	printf("%d %d %d\n", l, r, (ll)b * qpow(a, mo - 2) % mo);
	return (ll)b * qpow(a, mo - 2) % mo;
}
int main()
{
	n = read(), q = read();
	ru(i, 1, n) p[i] = (ll)read() * qpow(100, mo - 2) % mo;
	spro[n + 1] = 1;
	rd(i, n, 1) spro[i] = (ll)spro[i + 1] * p[i] % mo, sum[i] = ((ll)sum[i + 1] * p[i] % mo + 1) % mo;
	ll ans = calc(1, n);
	pos.insert(1), pos.insert(n + 1);
	ru(i, 1, q)
	{
		int x = read();
		if(pos.find(x) != pos.end())
		{
			it = pos.find(x);
			it2 = it, it2--;
			ans -= calc((*it2), x - 1);
			it2 = it, it2++;
			ans -= calc(x, (*it2) - 1);
			pos.erase(it);
			it = pos.lower_bound(x);
			it2 = it, it2--; 
			ans += calc((*it2), (*it) - 1);
		}
		else
		{
			it = pos.lower_bound(x);
			it2 = it, it2--;
			ans -= calc((*it2), (*it) - 1);
			it = pos.insert(x).first;
			it2 = it, it2--;
			ans += calc((*it2), (*it) - 1);
			it2 = it, it2++;
			ans += calc((*it), (*it2) - 1);
		}
		ans = (ans % mo + mo) % mo;
		printf("%d\n", ans);
	}
	return 0;
}