#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5;
int par[MX], sz[MX];

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
	
	iota(par, par + n, 0);
	fill(sz, sz + n, 1);
	for (int j = 0; j < m; ++j) {
		int k;
		cin >> k;
		if (!k) continue;
		int f;
		cin >> f;
		for (int i = 1; i < k; ++i) {
			int a;
			cin >> a;
			unite(f - 1, a - 1);
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << sz[find(i)] << ' ';
	}
	cout << '\n';
}