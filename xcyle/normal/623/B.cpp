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
const ll INF = 1e18;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn];
ll A, B;
ll ans = INF;
vector<int> p;
void work(int x)
{
	for (int i = 2; i * i <= x; i++) if(x % i == 0)
	{
		p.push_back(i);
		while(x % i == 0) x /= i;
	}
	if(x != 1) p.push_back(x);
}
ll pre[maxn], suf[maxn];
void check(int x)
{
	suf[n] = A * n;
	rd(i, n, 1)
	{
		suf[i - 1] = suf[i] - A;
		if(a[i] % x != 0) suf[i - 1] += B;
		if(a[i] % x != 0 && (a[i] + 1) % x != 0 && (a[i] - 1) % x != 0) suf[i - 1] = INF;
	}
	ans = min(ans, suf[0]);
	ll mn = 0;
	ru(i, 1, n)
	{
		pre[i] = pre[i - 1] - A;
		if(a[i] % x != 0) pre[i] += B;
		if(a[i] % x != 0 && (a[i] + 1) % x != 0 && (a[i] - 1) % x != 0) pre[i] = INF;
		mn = min(mn, pre[i]);
		ans = min(ans, mn + suf[i]);
	}
}
int main()
{
	n = read(), A = read(), B = read();
	ru(i, 1, n) a[i] = read();
	work(a[1]), work(a[1] - 1), work(a[1] + 1);
	work(a[n]), work(a[n] - 1), work(a[n] + 1);
	for (auto x: p) check(x);
	printf("%lld", ans);
	return 0;
}