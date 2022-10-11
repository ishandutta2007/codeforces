#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int dx[] = {2, 2, 1, 1, -2, -2, -1, -1};
const int dy[] = {1, -1, 2, -2, 1, -1, 2, -2};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> mat(n, std::vector<int>(n));
	const int INF = 1e9;
	const int ms = 1e4;
	std::vector<std::vector<int>> kni(n, std::vector<int>(n, 0));
	std::vector<std::vector<int>> rook(n, std::vector<int>(n, 0));
	std::vector<std::vector<int>> bish(n, std::vector<int>(n, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cin >> mat[i][j];
		}
	}
	for(int k = 1; k <= n * n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(mat[i][j] != k) {
					kni[i][j] = rook[i][j] = bish[i][j] = INF;
				} else if(k == n * n) {
					int ans = std::min(kni[i][j], std::min(rook[i][j], bish[i][j]));
					std::cout << ans / ms << ' ' << ans % ms << std::endl;
					return 0;
				} else {
					int ans = std::min(kni[i][j], std::min(rook[i][j], bish[i][j]));
					//std::cout << ans / ms << ' ' << ans % ms << std::endl;
				}
			}
		}
		for(int rep = 0; rep < 4; rep++) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					int cst = std::min(kni[i][j], std::min(rook[i][j], bish[i][j])) + 1 + ms;
					kni[i][j] = std::min(kni[i][j], cst);
					rook[i][j] = std::min(rook[i][j], cst);
					bish[i][j] = std::min(bish[i][j], cst);
					cst = rook[i][j] + ms;
					for(int x = 0; x < n; x++) {
						rook[x][j] = std::min(rook[x][j], cst);
						rook[i][x] = std::min(rook[i][x], cst);
					}
					cst = bish[i][j] + ms;
					for(int x = 1; x < n; x++) {
						int ii, jj;
						ii = i + x, jj = j + x;
						if(0 <= ii && ii < n && 0 <= jj && jj < n) {
							bish[ii][jj] = std::min(bish[ii][jj], cst);
						}
						ii = i - x, jj = j + x;
						if(0 <= ii && ii < n && 0 <= jj && jj < n) {
							bish[ii][jj] = std::min(bish[ii][jj], cst);
						}
						ii = i + x, jj = j - x;
						if(0 <= ii && ii < n && 0 <= jj && jj < n) {
							bish[ii][jj] = std::min(bish[ii][jj], cst);
						}
						ii = i - x, jj = j - x;
						if(0 <= ii && ii < n && 0 <= jj && jj < n) {
							bish[ii][jj] = std::min(bish[ii][jj], cst);
						}
					}
					cst = kni[i][j] + ms;
					for(int x = 0; x < 8; x++) {
						int ii = i + dx[x], jj = j + dy[x];
						if(0 <= ii && ii < n && 0 <= jj && jj < n) {
							kni[ii][jj] = std::min(kni[ii][jj], cst);
						}
					}
				}
			}

		}
	}
}