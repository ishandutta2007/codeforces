#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		std::set<int> wtf;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			wtf.insert(a[i]);
		}
		std::vector<int> sum(1, 0);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < (1 << i); j++) {
				sum.push_back(sum[j] + a[i]);
			}
		}
		bool good = false;
		for(int mask = 1; mask < (1 << n) && !good; mask++) {
			for(int sub = mask; sub; sub = (sub - 1) & mask) {
				if(sum[mask ^ sub] - sum[sub] == 0) {
					good = true;
					break;
				}
			}
		}
		std::cout << (good ? "YES\n" : "NO\n");
	}
}