#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#define maxn 200005 
using namespace std;
int n, a[maxn], u, v, pr;
int cnt = 0, ans = 0, cf[maxn];
vector<int> G[maxn];
int fa[maxn][30], dep[maxn];
int vis[maxn];
map<int, int> p;
void dfs(int x, int fat)
{
	fa[x][0] = fat;
	dep[x] = dep[fat] + 1;
	for (int i = 1; i <= 23; i++)
	{
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fat) continue;
		dfs(V, x);
	}
}
int LCA(int x, int y)
{
	if(dep[x] > dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--)
	{
		if(dep[fa[y][i]] > dep[x])
		{
			y = fa[y][i];
		}
	}
	return y;
}
int lca(int x, int y)
{
	if(dep[x] > dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--)
	{
		if(dep[fa[y][i]] >= dep[x])
		{
			y = fa[y][i];
		}
	}
	if(x == y) return x;
	for (int i = 20; i >= 0; i--)
	{
		if(fa[x][i] != fa[y][i])
		{
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
void calc(int x, int fat, long long res)
{
	if(res < 0) return;
	int pl = res + cf[x];
	if(pl == cnt)
	{
		ans++;
		pr = x;
	}
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fat) continue;
		calc(V, x, pl);
	}
}
set<int> p2;
int check(int x, int fat)
{
	set<int>::iterator iter = p2.find (a[x]);
	if(iter != p2.end()) return 0;
	p2.insert(a[x]);
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fat) continue;
		if(!check(V, x)) return 0;
	}
	p2.erase(a[x]);
	return 1;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 1);
	for (int i = 1; i <= n; i++)
	{
		map<int, int>::iterator iter = p.find(a[i]);
		if(iter != p.end())
		{
			int tmp = (iter->second);
			vis[i] = vis[tmp] = 1;
			int L = lca(i, tmp);
			if(L == i)
			{
				cf[LCA(i, tmp)]++;
				cf[tmp] -= n;
			}
			else if(L == tmp)
			{
				cf[LCA(i, tmp)]++;
				cf[i] -= n;
			}
			else
			{
				cf[1]++;
				cf[tmp] -= n;
				cf[i] -= n;
			}
			cnt++;
		}
		else p.insert(pair<int, int>(a[i], i));
	}
	calc(1, 1, 0);
	if(ans == 0)
	{
		printf("%d", ans);
		return 0;
	}
	if(check(pr, pr)) printf("%d", ans);
	else printf("0\n");
	return 0;
}