#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct PT {
	typedef int T;
	T x, y;
	PT(T x = 0, T y = 0) : x(x), y(y){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	bool operator < (const PT &o) const { return x != o.x ? x < o.x : y < o.y; }
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<PT> a(n), b(n);
	std::map<PT, int> id;
	for(int i = 0; i < n; i++) {
		std::cin >> b[i].x >> b[i].y;
		id[b[i]] = i;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].x >> a[i].y;
	}
	for(int k = 0; k < n; k++) {
		bool valid = true;
		PT target = a[0] + b[k];
		for(int i = 0; i < n; i++) {
			if(!id.count(target - a[i])) {
				valid = false;
				break;
			}
		}
		if(valid) {
			std::cout << target.x << ' ' << target.y << '\n';
			return 0;
		}
	}
}