#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;

int par[MX + 1], sz[MX + 1];

int find(int a) {
	if (a == par[a]) return a;
	return par[a] = find(par[a]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[a] > sz[b]) {
		swap(a, b);
	}
	par[a] = b;
	sz[b] += sz[a];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	iota(par + 1, par + 1 + n, 1);
	fill(sz + 1, sz + 1 + n, 1);

	vector<pair<int, int>> qry;
	while (m--) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t) {
			for (int i = a + 1; i <= b; ++i) {
				unite(i, a);
			}
		} else {
			qry.emplace_back(a, b);
		}
	}

	for (auto [a, b] : qry) {
		if (find(a) == find(b)) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
	for (int i = 1; i <= n; ++i) {
		cout << n + 1 - find(i) << ' ';
	}
	cout << '\n';
}