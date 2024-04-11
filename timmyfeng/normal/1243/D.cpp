#include <bits/stdc++.h>
using namespace std;

map<int, int> rt;
set<int> rem;
int par[100001], sz[100001];
vector<int> far[100001];

int find(int a) {
	if (a == par[a]) return a;
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
		rem.insert(a);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		far[u].push_back(v);
		far[v].push_back(u);
	}
	
	for (int i = 1; i <= n; ++i) {
		rt[i] = 0;
	}
	iota(par + 1, par + 1 + n, 1);
	fill(sz + 1, sz + 1 + n, 1);
	for (int i = 1; i <= n; ++i) {
		for (auto j : far[i]) {
			++rt[find(j)];
		}
		for (auto& j : rt) {
			if (j.second < sz[j.first]) {
				unite(j.first, i);
			}
			j.second = 0;
		}
		for (auto i : rem) {
			rt.erase(i);
		}
		rem.clear();
	}
	cout << rt.size() - 1 << '\n';	
}