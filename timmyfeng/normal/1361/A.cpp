#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	while (m--) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> w(n);
	vector<pair<int, int>> blogs(n);
	for (int i = 0; i < n; ++i) {
		cin >> blogs[i].first;
		blogs[i].second = i;
	}
	sort(blogs.begin(), blogs.end());

	bool ok = true;
	for (auto b : blogs) {
		int d, u;
		tie(d, u) = b;
		set<int> cnt;
		for (auto v : adj[u]) {
			cnt.insert(w[v]);
		}
		int j = 1;
		while (cnt.count(j)) {
			++j;
		}
		ok &= (j == d);
		w[u] = d;
	}

	if (!ok) {
		cout << -1 << '\n';
		return 0;
	}

	for (auto i : blogs) {
		cout << i.second + 1 << ' ';
	}
	cout << '\n';
}