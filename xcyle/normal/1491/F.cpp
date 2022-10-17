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
#define maxn 2005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n;
int que(int l1, int r1, int l2, int r2)
{
	printf("? %d %d\n", r1 - l1 + 1, r2 - l2 + 1);
	for (int i = l1; i <= r1; i++) printf("%d ", i);
	printf("\n");
	for (int i = l2; i <= r2; i++) printf("%d ", i);
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}
int vis[maxn];
void solve()
{
	scanf("%d", &n);
	int flag = 0;
	for (int i = 2; i <= n; i++)
	{
		int x = que(1, i - 1, i, i);
		if(x)
		{
			vis[i] = 1;
			int l = 1, r = i - 1, mid;
			while(l < r)
			{
				mid = (l + r) >> 1;
				if(que(1, mid, mid + 1, i)) r = mid;
				else l = mid + 1;
			}
			vis[l] = 1;
			flag = i;
			break;
		}
	}
	int las = 0;
	for (int i = flag + 1; i <= n; i++)
	{
		int x = que(flag, flag, flag + 1, i);
		if(x != las) vis[i] = 1;
		las = x;
	}
	int cnt = n;
	for (int i = 1; i <= n; i++) cnt -= vis[i];
	printf("! %d ", cnt);
	for (int i = 1; i <= n; i++) if(!vis[i]) printf("%d ", i);
	printf("\n");
	fflush(stdout);
	for (int i = 1; i <= n; i++) vis[i] = 0;
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}