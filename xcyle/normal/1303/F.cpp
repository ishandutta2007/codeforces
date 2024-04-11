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
#define maxn 305
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, q;
int a[maxn][maxn];
int fa[maxn * maxn];
struct node
{
	int x, y, t;
};
vector<node> add[2000005], del[2000005];
inline int id(int x, int y)
{
	if(x < 1 || x > n || y < 1 || y > m) return 0;
	return (x - 1) * m + y;
}
inline int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
inline int merge(int p, int q)
{
	if(p <= 0 || p > n * m || !fa[p]) return 0;
	if(q <= 0 || q > n * m || !fa[q]) return 0;
	p = find(p), q = find(q);
	fa[p] = q;
//	printf("%d %d\n", p, q);
	return p != q; 
}
int cf[2000005];
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	int x, y, c;
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d%d", &x, &y, &c);
		add[c].push_back({x, y, i});
		del[a[x][y]].push_back({x, y, i}); 
		a[x][y] = c;
	}
	for (int i = 0; i <= c; i++)
	{
		del[i].push_back({1, 1, q + 1});
		for (int j = 1; j <= n; j++) for (int k = 1; k <= m; k++) fa[id(j, k)] = 0;
		int cnt = 0;
		add[i].push_back({1, 1, del[i][0].t});
//		printf("!!! %d\n", i);
		for (int j = 0; j < add[i].size() - 1; j++)
		{
			int nx = add[i][j].x, ny = add[i][j].y;
			if(!fa[id(nx, ny)]){
			fa[id(nx, ny)] = id(nx, ny);
			cnt++;
			cnt -= merge(id(nx - 1, ny), id(nx, ny));
			cnt -= merge(id(nx + 1, ny), id(nx, ny));
			cnt -= merge(id(nx, ny - 1), id(nx, ny));
			cnt -= merge(id(nx, ny + 1), id(nx, ny));}
			cf[add[i][j].t] += cnt;
			cf[add[i][j + 1].t] -= cnt;
//			printf("%d %d %d %d %d\n", nx, ny, add[i][j].t, add[i][j + 1].t, cnt);
		}
		cnt = 0;
		for (int j = 1; j <= n; j++) for (int k = 1; k <= m; k++) fa[id(j, k)] = 0;
		for (int j = 1; j <= n; j++) for (int k = 1; k <= m; k++)
		{
			if(a[j][k] == i)
			{
//				printf("hahah %d %d\n", j, k);
				fa[id(j, k)] = id(j, k);
				cnt++;
				cnt -= merge(id(j - 1, k), id(j, k));
				cnt -= merge(id(j + 1, k), id(j, k));
				cnt -= merge(id(j, k - 1), id(j, k));
				cnt -= merge(id(j, k + 1), id(j, k));
			}
			else fa[id(j, k)] = 0;
		}
//		printf("????????%d\n", cnt);
		for (int j = del[i].size() - 2; j >= 0; j--)
		{
			cf[del[i][j].t] += cnt;
			cf[del[i][j + 1].t] -= cnt;
			int nx = del[i][j].x, ny = del[i][j].y;
//			printf("%d %d %d %d %d\n", nx, ny, del[i][j].t, del[i][j + 1].t, cnt);
			if(!fa[id(nx, ny)]){
			fa[id(nx, ny)] = id(nx, ny);
			cnt++;
			cnt -= merge(id(nx - 1, ny), id(nx, ny));
			cnt -= merge(id(nx + 1, ny), id(nx, ny));
			cnt -= merge(id(nx, ny - 1), id(nx, ny));
			cnt -= merge(id(nx, ny + 1), id(nx, ny));}
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cf[i] += cf[i - 1];
		printf("%d\n", cf[i]);
	}
	return 0;
}