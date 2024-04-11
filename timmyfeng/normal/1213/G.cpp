#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e5 + 1;
using ll = long long;

ll sz[MX], ans[MX], cur;
int par[MX];

int find(int a) {
	if (par[a] != a) {
		par[a] = find(par[a]);
	}
	return par[a];
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (a < b) {
		swap(a, b);
	}
	cur -= sz[b] * (sz[b] - 1) / 2 + sz[a] * (sz[a] - 1) / 2;
	par[a] = b;
	sz[b] += sz[a];
	cur += sz[b] * (sz[b] - 1) / 2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> edge;
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.emplace_back(w, u, v);
	}
	for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		edge.emplace_back(a, n + 1, i);
	}
	sort(edge.begin(), edge.end());

	iota(par, par + n + 1, 0);
	fill(sz, sz + n + 1, 1);
	for (auto [a, b, c] : edge) {
		if (b == n + 1) {
			ans[c] = cur;
		} else {
			unite(b, c);
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}