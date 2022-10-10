#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

std::vector<int> edges[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	std::vector<int> leaf, other;
	for(int i = 0; i < n; i++) {
		if((int) edges[i].size() == 1) {
			leaf.push_back(i);
		} else {
			other.push_back(i);
		}
	}
	std::vector<bool> good(n, false);
	std::vector<int> cnt(n, 0);
	for(auto x : leaf) {
		good[x] = true;
		cnt[edges[x][0]]++;
	}
	int got = 0;
	bool ans = n != 3;
	for(auto x : other) {
		good[x] = cnt[x] >= 2;
		if(good[x]) {
			got++;
		} else {
			ans = ans && (int) edges[x].size() >= 3;
		}
	}
	std::cout << (ans ? "YES\n" : "NO\n");
}