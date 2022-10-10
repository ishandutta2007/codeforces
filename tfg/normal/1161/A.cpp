#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> mask(n, 0);
	while(k--) {
		int x;
		std::cin >> x;
		x--;
		mask[x] |= 1;
		for(int i = -1; i <= 1; i++) {
			int pos = x + i;
			if(pos < 0 || pos >= n) continue;
			if(mask[pos] & 1) {
				mask[x] |= 1 << (i + 2);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 1; j <= 3; j++) {
			if(i + j - 2 < 0 || i + j - 2 >= n) continue;
			//std::cout << "at (" << i + 1 << ", " << i + 1 + j - 2 << ") got " << (mask[i] >> j) % 2 << "\n"; 
			ans += ((mask[i] >> j) ^ 1) & 1;
		}
	}
	std::cout << ans << '\n';
}