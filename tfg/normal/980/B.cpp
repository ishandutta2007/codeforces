#include <iostream>

bool is[4][101];

int main() {
	int n, k;
	std::cin >> n >> k;
	std::cout << "YES\n";
	for(int i = 1; n - i - 1 > i; i++) {
		for(int j = 1; j < 3; j++) {
			if(k > 1) {
				k -= 2;
				is[j][i] = is[j][n - i - 1] = true;
			}
		}
	}
	if(k > 0) {
		k--;
		is[1][n / 2] = true;
	}
	if(k > 0) {
		k--;
		is[2][n / 2] = true;
	}
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < n; j++) {
			std::cout << (is[i][j] ? '#' : '.');
		}
		std::cout << std::endl;
	}
}