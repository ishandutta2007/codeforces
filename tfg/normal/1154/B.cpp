#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int d = 0; d <= 100; d++) {
		std::vector<int> wtf;
		wtf.push_back(a[0]);
		wtf.push_back(a[0]+d);
		wtf.push_back(a[0]-d);
		for(int i = 1; i < n; i++) {
			std::vector<int> nxt;
			for(auto v : wtf) {
				if(v == a[i] - d || v == a[i] + d || v == a[i]) {
					nxt.push_back(v);
				}
			}
			nxt.swap(wtf);
		}
		if(!wtf.empty()) {
			std::cout << d << '\n';
			return 0;
		}
	}
	std::cout << "-1\n";
}