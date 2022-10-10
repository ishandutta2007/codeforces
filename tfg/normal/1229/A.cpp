#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 7070;

long long a[ms];
int deg[ms];

bool better(long long x1, long long x2) {
	// x1 thinks not better than x2
	return (x1 | x2) == x2;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			if(better(a[j], a[i])) {
				//std::cout << "edge (" << j << ", " << i << ")\n";
				deg[j]++;
			}
		}
	}
	std::queue<int> q;
	for(int i = 0; i < n; i++) {
		if(deg[i] == 0) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int i = q.front();
		q.pop();
		for(int j = 0; j < n; j++) {
			if(j == i) continue;
			if(better(a[j], a[i])) {
				deg[j]--;
				if(deg[j] == 0) {
					q.push(j);
				}
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		long long cost;
		std::cin >> cost;
		if(deg[i]) {
			ans += cost;
		}
	}
	std::cout << ans << '\n';
}