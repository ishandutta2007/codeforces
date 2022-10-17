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
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n;
int vis[maxn], p[maxn];
int sta[maxn], top;
inline int que(int pos)
{
	printf("? %d\n", pos);
	fflush(stdout);
	return read();
}
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) vis[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		if(vis[i]) continue;
		sta[top = 1] = que(i);
		while(1)
		{
			int now = que(i);
			vis[now] = 1;
			if(now == sta[1]) break;
			sta[++top] = now;
		}
		for (int j = 1; j <= top; j++)
		{
			p[sta[j]] = sta[j % top + 1];
		}
	}
	printf("! ");
	for (int i = 1; i <= n; i++) printf("%d ", p[i]);
	printf("\n");
	fflush(stdout);
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