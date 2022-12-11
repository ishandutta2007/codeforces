#include <bits/stdc++.h>
using namespace std;

int up[100005];
int parent[100005];
int dat[100005];
vector<int> graph[100005];
int degree[100005];
int force[100005];
bool chosen[100005];
queue<int> leafs;

void dfs(int t)
{
	if (graph[t].empty())
	{
		leafs.push(t);
	}

	for (int nxt : graph[t])
	{
		dfs(nxt);
	}
}

vector<int> present;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		parent[b] = a;
	}

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &dat[i]);
		chosen[dat[i]] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		if (parent[i] == 0)
		{
			dfs(i);
		}

		while (leafs.empty() == false)
		{
			int t = leafs.front(); leafs.pop();
			if (chosen[t]) present.push_back(t);

			if (parent[t] && ++degree[parent[t]] == graph[parent[t]].size())
			{
				leafs.push(parent[t]);
			}

			int now;
			for (now = t; force[now] == 0 && now != dat[t]; now = parent[now])
				;

			if (force[now] && force[now] != dat[t])
			{
				printf("-1\n");
				return 0;
			}

			for (int now2 = t; force[now2] == 0 && now2 != now; now2 = parent[now2])
			{
				force[now2] = dat[t];
			}

			if (force[dat[t]] != dat[t])
			{
				force[dat[t]] = dat[t];
			}
		}
	}

	printf("%zd\n", present.size());
	for (int t : present) printf("%d\n", t);
}