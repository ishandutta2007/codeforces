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
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<array<int, 3>> edges;
		int maxW = 0;
		for (int i = 0; i < m; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			maxW = max(maxW, w);
			--x; --y;
			edges.push_back({x, y, w});
		}
		int pw = 0;
		while ((1<<pw) <= maxW) ++pw;
		int res = 0;
		for (int i = pw - 1; i >= 0; i--) {
			vector<array<int, 3>> edges2;
			Dsu dsu(n);
			int cntEdges = 0;
			for (auto edge : edges) {
				if ((edge[2] & (1<<i)) == 0) {
					int x = dsu.findSet(edge[0]);
					int y = dsu.findSet(edge[1]);
					if (x != y) {
						++cntEdges;
						dsu.unionSets(x, y);
					}
					edges2.push_back(edge);
				}
			}
			if (cntEdges == n - 1) {
				edges = edges2;
			} else {
				res |= (1<<i);
			}
		}
		cout << res << "\n";
	}
	return 0;
}