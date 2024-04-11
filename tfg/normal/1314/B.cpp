#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1 << 16;
const int INF = 1e9;

int dp[ms][3][3], nxt[ms][3][3];
int st[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, want;
	std::cin >> n >> want;
	n = 1 << n;
	while(want--) {
		int x;
		std::cin >> x;
		x--;
		st[x / 2]++;
	}
	for(int i = 0; i < n / 2; i++) {
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				dp[i][j][k] = -INF;
			}
		}
		dp[i][st[i]][0] = 0;
	}
	n /= 2;
	bool first = true;
	while(n > 1) {
		// do upper round and lower round
		//std::cout << "at " << n << std::endl;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j <= 2; j++) {
				for(int k = 0; k <= 2; k++) {
					//if(dp[i][j][k] >= 0) std::cout << "(" << i << ", " << j << ", " << k << ") = " << (dp[i][j][k] < 0 ? -1 : dp[i][j][k]) << std::endl;
					nxt[i][j][k] = -INF;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j <= 2; j++) {
				for(int jj = j == 2 ? 1 : 0; jj <= 1 && jj <= j; jj++) {
					for(int k = 0; k <= 2; k++) {
						int cost = std::min(j, 1) + std::min(k, 1);
						int nxtJ = jj;
						int nxtK = std::min(k, 1) + (j - jj);
						assert(nxtJ <= 1);
						nxt[i][nxtJ][nxtK] = std::max(nxt[i][nxtJ][nxtK], dp[i][j][k] + cost);
					}
				}
			}
		}
		// combine pairs into one
		for(int i = 0; i < n; i++) {
			for(int j = 0; j <= 2; j++) {
				for(int k = 0; k <= 2; k++) {
					dp[i][j][k] = -INF;
					std::swap(dp[i][j][k], nxt[i][j][k]);
				}
			}
		}
		for(int i = 0; i < n; i += 2) {
			for(int j = 0; j <= 1; j++) {
				for(int jj = 0; jj <= 1; jj++) {
					for(int k = 0; k <= 2; k++) {
						for(int kk = 0; kk <= 2; kk++) {
							int cost = std::min(k, 1) + std::min(kk, 1);
							if(first) {
								cost = 0;
							}
							int nxtJ = j + jj;
							int nxtK = std::min(k, 1) + std::min(kk, 1);
							nxt[i/2][nxtJ][nxtK] = std::max(nxt[i/2][nxtJ][nxtK], dp[i][j][k] + dp[i+1][jj][kk] + cost);
						}
					}
				}
			}
		}
		first = false;
		n /= 2;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j <= 2; j++) {
				for(int k = 0; k <= 2; k++) {
					dp[i][j][k] = nxt[i][j][k];
				}
			}
		}
	}
	// do upper round and lower round
	//std::cout << "at " << n << std::endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= 2; j++) {
			for(int k = 0; k <= 2; k++) {
				//if(dp[i][j][k] >= 0) std::cout << "(" << i << ", " << j << ", " << k << ") = " << (dp[i][j][k] < 0 ? -1 : dp[i][j][k]) << std::endl;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= 2; j++) {
			for(int k = 0; k <= 2; k++) {
				nxt[i][j][k] = -INF;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= 2; j++) {
			for(int jj = j == 2 ? 1 : 0; jj <= 1 && jj <= j; jj++) {
				for(int k = 0; k <= 2; k++) {
					int cost = std::min(j, 1) + std::min(k, 1);
					int nxtJ = jj;
					int nxtK = std::min(k, 1) + (j - jj);
					assert(nxtJ <= 1);
					nxt[i][nxtJ][nxtK] = std::max(nxt[i][nxtJ][nxtK], dp[i][j][k] + cost);
				}
			}
		}
	}
	// combine pairs into one
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= 2; j++) {
			for(int k = 0; k <= 2; k++) {
				dp[i][j][k] = -INF;
				std::swap(dp[i][j][k], nxt[i][j][k]);
			}
		}
	}
	//std::cout << "at " << n << std::endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= 2; j++) {
			for(int k = 0; k <= 2; k++) {
				//if(dp[i][j][k] >= 0) std::cout << "(" << i << ", " << j << ", " << k << ") = " << (dp[i][j][k] < 0 ? -1 : dp[i][j][k]) << std::endl;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= 2; j++) {
			for(int k = 0; k <= 2; k++) {
				ans = std::max(ans, dp[i][j][k] + std::min(k, 1) + std::min(j + k, 1));
			}
		}
	}
	std::cout << ans << '\n';
}