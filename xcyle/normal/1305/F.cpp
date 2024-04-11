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
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n;
ll a[maxn];
mt19937 Rand(time(NULL));
int vis[maxn], prime[maxn], cnt;
void init()
{
	ru(i, 2, maxn - 1)
	{
		if(!vis[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && prime[j] * i < maxn; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}
set<ll> d;
void check(ll t)
{
	if(t == 0) return;
	ru(i, 1, cnt) if(t % prime[i] == 0) 
	{
		d.insert(prime[i]);
		while(t % prime[i] == 0) t /= prime[i];
	}
	if(t != 1) d.insert(t);
}
int main()
{
	n = read();
	init();
	ru(i, 1, n) scanf("%lld", &a[i]);
	ru(i, 1, 50)
	{
		int x = Rand() % n + 1; 
		check(a[x]), check(a[x] - 1), check(a[x] + 1);
	}
	ll ans = n;
	for (auto x: d)
	{
		ll res = 0;
		ru(i, 1, n)
		{
			if(a[i] <= x) res += x - a[i];
			else res += min(a[i] % x, x - a[i] % x);
			if(res > ans) break;
		}
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
	return 0;
}