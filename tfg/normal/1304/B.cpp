#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::string a, ra, ma;
	std::vector<std::string> buffer;
	for(int i = 0; i < n; i++) {
		std::string cur;
		std::cin >> cur;
		std::string rcur = cur;
		std::reverse(rcur.begin(), rcur.end());
		if(cur == rcur) {
			ma = cur;
			continue;
		}
		bool flag = false;
		for(auto it = buffer.begin(); it != buffer.end(); it++) {
			if(rcur == *it) {
				a += cur;
				ra = (*it) + ra;
				buffer.erase(it);
				flag = true;
				break;
			}
		}
		if(!flag) {
			buffer.push_back(cur);
		}
	}
	std::cout << 2 * a.size() + ma.size() << '\n' << (a + ma + ra) << std::endl;
}