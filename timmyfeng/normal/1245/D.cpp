#include <bits/stdc++.h>
using namespace std;

int par[2001], sz[2001];

int find(int a) {
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (sz[a] > sz[b]) swap(a, b);
		sz[b] += sz[a];
		par[a] = b;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> x(n), y(n), c(n), k(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	for (auto& i : c) {
		cin >> i;
	}
	for (auto& i : k) {
		cin >> i;
	}

	vector<tuple<long long, int, int>> edge;
	for (int i = 0; i < n; ++i) {
		edge.emplace_back(c[i], n, i);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			edge.emplace_back((long long)(abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]), i, j);
		}
	}
	sort(edge.begin(), edge.end());

	vector<int> sta;
	vector<pair<int, int>> con;
	iota(par, par + 1 + n, 0);
	fill(sz, sz + 1 + n, 1);
	long long ans = 0;
	int ct = 0;
	for (auto [w, u, v] : edge) {
		if (find(u) == find(v)) continue;
		++ct;
		ans += w;
		unite(u, v);
		if (u == n) {
			sta.push_back(v + 1);
		} else {
			con.emplace_back(u + 1, v + 1);
		}
	}

	cout << ans << '\n';
	cout << sta.size() << '\n';
	for (auto i : sta) {
		cout << i << ' ';
	}
	cout << '\n';
	cout << con.size() << '\n';
	for (auto [u, v] : con) {
		cout << u << ' ' << v << '\n';
	}
}