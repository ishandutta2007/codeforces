#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int ms = 300300;
	std::vector<bool> isPrime(ms, true);
	for(int i = 2; i < ms; i++) {
		if(!isPrime[i]) continue;
		for(int j = i+i; j < ms; j += i) {
			isPrime[j] = false;
		}
	}
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		char want;
		std::cin >> n >> want;
		std::string str;
		std::cin >> str;
		int bad = 0;
		for(auto ch : str) if(ch != want) {
			bad++;
		}
		if(bad == 0) {
			std::cout << "0\n";
			continue;
		}
		int kek = -1;
		for(int i = 2; i <= n; i++) {
			int gotBad = 0;
			for(int j = i-1; j < n; j += i) if(str[j] != want) {
				gotBad++;
			}
			if(gotBad == 0) {
				kek = i;
				break;
			}
		}
		if(kek != -1) {
			std::cout << "1\n" << kek << '\n';
		} else {
			std::cout << "2\n";
			for(int i = n, j = 2; j > 0; i--) {
				if(isPrime[i]) {
					j--;
					std::cout << i << (j == 0 ? '\n' : ' ');
				}
			}
		}
	}
}