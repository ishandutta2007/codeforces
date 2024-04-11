#include <cstdio>
#include <algorithm>
#include <vector>

const int N = 300000;
int t, n;
std::vector<int> g[N];

int dfs(int v, int pr = -1) {
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i] == pr) g[v].erase(g[v].begin() + i);
	if (g[v].size() < 2) return g[v].size();
	return std::min(dfs(g[v][0], v), dfs(g[v][1], v)) + 2;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i < n; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			g[a - 1].push_back(b - 1);
			g[b - 1].push_back(a - 1);
		}
		printf("%d\n", n - 1 - dfs(0));
		for (int i = 0; i < n; ++i) g[i].clear();
	}
	return 0;
}