#include <iostream>
#include <cstdio>
#include <vector>
#define ll long long 
#define maxn 500005
using namespace std;
const int mo = 1e9 + 7;
int n, m, a[maxn], b[maxn], vis[maxn], vis2[maxn];
vector<int> G[maxn], ans;
int fa[maxn], color[maxn];
int find(int x)
{
	int p = x;
	while(p != fa[p]) p = fa[p];
	int p2 = x;
	while(p2 != fa[p2])
	{
		int tmp = fa[p2];
		fa[p2] = p;
		p2 = tmp;
	}
	return p;
}
int uni(int x, int y)
{
	int fx = find(x), fy = find(y);
	if(fx == fy) return 0;
	if(vis2[fx]) vis2[fy] = 1;
	if(vis2[fy]) vis2[fx] = 1;
	fa[fx] = fy;
	return 1;
}
void dfs(int x, int c)
{
	color[x] = c;
	vis[x] = 1;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(vis[V]) continue;
		dfs(V, c);
	}
}
vector<int> p;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) fa[i] = i;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] == 1)
		{
			scanf("%d", &a[i]);
			p.push_back(a[i]);
		}
		else 
		{
			scanf("%d%d", &a[i], &b[i]);
			G[a[i]].push_back(b[i]);
			G[b[i]].push_back(a[i]); 
		}
	}
	int aaaans = 1;
	int cnt = 0;
	int num = m;
	for (int i = 0; i < p.size(); i++)
	{
		if(!vis[p[i]]) 
		{
			dfs(p[i], ++cnt);
		}
	}
	int tmp = cnt;
	for (int i = 1; i <= m; i++)
	{
		if(!vis[i]) dfs(i, ++cnt);
	}
	num -= (cnt - tmp);
	for (int i = 1; i <= num; i++) 
		aaaans = aaaans * 2 % mo;
	for (int i = 1; i <= n; i++)
	{
		if(!b[i])
		{
			if(!vis2[find(a[i])])
			{
				ans.push_back(i);
				vis2[find(a[i])] = 1;
			}
		}
		else
		{
			if(vis2[find(a[i])] && vis2[find(b[i])]) continue;
			if(uni(a[i], b[i])) ans.push_back(i);
		}
	}
	printf("%d %d\n", aaaans, ans.size());
	for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	return 0;
}