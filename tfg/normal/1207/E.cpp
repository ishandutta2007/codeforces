#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	int wtf = rng() % (1<<14);
	wtf = -1;
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cout << "?";
	for(int i = 1; i <= 100; i++) {
		std::cout << ' ' << i;
	}
	std::cout << std::endl;
	int ans;
	if(wtf == -1) {
		std::cin >> ans;
	} else {
		ans = wtf ^ (rng() % 100 + 1);
	}
	const int mask = (1<<7)-1;
	ans &= mask << 7;
	std::cout << "?";
	for(int i = 1; i <= 100; i++) {
		std::cout << ' ' << (i << 7);
	}
	std::cout << std::endl;
	int x;
	if(wtf == -1) {
		std::cin >> x;
	} else {
		x = wtf ^ ((1<<14) + ((rng() % 100 + 1) << 7));
	}
	ans |= x & mask;
	std::cout << "! " << ans << std::endl;
	if(wtf != -1) {
		std::cout << wtf << std::endl;
	}
}