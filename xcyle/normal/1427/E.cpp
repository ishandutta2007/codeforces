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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
ll n;
struct node {ll x, y, tp;};
vector<node> ans;
inline ll find(ll x)
{
	rd(i, 61, 0) if((x >> i) & 1) return (1ll << i);
}
set<ll> t;
int main()
{
	scanf("%lld", &n); t.insert(n);
	if(n & 2)
	{
		ans.push_back({n, n, 0});
		ans.push_back({n, 2 * n, 1});
		n = n ^ (2 * n);
	}
	ll c = 1;
	while(c * 2 <= n) 
	{
		ans.push_back({n * c, n * c, 0});
		c *= 2;
	}
	ans.push_back({n, n * c, 0});
	ll x = n + n * c;
	ans.push_back({n, n * c, 1});
	ll y = n ^ (n * c);
	ans.push_back({x, y, 1});
	ll z = x ^ y;
	ll tmp = z;
	while(tmp <= (1ll << 60))
	{
		ans.push_back({tmp, tmp, 0});
		tmp *= 2;
	}
	while(n != 1)
	{
		ans.push_back({n, n, 0});
		ll t = 2;
		while(!(n & t))
		{
			ans.push_back({n * t, n * t, 0});
			t *= 2;
		}
		ans.push_back({n, n * t, 1});
		n = n ^ (n * t);
		while(1)
		{
			ll t = find(n);
			if(t < z) break;
			ans.push_back({n, t, 1});
			n ^= t; 
		}
	}
	printf("%d\n", (int)ans.size());
	for (auto p: ans)
	{
		if(!p.tp) printf("%lld + %lld\n", p.x, p.y);
		else printf("%lld ^ %lld\n", p.x, p.y);
		if(t.find(p.x) == t.end() || t.find(p.y) == t.end()) {printf("!!!!!!!!!!wa\n"); return 0;}
		if(!p.tp) t.insert(p.x + p.y);
		else t.insert(p.x ^ p.y);
	}
	return 0;
}