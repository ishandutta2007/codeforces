#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n;
	std::string str;
	std::cin >> n >> str;
	for(int i = 0; i + 11 <= n; i++) {
		if(str[i] == '8') {
			std::cout << "YES\n";
			return;
		}
	}
	std::cout << "NO\n";
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}