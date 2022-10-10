#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

std::vector<int> edges[ms];
int freq[ms], size[ms], deg[ms];

void dfs(int on) {
	for(auto to : edges[on]) {
		dfs(to);
		size[on] += size[to];
	}
	if(size[on] == 0) {
		size[on]++;
	}
	freq[size[on]]++;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int p;
		std::cin >> p;
		edges[p-1].push_back(i);
		deg[p-1]++;
		deg[i]++;
	}
	dfs(0);
	int pt = 0;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		while(sum < i) {
			sum += freq[pt++];
		}
		std::cout << pt - 1 << (i == n ? '\n' : ' ');
	}
}