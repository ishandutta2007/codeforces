#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200100;

std::vector<int> q[ms];

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
long long pairs(long long x) { return x * (x + 1) / 2; }
long long solve(int x, int g) {
	if(x % g != 0) {
		return x / g + 1 + solve(x - 1, g);
	} else {
		return (long long) g * pairs(x / g) + x / g + 1;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int m, a, b;
	std::cin >> m >> a >> b;
	std::vector<int> dist(a + b + 1, (int) 1e9);
	dist[0] = 0;
	q[0].push_back(0);
	int cnt = 0;
	long long ans = 0;
	for(int i = 0; i <= a + b; i++) {
		while(!q[i].empty()) {
			int on = q[i].back();
			q[i].pop_back();
			if(dist[on] != i) continue;
			cnt++;
			if(on - b >= 0 && dist[on - b] > i) {
				dist[on - b] = i;
				q[i].push_back(on - b);
			}
			if(on + a <= a + b && dist[on + a] > std::max(i, on + a)) {
				dist[on + a] = std::max(i, on + a);
				q[dist[on + a]].push_back(on + a);
			}
		}
		if(i <= m) {
			ans += cnt;
		}
	}
	int g = gcd(a, b);
	for(int i = 0; i <= a + b; i += g) {
		assert(dist[i] < int(1e9));
	}
	if(m > a + b) {
		ans += solve(m, g) - solve(a + b, g);
	}
	std::cout << ans << '\n';
}