#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> edges(m);
	std::vector<int> p(m);
	for(int i = 0; i < m; i++) {
		std::cin >> edges[i].first >> edges[i].second;
		edges[i].second = -edges[i].second;
		p[i] = i;
	}
	std::sort(p.begin(), p.end(), [&](int a, int b) { return edges[a] < edges[b]; });
	int got = 1;
	std::vector<int> pt(n, 1);
	for(int i = 0; i < n; i++) {
		pt[i] = i + 2;
	}
	int all = 0;
	for(auto e : p) {
		if(edges[e].second == -1) {
			edges[e] = std::pair<int, int>(got - 1, got);
			got++;
			all = 0;
		} else {
			while(all < got && pt[all] >= got) {
				all++;
			}
			if(all == got) {
				std::cout << "-1\n";
				return 0;
			}
			assert(0 <= std::min(all, pt[all]) && std::max(all, pt[all]) < n);
			edges[e] = std::pair<int, int>(all, pt[all]);
			pt[all]++;
		}
	}
	assert(got == n);
	auto ed = edges;
	std::sort(ed.begin(), ed.end());
	for(int i = 0; i < m; i++) {
		if(i) {
			assert(ed[i] != ed[i-1]);
		}
		std::cout << edges[i].first + 1 << ' ' << edges[i].second + 1 << '\n';
	}
}