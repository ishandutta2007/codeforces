#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;

const int N = 100005, MOD = 1000000007;

vector<int> edge[N];

bool vis[N];

vector<int> stack;

int cnt, col[N];

const int LOG = 17;

int size[N][LOG], dep2[N];

void go(int u, int fa) {
	vis[u] = true;
	stack.push_back(u);
	for (int j = 0; j < (int)edge[u].size(); ++j) {
		int v = edge[u][j];
		if (v == fa) {
			continue;
		}
		if (vis[v]) {
			if (dep2[v] < dep2[u]) {
				size[cnt][0] = 1;
				col[u] = cnt;
				do {
					stack.pop_back();
					col[stack.back()] = cnt;
				} while (stack.back() != v);
				stack.pop_back();
				++cnt;
			}
		} else {
			dep2[v] = dep2[u] + 1;
			go(v, u);
		}
	}
	if (col[u] == -1) {
		col[u] = cnt++;
		stack.pop_back();
	}
}

vector<int> edge2[N];

int fa[N][LOG], dep[N];

void go2(int u) {
	for (int j = 0; j < (int)edge2[u].size(); ++j) {
		int v = edge2[u][j];
		if (v == fa[u][0]) {
			continue;
		}
		fa[v][0] = u;
		dep[v] = dep[u] + 1;
		go2(v);
	}
}

int lca(int u, int v, int &pow) {
	pow = 0;
	if (dep[u] < dep[v]) {
		swap(u, v);
	}
	int delta = dep[u] - dep[v];
	for (int i = LOG - 1; i >= 0; --i) {
		if (delta >> i & 1) {
			pow += size[u][i];
			u = fa[u][i];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = LOG - 1; i >= 0; --i) {
		if (fa[u][i] != fa[v][i]) {
			pow += size[u][i] + size[v][i];
			u = fa[u][i], v = fa[v][i];
		}
	}
	pow += size[u][0] + size[v][0];
	return fa[u][0];
}

int ans[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	memset(col, -1, sizeof(col));
	memset(vis, 0, sizeof(vis));

	go(0, -1);

	for (int i = 0; i < n; ++i) {
		int u = i;
		for (int j = 0; j < (int)edge[u].size(); ++j) {
			int v = edge[u][j];
			if (col[u] != col[v]) {
				edge2[col[u]].push_back(col[v]);
			}
		}
	}

	memset(fa, -1, sizeof(-1));
	go2(0);

	for (int i = 1; i < LOG; ++i) {
		for (int j = 0; j < cnt; ++j) {
			if (fa[j][i - 1] == -1) {
				fa[j][i] = -1;
				size[j][i] = size[j][i - 1];
			} else {
				fa[j][i] = fa[fa[j][i - 1]][i - 1];
				size[j][i] = size[fa[j][i - 1]][i - 1] + size[j][i - 1];
			}
		}
	}

	int q;
	scanf("%d", &q);
	ans[0] = 1;
	for (int i = 1; i <= n; ++i) {
		ans[i] = ans[i - 1] * 2 % MOD;
	}
	while (q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		if (col[u] == col[v]) {
			printf("%d\n", ans[size[col[u]][0]]);
		} else {
			int w, pow;
			w = lca(col[u], col[v], pow);
			pow += size[w][0];
			printf("%d\n", ans[pow]);
		}
	}
	return 0;
}