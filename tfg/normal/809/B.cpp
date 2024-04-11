#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::map<std::pair<int, int>, bool> memo;

bool qry(int a, int b) {
	if(memo.count(std::pair<int, int>(a, b))) return memo[std::pair<int, int>(a, b)];
	std::cout << "1 " << a << " " << b << std::endl;
	std::string str;
	std::cin >> str;
	return memo[std::pair<int, int>(a, b)] = str == "TAK";
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, trash;
	std::cin >> n >> trash;
	int on = 1;
	{
		int l = 1, r = n;
		while(l != r) {
			int mid = (l + r) / 2;
			if(qry(mid, mid+1)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		on = l;
	}
	std::cerr << "on is at " << on << std::endl;
	{
		int l = on;
		for(int i = 20; i >= 0; i--) {
			int nxt = l - (1 << i);
			if(nxt > 0 && qry(nxt, nxt+1)) {
				l = nxt;
			}
		}
		if(l != on) {
			assert(qry(on, l));
			std::cout << "2 " << on << ' ' << l << std::endl;
			return 0;
		}
	}
	{
		int l = on;
		for(int i = 20; i >= 0; i--) {
			int nxt = l + (1 << i);
			if(nxt <= n && qry(nxt, nxt-1)) {
				l = nxt;
			}
		}
		if(l != on) {
			assert(qry(on, l));
			std::cout << "2 " << on << ' ' << l << std::endl;
			return 0;
		}
	}
	assert(0);
}