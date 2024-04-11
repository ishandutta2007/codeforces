#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m, W, M, w[1005], b[1005], sumw[1005], sumb[1005], color[1005], f[1005][1005];
vector<int> g[1005];
vector<int> G[1005];
void dfs(int x) {
	G[color[x] = m].push_back(x);
	sumw[m] += w[x];
	sumb[m] += b[x];
	for (unsigned int i = 0; i < g[x].size(); ++i)
		if (!color[g[x][i]]) dfs(g[x][i]);
}
int main(){
	scanf("%d%d%d", &n, &M, &W);
	for (int i = 1; i <= n; ++i)
		scanf("%d", w + i);
	for (int i = 1; i <= n; ++i)
		scanf("%d", b + i);
	for (int i = 1; i <= M; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		if (!color[i]) {
			++m;
			dfs(i);
		}

	f[0][0] = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j <= W; ++j) f[i][j] = f[i - 1][j];
		for (int j = sumw[i]; j <= W; ++j)
			f[i][j] = max(f[i - 1][j - sumw[i]] + sumb[i], f[i][j]);
		for (unsigned int k = 0; k < G[i].size(); ++k) {
			int x = G[i][k];
			for (int j = w[x]; j <= W; ++j)
				f[i][j] = max(f[i - 1][j - w[x]] + b[x], f[i][j]);
		}
	}
	printf("%d\n", f[m][W]);
}