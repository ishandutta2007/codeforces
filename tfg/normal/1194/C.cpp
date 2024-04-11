#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int tt;
	std::cin >> tt;
	while(tt--) {
		std::string s, p;
		std::string t;
		std::cin >> s >> t >> p;
		int on = 0;
		for(auto c : s) {
			while(on < (int) t.size() && t[on] != c) {
				on++;
			}
			if(on == (int) t.size()) {
				on = -1;
				break;
			}
			on++;
		}
		if(on == -1) {
			std::cout << "NO\n";
			continue;
		}
		std::vector<int> freq(26, 0);
		for(auto c : s) {
			freq[c-'a']--;
		}
		for(auto c : t) {
			freq[c-'a']++;
		}
		for(auto c : p) {
			freq[c-'a']--;
		}
		on = 0;
		for(auto c : freq) {
			on = std::max(on, c);
		}
		std::cout << (on == 0 ? "YES\n" : "NO\n");
	}
}