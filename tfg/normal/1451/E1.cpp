#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n, 0);
	std::map<int, int> mp;
	mp[0] = 0;
	int special = -1;
	for(int i = 1; i < n; i++) {
		std::cout << "XOR " << 1 << ' ' << i+1 << std::endl;
		std::cin >> a[i];
		if(special == -1 && mp.count(a[i])) {
			std::cout << "AND " << i+1 << ' ' << mp[a[i]]+1 << std::endl;
			std::cin >> special;
			special ^= a[i];
		} else {
			mp[a[i]] = i;
		}
	}
	if(special == -1) {
		special = 0;
		for(int i = 1; i < n; i++) {
			if(a[i] == 1 || a[i] == n-2) {
				std::cout << "AND 1 " << i+1 << std::endl;
				int x;
				std::cin >> x;
				special ^= x;
			}
		}
	}
	std::cout << "!";
	for(int i = 0; i < n; i++) {
		std::cout << ' ' << (special ^ a[i]);
	}
	std::cout << std::endl;
}