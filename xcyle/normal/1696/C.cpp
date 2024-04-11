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
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, m;
ll a[maxn], ca[maxn], b[maxn], cb[maxn];
void solve()
{
	n = read(), m = read();
	int tota = 0, totb = 0;
	ru(i, 1, n) 
	{
		int x = read();
		int now = x;
		while(now % m == 0) now /= m;
		if(now == a[tota])
		{
			ca[tota] += x / now;
		}
		else a[++tota] = now, ca[tota] = x / now;
	}
	k = read();
	ru(i, 1, k) 
	{
		int x = read();
		int now = x;
		while(now % m == 0) now /= m;
		if(now == b[totb])
		{
			cb[totb] += x / now;
		}
		else b[++totb] = now, cb[totb] = x / now;
	}
	if(tota != totb) {printf("No\n"); return;}
	ru(i, 1, tota) if(a[i] != b[i] || ca[i] != cb[i]) {printf("No\n"); return;}
	printf("Yes\n");
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}