#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string s, t;
	std::cin >> s >> t;
	bool valid = s.size() == t.size();
	for(int i = 0; valid && i < (int) s.size(); i++) {
		bool a = s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u';
		bool b = t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u';
		valid = valid && a == b;
	}
	if(valid) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}