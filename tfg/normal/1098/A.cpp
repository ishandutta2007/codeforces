#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdlib>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

std::vector<int> edges[ms];
int sum[ms];
int par[ms];


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int p;
		std::cin >> p;
		p--;
		edges[p].push_back(i);
		par[i] = p;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> sum[i];
	}
	const int INF = 2e9;
	for(int i = 0; i < n; i++) {
		if(sum[i] != -1) {
			continue;
		}
		sum[i] = sum[par[i]];
		for(auto to : edges[i]) {
			sum[i] = std::min(sum[i], sum[to]);
		}
		if(sum[i] < sum[par[i]]) {
			std::cout << "-1\n";
			return 0;
		}
		sum[i] = INF;
		for(auto to : edges[i]) {
			sum[i] = std::min(sum[i], sum[to]);
		}
		if(sum[i] >= INF) {
			sum[i] = sum[par[i]];
		}
	}
	long long ans = sum[0];
	for(int i = 1; i < n; i++) {
		ans += sum[i] - sum[par[i]];
	}
	std::cout << ans << '\n';
}