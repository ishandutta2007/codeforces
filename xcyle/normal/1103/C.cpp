#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 250005 
using namespace std;
int n, m, k, x, y;
vector<int> G[maxn], T[maxn];
int vis[maxn], fa[maxn], dep[maxn];
int leaf[maxn];
void dfs(int x)
{
	leaf[x] = 1;
	vis[x] = 1;
	dep[x] = dep[fa[x]] + 1;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(vis[V]) continue;
		fa[V] = x;
		dfs(V);
		leaf[x] = 0;
	}
}
void work(int x, int aim)
{
	while(x != aim)
	{
		printf("%d ", x);
		x = fa[x];
	}
	printf("%d ", aim);
}
int main()
{
	int cnt = 0;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if(!vis[i]) dfs(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if(dep[i] > (n - 1) / k + 1)
		{
			printf("PATH\n");
			printf("%d\n", dep[i]);
			int x = i;
			while(x)
			{
				printf("%d ", x);
				x = fa[x];
			}
			return 0;
		}
	}
	printf("CYCLES\n");
	for (int i = 1; i <= n; i++)
	{
		if(leaf[i])
		{
			int V1 = 0, V2 = 0;
			for (int j = 0; j < G[i].size(); j++)
			{
				int V = G[i][j];
				if(V == fa[i]) continue;
				if(!V1) V1 = V;
				else V2 = V;
			}
			if(dep[V1] < dep[V2]) swap(V1, V2);
			if((dep[i] - dep[V1] + 1) % 3 != 0)
			{
				printf("%d\n", dep[i] - dep[V1] + 1);
				work(i, V1);
				printf("\n");
			}
			else if((dep[i] - dep[V2] + 1) % 3 != 0)
			{
				printf("%d\n", dep[i] - dep[V2] + 1);
				work(i, V2);
				printf("\n");
			}
			else
			{
				printf("%d\n", dep[V1] - dep[V2] + 2);
				work(V1, V2);
				printf("%d\n", i);
			}
			cnt++;
			if(cnt == k) return 0;
		}
	}
	return 0;
}