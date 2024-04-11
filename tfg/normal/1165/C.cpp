#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	std::string ans;
	for(int i = 0; i < n; ) {
		char c = str[i];
		while(i < n && str[i] == c) i++;
		if(i < n) {
			ans += c;
			ans += str[i++];
		}
	}
	std::cout << n - int(ans.size()) << '\n' << ans << '\n';
}