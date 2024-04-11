#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, T, f[Maxn], d[Maxn], l[Maxn], r[Maxn];
vector <int> G[Maxn];
void dfs(int u)
{
	d[u] = f[u] = 0;
	for (auto v : G[u])
	{
		dfs(v);
		d[u] = min(r[u], d[u] + d[v]);
		f[u] += f[v];
	}
	if (d[u] < l[u]) f[u]++, d[u] = r[u];
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 2; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			G[x].push_back(i);
		}
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &l[i], &r[i]);
		dfs(1);
		printf("%d\n", f[1]);
	}
	return 0;
}