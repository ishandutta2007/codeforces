#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::string removeA(std::string str) {
	std::string ans;
	for(auto c : str) if(c != 'a') ans += c;
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	int cnt = 0;
	for(auto c : str) if(c != 'a') cnt++;
	if(cnt % 2 != 0) {
		std::cout << ":(\n";
		return 0;
	}
	if(cnt == 0) {
		std::cout << str << '\n';
		return 0;
	}
	int cnt2 = 0;
	int i = 0;
	while(cnt2 <= cnt / 2) {
		if(str[i] != 'a') cnt2++;
		i++;
	}
	i--;
	std::string s = str.substr(0, i);
	if(s + removeA(s) == str) {
		std::cout << s << '\n';
	} else {
		std::cout << ":(\n";
	}
}