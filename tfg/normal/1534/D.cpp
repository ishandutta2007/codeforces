#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 2020;

bool visit[ms];
int n;
std::vector<std::pair<int, int>> ans;

std::vector<int> memo[ms];

std::vector<int> qry(int v) {
	if(!memo[v].empty()) return memo[v];
	std::cout << "? " << v+1 << std::endl;
	std::vector<int> dists(n);
	for(int i = 0; i < n; i++) {
		std::cin >> dists[i];
	}
	return memo[v] = dists;
}

void go(int on) {
	assert(!visit[on]);
	visit[on] = true;
	auto dists = qry(on);
	for(int i = 0; i < n; i++) {
		if(dists[i] == 1) {
			ans.emplace_back(i, on);
			visit[i] = true;
		}
	}
	for(int i = 0; i < n; i++) {
		if(dists[i] == 2 && !visit[i]) {
			go(i);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	int f[2] = {0, 0};
	auto dists = qry(0);
	for(int i = 0; i < n; i++) {
		f[dists[i] % 2]++;
	}
	if(f[0] <= f[1]) {
		go(0);
	} else {
		int id = 0;
		while(dists[id] % 2 == 0) id++;
		go(id);
	}
	std::cout << "!" << std::endl;
	assert((int) ans.size() == n - 1);
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i].first+1 << ' ' << ans[i].second+1 << std::endl;
	}
}