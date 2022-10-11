#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

typedef long double ld;

ld comb[10][10];
ld kek = 0;
std::vector<ld> work(const std::vector<ld> &a, int tot, int k) {
	int n = (int) a.size();
	std::vector<ld> ans(n, 0);
	for(int i = 1; i < n; i++) {
		int j = 0;
		while(j <= k && j <= i && tot - i - (k-j-1) <= 0) j++;
		if(j > k || j > i) continue;
		ld chance = 1;
		// chance for j is
		// comb(k, j) * (i * (i-1) * ... * (i-j+1) * (tot) * (tot-1) * (tot-2) * .... * (tot - (k-j + 1))) / (tot * tot-1 * tot-2)
		int haha = 0;
		for(int x = 0; x < j; x++) {
			chance *= i - x;
			chance /= tot - haha++;
		}
		for(int x = 0; x < k-j; x++) {
			chance *= tot - i - x;
			chance /= tot - haha++;
		}
		for(; j <= k && j <= i; j++) {
			//std::cout << "chance from " << i << " using " << j << " is " << chance * comb[k][j] << '\n';
			ans[i-j] += comb[k][j] * chance * a[i];
			chance *= i - j;
			chance /= tot - i - (k-j) + 1;
		}
	}
	kek += ans[0];
	ans[0] = 0;
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 0; i < 10; i++) {
		comb[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
		}
	}
	int n, q;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<std::vector<ld>> b(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		b[i].assign(a[i] + 1, 0);
		if(a[i]) b[i][a[i]] = 1;
		else kek += 1;
	}
	std::cin >> q;
	std::cout << std::fixed << std::setprecision(15);
	while(q--) {
		int u, v, k;
		std::cin >> u >> v >> k;
		u--;v--;
		b[u] = work(b[u], a[u], k);
		std::cout << kek << '\n';
		a[v] += k;
		a[u] -= k;
	}
}