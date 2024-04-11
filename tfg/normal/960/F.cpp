#include <iostream>
#include <set>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

const int ms = 100100;

struct BIT {
	std::vector<int> coords;
	std::vector<int> bit;

	void init() {
		std::sort(coords.begin(), coords.end());
		bit.assign(coords.size() + 1, 0);
	}

	void upd(int x, int v) {
		x = std::upper_bound(coords.begin(), coords.end(), x) - coords.begin();
		for(; x < bit.size(); x += x & -x) {
			bit[x] = std::max(bit[x], v);
		}
	}

	int qry(int x) {
		int ans = 0;
		x = std::upper_bound(coords.begin(), coords.end(), x) - coords.begin();
		for(; x > 0; x -= x & -x) {
			ans = std::max(ans, bit[x]);
		}
		return ans;
	}
};

BIT bits[ms];

int from[ms], to[ms], w[ms];

int main() {
	int n, m;
	std::cin >> n >> m;
	int ans = 0;
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", from + i, to + i, w + i);
		bits[from[i]].coords.push_back(w[i] - 1);
		bits[from[i]].coords.push_back(w[i]);
		bits[from[i]].coords.push_back(w[i] + 1);
		bits[to[i]].coords.push_back(w[i] - 1);
		bits[to[i]].coords.push_back(w[i]);
		bits[to[i]].coords.push_back(w[i] + 1);
	}
	for(int i = 1; i <= n; i++) {
		bits[i].init();
	}
	for(int i = 0; i < m; i++) {
		int got = bits[from[i]].qry(w[i] - 1);
		ans = std::max(ans, got + 1);
		bits[to[i]].upd(w[i], got + 1);
	}
	std::cout << ans << '\n';
}