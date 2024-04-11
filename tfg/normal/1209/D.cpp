#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int par[200200];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
bool makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	par[a] = b;
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		par[i] = i;
	}
	int ans = 0;
	for(int i = 0; i < k; i++) {
		int u, v;
		std::cin >> u >> v;
		makeUnion(u-1, v-1);
	}
	ans = n;
	for(int i = 0; i < n; i++) {
		if(par[i] == i) {
			ans--;
		}
	}
	std::cout << k - ans << std::endl;
}