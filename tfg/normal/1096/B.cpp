#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long ans = 1;
	int n;
	std::string str;
	std::cin >> n >> str;
	// count left
	int l = 0;
	while(str[l] == str[0]) {
		l++;
	}
	ans += l;
	// count right
	int r = 0;
	while(str[n-1-r] == str[n-1]) {
		r++;
	}
	ans += r;
	if(str[0] == str[n-1]) {
		ans += (long long) (l) * (r);
	}
	std::cout << ans % 998244353 << '\n';
}