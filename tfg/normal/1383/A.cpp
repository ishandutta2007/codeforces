#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::string a, b;
		std::cin >> n >> a >> b;
		const int me = 20;
		std::vector<int> masks(me, 0);
		bool bad = false;
		for(int i = 0; i < n; i++) {
			bad = bad || a[i] > b[i];
			if(a[i] != b[i]) masks[a[i] - 'a'] |= 1 << (b[i] - 'a');
		}
		if(bad) {
			std::cout << "-1\n";
			continue;
		}
		int ans = 0;
		for(int i = 0; i < me; i++) {
			int j = i+1;
			while(((1 << j) & masks[i]) == 0 && j < me) j++;
			if(j != me) {
				ans++;
				masks[j] |= masks[i];
			}
		}
		std::cout << ans << '\n';
	}
}