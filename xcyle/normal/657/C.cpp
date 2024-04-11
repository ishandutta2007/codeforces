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
#define int long long
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, v[maxn];
ll b, c, k, ans = 2e18;
priority_queue<ll> q;
void work()
{
	ll sum = 2e12 * k;
	while(!q.empty()) q.pop();
	ru(i, 1, k) q.push(2e12);
	ru(i, 1, n)
	{
		int A = v[i] / 5, B = 5 * A - v[i];
		while(B < 0) B += 5, A++; 
		while(B >= 5) B -= 5, A--;
		ll val = c * B - b * A;
		sum += val, q.push(val);
		sum -= q.top(); q.pop();
		if(q.top() < 2e12) ans = min(ans, b * A * k + sum); 
	}
}
signed main()
{
	n = read(), k = read(), b = read(), c = read();
	b = min(b, 5 * c);
	ru(i, 1, n) v[i] = read(); sort(v + 1, v + n + 1);
	ru(i, 0, 4)
	{
		ru(j, 1, n) v[j] -= i;
		work();
		ru(j, 1, n) v[j] += i; 
	}
	printf("%lld\n", ans);
	return 0;
}