#include <iostream>

using namespace std;

int x = 0, y = 0, n, k;

void inc() {
	if (y + 1 < n) {
		y ++;
		return;
	}
	x ++;
	y = 0;
}


int main() {
	cin >> n >> k;
	if (k > n * n) {
		cout << -1 << endl;
		return 0;
	}
	bool matrix[n][n];
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			matrix[i][j] = 0;
		}
	}
	while (k > 1) {
		if (matrix[x][y]) {
			inc();
			continue;
		}
		matrix[x][y] = 1;
		k --;
		if (x != y) {
			matrix[y][x] = 1;
			k --;
		}
		inc();
	}
	if (k == 1) {
		for (int i = 0; i < n; i ++) {
			if (matrix[i][i] == 0) {
				matrix[i][i] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}