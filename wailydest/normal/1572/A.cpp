#include <cstdio>
#include <algorithm>
#include <vector>

const int N = 200000;
int t, n, ord[N], u[N], ans[N];
std::vector<int> g[N];

int dfs_t;
bool dfs(int v) 
{
	u[v] = 1;
	for (int i = 0; i < (int)g[v].size(); ++i) {
		if (u[g[v][i]] == 1) return false;
		if (!u[g[v][i]] && !dfs(g[v][i])) return false;
	}
	u[v] = 2;
	ord[dfs_t++] = v;
	return true;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		dfs_t = 0;
		for (int i = 0; i < n; ++i) {
			u[i] = 0;
			g[i].clear();
			int s;
			scanf("%d", &s);
			g[i].resize(s);
			for (int j = 0; j < s; ++j) {
				scanf("%d", &g[i][j]);
				--g[i][j];
			}
		}
		bool ok = true;
		for (int i = 0; i < n; ++i) if (!u[i] && !dfs(i)) ok = false;
		if (ok) {
			int ov = 0;
			for (int i = 0; i < n; ++i) {
				ans[ord[i]] = 1;
				for (int j = 0; j < (int)g[ord[i]].size(); ++j) {
					int val = ans[g[ord[i]][j]] + (g[ord[i]][j] > ord[i]);
					ans[ord[i]] = std::max(ans[ord[i]], val);
				}
				ov = std::max(ov, ans[ord[i]]);
			}
			printf("%d\n", ov);
		}
		else printf("-1\n");
	}
	return 0;
}