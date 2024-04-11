#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int N = (int)2e5 + 200;
int n;
vector<int> g[N];
int h[N], sz[N];
int dp[N][2];

void dfs0(int v)
{
	sz[v] = (int)(g[v].size() == 0);
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int to = g[v][i];
		h[to] = h[v] + 1;
		dfs0(to);
		sz[v] += sz[to];
	}
	return;
}

void read()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
	}
	h[0] = 0;
	dfs0(0);
	return;
}

void dfs(int v)
{
	if (g[v].size() == 0)
	{
		dp[v][0] = dp[v][1] = 1;
		return;
	}
	if (h[v] % 2 == 0)
	{
		dp[v][0] = 0;
		dp[v][1] = sz[v];
		for (int i = 0; i < (int)g[v].size(); i++)
		{
			int to = g[v][i];
			dfs(to);
			dp[v][0] = max(dp[v][0], sz[v] - (sz[to] - dp[to][0]));
			dp[v][1] -= sz[to] - dp[to][1];
		}
	}
	else
	{
		dp[v][0] = 1;
		dp[v][1] = sz[v];
		for (int i = 0; i < (int)g[v].size(); i++)
		{
			int to = g[v][i];
			dfs(to);
			dp[v][0] += dp[to][0] - 1;
			dp[v][1] = min(dp[v][1], dp[to][1]);
		}
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	dfs(0);
	printf("%d %d\n", dp[0][0], dp[0][1]);

	return 0;
}