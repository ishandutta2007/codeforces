#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 1e5 + 1;

int dsu[MX], a[MX];

int find(int a) {
	if (dsu[a] < 0)
		return a;
	dsu[a] = find(dsu[a]);
	return dsu[a];
}

void unite(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)
		return;
	if (dsu[u] < dsu[v]) {
		swap(u, v);
	}
	dsu[v] += dsu[u];
	dsu[u] = v;
	a[v] = min(a[v], a[u]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	memset(dsu, -1, sizeof dsu);
	while (m--) {
		int u, v;
		cin >> u >> v;
		unite(u, v);
	}

	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (dsu[i] < 0) {
			ans += a[i];
		}
	}
	cout << ans << '\n';
}