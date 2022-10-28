#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<ll> bal(n + 1);
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		bal[u] -= w;
		bal[v] += w;
	}

	int j = 1;
	vector<tuple<int, int, ll>> ans;
	for (int i = 1; i <= n; ++i) {
		while (bal[i] > 0) {
			while (bal[j] >= 0) {
				++j;
			}
			ll z = min(bal[i], -bal[j]);
			ans.emplace_back(j, i, z);
			bal[i] -= z;
			bal[j] += z;
		}
	}

	cout << ans.size() << "\n";
	for (auto [a, b, c] : ans) {
		cout << a << " " << b << " " << c << "\n";
	}
}