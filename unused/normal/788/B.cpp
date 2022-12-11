#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[1000005];
int degree[1000005];
bool visit[1000005];
bool evisit[1000005];
bool loop[1000005];

void dfs(int t)
{
	visit[t] = true;
	for (auto &e : graph[t])
	{
		evisit[e.second] = true;
		if (visit[e.first] == false) dfs(e.first);
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	if (m == 1)
	{
		printf("0\n");
		return 0;
	}

	int t = -1;
	int loops = 0;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == b) loop[a] = true, ++loops, graph[a].emplace_back(a, i);
		else {
			graph[a].emplace_back(b, i);
			graph[b].emplace_back(a, i);
		}
		t = a;
	}

	dfs(t);

	if (accumulate(evisit, evisit + m, 0) != m)
	{
		printf("0\n");
		return 0;
	}

	long long ans = 0;

	for (int i = 1; i <= n; i++)
	{
		ans += (graph[i].size() - loop[i]) * ((long long)graph[i].size() - 1 - loop[i]) / 2;
	}

	ans += loops * 1ll * (m - 1) - loops * (long long)(loops - 1) / 2;

	printf("%lld\n", ans);
}