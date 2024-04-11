#include "bits/stdc++.h"
using namespace std;

int dat[200005];
int par[200005][20];
vector<pair<int,int>> child[200005];
long long dist[200005];
int sum[200005];

void dfs(int t)
{
	for (auto &e : child[t])
	{
		dist[e.first] = dist[t] + e.second;
		dfs(e.first);
	}
}

void dfs2(int t)
{
	for (auto &e : child[t])
	{
		dfs2(e.first);
		sum[t] += sum[e.first];
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d",&dat[i]);
	}

	for (int i = 2; i <= n; i++)
	{
		int cost;
		scanf("%d%d",&par[i][0], &cost);
		child[par[i][0]].emplace_back(i, cost);
	}

	par[1][0] = 1;

	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			par[j][i] = par[par[j][i-1]][i-1];
		}
	}

	dfs(1);

	for (int i = 2; i <= n; i++)
	{
		int j = i;
		for (int t = 18; t >= 0; t--)
		{
			if (dist[i] - dist[par[j][t]] <= dat[i])
				j = par[j][t];
		}

		sum[par[i][0]]++;
		if (j != 1) sum[par[j][0]]--;
	}

	dfs2(1);

	for (int i = 1; i <= n; i++) printf("%d ", sum[i]);
}