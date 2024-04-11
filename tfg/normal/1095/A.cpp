#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str, ans;
	int n;
	std::cin >> n;
	std::cin >> str;
	for(int i = 1, j = 0, x = 0; x < n; x++) {
		if(j == 0) {
			ans += str[x];
		}
		j++;
		if(j == i) {
			i++;
			j = 0;
		}
	}
	std::cout << ans << '\n';
}