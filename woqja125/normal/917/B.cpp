#include<cstdio>
#include<vector>
using namespace std;
int dp[101][101][26]; // 1 : win x, 2 : win y
vector<pair<int, int>> map[101];
int dfs(int x, int y, int v) {
	if (dp[x][y][v] != 0) return dp[x][y][v];
	for (auto e : map[x]) {
		if (e.second < v) continue;
		int t = dfs(y, e.first, e.second);
		if (t == 2) return dp[x][y][v] = 1;
	}
	return dp[x][y][v] = 2;
}
int main() {
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		char t[5];
		scanf("%d%d%s", &a, &b, t);
		map[a].emplace_back(b, t[0] - 'a');
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%c", dfs(i, j, 0) == 1 ? 'A' : 'B');
		printf("\n");
	}
	return 0;
}