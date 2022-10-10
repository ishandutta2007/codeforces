#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 2020;

int n, m;

std::string mat[ms];
std::vector<std::pair<int, int>> st;

void go(int i, int j) {
	if(mat[i][j] == '.' || i == 0 || i == n+1 || j == 0 || j == m+1) return;
	bool good = false;
	int dx[3] = {1, 1, 0}, dy[3] = {0, 1, 1};
	for(int k = 0; k < 4; k++) {
		bool cur = true;
		for(int kek = 0; kek < 3 && cur; kek++) {
			cur = cur && mat[i + dx[kek]][j + dy[kek]] == '.';
		}
		if(cur) {
			good = true;
			break;
		}
		for(int kek = 0; kek < 3; kek++) {
			std::swap(dx[kek], dy[kek]);
			dx[kek] = -dx[kek];
		}
	}
	if(good) {
		mat[i][j] = '.';
		for(int di = -1; di <= 1; di++) for(int dj = -1; dj <= 1; dj++) {
			st.emplace_back(i + di, j + dj);
		}
	}
}

void go() {
	while(!st.empty()) {
		int i = st.back().first, j = st.back().second;
		st.pop_back();
		go(i, j);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		std::cin >> mat[i];
		mat[i] = "*" + mat[i] + "*";
	}
	mat[0] = mat[n+1] = std::string(m+2, '*');
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
		st.emplace_back(i, j);
		go();
	}
	for(int i = 1; i <= n; i++) {
		std::cout << mat[i].substr(1, m) << '\n';
	}
}