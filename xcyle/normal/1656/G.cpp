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
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], p[maxn], buc[maxn], las[maxn];
int id[maxn], to[maxn];
inline void work(int x, int y, int z)
{
	p[x] = z;
	id[y] = id[x];
	to[y] = to[x];
	to[to[y]] = y;
}
void solve()
{
	n = read();
	for (int i = 0; i <= n; i++) buc[i] = las[i] = p[i] = to[i] = 0, id[i] = i;
	for (int i = 1; i <= n; i++) buc[a[i] = read()]++;
	int cnt = 0, pos = 0;
	for (int i = 1; i <= n; i++)
	{
		if(buc[i] & 1) cnt++, pos = i;
	}
	if(cnt > 1) 
	{
		printf("NO\n");
		return;
	}
	int fl = 0;
	if(n & 1)
	{
		if(buc[pos] == 1 && a[n / 2 + 1] == pos)
		{
			printf("NO\n");
			return;
		}
		for (int i = 1; i <= n; i++)
		{
			if(a[i] != pos || i == n / 2 + 1) continue;
			pos = i; break;
		}
	}
	for (int i = 1; i <= n; i++) 
	{
		if(i == pos) continue;
		if(las[a[i]]) to[las[a[i]]] = i, to[i] = las[a[i]], las[a[i]] = 0;
		else las[a[i]] = i;
	}
	if(n & 1) work(n / 2 + 1, pos, id[pos]);
	for (int i = 1; i <= n / 2; i++)
	{
//		for (int j = 1; j <= n; j++) printf("%d ", to[j]);
//		printf("\n");
		if(i * 2 + 1 != n && (i * 2 == n || to[i + 1] != n - i + 1))
		{
			int ida = id[i + 1], tmp = to[i + 1], idb = id[tmp];
			work(n - i + 1, tmp, idb);
			work(i, i + 1, ida);
		}
		else
		{
			int tmp = to[i], ida = id[tmp], idb = id[i];
			work(n - i + 1, i, idb);
			work(i, tmp, ida);
		}
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++) printf("%d ", p[i]);
	printf("\n");
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}