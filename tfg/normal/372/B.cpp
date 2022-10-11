#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

typedef std::pair<int, int> pi;

const int ms = 42;

int dp[ms][ms][ms][ms];
char mat[ms][ms];

int pairs(int x) { return x * (x + 1) / 2; }

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, q;
	std::cin >> n >> m >> q;
	for(int i = 1; i <= n; i++) {
		scanf(" %s", mat[i] + 1);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			//std::cout << "solving corner (" << i << ", " << j << ")\n";
			// fixing upper left corner
			int cur = 0;
			// base case
			std::vector<int> upper(m + 1, i - 1);
			for(int k = j; k <= m; k++) {
				dp[i][j][i][k] = dp[i][j][i][k - 1];
				if(mat[i][k] == '0') {
					dp[i][j][i][k] += ++cur;
				} else {
					cur = 0;
					upper[k] = i;
				}
				//std::cout << "base (" << i << ", " << j << ", " << i << ", " << k << ") has " << dp[i][j][i][k] << std::endl;
			}
			for(int ii = i + 1; ii <= n; ii++) {
				// fixing second row
				std::vector<pi> hist;
				cur = 0;
				for(int jj = j; jj <= m; jj++) {
					if(mat[ii][jj] == '1') {
						hist.clear();
						cur = 0;
						upper[jj] = ii;
					} else {
						int h = ii - upper[jj];
						int f = 1;
						while(!hist.empty() && hist.back().second >= h) {
							f += hist.back().first;
							cur -= hist.back().first * hist.back().second;
							hist.pop_back();
						}
						cur += f * h;
						hist.emplace_back(f, h);
					}
					dp[i][j][ii][jj] = dp[i][j][ii - 1][jj] + dp[i][j][ii][jj - 1] - dp[i][j][ii - 1][jj - 1] + cur;
				}
			}
		}
	}
	while(q--) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", dp[x1][y1][x2][y2]);
		//std::cin >> x1 >> y1 >> x2 >> y2;
		//std::cout << dp[x1][y1][x2][y2] << std::endl;
	}
}