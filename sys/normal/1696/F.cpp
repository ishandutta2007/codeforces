#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 105;
int T, n, fa[Maxn], Fa[Maxn], dis[Maxn][Maxn];
bool flag, vis[Maxn], s[Maxn][Maxn][Maxn];
vector <int> Ve[Maxn], G[Maxn];
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void dfs(int rt, int u, int fa)
{
	for (auto v : G[u])
		if (v != fa)
			dis[rt][v] = dis[rt][u] + 1, dfs(rt, v, u);
}
void test(int x)
{
	for (int i = 1; i <= n; i++) Ve[i].clear(), G[i].clear(), vis[i] = false;
	for (int i = 2; i <= n; i++)
		if (get_fa(i) == x) G[1].push_back(i), G[i].push_back(1), Ve[1].push_back(i), vis[i] = true, Fa[i] = 1;
	for (int d = 2; d <= n; d++)
	{
		for (auto u : Ve[d - 1])
			for (int i = 2; i <= n; i++)
				if (!vis[i] && s[i][Fa[u]][u]) Ve[d].push_back(i), vis[i] = true, Fa[i] = u, G[u].push_back(i), G[i].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			dis[i][j] = dis[j][i] = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0, dfs(i, i, 0);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (dis[i][j] == 0x3f3f3f3f) return ;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if ((dis[i][k] == dis[j][k]) != s[i][j][k]) return ;
	flag = true;
	puts("Yes");
	for (int i = 2; i <= n; i++)
		printf("%d %d\n", i, Fa[i]);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		flag = false;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
			{
				string str;
				cin >> str;
				for (int k = 0; k < n; k++)
					s[j][i][k + 1] = s[i][j][k + 1] = str[k] - '0';
			}
		for (int i = 2; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (s[i][j][1]) fa[get_fa(i)] = get_fa(j);
		for (int i = 2; i <= n; i++)
			if (!flag && get_fa(i) == i) test(i);
		if (!flag) puts("No");
	}
	return 0;
}