#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int par[2020];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
void makeUnion(int a, int b) {
	a = getPar(a), b = getPar(b);
	par[a] = b;
}
int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		par[i] = i;
	}
	for(int i = 0; i + k <= n; i++) {
		for(int j = 0; j < k / 2; j++) {
			makeUnion(i + j, i + k - 1 - j);
		}
	}
	const int MOD = 1e9 + 7;
	long long ans = 1;
	for(int i = 0; i < n; i++) {
		if(par[i] == i) {
			ans = ans * m % MOD;
		}
	}
	std::cout << ans << std::endl;
}