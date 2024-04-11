#include <vector>
#include <algorithm>
#include <stdio.h>
#include <set>
#include <string.h>
#include <queue>
using namespace std;

vector<int> graph[200005];
vector<int> child[200005];
int parent[200005];
int back[200005];
int sum[200005];
bool visit[200005];
bool iscand[200005];
int dist[200005];

long long ans;
int root;

int Sum(int t)
{
	if (sum[t] == -1)
	{
		sum[t] = iscand[t];
		for (int next : child[t]) sum[t] += Sum(next);
	}
	return sum[t];
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);

	fill(sum + 1, sum + 1 + n, -1);

	for (int i = 0; i < 2 * k; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		iscand[tmp] = true;
	}

	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	queue<int> que;
	visit[1] = true;
	que.push(1);
	int last;
	while (que.empty() == false)
	{
		last = que.front();
		que.pop();
		for (int next : graph[last])
		{
			if (!visit[next]) visit[next] = true, que.push(next);
		}
	}

	memset(visit, 0, sizeof(visit));
	visit[last] = true;
	que.push(last);
	back[last] = -1;
	int last2;
	while (que.empty() == false)
	{
		last2 = que.front();
		que.pop();
		for (int next : graph[last2])
		{
			if (!visit[next]) visit[next] = true, back[next] = last2, que.push(next);
		}
	}

	vector<int> paths;
	paths.push_back(last2);

	while (back[last2] != -1)
	{
		last2 = back[last2];
		paths.push_back(last2);
	}

	int root = paths[paths.size() / 2];

	memset(visit, 0, sizeof(visit));
	visit[root] = true;
	parent[root] = -1;
	que.push(root);
	while (que.empty() == false)
	{
		int t = que.front();
		que.pop();

		for (int next : graph[t])
		{
			if (visit[next]) continue;
			child[t].push_back(next);
			parent[next] = t;
			visit[next] = true;
			que.push(next);
		}
	}

	int ptr = root;
	for (bool flag = true; flag;)
	{
		flag = false;
		for (int next : child[ptr])
		{
			if (Sum(next) >= k)
			{
				ptr = next;
				flag = true;
				break;
			}
		}
	}

	memset(visit, 0, sizeof(visit));
	visit[ptr] = true;
	que.push(ptr);
	while (que.empty() == false)
	{
		int t = que.front();
		que.pop();
		if (iscand[t]) ans += dist[t];

		for (int next : graph[t])
		{
			if (visit[next]) continue;
			dist[next] = dist[t] + 1;
			visit[next] = true;
			que.push(next);
		}
	}

	printf("%lld\n", ans);
}