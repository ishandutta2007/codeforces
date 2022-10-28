#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 3e5 + 1;

vector<pair<int, int>> adj[MX];
bool vstd[MX];
int n;

vector<ll> bfs(int s) {
	vector<ll> dist(n + 1, -1);
	dist[s] = 0;
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (auto [c, w] : adj[u]) {
			if (dist[c] == -1) {
				dist[c] = dist[u] + w;
				que.push(c);
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int m;
	cin >> n >> m;
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	vector<ll> dist_1 = bfs(1);
	vector<ll> dist_n = bfs(n);

	vector<pair<ll, int>> pos_1;
	multiset<ll> pos_n;
	for (int i = 1; i <= n; ++i) {
		pos_1.emplace_back(dist_1[i] - dist_n[i], i);
		pos_n.insert(dist_n[i]);
	}
	sort(pos_1.begin(), pos_1.end());

	ll mx_dist = 0;
	for (auto [ignore, u] : pos_1) {
		vstd[u] = true;
		pos_n.erase(pos_n.find(dist_n[u]));
		for (auto [v, ignore] : adj[u]) {
			if (!vstd[v]) {
				pos_n.erase(pos_n.find(dist_n[v]));
			}
		}
		if (!pos_n.empty()) {
			mx_dist = max(mx_dist, dist_1[u] + *pos_n.rbegin());
		}
		for (auto [v, ignore] : adj[u]) {
			if (!vstd[v]) {
				pos_n.insert(dist_n[v]);
			}
		}
	}

	while (m--) {
		int x;
		cin >> x;
		cout << min(mx_dist + x, dist_1[n]) << '\n';
	}
}