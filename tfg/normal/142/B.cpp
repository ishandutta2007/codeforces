#include <iostream>

const int ms = 1050;

int got[ms][ms];

int dx[] = {5, -5, 0, 0, 1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {0, 0, 5, -5, 2, -2, 2, -2, 1, -1, 1, -1};

int main() {
	int n, m;
	std::cin >> n >> m;
	int ans = (n * m + 1) / 2;
	if(n < m) {
		std::swap(n, m);
	}
	int cans = 0;
	for(int i = 5; i < n + 5; i++) {
		for(int j = 5; j < m + 5; j++) {
			bool can = true;
			for(int k = 4; k < 12; k++) {
				can = can && !got[i + dx[k]][j + dy[k]];
			}
			if(can) {
				cans++;
				got[i][j] = true;
				//std::cout << i - 4 << ", " << j - 4 << "\n";
			}
		}
	}
	ans = std::max(ans, cans);
	std::cout << ans << '\n';
}