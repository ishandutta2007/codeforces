#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll x, y;
const int INF = (int)1e7;
const int N = 200200;
int n;
vector<int> g[N];
int deg[N];
int dp[N][2];
bool used[N];

ll solveEasy()
{
	int val = n;
	for (int i = 0; i < n; i++)
	{
		int d = n - 1 - (int)g[i].size();
		val = min(val, d);
	}
	if (val == 0)
		return (n - 2) * y + x;
	else
		return (n - 1) * y;
}

void dfs(int v)
{
	used[v] = 1;
	int sum = 0;
	int delta1 = INF, delta2 = INF;
	for (int u : g[v])
	{
		if (used[u]) continue;
		dfs(u);
		sum += dp[u][0];
		int d = dp[u][1] - dp[u][0];
		if (d < delta1)
		{
			delta2 = delta1;
			delta1 = d;
		}
		else if (d < delta2)
			delta2 = d;
	}
	dp[v][1] = min(sum + 1, sum + delta1);
	dp[v][0] = min(dp[v][1], sum + delta1 + delta2 - 1);
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld%lld", &n, &x, &y);
	for (int i = 1; i < n; i++)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	if (x >= y)
	{
		printf("%lld\n", solveEasy());
		return 0;
	}
	dfs(0);
//	for (int i = 0; i < n; i++)
//		printf("%d %d\n", dp[i][0], dp[i][1]);
	printf("%lld\n", (n - dp[0][0]) * x + (dp[0][0] - 1) * y);

	return 0;
}