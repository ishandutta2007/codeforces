/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

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
#define maxn 1505
using namespace std;
const double pi = 3.1415926535;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
vector<int> G[maxn];
struct pnt
{
	int x, y, id;
	double val;
	inline bool friend operator < (pnt aa, pnt bb)
	{
		return aa.val < bb.val;
	}
}a[maxn], tmp[maxn];
int siz[maxn], ans[maxn];
void dfs(int x, int fa)
{
	siz[x] = 1;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		dfs(V, x);
		siz[x] += siz[V];
	}
}
inline ll dis(int p, int q)
{
	return (ll)(a[p].x - a[q].x) * (a[p].x - a[q].x) + (ll)(a[p].y - a[q].y) * (a[p].y - a[q].y);
}
int rk[maxn];
void work(int x, int fa, int l, int r)
{
	ans[a[l].id] = x;
	rk[x] = l;
//	printf("%d %d %d\n", x, a[l].x, a[l].y);
	for (int i = l + 1; i <= r; i++) a[i].val = atan2(a[i].y - a[l].y, a[i].x - a[l].x);
	sort(a + l + 1, a + r + 1);
//	for (int i = l + 1; i <= r; i++) printf("%d %d\n", a[i].x, a[i].y);
//	printf("\n");
	for (int i = l + 1; i < r; i++)
	{
		if(a[i + 1].val - a[i].val >= pi) 
		{
			for (int j = l + 1; j <= r; j++) tmp[j] = a[j];
			int now = i + 1;
			for (int j = l + 1; j <= r; j++) a[j] = tmp[now++], (now > r) && (now = l + 1); 
			break; 
		}
	}
//	for (int i = l + 1; i <= r; i++) printf("%d %d\n", a[i].x, a[i].y);
//	printf("\n");
	for (int i = 0, j = l + 1; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		work(V, x, j, j + siz[V] - 1);
		j += siz[V];
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int xx, yy;
		scanf("%d%d", &xx, &yy);
		G[xx].push_back(yy);
		G[yy].push_back(xx); 
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].id = i;
	}
	dfs(1, 1);
	for (int i = 1; i <= n; i++) a[i].val = atan2(a[i].y + 0x3f3f3f3f, a[i].x + 0x3f3f3f3f);
	sort(a + 1, a + n + 1);
	work(1, 1, 1, n);
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}