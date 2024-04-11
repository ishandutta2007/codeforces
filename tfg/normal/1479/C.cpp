#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Edge {
	Edge() {}
	Edge(int a, int b, int co) : u(a), v(b), c(co) {}
	int u, v, c;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	// 1 can get 0
	// 2 can get 1
	// 3 can get 2
	// 4 can get 4
	// and so on
	int l, r;
	std::cin >> l >> r;
	int n = 22;
	std::vector<Edge> edges;
	std::vector<int> dp(n, 0);
	dp[n-1] = 1;
	for(int i = n-1; i > 0; i--) {
		int got = 0;
		for(int j = n-1; j > i; j--) {
			edges.emplace_back(i, j, std::max(got, 1));
			got += dp[j];
			dp[i] += dp[j];
		}
		//std::cout << "at " << i << " got " << got << '\n';
	}
	for(int i = 1; i+1 < n; i++) {
		if(dp[i] <= r - l) {
			edges.emplace_back(0, i, r - dp[i]);
			r -= dp[i];
		}
	}
	assert(l == r);
	edges.emplace_back(0, n-1, l);
	std::cout << "YES\n";
	std::cout << n << ' ' << edges.size() << '\n';
	for(auto e : edges) {
		std::cout << e.u+1 << ' ' << e.v+1 << ' ' << e.c << '\n';
	}
}