#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 100005
using namespace std;
int t, n, u, v;
long long l[maxn], r[maxn], f[maxn][2];
vector<int> G[maxn];
inline long long Abs(long long x)
{
	return x >= 0 ? x : -x ;
}
void dfs(int x, int fa)
{
	f[x][0] = f[x][1] = 0;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		dfs(V, x);
		f[x][0] += max(f[V][0] + Abs(l[V] - l[x]), f[V][1] + Abs(r[V] - l[x]));
		f[x][1] += max(f[V][0] + Abs(l[V] - r[x]), f[V][1] + Abs(r[V] - r[x]));
	}
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
			scanf("%lld%lld", &l[i], &r[i]);
		}
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 0);
		printf("%lld\n", max(f[1][0], f[1][1]));
	}
	return 0;
}