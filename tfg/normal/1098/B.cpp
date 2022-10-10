#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int n, m;

std::string mat[300300], wtf[300300];
std::string wut[300300];

std::string dna = "ACGT";

int count = 0;
int ans = (int) 1e9;

void brute(int i, int j, int cost) {
	if(cost >= ans) return;
	if(n == i) {
		// end
		ans = cost;
		for(int k = 0; k < n; k++) {
			wut[k] = wtf[k];
		}
		/*count++;
		std::cout << "!" << std::endl;
		for(int k = 0; k < n; k++) {
			std::cout << wtf[k] << '\n';
		}
		// check weird stuff
		int mask = 3;
		for(int ii = 2; ii < n; ii++) {
			for(int jj = 2; jj < m; jj++) {
				if(wtf[ii][jj] != wtf[ii-2][jj]) {
					mask &= 2;
				}
				if(wtf[ii][jj] != wtf[ii][jj-2]) {
					mask &= 1;
				}
			}
		}
		std::cout << "got mask " << mask << "\n";
		assert(mask > 0);*/

		return;
	}
	if(m == j) {
		brute(i+1, 0, cost);
		return;
	}
	for(auto c : dna) {
		if(i && wtf[i-1][j] == c) continue;
		if(j && wtf[i][j-1] == c) continue;
		if(i && j + 1 < m && wtf[i-1][j+1] == c) continue;
		if(i && j && wtf[i-1][j-1] == c) continue;
		wtf[i][j] = c;
		brute(i, j + 1, cost + (c != mat[i][j] ? 1 : 0));
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> m;
	if(false) {
		for(int i = 0; i < n; i++) {
			mat[i] = wtf[i] = std::string(m, '#');
			//std::cin >> mat[i];
		}
		brute(0, 0, 0);
		std::cout << ans << '\n';
		for(int i = 0; i < n; i++) {
			std::cout << wut[i] << '\n';
		}
	} else {
		int p[] = {0, 1, 2, 3};
		for(int i = 0; i < n; i++) {
			mat[i] = wtf[i] = std::string(m, '#');
			std::cin >> mat[i];
		}
		do {
			if(p[0] > p[1] || p[2] > p[3]) continue;
			// solve for vertical symmetry
			{
				int cost = n * m;
				for(int j = 0; j < m; j++) {
					int a1, a2;
					if(j % 2 == 0) {
						a1 = p[0], a2 = p[1];
					} else {
						a1 = p[2], a2 = p[3];
					}
					int cost1 = 0;
					int cost2 = 0;
					for(int i = 0; i < n; i++) {
						if(mat[i][j] == dna[a1]) {
							cost1++;
						} else if(mat[i][j] == dna[a2]) {
							cost2++;
						}
						std::swap(a1, a2);
					}
					if(j % 2 == 0) {
						a1 = p[0], a2 = p[1];
					} else {
						a1 = p[2], a2 = p[3];
					}
					if(cost2 > cost1) {
						std::swap(a1, a2);
						std::swap(cost2, cost1);
					}
					cost -= cost1;
					for(int i = 0; i < n; i++) {
						wtf[i][j] = dna[a1];
						std::swap(a1, a2);
					}
				}
				if(cost < ans) {
					ans = cost;
					for(int i = 0; i < n; i++) {
						wut[i] = wtf[i];
					}
				}
			}
			// solve for horizontal symmetry
			{
				int cost = n * m;
				for(int i = 0; i < n; i++) {
					int a1, a2;
					if(i % 2 == 0) {
						a1 = p[0], a2 = p[1];
					} else {
						a1 = p[2], a2 = p[3];
					}
					int cost1 = 0;
					int cost2 = 0;
					for(int j = 0; j < m; j++) {
						if(mat[i][j] == dna[a1]) {
							cost1++;
						} else if(mat[i][j] == dna[a2]) {
							cost2++;
						}
						std::swap(a1, a2);
					}
					if(i % 2 == 0) {
						a1 = p[0], a2 = p[1];
					} else {
						a1 = p[2], a2 = p[3];
					}
					if(cost2 > cost1) {
						std::swap(a1, a2);
						std::swap(cost2, cost1);
					}
					cost -= cost1;
					for(int j = 0; j < m; j++) {
						wtf[i][j] = dna[a1];
						std::swap(a1, a2);
					}
				}
				if(cost < ans) {
					ans = cost;
					for(int i = 0; i < n; i++) {
						wut[i] = wtf[i];
					}
				}
			}
		} while(std::next_permutation(p, p + 4));
		//std::cout << ans << '\n';
		for(int i = 0; i < n; i++) {
			std::cout << wut[i] << '\n';
		}
	}
}