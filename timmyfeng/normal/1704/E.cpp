#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;

	while (t--) {
		int n, m; cin >> n >> m;

		vector<long long> a(n);
		for (auto &i : a) cin >> i;

		vector adj(n, vector<int>());
		while (m--) {
			int u, v; cin >> u >> v; --u, --v;
			adj[u].push_back(v);
		}

		long long answer = 0;
		while (*max_element(a.begin(), a.end()) && answer < n) {
			vector<long long> a_new = a;
			for (int i = 0; i < n; ++i) {
				if (a[i]) {
					--a_new[i];
					for (auto j : adj[i]) {
						++a_new[j];
					}
				}
			}
			swap(a, a_new);
			++answer;
		}

		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				if (adj[i].empty()) continue;
				for (auto j : adj[i]) {
					a[j] = (a[j] + a[i]) % M;
				}
				a[i] = 0;
			}
		}

		answer = (answer + *max_element(a.begin(), a.end())) % M;

		cout << answer << "\n";
	}
}