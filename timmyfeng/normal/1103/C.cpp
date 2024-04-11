#include <bits/stdc++.h>
using namespace std;

const int N = 250000 + 1;

vector<vector<int>> cycles;
vector<int> adj[N];
int color[N];
int dep[N];
int par[N];
int n, k;

void dfs(int u) {
	color[u] = 1;

	int a = 0;
	int b = 0;
	bool leaf = true;
	for (int c : adj[u]) {
		if (c != par[u]) {
			if (color[c] == 1) {
				if (!a) {
					a = c;
				} else if (!b) {
					b = c;
				}
			} else if (!color[c]) {
				leaf = false;
				dep[c] = dep[u] + 1;
				par[c] = u;
				dfs(c);
			}
		}
	}

	if (leaf) {
		if (dep[u] >= (n - 1) / k) {
			cout << "PATH\n";
			cout << dep[u] + 1 << "\n";
			while (u != 1) {
				cout << u << " ";
				u = par[u];
			}
			cout << 1 << "\n";
			exit(0);
		}

		if (dep[a] < dep[b]) {
			swap(a, b);
		}

		vector<int> cycle;
		if ((dep[u] - dep[a] + 1) % 3) {
			b = a;
			a = u;
		} else if ((dep[u] - dep[b] + 1) % 3) {
			a = u;
		} else {
			cycle.push_back(u);
		}

		while (a != b) {
			cycle.push_back(a);
			a = par[a];
		}
		cycle.push_back(b);
		cycles.push_back(cycle);
	}
	color[u] = 2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> n >> m >> k;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	cout << "CYCLES\n";
	cycles.resize(k);
	for (vector<int>& i : cycles) {
		cout << i.size() << "\n";
		for (int j : i) {
			cout << j << " ";
		}
		cout << "\n";
	}
}