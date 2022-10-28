#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;

set<int> adj[MX];
long long a[MX];
int dist[MX];
int pre[MX];
int ans;
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	ans = 1e9;
	set<int> nodes;
	for (int i = 0; i <= 62; ++i) {
		vector<int> all;
		for (int j = 0; j < n; ++j) {
			if (a[j] & (1LL << i)) {
				all.push_back(j);
			}
		}
		if (all.size() >= 3u) {
			ans = 3;
		} else if (all.size() == 2u) {
			adj[all[0]].insert(all[1]);
			adj[all[1]].insert(all[0]);
			for (auto i : all) {
				nodes.insert(i);
			}
		}
	}

	for (auto i : nodes) {
		set<int> tmp = adj[i];
		for (auto j : tmp) {
			adj[i].erase(j);
			adj[j].erase(i);

			memset(dist, -1, sizeof dist);
			queue<int> que;
			que.push(i);
			dist[i] = 0;

			while (!que.empty()) {
				int u = que.front();
				que.pop();
				for (auto v : adj[u]) {
					if (dist[v] == -1) {
						dist[v] = dist[u] + 1;
						que.push(v);
					}
				}
			}

			if (dist[j] != -1) {
				ans = min(ans, dist[j] + 1);
			}
		}
	}
	cout << (ans == 1e9 ? -1 : ans) << "\n";
}