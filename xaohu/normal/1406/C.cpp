#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 100;

int n, leaf[N], siz[N], up[N];
vector <int> g[N];

void dfs(int v, int p) {
	//~ cout << v << endl;
	up[v] = p;
	siz[v] = 1;
	leaf[v] = -1;
	for (auto u : g[v])
		if (u != p) {
			dfs(u, v);
			leaf[v] = leaf[u];
			siz[v] += siz[u];
		}
	if (leaf[v] == -1) leaf[v] = v;
}

int main() {
	int q;
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; ++i) g[i].clear();
		for (int i = 1; i < n; ++i) {
			int a, b;
			scanf ("%d%d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		dfs(1, 0);
		int w = -1;
		for (int i = 1; i <= n; ++i)
			if (siz[i] == n - siz[i])
				w = i;
		if (w == -1) {
			printf ("%d %d\n%d %d\n", 1, g[1][0], 1, g[1][0]);
			continue;
		}
		else {
			int a = leaf[w], b = up[w];
			printf ("%d %d\n%d %d\n", a, up[a], a, b);
			continue;
		}	
	}
	
	return 0;
}