#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

const int N = 200111;

int n, m, sq, vis[N], dep[N], fa[N];
vector<int> g[N], ans[N];

void dfs(int v) {
	vis[v] = 1;
	ans[dep[v] % (sq - 1)].push_back(v);
	for (auto u : g[v]) {
		if (!vis[u]) {
			fa[u] = v;
			dep[u] = dep[v] + 1;
			dfs(u);
		}
		else if (dep[v] - dep[u] + 1 >= sq) {
			vector<int> cycle;
			while (v != fa[u]) {
				cycle.push_back(v);
				v = fa[v];
			}
			cout << "2\n" << cycle.size() << "\n";
			for (auto e : cycle)
				cout << e << " ";
			exit(0);
		}
	}
}

int main() {
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	sq = ceil(sqrt(n));
	dfs(1);
	int x = 0;
	rep(i, 1, sq - 2)
		if (ans[i].size() > ans[x].size())
			x = i;
	ans[x].resize(sq);
	cout << 1 << "\n";
	for (auto e : ans[x])
		cout << e << " ";
	return 0;
}