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
#define maxn 100005
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
	ll ans = 0, x = INF;
	for (int i = 1; i <= 2 * n; i++)
	{
		for (int j = 1; j <= 2 * n; j++)
		{
			ll y = read();
			if(i > n && j > n) ans += y;
			if(i == 1 && j == n + 1) x = min(x, y);
			if(i == n && j == n + 1) x = min(x, y);
			if(i == n && j == 2 * n) x = min(x, y);
			if(i == 1 && j == 2 * n) x = min(x, y);
			if(i == n + 1 && j == 1) x = min(x, y);
			if(i == n + 1 && j == n) x = min(x, y);
			if(i == 2 * n && j == n) x = min(x, y);
			if(i == 2 * n && j == 1) x = min(x, y);
		}
	}
	printf("%lld\n", x + ans);
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