#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200005];
int col[200005];
int md;

void dfs(int t, int p, int c, int cp)
{
	col[t] = c;
	int nc = 1;
	while (nc == c || nc == cp) ++nc;
	for (int nxt : graph[t])
	{
		if (nxt == p) continue;
		dfs(nxt, t, nc, col[t]);
		++nc;
		while (nc == c || nc == cp) ++nc;
	}
}

int main()
{
	int n;
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
		md = max(md, (int)graph[i].size());
	}

	printf("%d\n", md + 1);
	dfs(1, -1, 1, 0);
	for (int i = 1; i <= n; i++) printf("%d ", col[i]);
}