#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200005;

int n, k;

int a[N];

vector<int> edge[N], child[N];

vector<int> ord;

int fa[N], size[N];

void dfs(int u) {
	ord.push_back(u);
	size[u] = 1;
	for (int i = 0; i < (int)edge[u].size(); ++i) {
		int v = edge[u][i];
		if (v == fa[u]) {
			continue;
		}
		fa[v] = u;
		child[u].push_back(v);
		dfs(v);
		size[u] += size[v];
	}
}

int ans[N], best[N], bak[N], baks[N];

int check(int bar) {
	for (int i = n - 1; i >= 0; --i) {
		int u = ord[i];
		if (a[u] < bar) {
			ans[u] = 0;
			best[u] = -1;
			bak[u] = -1;
			baks[u] = 0;
		} else {
			ans[u] = 1;
			best[u] = -1;
			bak[u] = -1;
			baks[u] = 0;
			for (int j = 0; j < (int)child[u].size(); ++j) {
				int v = child[u][j];
				if (ans[v] == size[v]) {
					ans[u] += size[v];
				} else {
					if (best[u] == -1 || ans[v] > ans[best[u]]) {
						bak[u] = best[u];
						baks[u] = ans[bak[u]];
						best[u] = v;
					} else if (bak[u] == -1 || ans[v] > ans[bak[u]]) {
						bak[u] = v;
						baks[u] = ans[bak[u]];
					}
				}
			}
			if (best[u] != -1) {
				ans[u] += ans[best[u]];
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		int u = ord[i], tmp;
		if (u == 0) {
			tmp = ans[u];
		} else {
			if (ans[u] == 0) {
				tmp = 0;	
			} else if (ans[fa[u]] == 0) {
				tmp = ans[u];
			} else {
				if (ans[u] == size[u]) {
					tmp = ans[u] = ans[fa[u]];
				} else {
					if (best[fa[u]] == u && bak[fa[u]] == -1) {
						tmp = ans[u] = ans[fa[u]];
					} else {
						int ansp;
						if (best[fa[u]] == u) {
							ansp = ans[fa[u]] - ans[u] + baks[fa[u]];
						} else {
							ansp = ans[fa[u]];
						}
						if (ansp > ans[best[u]]) {
							tmp = ans[u] = ans[u] - ans[best[u]] + ansp;
							bak[u] = best[u];
							baks[u] = ans[bak[u]];
							best[u] = fa[u];
						} else {
							if (ansp > ans[bak[u]]) {
								bak[u] = fa[u];
								baks[u] = ansp;
							}
							tmp = ans[u];
						}
					}
				}
			}
		}
		ret = max(ret, tmp);
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &k);
	vector<int> val;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		val.push_back(a[i]);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	fa[0] = -1;
	dfs(0);
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	int l = 0, r = val.size() - 1;
	while (l < r) {
		int m = (l + r + 1) >> 1;
		if (check(val[m]) >= k) {
			l = m;
		} else {
			r = m - 1;
		}
	}
	printf("%d\n", val[l]);
	return 0;
}