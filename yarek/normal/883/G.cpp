#include <bits/stdc++.h>
using namespace std;

const int N = 300001;
vector<int> g[2][N];
set<pair<int, int>> edges;
bool vis[N];

int dfs(int v, int k)
{
	vis[v] = true;
	int ans = 1;
	for(int i = 0; i < k; i++)
		for(auto u: g[i][v])
			if(!vis[u])
			{
				edges.insert(make_pair(v, u));
				ans += dfs(u, k);
			}
	return ans;
}

int main()
{
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
	vector<pair<int, int>> undir;
	while(m--)
	{
		int t, u, v;
		scanf("%d %d %d", &t, &u, &v);
		if(t == 2) undir.emplace_back(u, v);
		for(int j = 0; j < t; j++)
		{
			g[t-1][u].push_back(v);
			swap(u, v);
		}
	}
	printf("%d\n", dfs(s, 2));
	for(auto p: undir)
		putchar(edges.count(p) ? '+' : '-');
	puts("");
	for(int i = 1; i <= n; i++)
		vis[i] = false;
	printf("%d\n", dfs(s, 1));
	for(auto p: undir)
		putchar(vis[p.first] && !vis[p.second] ? '-' : '+');
	puts("");
}