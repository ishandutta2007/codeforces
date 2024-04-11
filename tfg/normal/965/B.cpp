#include <iostream>

std::string board[101];
int sum[101][101][2];

int main() {
	int n, k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		std::cin >> board[i];
	}
	for(int i = 0; i < n; i++) {
		for(int l = 0, r = 0; l < n; l = r) {
			r = l + 1;
			if(board[i][l] == '#') continue;
			while(r < n && board[i][r] == '.') r++;
			for(int j = l; j + k <= r; j++) {
				sum[i][j][0]++;
				sum[i][j + k][0]--;
			}
		}
	}
	for(int j = 0; j < n; j++) {
		for(int l = 0, r = 0; l < n; l = r) {
			r = l + 1;
			if(board[l][j] == '#') continue;
			while(r < n && board[r][j] == '.') r++;
			for(int i = l; i + k <= r; i++) {
				sum[i][j][1]++;
				sum[i + k][j][1]--;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 1; j < n; j++) {
			sum[i][j][0] += sum[i][j - 1][0];
		}
	}
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < n; j++) {
			sum[i][j][1] += sum[i - 1][j][1];
		}
	}
	int ans[2] = {0, 0};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			sum[i][j][0] += sum[i][j][1];
			if(sum[ans[0]][ans[1]][0] < sum[i][j][0]) {
				ans[0] = i;
				ans[1] = j;
			}
		}
	}
	std::cout << ans[0] + 1 << ' ' << ans[1] + 1 << std::endl;
}