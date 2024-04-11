#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int solve(int x) {
	int cur[] = {1, 2};
	int st = 0;
	while(cur[1] < x) {
		if(st == 0) {
			cur[0] = 2 * cur[1];
		} else {
			cur[0] = 2 * cur[0] + 1;
		}
		cur[1] = cur[0] + 1;
		st = 1 - st;
	}
	return (x == cur[0] || x == cur[1]) ? 1 : 0;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::cout << solve(n) << '\n';
}