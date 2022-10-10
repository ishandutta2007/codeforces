#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <cstdlib>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200100;

std::vector<std::pair<int, int>> edges[ms];

// xi = a * xB + c
// xi = xB
// xj + xi = e
// xj = e - xi

bool visit[ms];
int ans[ms];
std::vector<int> comp;
void dfs(int on) {
	assert(!visit[on]);
	visit[on] = true;
	comp.push_back(on);
	for(auto e : edges[on]) {
		if(!visit[e.first]) {
			ans[e.first] = -ans[on] + e.second;
			dfs(e.first);
		} else if(ans[e.first] != -ans[on] + e.second) {
			std::cout << "NO\n";
			exit(0);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	while(m--) {
		int u, v, c;
		std::cin >> u >> v >> c;
		u--;v--;
		edges[2*u].emplace_back(2*v+1, c);
		edges[2*v].emplace_back(2*u+1, c);
		edges[2*u+1].emplace_back(2*v, c);
		edges[2*v+1].emplace_back(2*u, c);
	}
	for(int i = 0; i < n; i++) {
		if(visit[2*i]) {
			continue;
		}
		//std::cerr << "starting from " << i << std::endl;
		comp.clear();
		dfs(2*i);
		if(!visit[2*i+1]) {
			for(auto j : comp) {
				visit[j^1] = true;
			}
			std::vector<int> points;
			for(auto j : comp) {
				if(j % 2 == 0) {
					points.push_back(-ans[j]);
				} else {
					points.push_back(ans[j]);
				}
			}
			std::sort(points.begin(), points.end());
			int got = points[(int) points.size() / 2];
			for(auto j : comp) {
				if(j % 2 == 0) {
					ans[j] += got;
				} else {
					ans[j] -= got;
				}
				ans[j^1] = ans[j];
			}
		} else {
			//std::cerr << "is completely decided" << std::endl;
		}
	}
	std::cout << "YES\n";
	for(int i = 0; i < n; i++) {
		int got = ans[2*i] + ans[2*i+1];
		if(got < 0) {
			std::cout << '-';
			got = -got;
		}
		std::cout << got / 2 << "." << got % 2 * 5 << (i + 1 == n ? '\n' : ' ');
	}
}