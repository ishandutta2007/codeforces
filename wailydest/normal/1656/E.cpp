#include <cstdio>
#include <vector>

const int N = 100000;
int t, n, ans[N];
std::vector<int> g[N];

void dfs(int v, bool dep, int pr = -1) {
	int dg = 0;
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i] != pr) {
		dfs(g[v][i], !dep, v);
		++dg;
	}
	ans[v] = (dep ? -1 : 1) * (1 + dg);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n - 1; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			g[a - 1].push_back(b - 1);
			g[b - 1].push_back(a - 1);
		}
		dfs(0, 0);
		--ans[0];
		for (int i = 0; i < n; ++i) {
			printf("%d ", ans[i]);
			g[i].clear();
		}
		printf("\n");
	}
	return 0;
}