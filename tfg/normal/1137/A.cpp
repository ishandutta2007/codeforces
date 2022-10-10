#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1010;

int mat[ms][ms];
std::vector<int> row[ms], col[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> mat[i][j];
			row[i].push_back(mat[i][j]);
			col[j].push_back(mat[i][j]);
		}
	}
	auto fix = [](std::vector<int> &vec) {
		std::sort(vec.begin(), vec.end());
		vec.resize(std::unique(vec.begin(), vec.end()) - vec.begin());
	};
	auto getId = [](std::vector<int> &vec, int x) {
		return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin();
	};
	for(int i = 0; i < n; i++) {
		fix(row[i]);
	}
	for(int j = 0; j < m; j++) {
		fix(col[j]);
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int id1 = getId(row[i], mat[i][j]);
			int id2 = getId(col[j], mat[i][j]);
			int pos = std::max(id1, id2);
			std::cout << pos + std::max((int) row[i].size() - id1, (int) col[j].size() - id2) << (j + 1 == m ? '\n' : ' ');
		}
	}
}