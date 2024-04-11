#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector< std::pair<int, int> > off(std::vector< std::pair<int, int> > segs, const int n, const int d) {
	for(auto &s : segs) {
		s.first = (s.first + d) % n;
		s.second = (s.second + d) % n;
		if(s.first > s.second) std::swap(s.first, s.second);
	}
	std::sort(segs.begin(), segs.end());
	//std::cout << "for offset " << d << " got:";
	//for(auto s : segs) std::cout << " (" << s.first << ", " << s.second << ")";
	//std::cout << std::endl;
	return segs;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector< std::pair<int, int> > segs(m);
	for(int i = 0; i < m; i++) {
		std::cin >> segs[i].first >> segs[i].second;
	}
	int x = n;
	segs = off(segs, n, 0);
	/*for(int i = 1; i < n; i++) {
		if(segs == off(segs, n, i)) {
			std::cout << "Yes\n";
		}
	}*/
	for(int i = 2; i <= x; i++) {
		if(x % i == 0) {
			while(x % i == 0) {
				x /= i;
			}
			if(segs == off(segs, n, n / i)) {
				std::cout << "Yes\n";
				return 0;
			}
		}
	}
	std::cout << "No\n";
}