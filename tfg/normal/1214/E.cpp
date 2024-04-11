#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> d(n);
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		std::cin >> d[i];
		p[i] = i;
	}
	std::sort(p.rbegin(), p.rend(), [&](int a, int b) { return d[a] < d[b]; });
	std::vector<std::vector<int>> layers(d[p[0]]+1);
	//std::cout << "size is " << layers.size() << '\n';
	layers[0].push_back(2*p[0]);
	layers.back().push_back(2*p[0]+1);
	std::vector<std::pair<int, int>> edges;
	std::vector<std::pair<int, int>> special;
	for(int i = 1; i < n; i++) {
		int r = d[p[0]]-i;
		// connect shit to r
		//std::cout << "trying to connect " << p[i] << " to " << r << ", id should be " << d[p[i]] - 1 - r << "\n";
		if(r > 0 && 0 <= d[p[i]] - 1 - r && d[p[i]] - 1 - r < (int) layers[0].size()) {
			int id = d[p[i]] - 1 - r;
			if(id+1 == (int) layers[0].size()) {
				//std::cout << "first case\n";
				layers[0].push_back(2*p[i]);
				layers[r].push_back(2*p[i]+1);
			} else {
				//std::cout << "second case\n";
				edges.emplace_back(2*p[i], layers[0][id]);
				layers[r].push_back(2*p[i]+1);
			}
		} else if(r > 0) {
			int id = r - d[p[i]] + 1;
			assert(0 <= id && id <= r);
			layers[r].push_back(2*p[i]+1);
			special.emplace_back(2*p[i], id);
		} else if(d[p[i]] == 1) {
			layers[0].push_back(2*p[i]);
			layers[0].push_back(2*p[i]+1);
		} else {
			edges.emplace_back(2*p[i], layers[0][0]);
			edges.emplace_back(2*p[i]+1, layers[0][d[p[i]]-2]);
		}
	}
	for(int i = 0; i < (int) layers.size(); i++) {
		//std::cout << "at layer " << i << " we have:";
		for(int j = 0; j+1 < (int) layers[i].size(); j++) {
			//std::cout << ' ' << layers[i][j];
			edges.emplace_back(layers[i][j], layers[i][j+1]);
		}
		//std::cout << ' ' << layers[i].back() << std::endl;
		if(i) {
			edges.emplace_back(layers[i][0], layers[i-1][0]);
		}
	}
	for(auto s : special) {
		edges.emplace_back(s.first, layers[s.second][0]);
	}
	for(auto e : edges) {
		std::cout << e.first + 1 << ' ' << e.second + 1 << '\n';
	}
}