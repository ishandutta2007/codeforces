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
#define maxn 400005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
unordered_map<ll, int> ans;
inline int gcd(int x, int y) {return !y ? x : gcd(y, x % y);}
unordered_map<ll, set<pii> > s;
void work(int x, int y, int t)
{
	if(!x || !y) return;
	if(x < 0) x = -x;
	if(y < 0) y = -y;
	int d = gcd(x, y);
	x /= d, y /= d;
	ans[(ll)x * (int)(2e5) + y] += t;
}
int main()
{
	int n = read(), cnt = 0;
	ru(i, 1, n)
	{
		int tp = read(), x = read(), y = read();
		if(tp == 1)
		{
			ll t = (ll)x * x + (ll)y * y;
			for (auto z: s[t])
			{
				int X = z.fi, Y = z.se;
				work(X - x, Y - y, 2);
			}
			s[t].insert(mp(x, y));
			work(y, x, 1);
			cnt++;
		}
		if(tp == 2)
		{
			ll t = (ll)x * x + (ll)y * y;
			s[t].erase(mp(x, y));
			for (auto z: s[t])
			{
				int X = z.fi, Y = z.se;
				work(X - x, Y - y, -2);
			}
			cnt--;
			work(y, x, -1);
		}
		if(tp == 3)
		{
			int d = gcd(x, y);
			x /= d, y /= d;
			printf("%d\n", cnt - ans[(ll)y * (int)(2e5) + x]);
		}
	}
	return 0;
}