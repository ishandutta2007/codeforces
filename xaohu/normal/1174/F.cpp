#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

const int N = 200111;

int n, sz[N], big[N], fa[N], dep[N];
vector<int> g[N];

int ask(int x, char c) {
	cout << c << " " << x << endl;
	cin >> x;
	return x;
}

void ans(int x) {
	cout << "! " << x << endl;
	exit(0);
}

void dfs(int v) {
	sz[v] = 1;
	for (auto u : g[v]) {
		if (u != fa[v]) {
			dep[u] = dep[v] + 1;
			fa[u] = v;
			dfs(u);
			sz[v] += sz[u];
			if (sz[u] > sz[big[v]])
				big[v] = u;
		}
	}
}
			

int main() {
	cin >> n;
	rep(i, 1, n - 1) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
	int d = ask(1, 'd'), v = 1;
	while (1) {
		if (dep[v] == d)
			ans(v);
		while (big[v])
			v = big[v];
		int lca = (dep[v] + d - ask(v, 'd')) / 2;
		while (dep[v] > lca)
			v = fa[v];
		if (dep[v] == d)
			ans(v);
		v = ask(v, 's');
	}
	return 0;
}