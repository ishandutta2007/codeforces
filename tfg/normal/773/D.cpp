#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 2020;

long long dist[ms];
int cost[ms][ms];
bool visit[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int mn = 1e9;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			std::cin >> cost[i][j];
			cost[j][i] = cost[i][j];
			mn = std::min(mn, cost[i][j]);
		}
	}
	for(int i = 0; i < n; i++) {
		dist[i] = 2e9;
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			cost[i][j] -= mn;
			dist[i] = std::min(dist[i], 2LL * cost[i][j]);
		}
	}
	for(int rep = 0; rep < n; rep++) {
		int on = -1;
		for(int i = 0; i < n; i++) {
			if(!visit[i] && (on == -1 || dist[i] < dist[on])) {
				on = i;
			}
		}
		visit[on] = true;
		for(int i = 0; i < n; i++) {
			dist[i] = std::min(dist[i], dist[on] + cost[on][i]);
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << dist[i] + mn * (n-1LL) << '\n';
	}
}