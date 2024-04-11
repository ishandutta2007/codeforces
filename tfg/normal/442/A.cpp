#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int deco[256];

bool can(int hint, int mask) {
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			if(__builtin_popcount(hint & ((1 << (i + 5)) | (1 << j))) == 2) {
				mask &= ~(1 << (i * 5 + j));
			}
		}
	}

	while(1) {
		bool change = false;
		for(int k = 0; k < 25; k++) {
			if(mask & (1 << k)) {
				int a = k / 5;
				int b = k % 5;
				if(hint & (1 << (5 + a))) {
					int freq = 0;
					for(int i = 0; i < 5; i++) {
						if(mask & (1 << (a * 5 + i))) {
							freq++;
						}
					}
					if(freq == 1) {
						mask ^= 1 << k;
						change = true;
						continue;
					}
				}
				if(hint & (1 << b)) {
					int freq = 0;
					for(int i = 0; i < 5; i++) {
						if(mask & (1 << (i * 5 + b))) {
							freq++;
						}
					}
					if(freq == 1) {
						mask ^= 1 << k;
						change = true;
						continue;
					}
				}
			}
		}
		if(!change) {
			break;
		}
	}
	return __builtin_popcount(mask) <= 1;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	deco['R'] = 0;
	deco['G'] = 1;
	deco['B'] = 2;
	deco['Y'] = 3;
	deco['W'] = 4;
	int n;
	std::cin >> n;
	int mask = 0;
	while(n--) {
		std::string str;
		std::cin >> str;
		mask |= 1 << (deco[str[0]] * 5 + str[1] - '1');
	}
	int ans = 10;
	for(int i = 0; i < (1 << 10); i++) {
		if(can(i, mask)) {
			if(__builtin_popcount(i) < ans) {
				ans = __builtin_popcount(i);
				//std::cout << "got " << ans << " on " << i << "\n";
			}
		}
	}
	std::cout << ans << '\n';
}