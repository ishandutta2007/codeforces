#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a(n);
	std::vector<bool> use(n);
	std::vector<int> b(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first;
		a[i].second = i+1;
		b[i] = a[i].first;
	}
	std::sort(a.begin(), a.end());
	bool wtf = false;
	int neg = 1;
	for(auto p : a) {
		if(p.first < 0) {
			if(neg == 1) {
				neg = -p.second;
			} else {
				wtf = true;
				use[-neg-1] = true;
				use[p.second-1] = true;
				neg = 1;
			}
		} else if(p.first > 0) {
			wtf = true;
			use[p.second-1] = true;
		}
	}
	if(!wtf) {
		use[a.back().second-1] = true;
	}
	int last = -1;
	int other = -1;
	for(int i = 0; i < n; i++) {
		if(!use[i]) {
			if(other != -1) {
				std::cout << "1 " << other + 1 << " " << i + 1 << '\n';
			}
			other = i;
		} else {
			if(last != -1) {
				std::cout << "1 " << last + 1 << " " << i + 1 << '\n';
			}
			last = i;
		}
	}
	if(other != -1) {
		std::cout << "2 " << other + 1 << '\n';
	}
}