#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int limit;
	std::string str;
	std::cin >> limit >> str;
	std::vector<int> freq(ms, 0);
	int n = (int) str.size();
	for(int i = 0; i < n; i++) {
		int sum = 0;
		for(int j = i; j < n; j++) {
			sum += str[j] - '0';
			freq[sum]++;
		}
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		int sum = 0;
		for(int j = i; j < n; j++) {
			sum += str[j] - '0';
			if(limit == 0) {
				if(sum == 0) {
					ans += n * (n+1) / 2;
				} else {
					ans += freq[0];
				}
			} else if(sum != 0 && limit % sum == 0 && limit / sum < ms) {
				ans += freq[limit / sum];
			}
		}
	}
	std::cout << ans << '\n';
}