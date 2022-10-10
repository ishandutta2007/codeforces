#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long h, n;
	std::cin >> h >> n;
	n += (1LL << (h)) - 1;
	std::string str;
	long long ans = 0;
	while(n > 1) {
		str = (n % 2 == 1 ? 'R' : 'L') + str;
		n /= 2;
		ans++;
	}
	str = 'R' + str;
	//std::cout << "string is " << str << '\n';
	for(int i = 1; i < (int) str.size(); i++) {
		if(str[i] == str[i-1]) {
			//std::cout << "adding " << (1LL << (h - i + 1)) - 1 << std::endl;
			ans += (1LL << (h - i + 1)) - 1;
		}
	}
	std::cout << ans << '\n';
}