#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100005];

int gc[100005];
int ec[100005];
int group[100005];
int foo[100005];
bool visited[100005];

void bfs(int i)
{
	group[i] = i;
	gc[i] = 1;
	visited[i] = true;
	queue<int> que;
	que.push(i);

	while (que.empty() == false)
	{
		int t = que.front();
		que.pop();

		for (int next : graph[t])
		{
			if (visited[next] == false)
			{
				visited[next] = true;
				group[next] = i;
				gc[i]++;
				que.push(next);
			}
		}
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			bfs(i);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		ec[group[i]] += graph[i].size();
	}

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		if (gc[i] == 0) continue;
		if (ec[i] == (gc[i] - 1) * 2) ans++;
	}
	printf("%d\n", ans);
}