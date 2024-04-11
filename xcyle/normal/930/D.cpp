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
#define maxn 400008
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
int x[maxn], y[maxn];
int mn[maxn], mx[maxn];
int premn[maxn], premx[maxn];
int sufmn[maxn], sufmx[maxn];
ll ans = 0;
void work(int tp)
{
	for (int i = 0; i < maxn; i++) premn[i] = sufmn[i] = mn[i] = 2 * maxn, premx[i] = sufmx[i] = mx[i] = -2 * maxn;
	for (int i = 1; i <= n; i++) if((x[i] + y[i] + maxn / 2) % 2 == tp)
	{
		mn[x[i] + y[i] + maxn / 2] = min(mn[x[i] + y[i] + maxn / 2], x[i] - y[i]);
		mx[x[i] + y[i] + maxn / 2] = max(mx[x[i] + y[i] + maxn / 2], x[i] - y[i]);
	}
	for (int i = 1; i < maxn; i++)
	{
		premn[i] = min(premn[i - 1], mn[i]);
		premx[i] = max(premx[i - 1], mx[i]);
	}
	for (int i = maxn - 2; i >= 0; i--)
	{
		sufmn[i] = min(sufmn[i + 1], mn[i]);
		sufmx[i] = max(sufmx[i + 1], mx[i]);
	}
	for (int i = tp + 1; i < maxn - 1; i += 2)
	{
		int MN = max(premn[i - 1], sufmn[i + 1]) + 1;
		int MX = min(premx[i - 1], sufmx[i + 1]) - 1;
		if(MN <= MX) ans += (MX - MN) / 2 + 1;
	}
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++) x[i] = read(), y[i] = read();
	work(0), work(1);
	printf("%lld", ans);
	return 0;
}