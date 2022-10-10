#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	long long sum = 0;
	int mx = 0;
	while(n--) {
		int x;
		std::cin >> x;
		sum += x;
		mx = std::max(mx, x);
	}
	if(mx + mx <= sum && sum % 2 == 0) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}