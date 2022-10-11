#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int last[100100][26];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int m;
	std::string str;
	std::cin >> m >> str;
	int n = (int) str.size();
	for(int i = 0; i < 26; i++) {
		last[0][i] = -1;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 26; j++) {
			last[i+1][j] = last[i][j];
		}
		last[i+1][str[i] - 'a'] = i;
	}
	std::string ans;
	for(int i = 0; i + m <= n;) {
		int j = 0;
		while(last[i+m][j] < i) {
			j++;
		}
		ans += char(j + 'a');
		i = last[i+m][j] + 1;
	}
	std::sort(str.begin(), str.end());
	std::sort(ans.begin(), ans.end());
	std::string wtf;
	for(auto c : str) {
		if(c < ans.back()) {
			wtf += c;
		}
	}
	for(auto c : ans) {
		if(c == ans.back()) {
			wtf += c;
		}
	}
	std::cout << wtf << '\n';
}