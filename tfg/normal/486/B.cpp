#include <iostream>

const int ms = 101;

int a[ms][ms], b[ms][ms];
int row[2][ms], col[2][ms];

int main() {
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> a[i][j];
			row[0][i] += a[i][j];
			col[0][j] += a[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(row[0][i] == m && col[0][j] == n) {
				b[i][j] = 1;
				row[1][i]++;
				col[1][j]++;
			}
		}
	}
	bool valid = true;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int x = (row[1][i] + col[1][j] > 0 ? 1 : 0);
			valid = valid && x == a[i][j];
		}
	}
	if(valid) {
		std::cout << "YES\n";
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				std::cout << b[i][j] << (j + 1 == m ? '\n' : ' ');
			}
		}
	} else {
		std::cout << "NO\n";
	}
}