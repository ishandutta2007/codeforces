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
int T, n, a[maxn];
int work(int l, int r, int tmp)
{
	if(l >= r) return 1;
	if(a[l] != a[r])
	{
		if(a[l] == tmp) return work(l + 1, r, tmp);
		if(a[r] == tmp) return work(l, r - 1, tmp);
		if(!tmp) return (work(l + 1, r, a[l]) | work(l, r - 1, a[r]));
		return 0;
	}
	return work(l + 1, r - 1, tmp);
}
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if(work(1, n, 0)) printf("YES\n");
	else printf("NO\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}