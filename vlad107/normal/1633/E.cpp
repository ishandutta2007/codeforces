#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <array>
#include <limits>

using namespace std;

struct Edge {
	int x, y, z;
};

struct Dsu {
	vector<int> parent;
	vector<int> sz;

	Dsu(int n) {
		sz.assign(n, 1);
		parent.resize(n);
		for (int i = 0; i < n; i++) parent[i] = i;
	}

	int findSet(int x) {
		if (x == parent[x]) {
			return x;
		}
		parent[x] = findSet(parent[x]);
		return parent[x];
	}

	void unionSets(int x, int y) {
		x = findSet(x);
		y = findSet(y);
		if (x != y) {
			if (sz[x] < sz[y]) {
				swap(x, y);
			}
			parent[y] = x;
			sz[x] += sz[y];
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<Edge> edges;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		--x; --y;
		edges.push_back(Edge {x, y, z});
	}
	sort(edges.begin(), edges.end(), [](const Edge &l, const Edge &r) {
		return l.z < r.z;
	});
	vector<pair<long long, int>> v;
	int nn = 0;
	vector<int> bases;
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			bases.push_back((edges[i].z + edges[j].z) / 2);
		}
	}
	bases.push_back(0);
	bases.push_back(1e8 + 1);
	sort(bases.begin(), bases.end());
	for (int baseZ : bases) {
		vector<pair<Edge, bool>> edges2;
		for (int i = 0; i < m; i++) {
			bool notLess = edges[i].z >= baseZ;
			int cc = notLess ? edges[i].z : -edges[i].z;
			edges2.emplace_back(Edge{edges[i].x, edges[i].y, cc}, notLess);
		}
		sort(edges2.begin(), edges2.end(), [&](const auto &l, const auto &r) {
			int c1 = abs(abs(l.first.z) - baseZ);
			int c2 = abs(abs(r.first.z) - baseZ);
			return ((c1 < c2) || ((c1 == c2) && (l.first.z < r.first.z)));
		});
		Dsu dsu(n);
		long long totalCost = 0;
		int totalNotLess = 0;
		nn = 0;
		for (int i = 0; i < m; i++) {
			int x = dsu.findSet(edges2[i].first.x);
			int y = dsu.findSet(edges2[i].first.y);
			if (x != y) {
				dsu.unionSets(x, y);
				totalCost += edges2[i].first.z;
				totalNotLess += edges2[i].second;
				++nn;
			}
		}
		long long cc = totalCost + (-totalNotLess + (nn - totalNotLess) * 1LL * baseZ);
		v.emplace_back(totalCost, totalNotLess);
	}
	int pp, k, a, b, c;
	cin >> pp >> k >> a >> b >> c;
	int q;
	long long res = 0;
	for (int i = 0; i < k; i++) {
		if (i < pp) {
			cin >> q;
		} else {
			q = (q * 1LL * a + b) % c;
		}
		int l = 0, r = bases.size() - 1;
		while (l < r - 1) {
			int m = (l + r) / 2;
			if (bases[m] < q) {
				l = m;
			} else {
				r = m;
			}
		}
		long long ans = v[r].first + (-v[r].second + (nn - v[r].second)) * 1LL * q;
		res ^= ans;
	}
	cout << res << endl;
	return 0;
}