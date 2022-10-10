#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 2020;

std::string mat[ms];

int row[ms][2], col[ms][2];
int sum[ms][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		row[i][0] = col[i][0] = n;
		row[i][1] = col[i][1] = 0;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> mat[i];
		for(int j = 0; j < n; j++) {
			if(mat[i][j] == 'B') {
				row[i][0] = std::min(row[i][0], j);
				row[i][1] = std::max(row[i][1], j);
				col[j][0] = std::min(col[j][0], i);
				col[j][1] = std::max(col[j][1], i);
			}
		}
	}
	int baseAns = 0;
	for(int i = 0; i < n; i++) {
		if(row[i][0] > row[i][1]) {
			baseAns++;
		} else if(row[i][1] - row[i][0] + 1 > k) {
			// nothing
		} else {
			int topRow = std::max(0, i-k+1);
			int leftColumn = std::max(0, row[i][1]-k+1);
			sum[topRow][leftColumn]++;
			sum[topRow][row[i][0]+1]--;
			sum[i+1][leftColumn]--;
			sum[i+1][row[i][0]+1]++;
		}
	}
	for(int i = 0; i < n; i++) {
		if(col[i][0] > col[i][1]) {
			baseAns++;
		} else if(col[i][1] - col[i][0] + 1 > k) {
			// nothing
		} else {
			int topRow = std::max(0, col[i][1]-k+1);
			int leftColumn = std::max(0, i-k+1);
			sum[topRow][leftColumn]++;
			sum[topRow][i+1]--;
			sum[col[i][0]+1][leftColumn]--;
			sum[col[i][0]+1][i+1]++;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i && j) {
				sum[i][j] -= sum[i-1][j-1];
			}
			if(i) {
				sum[i][j] += sum[i-1][j];
			}
			if(j) {
				sum[i][j] += sum[i][j-1];
			}
			ans = std::max(ans, baseAns + sum[i][j]);
		}
	}
	std::cout << ans << '\n';
}