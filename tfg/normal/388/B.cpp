#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1010;
const int me = 60;
bool ans[ms][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < me; i++) {
		ans[2+i][2+i+1] = true;
	}
	ans[2+me][1] = true;
	int c = 2 + me + 1;
	int on = 0;
	for(int i = 0; (1 << i) <= n; i++) {
		if(n & (1 << i)) {
			ans[on][2 + 2 * i] = true;
		}
		ans[on][c] = true;
		ans[on][c+1] = true;
		ans[c][c+2] = true;
		ans[c+1][c+2] = true;
		on = c + 2;
		c += 3;
	}

	std::cout << c << '\n';
	for(int i = 0; i < c; i++) {
		for(int j = 0; j < c; j++) {
			std::cout << (ans[i][j] || ans[j][i] ? 'Y' : 'N');
		}
		std::cout << '\n';
	}
}