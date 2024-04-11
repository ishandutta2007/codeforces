#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::pair<int, int> game(std::pair<int, int> a) {
	//std::cout << "got game (" << a.first << ", " << a.second << ")\n";
	if(a.first == a.second) {
		return std::pair<int, int>(0, 0);
	} else if((a.first + 1) % 3 == a.second) {
		return std::pair<int, int>(1, 0);
	} else {
		return std::pair<int, int>(0, 1);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int a, b;
	long long k;
	std::cin >> k >> a >> b;
	a--;b--;
	int to[2][3][3];
	for(int i = 0; i < 2; i++) for(int j = 0; j < 3; j++) for(int jj = 0; jj < 3; jj++) {
		std::cin >> to[i][j][jj];
		to[i][j][jj]--;
	}
	const int MAGIC = 2520;
	std::pair<long long, long long> ans(0, 0);
	for(int i = 0; i < MAGIC && k > 0; i++, k--) {
		auto got = game(std::pair<int, int>(a, b));
		ans.first += got.first;
		ans.second += got.second;
		int aa = to[0][a][b];
		b = to[1][a][b];
		a = aa;
	}
	std::pair<long long, long long> wtf(0, 0);
	for(int i = 0; i < MAGIC && k > 0; i++, k--) {
		auto got = game(std::pair<int, int>(a, b));
		ans.first += got.first;
		ans.second += got.second;
		wtf.first += got.first;
		wtf.second += got.second;
		int aa = to[0][a][b];
		b = to[1][a][b];
		a = aa;
	}
	ans.first += (k / MAGIC) * wtf.first;
	ans.second += (k / MAGIC) * wtf.second;
	k %= MAGIC;
	for(int i = 0; i < MAGIC && k > 0; i++, k--) {
		auto got = game(std::pair<int, int>(a, b));
		ans.first += got.first;
		ans.second += got.second;
		int aa = to[0][a][b];
		b = to[1][a][b];
		a = aa;
	}
	std::cout << ans.second << ' ' << ans.first << '\n';
}