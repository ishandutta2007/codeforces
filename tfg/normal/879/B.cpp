#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	long long k;
	std::cin >> n >> k;
	k = std::min(k, n + 10LL);
	int got = 0;
	std::vector<int> p(n), a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		p[i] = i;
	}
	while(got < k) {
		if(a[p[0]] > a[p[1]]) {
			int u = p[1];
			for(int i = 1; i+1 < n; i++) p[i] = p[i+1];
			p[n-1] = u;
			got++;
		} else {
			int u = p[0];
			p[0] = p[1];
			for(int i = 1; i+1 < n; i++) p[i] = p[i+1];
			p[n-1] = u;
			got = 1;
		}
	}
	std::cout << a[p[0]] << std::endl;
}