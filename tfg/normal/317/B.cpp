#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200;

int mat[ms][ms];

inline bool go1(int x, int y) {
	if(mat[x][y] < 4) return false;
	int use = mat[x][y] / 4;
	assert(x != 0 && y != 0 && x != ms-1 && y != ms-1);
	mat[x][y] %= 4;
	mat[x+1][y] += use;
	mat[x-1][y] += use;
	mat[x][y+1] += use;
	mat[x][y-1] += use;
	return true;
}
int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> mat[ms/2][ms/2] >> q;
	std::pair<int, int> wtf(0, 0);
	while(1) {
		bool run = false;
		for(int i = 1; i+1 < ms; i++) for(int j = 1; j+1 < ms; j++) {
			run = go1(i, j) || run;
		}
		if(!run) break;
	}
	for(int i = 0; i < ms; i++) for(int j = 0; j < ms; j++) {
		if(mat[i][j]) wtf = std::pair<int, int>(i, j);
	}
	//std::cout << wtf.first << ' ' << wtf.second << '\n';
	while(q--) {
		int x, y;
		std::cin >> x >> y;
		x += ms/2, y += ms/2;
		if(0 <= std::min(x, y) && std::max(x, y) < ms) {
			std::cout << mat[x][y] << '\n';
		} else {
			std::cout << "0\n";
		}
	}
}