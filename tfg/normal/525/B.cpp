#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	int m;
	std::cin >> str >> m;
	int n = (int) str.size();
	std::vector<int> a(m);
	for(int i = 0; i < m; i++) {
		std::cin >> a[i];
		a[i]--;
	}
	std::sort(a.begin(), a.end());
	for(int i = 0, j = 0, k = 0; i < n-i-1; i++) {
		while(j < m && i == a[j]) j++, k ^= 1;
		if(k) {
			std::swap(str[i], str[n-i-1]);
		}
	}
	std::cout << str << '\n';
}