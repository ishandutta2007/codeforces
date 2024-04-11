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
#define maxn 4100
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, q, w[maxn];
int val[maxn];
char s[maxn];
int cnt[maxn];
struct node
{
	int d, num;
	inline bool friend operator < (node aa, node bb)
	{
		return aa.d < bb.d;
	} 
}f[maxn][maxn];
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = n - 1; i >= 0; i--) scanf("%d", &w[i]);
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(!((i >> j) & 1)) val[i] += w[j];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%s", s);
		int tmp = 0;
		for (int j = 0; j < n; j++) tmp = tmp * 2 + s[j] - '0';
		cnt[tmp]++;
	}
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < (1 << n); j++)
		{
			f[i][j].d = val[i ^ j];
			f[i][j].num = cnt[j];
		}
		sort(f[i], f[i] + (1 << n));
		for (int j = 1; j < (1 << n); j++) f[i][j].num += f[i][j - 1].num; 
	}
	int k;
	for (int i = 1; i <= q; i++)
	{
		scanf("%s%d", s, &k);
		int tmp = 0;
		for (int j = 0; j < n; j++) tmp = tmp * 2 + s[j] - '0';
		if(f[tmp][0].d > k)
		{
			printf("0\n");
			continue;
		}
		int l = 0, r = (1 << n) - 1, mid;
		while(l < r)
		{
			mid = (l + r + 1) >> 1;
			if(f[tmp][mid].d > k) r = mid - 1;
			else l = mid;
		}
		printf("%d\n", f[tmp][l].num);
	}
	return 0;
}