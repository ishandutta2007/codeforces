#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int, int> ii;

int deduce(std::vector<ii> a, std::vector<ii> b) {
	int ans = 0;
	for(int k = 1; k < 10; k++) {
		bool valid = false;
		for(auto i : a) {
			if(i.first != k && i.second != k) {
				continue;
			}
			for(auto j : b) {
				if(j.first != k && j.second != k) {
					continue;
				}
				if(j == i) continue;
				valid = true;
				break;
			}
			if(valid) {
				break;
			}
		}
		if(valid) {
			if(ans) {
				return 0;
			} else {
				ans = k;
			}
		}
	}
	return ans;
}

bool know(std::vector<ii> a, std::vector<ii> b) {
	for(auto i : a) {
		int got = 0;
		for(auto j : b) {
			if(i == j) continue;
			if(i.first == j.first || i.first == j.second) {
				got |= 1;
			}
			if(i.second == j.first || i.second == j.second) {
				got |= 2;
			}
		}
		if(got == 3) {
			return false;
		}
	}
	return true;
}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int s[2];
	std::cin >> s[0] >> s[1];
	std::vector<ii> p[2];
	for(int j = 0; j < 2; j++) {
		for(int i = 0; i < s[j]; i++) {
			int x, y;
			std::cin >> x >> y;
			if(x > y) {
				std::swap(x, y);
			}
			p[j].emplace_back(x, y);
		}
	}
	int ans = deduce(p[0], p[1]);
	if(ans) {
		std::cout << ans << std::endl;
	} else if(know(p[0], p[1]) && know(p[1], p[0])) {
		std::cout << "0\n";
	} else {
		std::cout << "-1\n";
	}
}