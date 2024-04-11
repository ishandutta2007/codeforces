#include <bits/stdc++.h>
using namespace std;
const int MX = 2e5;
set<int> adj[MX + 1];
vector<int> leaf;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}

	for (int i = 1; i <= n; ++i) {
		if (adj[i].size() == 1) {
			leaf.push_back(i);
		}
	}

	while (leaf.size() >= 2) {
		int a = leaf.back();
		leaf.pop_back();
		int b = leaf.back();
		leaf.pop_back();

		cout << "? " << a << ' ' << b << endl;
		int w;
		cin >> w;

		if (w == a || w == b) {
			cout << "! " << w << endl;
			return 0;
		}

		for (auto i : {a, b}) {
			int par = *adj[i].begin();
			adj[par].erase(i);
			if (adj[par].size() == 1) {
				leaf.push_back(par);
			}
		}
	}
	cout << "! " << leaf[0] << endl;
}