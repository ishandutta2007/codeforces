#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
int color[100005];
int parent[100005];
int gs[100005];

int getp(int t)
{
	return t == parent[t] ? t : (parent[t] = getp(parent[t]));
}

void merge(int a, int b)
{
	parent[getp(a)] = getp(b);
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

	for (int i = 1; i <= n; i++) {
		scanf("%d", &color[i]); parent[i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int nxt : graph[i])
		{
			if (color[i] == color[nxt]) merge(i, nxt);
		}
	}

	for (int i = 1; i <= n; i++) gs[getp(i)] ++;

	for (int i = 1; i <= n; i++)
	{
		int total = gs[getp(i)];
		for (int nxt : graph[i])
		{
			if (color[nxt] == color[i]) continue;
			total += gs[getp(nxt)];
		}

		if (total == n)
		{
			printf("YES\n%d\n", i);
			return 0;
		}
	}
	printf("NO\n");
}