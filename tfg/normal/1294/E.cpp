#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(m, std::vector<int>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int val;
			std::cin >> val;
			val -= j + 1;
			if(val % m != 0) {
				val = -1;
			} else {
				val = val / m;
				if(0 <= val && val < n) {
					val = (i - val + n) % n;
				} else {
					val = -1;
				}
			}
			a[j][i] = val;
			//std::cout << a[j][i] << (j + 1 == m ? '\n' : ' ');
		}
	}
	int ans = n * m;
	for(auto v : a) {
		std::map<int, int> f;
		int cur = 0;
		for(auto val : v) {
			if(val != -1) f[val]++;
		}
		for(auto it : f) {
			cur = std::max(cur, -it.first + it.second);
		}
		ans -= cur;
	}
	std::cout << ans << '\n';
}