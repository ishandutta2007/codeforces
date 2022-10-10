#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<bool> prime(n+1, true);
	std::vector<int> largest(n+1, 1);
	std::vector<int> special;
	for(int i = 2; i <= n; i++) {
		if(!prime[i]) continue;
		if(n % i == 0) special.push_back(i);
		for(int j = i + i; j <= n; j += i) {
			prime[j] = false;
		}
		for(int j = i; j <= n; j += i) {
			largest[j] = i;
		}
	}
	prime[0] = prime[1] = false;
	std::vector<bool> good(n+1, false);
	int mn = n;
	for(int i = 4; i <= n; i++) {
		for(auto p : special) {
			int nxt = (i+p-1)/p*p;
			if(nxt == n) {
				good[i] = true;
			}
		}
		if(good[i] && !prime[i]) {
			mn = std::min(mn, i - largest[i] + 1);
		}
	}
	std::cout << mn << '\n';
}