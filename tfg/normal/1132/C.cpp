#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 5050;

int table[ms][ms], f[ms];
int size[ms], arr[ms][2];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	for(int i = 0; i < q; i++) {
		int l, r;
		std::cin >> l >> r;
		l--;
		for(int x = l; x < r; x++) {
			if(size[x] < 2) {
				arr[x][size[x]] = i;
			}
			size[x]++;
		}
	}
	int base = 0;
	for(int i = 0; i < n; i++) {
		if(size[i] == 1) {
			f[arr[i][0]]++;
		} else if(size[i] == 2) {
			table[arr[i][0]][arr[i][1]]++;
		}
		if(size[i]) {
			base++;
		}
	}
	int ans = 0;
	for(int l = 0; l < q; l++) {
		for(int r = l + 1; r < q; r++) {
			ans = std::max(ans, base - f[l] - f[r] - table[l][r]);
		}
	}
	std::cout << ans << '\n';
}