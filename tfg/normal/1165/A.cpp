#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, r, l;
	std::cin >> n >> r >> l;
	std::string str;
	std::cin >> str;
	std::reverse(str.begin(), str.end());
	int ans = 0;
	for(int i = 0; i < r; i++) {
		int want = i == l ? '1' : '0';
		if(want != str[i]) {
			ans++;
		}
	}
	std::cout << ans << '\n';
}