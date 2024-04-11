#include <cstdio>
#include <vector>

const int N = 200000;
std::vector<int> g[N];
int n, ans, t, l[N], r[N];

long long dfs(int v) {
	long long sum = 0;
	for (int i = 0; i < (int)g[v].size(); ++i) sum += dfs(g[v][i]);
	if (sum < l[v]) {
		++ans;
		return r[v];
	}
	if (sum > r[v]) return r[v];
	return sum;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) g[i].clear();
		for (int i = 1; i < n; ++i) {
			int p;
			scanf("%d", &p);
			g[p - 1].push_back(i);
		}
		for (int i = 0; i < n; ++i) scanf("%d%d", l + i, r + i);
		ans = 0;
		dfs(0);
		printf("%d\n", ans);
	}
	return 0;
}