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
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], tp[maxn];
void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read(), tp[i] = (a[i] & 1);
	ll sum = 0;
	for (int i = 2; i < n; i++) sum += (a[i] + 1) / 2;
	int fl = 1;
	for (int i = 2; i < n; i++) fl &= (a[i] == 1);
	if((n == 3 && (a[2] & 1)) || fl) printf("-1\n");
	else printf("%lld\n", sum);
}
int main()
{
	int T = read();
	while(T--) solve(); 
	return 0;
}