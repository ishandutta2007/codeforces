#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, d;
	std::cin >> n >> m >> d;
	std::vector<int> a(m);
	std::vector<int> pos(m);
	pos[0] = d;
	for(int i = 0; i < m; i++) {
		std::cin >> a[i];
	}
	for(int i = 1; i < m; i++) {
		pos[i] = d + pos[i-1] + a[i-1] - 1;
	}
	if(pos[m-1] + a[m-1] - 1 + d <= n) {
		std::cout << "NO\n";
		return 0;
	}
	int sum = 0;
	int got = m;
	while(got > 0 && pos[got-1] + a[got-1]-1 + sum + d > n) {
		sum += a[--got];
	}
	std::vector<int> ans(n, 0);
	for(int i = 0; i < got; i++) {
		for(int j = 0; j < a[i]; j++) {
			ans[j+pos[i]-1] = i+1;
		}
	}
	// on + sum - 1 + d == n+1
	// on == n+1 - sum - d + 1
	int on = n - d - sum + 2;
	on = std::max(on, 1);
	for(int i = got; i < m; i++) {
		for(int j = 0; j < a[i]; j++) {
			ans[on++ - 1] = i+1;
		}
	}
	std::cout << "YES\n";
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i+1==n ? '\n' : ' ');
	}
}