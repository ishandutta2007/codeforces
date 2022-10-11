#include <iostream>
#include <string>

const int ms = 101;

std::string board[ms];
char ans[ms][ms];
bool attack[ms][ms];
int n;

bool valid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
	for(int i = 0; i < ms; i++) {
		for(int j = 0; j < ms; j++) {
			ans[i][j] = 'x';
		}
	}
	ans[ms / 2][ms / 2] = 'o';
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> board[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] != 'o') {
				continue;
			}
			for(int x = 0; x < n; x++) {
				for(int y = 0; y < n; y++) {
					if(board[x][y] == '.') {
						ans[x - i + ms / 2][y - j + ms / 2] = '.';
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] != 'o') {
				continue;
			}
			for(int x = 0; x < n; x++) {
				for(int y = 0; y < n; y++) {
					if(ans[x - i + ms / 2][y - j + ms / 2] != '.') {
						attack[x][y] = true;
					}
				}
			}
		}
	}

	bool valid = true;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] == 'x') {
				valid = valid && attack[i][j];
			}
		}
	}
	if(valid) {
		std::cout << "YES\n";
		for(int i = -n + 1; i <= n - 1; i++) {
			for(int j = -n + 1; j <= n - 1; j++) {
				std::cout << ans[i + ms / 2][j + ms / 2];
			}
			std::cout << '\n';
		}
	} else {
		std::cout << "NO\n";
	}
}