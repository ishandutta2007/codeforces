#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	int k;
	std::cin >> str >> k;
	int n = (int) str.size();
	for(int i = 0; i < n; i++) {
		for(int j = 9; j >= 0; j--) {
			int pos = i;
			while(pos < n && str[pos] != char('0' + j)) pos++;
			if(pos - i <= k && pos != n) {
				k -= pos - i;
				while(pos > i) {
					pos--;
					std::swap(str[pos], str[pos+1]);
				}
				break;
			}
		}
	}
	std::cout << str << '\n';
}