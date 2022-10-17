#include <cstdio>
#include <vector>
using namespace std;

const int N = 200;

int n, k;
int w[N];
vector<int> g[N];
int dp[N][N + 1];

void dfs(int v, int prev = -1) 
{
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != prev) {
			dfs(g[v][i], v);
			dp[v][0] += dp[g[v][i]][k - 1];
		}
	}
	dp[v][0] += w[v];
	for (int i = k - 1; i > 0; --i) {
		int sum = 0;
		for (int j = 0; j < g[v].size(); ++j) if (g[v][j] != prev) {
			sum += dp[g[v][j]][max(k - i - 1, i - 1)];
		}
		for (int j = 0; j < g[v].size(); ++j) if (g[v][j] != prev) {
			dp[v][i] = max(dp[v][i], sum - dp[g[v][j]][max(k - i - 1, i - 1)] + dp[g[v][j]][i - 1]);
		}
		if (i != k - 1 && dp[v][i + 1] > dp[v][i]) dp[v][i] = dp[v][i + 1];
	}
	if (dp[v][0] < dp[v][1]) dp[v][0] = dp[v][1];
}

int main() 
{
	scanf("%d%d", &n, &k);
	++k;
	for (int i = 0; i < n; ++i) scanf("%d", w + i);
	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d%d", &a, &b);
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	dfs(0);
	int mx = 0;
	printf("%d\n", dp[0][0]);
	return 0;
}