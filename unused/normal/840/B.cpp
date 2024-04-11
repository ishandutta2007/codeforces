#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[300005];
int d[300005];
int degree[300005];
bool ans[300005];
int n, m;

bool visit[300005];
pair<int, int> parent[300005];

void dfs(int t)
{
	visit[t] = true;

	for (auto &e : graph[t])
	{
		if (visit[e.first]) continue;
		parent[e.first] = { t, e.second };
		degree[t]++;
		dfs(e.first);
	}
}

int main()
{
	scanf("%d%d", &n, &m);

	int minus = -1;

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
		if (d[i] == -1)
		{
			if (minus == -1) minus = i;
			else d[i] = 0;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].emplace_back(b, i);
		graph[b].emplace_back(a, i);
	}

	if (minus > 0)
	{
		int sum = 0;
		for (int i = 1; i <= n; i++) if (i != minus) sum ^= d[i];
		d[minus] = sum;
	}
	else
	{
		int sum = 0;
		for (int i = 1; i <= n; i++) sum ^= d[i];
		if (sum == 1)
		{
			printf("-1\n");
			return 0;
		}
	}

	dfs(1);

	queue<int> que;
	for (int i = 1; i <= n; i++) if (degree[i] == 0) que.push(i);

	while (que.empty() == false)
	{
		int t = que.front(); que.pop();
		if (d[t] == 1)
		{
			ans[parent[t].second] = true;
			d[parent[t].first] ^= 1;
		}

		if (--degree[parent[t].first] == 0) que.push(parent[t].first);
	}

	if (ans[0]) for (;;);

	printf("%d\n", accumulate(ans + 1, ans + 1 + m, 0));
	for (int i = 1; i <= m; i++) if (ans[i]) printf("%d\n", i);
}