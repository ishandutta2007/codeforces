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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
ll f[105], sum[105];
void solve()
{
	int k = read();
	priority_queue<int> q; ll s = 0;
	ru(i, 1, k) {int x = read(); s += x; q.push(x);}
	int loc = lower_bound(sum, sum + 61, s) - sum;
	if(sum[loc] != s) {printf("NO\n"); return;}
	ll tmp = 0, las = 0;
	rd(i, loc, 0)
	{
		if(i < loc - 1) q.push(las);
		if(q.empty()) {printf("NO\n"); return;}
		ll mx = q.top(); q.pop();
		if(mx < f[i]) {printf("NO\n"); return;}
		las = tmp, tmp = mx - f[i];
	}
	printf("YES\n");
}
int main()
{
	f[0] = f[1] = 1, sum[0] = 1, sum[1] = 2; ru(i, 2, 60) f[i] = f[i - 1] + f[i - 2], sum[i] = sum[i - 1] + f[i];
	int T = read();
	while(T--) solve();
	return 0;
}