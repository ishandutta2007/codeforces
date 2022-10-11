#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

const int ms = 110;

int row[ms], col[ms];
char str[ms][ms];

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	memset(row, -1, sizeof row);
	memset(col, -1, sizeof col);
	for(int i = 0; i < n; i++) {
		scanf(" %s", str[i]);
		for(int j = 0; j < n; j++) {
			if(str[i][j] == '.') {
				row[i] = j;
				col[j] = i;
				//std::cout << "got on " << i << ", " << j << std::endl;
			}
		}
	}
	{
		bool valid = true;
		for(int i = 0; i < n; i++) {
			valid = valid && row[i] != -1;
		}
		if(valid) {
			for(int i = 0; i < n; i++) {
				std::cout << i + 1 << ' ' << row[i] + 1 << std::endl;
			}
			return 0;
		}
	}
	{
		bool valid = true;
		for(int i = 0; i < n; i++) {
			valid = valid && col[i] != -1;
		}
		if(valid) {
			for(int i = 0; i < n; i++) {
				std::cout << col[i] + 1 << ' ' << i + 1 << std::endl;
			}
			return 0;
		}
	}
	std::cout << "-1\n";
}