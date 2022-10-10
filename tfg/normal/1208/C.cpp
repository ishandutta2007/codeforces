#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<std::vector<int>> solve(int n) {
	std::vector<std::vector<int>> ans(n, std::vector<int>(n, -1));
	std::vector<std::vector<int>> base(4, std::vector<int>(4, -1));
	base[0] = {8, 9, 1, 13};
	base[1] = {3, 12, 7, 5};
	base[2] = {0, 2, 4, 11};
	base[3] = {6, 10, 15, 14};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			ans[i][j] = base[i/(n/4)][j/(n/4)] ^ (16 * (i%(n/4)+j%(n/4)*(n/4)));
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	auto ans = solve(n);
	int hmm = 0;
	for(int i = 0; i < n; i++) {
		hmm ^= ans[i][0];
	}
	for(int i = 0; i < n; i++) {
		int got = 0;
		for(int j = 0; j < n; j++) {
			got ^= ans[i][j];
		}
		assert(got == hmm);
		got = 0;
		for(int j = 0; j < n; j++) {
			got ^= ans[j][i];
		}
		assert(got == hmm);
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cout << ans[i][j] << (j + 1 == n ? '\n' : ' ');
		}
	}
}