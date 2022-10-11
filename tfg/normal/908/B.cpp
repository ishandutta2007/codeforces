#include <iostream>
#include <string>
#include <algorithm>

int perm[] = {0, 1 , 2, 3};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, m;
std::string board[55];

int main() {
	std::cin >> n >> m;
	int sx, sy;
	int ex, ey;
	for(int i = 0; i < n; i++) {
		std::cin >> board[i];
		for(int j = 0; j < m; j++) {
			if(board[i][j] == 'E') {
				ex = i, ey = j;
			} else if(board[i][j] == 'S') {
				sx = i, sy = j;
			}
		}
	}
	std::string path;
	std::cin >> path;
	int ans = 0;
	do {
		//std::cout << "----\n";
		int x = sx, y = sy;
		for(auto a : path) {
			int tox = x + dx[perm[a - '0']];
			int toy = y + dy[perm[a - '0']];
			if(tox < 0 || tox >= n || toy < 0 || toy >= m || board[tox][toy] == '#') {
				//std::cout << "nope\n";
				x = -1;
				break;
				continue;
			}
			x = tox;
			y = toy;
			if(x == ex && y == ey) {
				break;
			}
			//std::cout << x << ", " << y << "\n";
		}
		if(x == ex && y == ey) {
			ans++;
		}
	} while(std::next_permutation(perm, perm + 4));
	std::cout << ans << '\n';
}