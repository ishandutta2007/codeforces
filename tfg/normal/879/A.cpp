#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int on = 0;
	while(n--) {
		int s, d;
		std::cin >> s >> d;
		if(on < s) on = s;
		while((on-s) % d != 0) on++;
		on++;
	}
	std::cout << on-1 << std::endl;
}