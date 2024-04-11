#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct PT {
	typedef long long T;
	T x, y;
	PT(T xx = 0, T yy = 0) : x(xx), y(yy){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
	bool operator < (const PT &p) const { return x != p.x ? x < p.x : y < p.y; }
	bool operator == (const PT &p)const { return x == p.x && y == p.y; }
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int ms = 500400;
	int n;
	std::cin >> n;
	std::set<std::pair<PT, int>> pts;
	std::vector<int> ans(n, -1);
	for(int i = 0; i < n; i++) {
		PT cur;
		std::cin >> cur.x >> cur.y;
		pts.insert({cur, i});
	}
	int m;
	std::cin >> m;
	int kek = 0;
	for(int j = 1; j <= m; j++) {
		int x, y;
		std::cin >> x >> y;
		while(1) {
			auto it = pts.lower_bound({PT(x, 0), -1});
			if(it == pts.end() || (x - it->first.x) * (x - it->first.x) + y * y > it->first.y * it->first.y) break;
			ans[it->second] = j;
			pts.erase(it);
			kek++;
		}
		while(1) {
			auto it = pts.lower_bound({PT(x, 0), -1});
			if(it == pts.begin()) break;
			it--;
			if((x - it->first.x) * (x - it->first.x) + y * y > it->first.y * it->first.y) break;
			ans[it->second] = j;
			pts.erase(it);
			kek++;
		}
	}
	std::cout << kek << '\n';
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}