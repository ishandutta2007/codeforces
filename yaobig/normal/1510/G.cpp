#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void construct(int i, int& slack, vector<int>& res, const vector<bool>& spec, const vector<vector<int>>& g) {
	res.push_back(i);
	if (! spec[i]) --slack;

	for (auto t : g[i]) {
		if (! spec[t] && slack > 0) {
			construct(t, slack, res, spec, g);
			res.push_back(i);
		}
	}
	for (auto t : g[i]) {
		if (spec[t]) construct(t, slack, res, spec, g);
	}
}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<vector<int>> g(n);
	vector<int> par(n, -1);
	for (int i = 1; i < n; ++i) {
		cin >> par[i];
		--par[i];
		g[par[i]].push_back(i);
	}

	int t = 0;
	vector<int> dep(n, 0);
	for (int i = 1; i < n; ++i) {
		dep[i] = dep[par[i]] + 1;
		if (dep[i] > dep[t] && dep[i] < k) t = i;
	}
	int slack = k-1-dep[t];

	vector<bool> spec(n, 0);
	for (; t != -1; t = par[t]) spec[t] = 1;

	vector<int> res;
	construct(0, slack, res, spec, g);
	
	cout << res.size() - 1 << '\n';
	for (auto i : res) cout << i+1 << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}