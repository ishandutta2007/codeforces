#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	vector<int> p(n);
	vector<vector<int>> adj(n);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		p[i] = a % 2;
		if (i - a >= 0) {
			adj[i - a].push_back(i);
		}
		if (i + a < n) {
			adj[i + a].push_back(i);
		}
	}

	vector<int> ans(n);
	for (int i = 0; i <= 1; ++i) {
		queue<int> bfs;
		for (int j = 0; j < n; ++j) {
			if (p[j] == i) {
				bfs.push(j);
			}
		}
		while (!bfs.empty()) {
			int u = bfs.front();
			bfs.pop();
			for (auto c : adj[u]) {
				if (p[c] != i && !ans[c]) {
					ans[c] = (p[u] == i ? 1 : ans[u] + 1);
					bfs.push(c);
				}
			}
		}
	}

	for (auto i : ans) {
		cout << (i ? i : -1) << ' ';
	}
	cout << '\n';
}