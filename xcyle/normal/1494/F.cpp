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
#define maxn 3005
using namespace std; 
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, x[maxn], y[maxn], d[maxn];
int G2[maxn][maxn];
int tp[maxn], tmp[maxn];
vector<int> G[maxn], id[maxn], ans, odd;
int del[maxn];
int fa[maxn];
inline int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void dfs(int x)
{
	for (int i = del[x]; i < G[x].size(); i++)
	{
		int V = G[x][i];
		del[x]++;
		if(tp[id[x][i]] || ! G2[x][V]) continue;
		G2[x][V] = G2[V][x] = 0;
		dfs(G[x][i]);
	}
	ans.push_back(x);
}
void work(int x)
{
	ans.clear();
	for (int i = 1; i <= n; i++) del[x] = 0;
	dfs(x);
	for (int i = 0; i < ans.size() / 2; i++) swap(ans[i], ans[ans.size() - i - 1]);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		G[x[i]].push_back(y[i]);
		G[y[i]].push_back(x[i]);
		id[x[i]].push_back(i);
		id[y[i]].push_back(i);
		G2[x[i]][y[i]] = G2[y[i]][x[i]] = i;
		d[x[i]]++, d[y[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if(d[i] & 1) odd.push_back(i);
	}
	if(odd.size() == 0)
	{
		work(1);
		printf("%d\n", ans.size());
		for (int j = 0; j < ans.size(); j++) printf("%d ", ans[j]);
		return 0;
	}
	if(odd.size() == 2)
	{
		work(odd[0]);
		printf("%d\n", ans.size());
		for (int j = 0; j < ans.size(); j++) printf("%d ", ans[j]);
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) G2[x[j]][y[j]] = G2[y[j]][x[j]] = j;
		for (int j = 1; j <= m; j++) tp[j] = 0;
		for (int j = 1; j <= n; j++) fa[j] = j;
		int flag = 0;
		for (int j = 1; j <= n; j++)
		{
			if(i == j) continue;
			if(!G2[i][j] && (d[j] & 1)) 
			{
				if(flag)
				{
					flag = -1;
					break;
				}
				else flag = j;
			}
			if(G2[i][j] && (d[j] & 1)) tp[G2[i][j]] = 1;
		}
		if(flag == -1) continue; 
		for (int j = 1; j <= m; j++)
		{
			if(tp[j]) continue;
			int fx = find(x[j]), fy = find(y[j]);
			if(d[fx] & 1) swap(fx, fy);
			if(fx != fy) fa[fx] = fy; 
		}
		int haha = 0;
		for (int j = 1; j <= m; j++)
		{
			if(tp[j]) continue;
			if(!haha) haha = find(x[j]);
			else if(haha && find(x[j]) != haha)
			{
				haha = -1;
				break;
			}
		}
		if(flag)
		{
			if(haha == -1) continue;
			work(flag);
			ans.push_back(-1);
			for (int j = 1; j <= n; j++) 
			{
				if(j != i && G2[i][j] && (d[j] & 1))
				{
					ans.push_back(j);
					ans.push_back(i);
				}
			}
			printf("%d\n", ans.size());
			for (int j = 0; j < ans.size(); j++) printf("%d ", ans[j]);
			return 0;
		}
		else
		{
			int beg = -1;
//			printf("!!!%d %d     ", i, haha);
			for (int j = 1; j <= m; j++)
			{
				if(tp[j]) continue;
//				printf("%d %d\n", x[j], y[j]);
			}
//			for (int j = 1; j <= n; j++) printf("%d ", find(j));
//			printf("\n");
			for (int j = 1; j <= n; j++)
			{
				if(j == i) continue;
				if(haha != -1)
				{
					if((d[j] & 1) && (haha == 0 || d[j] > 1)) beg = j;
					if((d[j] % 2 == 0) && G2[i][j]) beg = i;
				}
				if(haha == -1 && (d[j] & 1))
				{
					for (int k = 1; k <= n; k++) tmp[k] = fa[k];
					tp[G2[i][j]] = tp[G2[j][i]] = 0;
					int fx = find(j), fy = find(i);
					if(fx == fy)
					{
					tp[G2[i][j]] = tp[G2[j][i]] = 1;
						for(int k = 1; k <= n; k++) fa[k] = tmp[k];
						continue;
					}
					fa[fx] = fy;
					haha = 0;
//					printf("??? %d %d\n", i, j);
//					for (int k = 1; k <= n; k++) printf("%d ", find(k));
//					printf("\n");
					for (int k = 1; k <= m; k++)
					{
						if(tp[k]) continue;
						if(!haha) haha = find(x[k]);
						else if(haha && find(x[k]) != haha)
						{
							haha = -1;
							break;
						}
					}
					if(haha != -1)
					{
						beg = j;
						haha = -1;
						break;
					}
					tp[G2[i][j]] = tp[G2[j][i]] = 1;
					for (int k = 1; k <= n; k++) fa[k] = tmp[k];
				}
			}
			if(beg == -1) continue;
//			printf("%d %d\n", i, beg);
			work(beg);
			if(ans[ans.size() - 1] != i) ans.push_back(i);
			ans.push_back(-1);
			for (int j = 1; j <= n; j++)
			{
				if(j != i && G2[i][j] && (d[j] & 1) && j != beg)
				{
					ans.push_back(j);
					ans.push_back(i);
				}
			}
			printf("%d\n", ans.size());
			for (int j = 0; j < ans.size(); j++) printf("%d ", ans[j]);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}