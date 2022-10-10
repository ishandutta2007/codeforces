#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, s;
	std::cin >> n >> s;
	if(n == 2) {
		std::cout << s << '\n';
		return 0;
	}
	std::vector<int> deg(n, 0);
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		deg[u]++;
		deg[v]++;
	}
	int q = 0;
	for(int i = 0; i < n; i++) {
		if(deg[i] == 1) {
			q++;
		}
	}
	s *= 2;
	std::cout << s / q << '.';
	s %= q;
	for(int i = 0; i < 10; i++) {
		s *= 10;
		std::cout << s / q;
		s %= q;
	}
	std::cout << std::endl;
}