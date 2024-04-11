#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[33];
pair<long long, long long> ans[33];
int pdr[33];
int parent[33];
int dr[4][2]=
{
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}
};

void dfs(int node, int len)
{
	int p = 0;
	for (int nxt : graph[node])
	{
		if (nxt == parent[node]) continue;
		if (p == pdr[node]) ++p;

		ans[nxt] = { ans[node].first + dr[p][0] * len, ans[node].second + dr[p][1] * len };
		pdr[nxt] = (p + 2) % 4;
		parent[nxt] = node;
		dfs(nxt, len / 2);
		++p;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		if (graph[i].size() > 4)
		{
			printf("NO\n");
			return 0;
		}
	}

	pdr[1] = -1;
	dfs(1, (1LL << 31) - 1);

	printf("YES\n");
	for (int i = 1; i <= n; i++) printf("%lld %lld\n", ans[i].first, ans[i].second);
}