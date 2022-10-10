#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<int> getBorder(std::string str) {
	int n = str.size();
	std::vector<int> border(n, -1);
	for(int i = 1, j = -1; i < n; i++) {
		while(j >= 0 && str[i] != str[j + 1]) {
			j = border[j];
		}
		if(str[i] == str[j + 1]) {
			j++;
		}
		border[i] = j;
	}
	return border;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string s, t;
	std::cin >> s >> t;
	int freq[2] = {0, 0};
	int f[2] = {0, 0};
	for(auto v : s) {
		freq[v - '0']++;
	}
	for(auto v : t) {
		f[v - '0']++;
	}
	if(freq[0] < f[0] || freq[1] < f[1]) {
		std::cout << s << '\n';
		return 0;
	}
	auto border = getBorder(t);
	std::string ans;
	//std::cout << "border is size " << border.back() << '\n';
	for(int i = 0; i <= border.back(); i++) {
		ans += t[i];
		f[t[i] - '0']--;
		freq[t[i] - '0']--;
	}
	t = t.substr(border.back() + 1, (int) t.size() - border.back() - 1);
	while(freq[0] >= f[0] && freq[1] >= f[1]) {
		for(auto v : t) {
			freq[v - '0']--;
			ans += v;
		}
	}
	while(freq[0] > 0) {
		freq[0]--;
		ans += '0';
	}
	while(freq[1] > 0) {
		freq[1]--;
		ans += '1';
	}
	std::cout << ans << '\n';
}