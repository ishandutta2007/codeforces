#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <cstdlib>
#include <cstring>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int n, k;
std::string mat[2];
int dist[2][100100];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> k >> mat[0] >> mat[1];
	memset(dist, 0x3f, sizeof dist);
	dist[0][0] = 0;
	std::queue<std::pair<int, int>> q;
	q.push({0, 0});
	while(!q.empty()) {
		int w = q.front().first, x = q.front().second;
		q.pop();
		if(dist[w][x] > x || mat[w][x] == 'X') {
			continue;
		}
		if(x + k >= n) {
			std::cout << "YES\n";
			return 0;
		}
		for(int d = -1; d <= 1; d++) {
			if(x + d >= 0 && 1 + dist[w][x] < dist[w][x+d]) {
				dist[w][x+d] = 1 + dist[w][x];
				q.push({w, x+d});
			}
		}
		if(dist[w^1][x+k] > 1 + dist[w][x]) {
			dist[w^1][x+k] = 1 + dist[w][x];
			q.push({w^1, x+k});
		}
	}
	std::cout << "NO\n";
}