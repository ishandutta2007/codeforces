#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long f(long long a, long long b, long long c) {
	//std::cout << a << ", " << b << ", " << c << "\n";
	long long x = a-b, y = a-c, z = b-c;
	return x * x + y * y + z * z;
}

void solve() {
	int n[3];
	std::vector<int> a[3];
	for(int i = 0; i < 3; i++) {
		std::cin >> n[i];
	}
	for(int i = 0; i < 3; i++) {
		a[i].resize(n[i]);
		for(int j = 0; j < n[i]; j++) {
			std::cin >> a[i][j];
		}
		std::sort(a[i].begin(), a[i].end());
	}
	long long ans = 3e18;
	for(int x = 0; x < 3; x++) {
		for(int y = 0; y < 3; y++) {
			for(int z = 0; z < 3; z++) {
				if(x == z || y == z || x == y) continue;
				for(auto val : a[y]) {
					auto itl = std::upper_bound(a[x].begin(), a[x].end(), val);
					if(itl == a[x].begin()) continue;
					itl--;
					auto itr = std::lower_bound(a[z].begin(), a[z].end(), val);
					if(itr == a[z].end()) continue;
					ans = std::min(ans, f(val, *itl, *itr));
				}
			}
		}
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}