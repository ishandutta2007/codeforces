#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct PT {
	PT(int xx = 0, int yy = 0) : x(xx), y(yy) {}
	PT operator + (const PT &o) const { return PT(x + o.x, y + o.y); }
	bool operator < (const PT &o) const { return x != o.x ? x < o.x : y < o.y; }
	int x, y;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::map<char, PT> decoder;
	decoder['R'] = PT(1, 0);
	decoder['L'] = PT(-1, 0);
	decoder['U'] = PT(0, 1);
	decoder['D'] = PT(0, -1);
	int t;
	std::cin >> t;
	while(t--) {
		int l = -1, r = 1e9;
		std::map<PT, int> where;
		PT sum;
		where[sum] = 0;
		int n;
		std::cin >> n;
		for(int i = 1; i <= n; i++) {
			char c;
			std::cin >> c;
			sum = sum + decoder[c];
			if(where.count(sum) && i - where[sum] < r - l) {
				r = i;
				l = where[sum];
			}
			where[sum] = i;
		}
		if(l == -1) {
			std::cout << "-1\n";
		} else {
			std::cout << l + 1 << ' ' << r << '\n';
		}
	}
}