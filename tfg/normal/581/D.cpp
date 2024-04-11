#include <iostream>

char mat[101][101];

int main() {
	int xx[3], yy[3];
	for(int i = 0; i < 3; i++) {
		std::cin >> xx[i] >> yy[i];
	}
	int n = 0, m = 0;
	for(int i = 0; i < 8 && n == 0; i++) {
		int x[3], y[3];
		for(int j = 0; j < 3; j++) {
			x[j] = xx[j];
			y[j] = yy[j];
			if(i & (1 << j)) std::swap(x[j], y[j]);
		}
		if(x[0] == x[1] && x[1] == x[2] && x[0] == y[0] + y[1] + y[2]) {
			m = x[0];
			n = 0;
			for(int k = 0; k < 3; k++) {
				for(int i = 0; i < y[k]; i++) {
					for(int j = 0; j < m; j++) {
						mat[n][j] = 'A' + k;
					}
					n++;
				}
			} 
		} else if(x[0] == x[1] + x[2] && y[1] == y[2] && x[0] == y[0] + y[1]) {
			int p[3] = {0, 1, 2};
			m = x[p[0]];
			n = y[p[0]] + y[p[1]];
			for(int i = 0; i < y[p[0]]; i++) {
				for(int j = 0; j < m; j++) {
					mat[i][j] = 'A' + p[0];
				}
			}
			for(int i = 0; i < y[p[1]]; i++) {
				for(int j = 0; j < x[p[1]]; j++) {
					mat[i + y[p[0]]][j] = 'A' + p[1];
				}
			}
			for(int i = 0; i < y[p[2]]; i++) {
				for(int j = 0; j < x[p[2]]; j++) {
					mat[i + y[p[0]]][j + x[p[1]]] = 'A' + p[2];
				}
			}
		} else if(x[1] == x[0] + x[2] && y[0] == y[2] && x[1] == y[1] + y[0]) {
			int p[3] = {1, 0, 2};
			m = x[p[0]];
			n = y[p[0]] + y[p[1]];
			for(int i = 0; i < y[p[0]]; i++) {
				for(int j = 0; j < m; j++) {
					mat[i][j] = 'A' + p[0];
				}
			}
			for(int i = 0; i < y[p[1]]; i++) {
				for(int j = 0; j < x[p[1]]; j++) {
					mat[i + y[p[0]]][j] = 'A' + p[1];
				}
			}
			for(int i = 0; i < y[p[2]]; i++) {
				for(int j = 0; j < x[p[2]]; j++) {
					mat[i + y[p[0]]][j + x[p[1]]] = 'A' + p[2];
				}
			}
		} else if(x[2] == x[0] + x[1] && y[0] == y[1] && x[2] == y[2] + y[0]) {
			int p[3] = {2, 0, 1};
			m = x[p[0]];
			n = y[p[0]] + y[p[1]];
			for(int i = 0; i < y[p[0]]; i++) {
				for(int j = 0; j < m; j++) {
					mat[i][j] = 'A' + p[0];
				}
			}
			for(int i = 0; i < y[p[1]]; i++) {
				for(int j = 0; j < x[p[1]]; j++) {
					mat[i + y[p[0]]][j] = 'A' + p[1];
				}
			}
			for(int i = 0; i < y[p[2]]; i++) {
				for(int j = 0; j < x[p[2]]; j++) {
					mat[i + y[p[0]]][j + x[p[1]]] = 'A' + p[2];
				}
			}
		}
	}
	if(n == 0) {
		std::cout << "-1\n";
		return 0;
	}
	std::cout << n << std::endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cout << mat[i][j];
		}
		std::cout << std::endl;
	}
}