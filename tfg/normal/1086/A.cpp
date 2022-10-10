#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct PT {
	int x, y;
	PT(int a = 0, int b = 0) : x(a), y(b) {}
	int operator !() { return abs(x) + abs(y); }
	PT operator -(PT o) { return PT(x-o.x, y-o.y); }
};

bool operator < (PT a, PT b) {
	return a.x != b.x ? a.x < b.x : a.y < b.y;
}

bool operator == (PT a, PT b) {
	return !(a < b) && !(b < a);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<PT> pts;
	for(int i = 0; i < 3; i++) {
		int x, y;
		std::cin >> x >> y;
		pts.emplace_back(x, y);
	}
	int tot = 1e9;
	std::vector<PT> ans;
	for(int i = 0; i <= 1000; i++) {
		for(int j = 0; j <= 1000; j++) {
			int cur = 0;
			for(int k = 0; k < 3; k++) {
				cur += !(pts[k] - PT(i, j));
			}
			if(cur < tot) {
				tot = cur;
				ans.clear();
			}
			if(cur == tot) {
				ans.emplace_back(i, j);
			}
		}
	}
	assert(ans.size() == 1);
	PT pivot = ans[0];
	for(int i = 0; i < 3; i++) {
		PT cur = pivot;
		//std::cout << "(" << cur.x << ", " << cur.y << "), (" << pts[i].x << ", " << pts[i].y << ")\n";
		//std::cout << cur.x << ", " << pts[i].x << "\n";
		while(cur.x > pts[i].x) {
			cur.x--;
			ans.push_back(cur);
		}
		while(cur.x < pts[i].x) {
			cur.x++;
			ans.push_back(cur);
		}
		while(cur.y > pts[i].y) {
			cur.y--;
			ans.push_back(cur);
		}
		while(cur.y < pts[i].y) {
			cur.y++;
			ans.push_back(cur);
		}
	}
	std::sort(ans.begin(), ans.end());
	ans.resize(std::unique(ans.begin(), ans.end()) - ans.begin());
	std::cout << (int) ans.size() << '\n';
	for(auto p : ans) {
		std::cout << p.x << ' ' << p.y << '\n';
	}
}