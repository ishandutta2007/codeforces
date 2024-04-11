#include <iostream>
#include <cstdio>
#include <vector> 
#include <algorithm>
#define maxn 2005
using namespace std;
int n, fa[maxn], c[maxn], siz[maxn], id[maxn], dfn[maxn], tot;
vector<int> G[maxn];
int vis[maxn];
int tmp[maxn], cnt = 0;
void dfs(int x)
{
	siz[x] = 1;
	dfn[x] = ++tot;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		dfs(V);
		siz[x] += siz[V];
	}
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if(dfn[x] < dfn[i] && dfn[i] <= dfn[x] + siz[x] - 1) tmp[++cnt] = id[i];
	}
	sort(tmp + 1, tmp + cnt + 1);
	id[x] = tmp[c[x]] + 1;
	for (int i = 1; i <= n; i++)
	{
		if(i == x) continue;
		if(id[i] >= id[x]) id[i]++;
	}
}
int root;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &fa[i], &c[i]);
		if(fa[i] == 0) root = i;
		else G[fa[i]].push_back(i);
	}
	dfs(root);
	for (int i = 1; i <= n; i++)
	{
		if(c[i] >= siz[i])
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", id[i]);
	}
	return 0;
}