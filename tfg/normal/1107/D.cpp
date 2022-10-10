#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <bitset>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool isPrime(int x) {
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::bitset<5200>> mat(n);
	int mask;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(j % 4 == 0) {
				char c;
				std::cin >> c;
				if('0' <= c && c <= '9') {
					mask = c - '0';
				} else {
					mask = c - 'A' + 10;
				}
			}
			mat[i][j] = (mask >> 3) & 1;
			mask <<= 1;
		}
	}
	auto check = [&](int x) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(mat[i][j] != mat[i/x*x][j/x*x]) {
					return false;
				}
			}
		}
		return true;
	};
	int ans = 1;
	for(int i = 2; i <= n; i++) {
		if(!isPrime(i)) {
			continue;
		}
		while(n % (ans * i) == 0 && check(ans * i)) {
			ans *= i;
		}
	}
	std::cout << ans << '\n';
}