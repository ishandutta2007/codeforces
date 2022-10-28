#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5;

int par[MX + 1], sz[MX + 1], mx[MX + 1];

int find(int a) {
	if (par[a] == a) {
		return a;
	}
	return par[a] = find(par[a]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (sz[a] > sz[b]) {
			swap(a, b);
		}
		par[a] = b;
		sz[b] += sz[a];
		mx[b] = max(mx[b], mx[a]);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	iota(par + 1, par + 1 + n, 1);
	iota(mx + 1, mx + 1 + n, 1);
	fill(sz + 1, sz + 1 + n, 1);
	while (m--) {
		int u, v;
		cin >> u >> v;
		unite(u, v);
	}

	int far = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (i > far) {
			far = mx[find(i)];
		}
		if (find(i) != find(far)) {
			unite(i, far);
			far = mx[find(i)];
			++ans;
		}
	}
	cout << ans << '\n';
}