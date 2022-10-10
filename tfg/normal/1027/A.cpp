#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::string str;
		std::cin >> n >> str;
		bool valid = true;
		for(int i = 0; i < n / 2; i++) {
			if(str[i] < str[n-i-1]) std::swap(str[i], str[n-i-1]);
			int delta = str[i] - str[n-i-1];
			if(delta == 2) {
				str[i]--, str[n-i-1]++;
			} else if(delta != 0) {
				valid = false;
			} else if(str[i] == 'a') {
				str[i]++, str[n-i-1]++;
			} else {
				str[i]--, str[n-i-1]--;
			}
		}
		std::cout << (valid ? "YES\n" : "NO\n");
	}
}