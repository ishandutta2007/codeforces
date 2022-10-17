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
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], nxt[maxn];
void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) nxt[i] = 0;
	for (int i = 1; i <= n; i++) nxt[a[i] = read()] = i;
	int ans = 0, r = 1, now = 1;
	while(now <= n)
	{
//		printf("%d %d %d\n", ans, now, r);
		if(nxt[a[now]] <= r)
		{
			ans++;
			now++;
			r++;
			continue;
		}
		int mxid = nxt[a[now]];
		while(r < nxt[a[now]])
		{
			r++;
			if(nxt[a[mxid]] < nxt[a[r]]) mxid = r;
		}
		now = mxid;
		ans++;
	}
	printf("%d\n", n - ans);
}
int main()
{
	solve();
	return 0;
}