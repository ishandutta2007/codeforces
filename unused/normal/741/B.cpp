#include <bits/stdc++.h>
using namespace std;

int weight[1005];
int beauty[1005];
list<int> group[1005];
int parent[1005];

int getp(int a)
{
	return a != parent[a] ? (parent[a] = getp(parent[a])) : a;
}

void merge(int a, int b)
{
	int pa = getp(a);
	int pb = getp(b);
	if (pa == pb) return;

	parent[pa] = pb;
	group[pb].splice(group[pb].end(), group[pa]);
}

vector<int> gs;

int dp[1005][1005];

int main()
{
	int n, m, w;
	scanf("%d%d%d", &n, &m, &w);

	for (int i = 0; i < n; i++) group[i].push_back(i), parent[i] = i;
	for (int i = 0; i < n; i++) scanf("%d", &weight[i]);
	for (int i = 0; i < n; i++) scanf("%d", &beauty[i]);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		merge(a - 1, b - 1);
	}

	for (int i = 0; i < n; i++)
	{
		if (group[i].empty()) continue;
		gs.push_back(i);
	}

	for (int i = 0; i < gs.size(); i++)
	{
		for (int j = 0; j <= w; j++) dp[i + 1][j] = dp[i][j];
		int totalw = 0, totalb = 0;

		for (int t : group[gs[i]])
		{
			totalw += weight[t];
			totalb += beauty[t];

			for (int j = weight[t]; j <= w; j++)
			{
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - weight[t]] + beauty[t]);
			}
		}

		for (int j = totalw; j <= w; j++)
		{
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - totalw] + totalb);
		}
	}

	printf("%d", dp[gs.size()][w]);
}