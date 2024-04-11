#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int N = 1010;
int n, m;
vector<int> g[N];
bool used[N];
vector<int> a[N];
int k;
int w[N], c[N];
int dp[2][N];
int W;

void dfs(int v)
{
	a[k].push_back(v);
	used[v] = 1;
	for (int u : g[v])
		if (!used[u])
			dfs(u);
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &W);
	for (int i = 0; i < n; i++)
		scanf("%d", &w[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	while(m--)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	k = 0;
	for (int i = 0; i < n; i++)
	{
		if (used[i]) continue;
		dfs(i);
		k++;
	}
	for (int i = 0; i <= W; i++)
		dp[0][i] = -1;
	dp[0][0] = 0;
	for (int it = 0; it < k; it++)
	{
		for (int x = 0; x <= W; x++)
			dp[1][x] = dp[0][x];
		int t = 0, q = 0;
		for (int x : a[it])
		{
			t += w[x];
			q += c[x];
			for (int y = 0; y + w[x] <= W; y++)
				if (dp[0][y] >= 0)
					dp[1][y + w[x]] = max(dp[1][y + w[x]], dp[0][y] + c[x]);
		}
		for (int y = 0; y + t <= W; y++)
			if (dp[0][y] >= 0)
				dp[1][y + t] = max(dp[1][y + t], dp[0][y] + q);
		for (int x = 0; x <= W; x++)
			dp[0][x] = dp[1][x];
	}
	int ans = 0;
	for (int x = 0; x <= W; x++)
		ans = max(ans, dp[0][x]);
	printf("%d\n", ans);

	return 0;
}