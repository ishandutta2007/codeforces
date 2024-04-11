#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<int> vert;
std::string str[505];
int n, m;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void dfs(int x, int y) {
	assert(str[x][y] == '.');
	str[x][y] = 'X';
	vert.push_back(x * m + y);
	for(int k = 0; k < 4; k++) {
		int tox = x + dx[k], toy = y + dy[k];
		if(tox < 0 || toy < 0 || tox >= n || toy >= m || str[tox][toy] != '.') continue;
		dfs(tox, toy);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> m;
	int k;
	std::cin >> k;
	for(int i = 0; i < n; i++) {
		std::cin >> str[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(str[i][j] == '.') {
				dfs(i, j);
			}
		}
	}
	k = (int) vert.size() - k;
	for(int i = 0; i < k; i++) {
		int x = vert[i] / m, y = vert[i] % m;
		str[x][y] = '.';
	}
	for(int i = 0; i < n; i++) {
		std::cout << str[i] << '\n';
	}
}