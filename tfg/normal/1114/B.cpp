#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> a(n), p(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		p[i] = i;
	}
	std::sort(p.begin(), p.end(), [&](int v1, int v2) { return a[v1] > a[v2]; });
	std::vector<bool> mark(n, false);
	long long sum = 0;
	for(int i = 0; i < m * k; i++) {
		mark[p[i]] = true;
		sum += a[p[i]];
	}
	std::cout << sum << '\n';
	for(int l = 0, r = 0; k > 1; l = r) {
		int got = 0;
		while(got < m) {
			if(mark[r]) got++;
			r++;
		}
		std::cout << r << ' ';
		k--;
	}
	std::cout << '\n';
}