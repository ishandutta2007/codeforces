#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n;
	char c;
	std::cin >> n >> c;
	long long ans = 0;
	if(c <= 'c') ans += c - 'a' + 4;
	else ans += 'f' - c + 1;
	n--;
	ans += n;
	ans += 6 * (n / 4 * 2);
	if(n % 2 == 1) {
		ans += 6;
	}
	if(n % 4 >= 2) ans -= 2;
	std::cout << ans << '\n';
}