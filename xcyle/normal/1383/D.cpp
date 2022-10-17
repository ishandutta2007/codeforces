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
#define maxn 255
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, a[maxn][maxn];
int tagx[maxn * maxn], tagy[maxn * maxn], ans[maxn][maxn];
struct node
{
	int x, y, d, id;
	inline bool friend operator < (node aa, node bb)
	{
		return aa.d == bb.d ? aa.id < bb.id : aa.d < bb.d;
	}
}p[maxn * maxn];
int ansx[maxn], ansy[maxn];
inline int que(int x, int y)
{
	return min(ansx[x], ansy[y]);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) ans[i][j] = n * m + 1;
	for (int i = 1; i <= n; i++)
	{
		int tmp = 0;
		for (int j = 1; j <= m; j++) tmp = max(tmp, a[i][j]);
		tagx[tmp] = 1;
	}
	for (int j = 1; j <= m; j++)
	{
		int tmp = 0;
		for (int i = 1; i <= n; i++) tmp = max(tmp, a[i][j]);
		tagy[tmp] = 1;
	}
	int pos = 0;
	for (int i = 1; i <= n * m; i++)
	{
		if(tagx[i] && tagy[i])
		{
			pos++;
			ans[pos][pos] = i;
			ansx[pos] = ansy[pos] = i;
		}
	}
	int tmp = pos;
	for (int i = n * m; i >= 1; i--)
	{
		if(tagx[i] && !tagy[i]) tmp++, ans[tmp][pos] = ansx[tmp] = i;
	}
	tmp = pos;
	for (int i = n * m; i >= 1; i--)
	{
		if(!tagx[i] && tagy[i]) tmp++, ans[pos][tmp] = ansy[tmp] = i;
	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++) printf("%d ", ans[i][j]);
//		printf("\n");
//	}
	int tot = 0;
	for (int i = 1; i < pos; i++)
	{
		for (int j = m; j > i; j--)
		{
			p[++tot] = {i, j, que(i, j), tot};
		}
	}
	for (int i = 1; i < pos; i++)
	{
		for (int j = n; j > i; j--)
		{
			p[++tot] = {j, i, que(j, i), tot};
		}
	}
	for (int i = n; i > pos; i--)
	{
		for (int j = m; j > pos; j--)
		{
			p[++tot] = {i, j, que(i, j), tot};
		}
	}
//	printf("!\n");
//	for (int i = 1; i <= tot; i++) printf("%d %d %d\n", p[i].x, p[i].y, p[i].d); 
//	printf("\n");
	sort(p + 1, p + tot + 1);
	for (int i = n * m; i >= 1; i--)
	{
		if(tagx[i] || tagy[i]) continue;
		ans[p[tot].x][p[tot].y] = i;
		tot--;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}