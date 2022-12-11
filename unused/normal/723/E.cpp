#include <stdio.h>
#include <set>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int graph[205][205];
int degree[205];
bool visit[205];
bool fake[205][205];
vector<pair<int, int>> ans;
int n;

void dfs(int t)
{
	for (int i = 1; i <= n; i++)
	{
		if (graph[t][i])
		{
			ans.emplace_back(t, i);

			graph[t][i]--;
			graph[i][t]--;
			degree[t]--;
			degree[i]--;

			dfs(i);
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int m;
		scanf("%d%d", &n, &m);

		for (int i = 1; i <= n; i++) degree[i] = 0;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) fake[i][j] = false;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) graph[i][j] = 0;
		ans.clear();

		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			graph[a][b]++;
			graph[b][a]++;
			degree[a]++; degree[b]++;
		}

		vector<int> odds;

		for (int i = 1; i <= n; i++)
		{
			if (degree[i] & 1)
			{
				odds.push_back(i);
				degree[i]++;
			}
		}

		printf("%d\n", n - (int)odds.size());

		for (int i = 0; i < odds.size(); i+=2)
		{
			graph[odds[i]][odds[i+1]]++;
			graph[odds[i+1]][odds[i]]++;

			fake[odds[i]][odds[i + 1]] = true;
		}

		for (int i = 1; i <= n; i++)
		{
			if (degree[i]) dfs(i);
		}

		for (auto &&e : ans)
		{
			auto &&b = fake[min(e.first, e.second)][max(e.first, e.second)];
			if (b) b = false;
			else printf("%d %d\n", e.first, e.second);
		}
	}
}