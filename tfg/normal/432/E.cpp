#include <iostream>
#include <algorithm>

const int ms = 120;

char got[ms][ms];

int main() {
	int n, m;
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(got[i][j]) {
				continue;
			}
			char cur = 'A';
			while(got[i - 1][j] == cur || got[i][j - 1] == cur || got[i][j + 1] == cur) cur++; 
			int size = 1 + std::min(n - i, m - j);
			if(cur >= 'C') size = 1;
			if(cur >= 'B' && got[i - 1][j + 1] != 'A' && got[i][j + 1] != 'A') size = 1;
			for(int ii = 0; ii < size; ii++) {
				for(int jj = 0; jj < size; jj++) {
					if(got[i + ii][j + jj]) {
						size = std::min(size, std::max(ii, jj));
						if(got[i + ii][j + jj] == cur) {
							size = std::min(size, - 1 + std::max(ii, jj));
						}
					}
				}
			}
			for(int ii = 0; ii < size; ii++) {
				if(got[i][j + ii + 1] == cur || got[i - 1][j + ii] == cur) {
					size = ii;
				}
				if(got[i][j + ii + 1] != 'A' && got[i - 1][j + ii] != 'A' && got[i][j + ii - 1] != 'A' && cur != 'A') {
					size = ii;
				}
			}
			for(int ii = 0; ii < size; ii++) {
				for(int jj = 0; jj < size; jj++) {
					got[i + ii][j + jj] = cur;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			std::cout << got[i][j];
		}
		std::cout << std::endl;
	}
}