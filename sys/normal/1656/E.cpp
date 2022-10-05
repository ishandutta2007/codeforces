#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, T, S, tot[Maxn], a[Maxn];
vector <int> G[Maxn];
void dfs(int u, int fa, bool flag)
{
	a[u] = flag ? G[u].size() : -G[u].size();
	for (auto v : G[u])
		if (v != fa) dfs(v, u, flag ^ 1);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			G[x].push_back(y), G[y].push_back(x); 
		}
		dfs(1, 0, 0);
		for (int i = 1; i <= n; i++)
			printf("%d ", a[i]);
		puts("");
	}
	return 0;
}