#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define maxn 100005
using namespace std;
int n, fa[maxn];
int cnt, ans[maxn], siz[maxn], dep[maxn];
struct node
{
	int id, data;
};
node tmp[maxn];
vector<int> G[maxn]; 
inline bool cmp(node aa, node bb)
{
	return aa.data < bb.data;
}
int to[maxn], EED[maxn];
void dfs(int x)
{
	siz[x] = 1;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		dep[V] = dep[x] + 1;
		dfs(V);
		siz[x] += siz[V];
	}
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		tmp[i].data = dep[EED[V]] - dep[V];
		tmp[i].id = V;
	}
//	printf("!   %d\n",x);
	EED[x] = x;
	if(G[x].size() == 0) return;
	sort(tmp, tmp + G[x].size(), cmp);
//	for (int i = 0; i < G[x].size(); i++) printf("%d ", tmp[i].id);
//	printf("\n");
	for (int i = G[x].size() - 1; i >= 1; i--)
	{
		int V = tmp[i].id;
		to[EED[tmp[i - 1].id]] = V;
		for (int j = 1; j <= dep[EED[tmp[i - 1].id]] - dep[tmp[i - 1].id]; j++) ans[++cnt] = V;
		EED[tmp[i - 1].id] = EED[V];
	}
	for (int i = 1; i <= G[x].size() - 1; i++) ans[++cnt] = tmp[i].id;
	to[x] = tmp[0].id;
	EED[x] = EED[tmp[0].id];
	
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) to[i] = -1;
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &fa[i]);
		G[fa[i]].push_back(i);
	}
	dfs(0);
	int x = 0;
	while(to[x] != -1)
	{
		printf("%d ", x);
		x = to[x];
	}
	printf("%d\n", x);
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
	return 0;
}