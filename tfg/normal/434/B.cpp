#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1010;

int aa[ms][ms];
int row[ms][ms][2];
int col[ms][ms][2];

int n, m;

void updRow(int r) {
	for(int i = 0; i < m; i++) {
		row[r][i+1][0] = row[r][i][0] + 1;
		if(aa[r][i+1] == 0) {
			row[r][i+1][0] = 0;
		}
	}
	for(int i = m-1; i >= 0; i--) {
		row[r][i+1][1] = row[r][i+2][1] + 1;
		if(aa[r][i+1] == 0) {
			row[r][i+1][1] = 0;
		}
	}
}

void updCol(int c) {
	for(int i = 0; i < n; i++) {
		col[c][i+1][0] = col[c][i][0] + 1;
		if(aa[i+1][c] == 0) {
			col[c][i+1][0] = 0;
		}
	}
	for(int i = n-1; i >= 0; i--) {
		col[c][i+1][1] = col[c][i+2][1] + 1;
		if(aa[i+1][c] == 0) {
			col[c][i+1][1] = 0;
		}
	}
}

int solve(const std::vector<int> &a, const std::vector<int> &b) {
	int ans = a[0];
	int mn = a[0];
	int i = 1, j = 0;
	while(i < (int) a.size() && j < (int) b.size()) {
		while(i < (int) a.size() && a[i] >= mn) i++;
		while(j < (int) b.size() && b[j] >= mn) j++;
		ans = std::max((i+j) * mn, ans);
		if(i < (int) a.size() && j < (int) b.size()) {
			if(a[i] < b[j]) {
				mn = b[j++];
			} else {
				mn = a[i++];
			}
		}
	}
	ans = std::max((i+j) * mn, ans);
	while(i < (int) a.size()) {
		mn = std::min(a[i++], mn);
		ans = std::max((i+j) * mn, ans);
	}
	while(j < (int) b.size()) {
		mn = std::min(b[j++], mn);
		ans = std::max((i+j) * mn, ans);
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> n >> m >> q;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			std::cin >> aa[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		updRow(i);
	}
	for(int j = 1; j <= m; j++) {
		updCol(j);
	}
	while(q--) {
		int op, x, y;
		std::cin >> op >> x >> y;
		if(op == 1) {
			// change
			aa[x][y] ^= 1;
			updRow(x);
			updCol(y);
		} else {
			int ans = 0;
			// solve left
			{
				std::vector<int> a, b;
				for(int i = x; i <= n; i++) {
					a.push_back(row[i][y][0]);
				}
				for(int i = x-1; i > 0; i--) {
					b.push_back(row[i][y][0]);
				}
				ans = std::max(ans, solve(a, b));
			}
			// solve right
			{
				std::vector<int> a, b;
				for(int i = x; i <= n; i++) {
					a.push_back(row[i][y][1]);
				}
				for(int i = x-1; i > 0; i--) {
					b.push_back(row[i][y][1]);
				}
				ans = std::max(ans, solve(a, b));
			}
			// solve up
			{
				std::vector<int> a, b;
				for(int i = y; i <= m; i++) {
					a.push_back(col[i][x][0]);
				}
				for(int i = y-1; i > 0; i--) {
					b.push_back(col[i][x][0]);
				}
				ans = std::max(ans, solve(a, b));
			}
			// solve down
			{
				std::vector<int> a, b;
				for(int i = y; i <= m; i++) {
					a.push_back(col[i][x][1]);
				}
				for(int i = y-1; i > 0; i--) {
					b.push_back(col[i][x][1]);
				}
				ans = std::max(ans, solve(a, b));
			}
			std::cout << ans << '\n';
		}
	}
}