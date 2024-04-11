#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int n, u, r;
int a[30], b[30], k[30], p[30];
int val[101][30];

long long bf(int on, bool canXor) {
	long long ans = -1e18;
	if(on == u) {
		ans = 0;
		for(int i = 0; i < n; i++) {
			ans += (long long) k[i] * val[on][i];
		}
		return ans;
	}
	if((u - on) % 2 == 0) {
		ans = 0;
		for(int i = 0; i < n; i++) {
			ans += (long long) k[i] * val[on][i];
		}
	}
	if(canXor) {
		for(int i = 0; i < n; i++) {
			val[on+1][i] = val[on][i] ^ b[i];
		}
		ans = std::max(ans, bf(on+1, false));
	}
	for(int i = 0; i < n; i++) {
		val[on+1][i] = val[on][p[i]] + r;
	}
	ans = std::max(ans, bf(on+1, true));
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> u >> r;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	for(int i = 0; i < n; i++) {
		std::cin >> k[i];
	}
	for(int i = 0; i < n; i++) {
		std::cin >> p[i];
		p[i]--;
	}
	for(int i = 0; i < n; i++) {
		val[0][i] = a[i];
	}
	std::cout << bf(0, true) << '\n';
}