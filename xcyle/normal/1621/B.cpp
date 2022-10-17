/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
using namespace std;
const ll INF = 1e11;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n;
void solve()
{
	scanf("%d", &n);
	ll L = INF, R = INF, T = INF;
	int nl = 1e9 + 1, nr = 0;
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		ll k;
		scanf("%d%d%lld", &l, &r, &k);
		if(l < nl)
		{
			nl = l;
			L = k;
			T = INF;
		}
		if(r > nr)
		{
			nr = r;
			R = k;
			T = INF;
		}
		if(l == nl) L = min(L, k);
		if(r == nr) R = min(R, k);
		if(l == nl && r == nr) T = min(T, k);
		printf("%lld\n", min(L + R, T));
	}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		solve();
	 } 
	return 0;
}