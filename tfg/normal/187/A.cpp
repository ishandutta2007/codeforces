#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		std::cin >> p[i];
		p[i]--;
	}
	std::vector<int> inv(n);
	for(int i = 0; i < n; i++) {
		int v;
		std::cin >> v;
		v--;
		inv[v] = i;
	}
	int on = -1;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int to = inv[p[i]];
		if(to > on) {
			on = to;
		} else {
			on = n;
			ans++;
		}
	}
	std::cout << ans << '\n';
}