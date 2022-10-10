#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		std::string str;
		std::cin >> str;
		std::vector<int> pos;
		int ans = (int) str.size();
		for(int i = 0; i < (int) str.size(); i++) {
			if(str[i] == '1') pos.push_back(i);
		}
		if(pos.empty()) ans = 0;
		for(int i = 0; i < (int) pos.size() && i < 1; i++) {
			for(int j = (int) pos.size(); j <= (int) pos.size(); j++) {
				ans = std::min(ans, pos[j-1] - pos[i] + 1 - (j-i) + ((int) pos.size() - (j-i)));
			}
		}
		std::cout << ans << std::endl;
	}
}