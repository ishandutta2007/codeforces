#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int me = 61;

int table[me][me];
std::vector<int> pos[me];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] == 0) {
			n--;
			i--;
			continue;
		}
		for(int j = 0; j < me; j++) {
			for(int k = 0; k < me; k++) {
				if((a[i] & (1LL << j)) && (a[i] & (1LL << k))) {
					if(j == k) {
						pos[j].push_back(i);
						//std::cout << "added " << i << " in position " << j << '\n';
					}
					table[j][k]++;
					if(table[j][k] > 2) {
						std::cout << "3\n";
						return 0;
					}
				}
			}
		}
	}
	a.resize(n);
	int ans = 1e8;
	for(int i = 0; i < me; i++) {
		if(table[i][i] > 2) {
			ans = 3;
		}
	}
	if(ans != 3) {
		assert(n < me * me);
		std::vector< std::vector<int> > edges(n);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < me; j++) {
				if((a[i] & (1LL << j)) == 0) continue;
				for(auto to : pos[j]) {
					if(to != i) {
						edges[i].push_back(to);
					}
				}
			}
			std::sort(edges[i].begin(), edges[i].end());
			edges[i].resize(std::unique(edges[i].begin(), edges[i].end()) - edges[i].begin());
		}
		long long mask = 0;
		for(int i = 0; i < n; i++) {
			if((mask | a[i]) == mask) {
				continue;
			}
			mask |= a[i];
			std::queue<int> q;
			q.push(i);
			std::vector<int> dist(n, 1e6);
			std::vector<int> from(n, -1);
			dist[i] = 0;
			while(!q.empty()) {
				int on = q.front();
				q.pop();
				for(auto to : edges[on]) {
					if(dist[to] > 1 + dist[on]) {
						from[to] = on;
						dist[to] = dist[on] + 1;
						q.push(to);
					} else if(from[to] != on && to != from[on]) {
						ans = std::min(ans, 1 + dist[on] + dist[to]);
					}
				}
			}
		}
	}
	if(ans > 298389) {
		ans = -1;
	}
	std::cout << ans << '\n';
}