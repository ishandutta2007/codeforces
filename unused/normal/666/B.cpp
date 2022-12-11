#include <stdio.h>
#include <tuple>
#include <string.h>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[3005];
int dist[3005][3005];
int n;

priority_queue<pair<int, int>> max1[3005], max2[3005];
vector<pair<int, int>> max11[3005], max12[3005];

bool visit[3005];

void bfs(int t)
{
	memset(visit + 1, 0, n);

	queue<int> que;
	visit[t] = true;
	dist[t][t] = 0;
	que.push(t);

	while (que.empty() == false)
	{
		auto x = que.front();
		que.pop();

		for (int nxt : graph[x])
		{
			if (visit[nxt]) continue;
			dist[t][nxt] = dist[t][x] + 1;
			visit[nxt] = true;
			que.push(nxt);
		}
	}
}

int main()
{
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dist[i][j] = 1e8;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		bfs(i);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (dist[i][j] < (int)1e7) max1[i].emplace(-dist[i][j], j);
			if (dist[j][i] < (int)1e7) max2[i].emplace(-dist[j][i], j);

			while (max1[i].size() > 2) max1[i].pop();
			while (max2[i].size() > 2) max2[i].pop();
		}
	}

	for (int i = 1; i <= n; i++)
	{
		while (max1[i].empty() == false)
		{
			max11[i].push_back(max1[i].top());
			max1[i].pop();
		}

		while (max2[i].empty() == false)
		{
			max12[i].push_back(max2[i].top());
			max2[i].pop();
		}
	}

	tuple<int, int, int, int> ans1;
	int maxdist = -1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (dist[i][j] >= (int)1e7) continue;

			for (int a = 0; a < max12[i].size(); a++)
			{
				for (int b = 0; b < max11[j].size(); b++)
				{
					if (max12[i][a].second == j ||
						max12[i][a].second == max11[j][b].second ||
						max11[j][b].second == i) continue;

					int total = dist[i][j] - max12[i][a].first - max11[j][b].first;
					if (total > maxdist)
					{
						maxdist = total;
						ans1 = make_tuple(max12[i][a].second, i, j, max11[j][b].second);
					}
				}
			}
		}
	}

	printf("%d %d %d %d", get<0>(ans1), get<1>(ans1), get<2>(ans1), get<3>(ans1));
}