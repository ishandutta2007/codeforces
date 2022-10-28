#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e6 + 1;

int par[MX], sz[MX];
vector<int> pt[MX];

int find(int a) {
	if (a != par[a]) {
		par[a] = find(par[a]);
	}
	return par[a];
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (sz[a] > sz[b]) {
		swap(a, b);
	}
	par[a] = b;
	sz[b] += sz[a];
	
	if (pt[a].size() > pt[b].size()) {
		swap(pt[a], pt[b]);
	}
	while (!pt[a].empty()) {
		int u = pt[a].back();
		pt[a].pop_back();
		pt[b].push_back(u);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	iota(par, par + n + 1, 0);
	fill(sz, sz + n + 1, 1);

	map<int, int> id;
	for (int i = 1; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		pt[i] = {a, b};

		if (id[a]) {
			unite(i, id[a]);
		} else {
			id[a] = i;
		}

		if (id[b]) {
			unite(i, id[b]);
		} else {
			id[b] = i;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (find(i) != i)
			continue;
		sort(pt[i].begin(), pt[i].end());
		pt[i].erase(unique(pt[i].begin(), pt[i].end()), pt[i].end());
		if (sz[i] > (int)pt[i].size()) {
			cout << -1 << '\n';
			return 0;
		}
		ans = max(ans, pt[i][sz[i] - 1]);
	}
	cout << ans << '\n';
}