#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 202;

int n, m;
int mat[ms][ms];
int row[ms], col[ms];

int getVal(int i, int j) { return mat[i][j] ^ row[i] ^ col[j]; }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> mat[i][j];
		}
	}
	for(int rep = 0; rep < 2; rep++) { row[0] ^= 1;
	for(int x = 0; x <= m; x++) {
		for(int i = 0; i < x; i++) {
			if(getVal(0, i)) {
				col[i] ^= 1;
			}
		}
		for(int i = x; i < m; i++) {
			if(getVal(0, i) == 0) {
				col[i] ^= 1;
			}
		}
		// going for rest
		int st = (x == m ? 0 : 1);
		for(int i = 1; i < n && st != -1; i++) {
			bool same = true;
			for(int j = 0; j < m; j++) {
				same = same && getVal(i, j) == getVal(i, 0);
			}
			if(same) {
				if(getVal(i, 0) != st) {
					row[i] ^= 1;
				}
				continue;
			}
			if(st == 1) {
				st = -1;
				break;
			}
			if(getVal(i, 0)) {
				row[i] ^= 1;
			}
			for(int j = 0; j < m && st != -1; j++) {
				if(getVal(i, j) < st)  {
					st = -1;
				} else {
					st = getVal(i, j);
				}
			}
		}
		if(st != -1) {
			// found answer
			std::cout << "YES\n";
			for(int i = 0; i < n; i++) {
				std::cout << row[i];
			}std::cout << '\n';
			for(int j = 0; j < m; j++) {
				std::cout << col[j];
			}std::cout << '\n';
			return 0;
		}
	}
	}
	std::cout << "NO\n";
}