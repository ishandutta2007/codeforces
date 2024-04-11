#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int mat[1001][1001];
bool visit[1001];
long double dist[1001], dist2[1001];
long double prob1[1001], prob2[1001];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cin >> mat[j][i];
		}
		dist[i] = 1e18;
		prob1[i] = 1;
	}
	dist[n-1] = 0;
	for(int r = 0; r < n; r++) {
		int bst = -1;
		for(int i = 0; i < n; i++) {
			if(visit[i]) continue;
			if(bst == -1 || dist[bst] > dist[i]) {
				bst = i;
			}
		}
		visit[bst] = true;
		//std::cout << "visiting " << bst << " with cost " << (double) dist[bst] << '\n';
		for(int i = 0; i < n; i++) {
			if(mat[bst][i] == 0 || visit[i]) continue;
			long double p = mat[bst][i] / 100.0;
			long double p2 = 1 - prob1[i] * (1.0 - p);
			long double cost = (dist2[i] + prob1[i] * dist[bst] * p) / p2;
			long double nxtDist = 1.0 / p2 + cost;
			if(dist[i] > nxtDist) {
				dist[i] = nxtDist;
				dist2[i] = (dist2[i] + prob1[i] * dist[bst] * p);
				prob1[i] *= (1.0 - p);
				prob2[i] = prob2[i] + p - prob2[i] * p;
				//std::cout << "setting cost to " << i << " as " << (double) dist[i] << ", " << (double) dist2[i] << "\n";
			}
		}
	}
	std::cout << std::fixed << std::setprecision(10) << (double) dist[0] << '\n';
}