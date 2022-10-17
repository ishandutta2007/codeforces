#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define maxn 200005
using namespace std;
int n, k, x, y;
vector<int> G[maxn];
int siz[maxn], id[maxn], dep[maxn];
inline int cmp(int x, int y)
{
	return dep[x] - siz[x] > dep[y] - siz[y]; 
}
void dfs(int x, int fa)
{
	dep[x] = dep[fa] + 1;
	siz[x] = 1;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		dfs(V, x);
		siz[x] += siz[V];
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	long long ans = 0;
	for (int i = 1; i <= k; i++)
	{
		ans += dep[id[i]] - siz[id[i]];
	}
	printf("%lld\n", ans);
	return 0;
}