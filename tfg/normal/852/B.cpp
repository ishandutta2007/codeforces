#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

std::vector<int> mul(std::vector<int> &a, std::vector<int> &b) {
	int n = (int) a.size();
	std::vector<int> c(n, 0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			c[(i+j)%n] = (int)((c[(i+j)%n] + (long long) a[i] * b[j]) % MOD);
		}
	}
	return c;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, l, m;
	std::cin >> n >> l >> m;
	std::vector<int> paths(m, 0);
	std::vector<std::vector<int>> costs(3, std::vector<int>(n, 0));
	for(int j = 0; j < 3; j++) {
		for(int i = 0; i < n; i++) {
			std::cin >> costs[j][i];
		}
	}
	for(int i = 0; i < n; i++) {
		paths[costs[0][i] % m]++;
	}
	std::vector<int> poly(m, 0);
	for(int i = 0; i < n; i++) {
		poly[costs[1][i] % m] = (poly[costs[1][i] % m] + 1) % MOD;
	}
	for(int e = l-2; e > 0; e /= 2) {
		if(e & 1) {
			paths = mul(paths, poly);
		}
		poly = mul(poly, poly);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int cur = (costs[1][i] + costs[2][i]) % m;
		cur = (m - cur) % m;
		ans = (ans + paths[cur]) % MOD;
	}
	std::cout << ans << std::endl;
}