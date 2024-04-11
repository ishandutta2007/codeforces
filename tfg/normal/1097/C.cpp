#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 500500;

int left[ms], right[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int good = 0;
	int n;
	std::cin >> n;
	while(n--) {
		std::string str;
		std::cin >> str;
		int bal = 0;
		for(int i = 0; i < (int) str.size() && bal >= 0; i++) {
			bal += str[i] == '(' ? 1 : -1;
		}
		//std::cout << "got " << str << "\n";
		if(bal == 0) {
			good++;
			//std::cout << bal << ", is balanced\n";
			continue;
		}
		if(bal > 0) {
			//std::cout << bal << ", is left ok\n";
			left[bal]++;
			continue;
		}
		bal = 0;
		for(int i = 0; i < (int) str.size() && bal >= 0; i++) {
			bal -= str[(int)str.size()-i-1] == '(' ? 1 : -1;
		}
		if(bal > 0) {
			//std::cout << bal << ", is right ok\n";
			right[bal]++;
		}
	}
	int ans = good / 2;
	for(int i = 0; i < ms; i++) {
		ans += std::min(left[i], right[i]);
	}
	std::cout << ans << '\n';
}