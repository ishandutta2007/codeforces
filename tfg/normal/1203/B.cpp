#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> q;
	while(q--) {
		int n;
		std::cin >> n;
		std::vector<int> a(4*n);
		for(auto &v : a) {
			std::cin >> v;
		}
		std::sort(a.begin(), a.end());
		bool valid = true;
		for(int i = 0, j = 4*n-1; i < j; i += 2, j -= 2) {
			//std::cout << "(" << a[i] << ", " << a[i+1] << ", " << a[j-1] << ", " << a[j] << ")\n";
			valid = valid && a[i] == a[i+1] && a[j] == a[j-1] && (long long) a[i] * a[j] == (long long) a[0] * a.back();
		}
		std::cout << (valid ? "YES\n" : "NO\n");
	}
}