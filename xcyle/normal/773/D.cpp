/*

_/      _/      _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/     _/      _/     _/    _/     _/           _/
  _/  _/      _/              _/  _/      _/           _/
   _/_/       _/                _/        _/           _/_/_/_/
  _/  _/      _/                _/        _/           _/
 _/    _/     _/      _/        _/        _/           _/
_/      _/      _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <cstdlib>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 2005
using namespace std;
const int INF = 1e9 + 7;
const long long INF2 = 9e16;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
int a[maxn][maxn], vis[maxn], b[maxn][maxn];
long long f[maxn][maxn];
long long ans = 0;
long long dis[maxn];
int main()
{
	int tmp = INF;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			a[j][i] = a[i][j];
			tmp = min(tmp, a[i][j]);
		}
	}
	ans = (long long)tmp * (n - 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(i == j) continue;
			a[i][j] -= tmp;
//			printf("%d ", a[i][j]);
		}
//		printf("\n");
		dis[i] = INF2;
	}
	for (int i = 1; i <= n; i++)
	{
		int mn = INF;
		for (int j = 1; j <= n; j++) 
		{
			if(i == j) continue;
			mn = min(mn, a[i][j]);
		}
		if(mn == 0)
		{
			dis[i] = 0;
//			printf("%d\n", i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int mn = INF;
		for (int j = 1; j <= n; j++)
		{
			if(i == j) continue;
			mn = min(mn, a[j][i]);
		} 
//		printf("%d ", mn);
		for (int j = 1; j <= n; j++)
		{
			b[j][i] = min(a[j][i], 2 * mn);
		}
	}
//	printf("\n");
	dis[0] = INF2;
	for (int i = 1; i <= n; i++)
	{
		int id = 0;
		for (int j = 1; j <= n; j++)
		{
			if(vis[j]) continue;
			if(dis[j] < dis[id]) id = j;
		}
		if(id == 0) break;
		vis[id] = 1;
		for (int j = 1; j <= n; j++) dis[j] = min(dis[j], dis[id] + b[id][j]);
	}
	for (int i = 1; i <= n; i++) printf("%lld\n", ans + dis[i]);
	return 0;
}