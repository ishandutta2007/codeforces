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
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn][6], vis[maxn];
inline int check(int x, int y)
{
	int cnt = 0;
	for (int j = 1; j <= 5; j++) cnt += a[x][j] < a[y][j];
	return cnt >= 3;
}
void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) vis[i] = 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= 5; j++) a[i][j] = read();
	int now = 1;
	for (int i = 2; i <= n; i++) if(check(i, now)) now = i;
	for (int i = 1; i <= n; i++) if(check(i, now))
	{
		printf("-1\n");
		return;
	}
	printf("%d\n", now);
}
int main()
{
	int T = read();
	while(T--) solve(); 
	return 0;
}