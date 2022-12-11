#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200005];
vector<int> dfsorder;
bool visit[200005];

void dfs(int t)
{
	visit[t] = true;
	dfsorder.push_back(t);
	for (int nxt : graph[t])
	{
		if (visit[nxt]) continue;
		dfs(nxt);
		dfsorder.push_back(t);
	}
}

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == b) continue;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	int cnt = dfsorder.size() / k;
	for (int i = 0, last = 0; i < k; i++)
	{
		int z = cnt + (dfsorder.size() % k > i);
		printf("%d ", z);
		while (z--) printf("%d ", dfsorder[last++]);
		printf("\n");
	}
}