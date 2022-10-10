#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int mat[26][26];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	while(n--) {
		std::string str;
		std::cin >> str;
		int size = (int) str.size();
		std::sort(str.begin(), str.end());
		str.resize(std::unique(str.begin(), str.end()) - str.begin());
		if(str.size() > 2) continue;
		//std::cout << "got " << str << " size " << size << '\n';
		if(str.size() == 1) {
			mat[str[0] - 'a'][str[0] - 'a'] += size;
		} else {
			mat[str[1] - 'a'][str[0] - 'a'] += size;
			mat[str[0] - 'a'][str[1] - 'a'] += size;
		}
	}
	int ans = 0;
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < 26; j++) {
			if(i != j) {
				ans = std::max(ans, mat[i][j] + mat[i][i] + mat[j][j]);
			}
			ans = std::max(ans, mat[i][j]);
		}
	}
	std::cout << ans << '\n';
}