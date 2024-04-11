#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 101;

int row[ms];
int col[ms];
int mat[ms][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> mat[i][j];
		}
	}
	while(1) {
		bool run = false;
		for(int i = 0; i < n; i++) {
			int sum = 0;
			for(int j = 0; j < m; j++) {
				sum += (row[i]^col[j]) == 0 ? mat[i][j] : -mat[i][j];
			}
			if(sum < 0) {
				row[i] ^= 1;
				run = true;
			}
		}
		for(int j = 0; j < m; j++) {
			int sum = 0;
			for(int i = 0; i < n; i++) {
				sum += (row[i]^col[j]) == 0 ? mat[i][j] : -mat[i][j];
			}
			if(sum < 0) {
				col[j] ^= 1;
				run = true;
			}
		}
		if(!run) {
			break;
		}
	}
	std::vector<int> ans;
	for(int i = 0; i < n; i++) {
		if(row[i]) {
			ans.push_back(i);
		}
	}
	std::cout << ans.size();
	for(auto v : ans) std::cout << ' ' << v+1;
	std::cout << std::endl;
	ans.clear();
	for(int i = 0; i < m; i++) {
		if(col[i]) {
			ans.push_back(i);
		}
	}
	std::cout << ans.size();
	for(auto v : ans) std::cout << ' ' << v+1;
	std::cout << std::endl;
}