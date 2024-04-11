#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 8;

bool stone[ms][ms][ms];
bool vis[ms][ms][ms];

bool dfs(int t, int i, int j) {
	if(t == 8) return true;
	if(vis[t][i][j] || stone[t][i][j]) return false;
	vis[t][i][j] = true;
	//std::cout << "at " << t << ", " << i << ", " << j << "\n";
	for(int dx = -1; dx <= 1; dx++) {
		for(int dy = -1; dy <= 1; dy++) {
			int x = i + dx, y = j + dy;
			if(std::min(x, y) < 0 || std::max(x, y) >= 8 || stone[t][x][y]) continue;
			if(dfs(t+1, x, y)) return true;
		}
	}
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			char c;
			std::cin >> c;
			if(c == 'S') {
				for(int ii = i; ii < 8; ii++) {
					//std::cout << "stone at (" << ii-i << ", " << ii << ", " << j << ")\n";
					stone[ii-i][ii][j] = true;
				}
			}
		}
	}
	std::cout << (dfs(0, 7, 0) ? "WIN\n" : "LOSE\n");
}