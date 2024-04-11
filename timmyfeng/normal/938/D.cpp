#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 2e5 + 1;

vector<pair<int, ll>> adj[MX];
ll a[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, 2 * w);
		adj[v].emplace_back(u, 2 * w);
	}

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pq.emplace(a[i], i);
	}

	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (d > a[u]) 
			continue;
		for (auto [v, w] : adj[u]) {
			if (d + w < a[v]) {
				a[v] = d + w;
				pq.emplace(a[v], v);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}