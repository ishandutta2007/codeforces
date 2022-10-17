#include <cstdio>
#include <algorithm>
#include <vector>

const int N = 100005;
int t, n, ans[N], b[N];
std::vector<int> g[N];

bool cmp(int a, int b) {
	return g[a].size() < g[b].size();
}

int it, cnt;
void dfs(int v, bool dep) {
	cnt += dep;
	std::sort(g[v].begin(), g[v].end(), cmp);
	for (int i = 0; i < (int)g[v].size(); ++i) {
		ans[it++] = g[v][i];
		dfs(g[v][i], !dep);
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i <= n; ++i) g[i].clear();
		bool z = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", b + i);
			if (!b[i]) {
				g[0].push_back(i);
				z = 1;
			} else if (b[i] == n + 1) g[0].push_back(i);
			else g[b[i]].push_back(i);
		}
		it = cnt = 0;
		dfs(0, 0);
		printf("%d\n", z ? n - cnt : cnt);
		for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}