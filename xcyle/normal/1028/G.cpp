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
ll g[6], f[10005][6];
void init()
{
	g[0] = 0; ru(i, 1, 10000) f[i][0] = i - 1;
	ru(i, 1, 4) g[i] = (g[i - 1] + 1) * 10001 - 1;
	rd(i, 10000, 1) ru(j, 1, 5)
	{
		if(i > 1 && j == 5) continue;
		int tim = i; f[i][j] = f[i][j - 1];
		while(tim && f[i][j] + 2 <= 10000) f[i][j] = f[f[i][j] + 2][j - 1], tim--;
		f[i][j] += (g[j - 1] + 1) * tim;
	}
//	ru(i, 1, 5) printf("%lld ", f[1][i]); printf("%lld", g[4]);
//	printf("%lld\n", f[1][5]);
}
vector<ll> x;
ll query()
{
	while(!x.empty() && x.back() > f[1][5]) x.pop_back();
	printf("%d\n", (int)x.size() - 1);
	ru(i, 1, (int)x.size() - 1) printf("%lld ", x[i]); printf("\n"), fflush(stdout);
	int res = read(); if(res == -1) exit(0);
	return x[res] + 1;
}
void solve(ll now, int rem)
{
	int tim = min(10000ll, now);
	now--, x.clear(), x.push_back(now);
	while(tim && now < 10000) now = f[now + 1][rem - 1] + 1, x.push_back(now), tim--;
	ru(i, 1, tim) now += g[rem - 1] + 1, x.push_back(now);
	solve(query(), rem - 1);
}
int main()
{
	init(), solve(1, 5);
	return 0;
}