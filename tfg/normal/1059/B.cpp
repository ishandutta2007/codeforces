#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> mine(n, std::string(m, '.'));
	std::vector<std::string> his(n);
	for(int i = 0; i < n; i++) {
		std::cin >> his[i];
	}
	for(int i = 1; i + 1 < n; i++) {
		for(int j = 1; j + 1 < m; j++) {
			int got = 0;
			for(int k = 0; k < 8; k++) {
				if(his[i+dx[k]][j+dy[k]] == '#') got++;
			}
			if(got == 8) {
				for(int k = 0; k < 8; k++) {
					mine[i+dx[k]][j+dy[k]] = '#';
				}
			}
		}
	}
	std::cout << (mine == his ? "YES\n" : "NO\n");
}