#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5;
const int R = 1500;

tuple<int, int, int> ques[MX];
int par[MX + 1], sz[MX + 1]; 
vector<pair<int, int>> stk;

int find(int a, bool r) {
	if (par[a] == a) return a;
	return r ? find(par[a], r) : par[a] = find(par[a], r);
}

void unite(int a, int b, bool r) {
	a = find(a, r);
	b = find(b, r);
	if (a == b) return;
	if (sz[a] > sz[b]) {
		swap(a, b);
	}
	par[a] = b;
	sz[b] += sz[a];
	if (r) {
		stk.emplace_back(a, b);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		auto& [t, u, v] = ques[i];
		cin >> t >> u >> v;
		if (u > v) {
			swap(u, v);
		}
	}

	bool last = 0;
	set<pair<int, int>> ten, edge;
	for (int i = 0; i < m; ++i) {
		if (i % R == 0) {
			ten.clear();
			set<pair<int, int>> may;
			for (int j = i; j < i + R && j < m; ++j) {
				auto [t, u, v] = ques[j];
				if (t == 1) {
					may.emplace(u, v);
					may.emplace(u % n + 1, v % n + 1);
				}
			}
			fill(sz + 1, sz + 1 + n, 1);
			iota(par + 1, par + 1 + n, 1);
			for (auto e : edge) {
				if (may.count(e)) {
					ten.insert(e);
				} else {
					unite(e.first, e.second, false);
				}
			}
		}
		
		auto [t, u, v] = ques[i];
		if (last) {
			u = u % n + 1;
			v = v % n + 1;
			if (u > v) {
				swap(u, v);
			}
		}

		if (t == 1) {
			if (ten.count({u, v})) {
				ten.erase({u, v});
				edge.erase({u, v});
			} else {
				ten.emplace(u, v);
				edge.emplace(u, v);
			}
		} else {
			for (auto [a, b] : ten) {
				unite(a, b, true);
			}
			last = (find(u, true) == find(v, true));
			cout << last;
			while (!stk.empty()) {
				auto [a, b] = stk.back();
				stk.pop_back();
				sz[b] -= sz[a];
				par[a] = a;
			}
		}
	}
	cout << '\n';
}