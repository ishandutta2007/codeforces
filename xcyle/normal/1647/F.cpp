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
#define maxn 500005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], pre[maxn], suf[maxn];
int f[maxn], g[maxn];
int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++)
	{
		if(pre[i - 1] == -1 || (pre[i - 1] > a[i] && a[i - 1] > a[i])) pre[i] = -1;
		else if(pre[i - 1] < a[i] && a[i - 1] < a[i]) pre[i] = min(pre[i - 1], a[i - 1]);
		else pre[i] = max(pre[i - 1], a[i - 1]);
	}
	for (int i = n; i >= 1; i--)
	{
		if(suf[i + 1] == -1 || (suf[i + 1] > a[i] && a[i + 1] > a[i])) suf[i] = -1;
		else if(suf[i + 1] < a[i] && a[i + 1] < a[i]) suf[i] = min(suf[i + 1], a[i + 1]);
		else suf[i] = max(suf[i + 1], a[i + 1]);
	}
	int pos = 0, ans = 0;
	for (int i = 1; i <= n; i++) if(a[i] > a[pos]) pos = i;
	f[pos] = suf[pos] < 0 ? 1e9 + 1 : suf[pos], g[pos] = 0;
	for (int i = pos - 1; i >= 1; i--)
	{
		f[i] = 1e9 + 1, g[i] = 0;
		if(a[i] < a[i + 1]) f[i] = min(f[i], f[i + 1]);
		if(a[i] < g[i + 1]) f[i] = min(f[i], a[i + 1]);
		if(a[i] > a[i + 1]) g[i] = max(g[i], g[i + 1]);
		if(a[i] > f[i + 1]) g[i] = max(g[i], a[i + 1]);
		if(pre[i] != -1 && g[i] > pre[i]) ans++;
	}
	f[pos] = pre[pos] < 0 ? 1e9 + 1 : pre[pos], g[pos] = 0;
	for (int i = pos + 1; i <= n; i++)
	{
		f[i] = 1e9 + 1, g[i] = 0;
		if(a[i] < a[i - 1]) f[i] = min(f[i], f[i - 1]);
		if(a[i] < g[i - 1]) f[i] = min(f[i], a[i - 1]);
		if(a[i] > a[i - 1]) g[i] = max(g[i], g[i - 1]);
		if(a[i] > f[i - 1]) g[i] = max(g[i], a[i - 1]);
		if(suf[i] != -1 && g[i] > suf[i]) ans++;
	}
	printf("%d\n", ans);
	return 0;
}