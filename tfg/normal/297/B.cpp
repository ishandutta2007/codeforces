#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, trash;
	std::cin >> n >> m >> trash;
	std::map<int, int> f;
	while(n--) {
		int x;
		std::cin >> x;
		f[x]++;
	}
	while(m--) {
		int x;
		std::cin >> x;
		f[x]--;
	}
	long long ans = 0;
	for(auto it : f) {
		ans = std::max(ans + it.second, (long long) it.second);
	}
	std::cout << (ans > 0 ? "YES\n" : "NO\n");
}