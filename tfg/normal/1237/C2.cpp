#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct PT {
	int x, y, z, id;
	void read() {
		std::cin >> x >> y >> z;
	}
	int dist(PT o) const {
		return abs(x - o.x) + abs(y - o.y) + abs(z - o.z);
	}

	bool operator < (PT o) const {
		if(x != o.x) return x < o.x;
		if(y != o.y) return y < o.y;
		return z < o.z;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<PT> pts(n);
	for(int i = 0; i < n; i++) {
		pts[i].read();
		pts[i].id = i + 1;
	}
	std::sort(pts.begin(), pts.end());
	std::vector<PT> buffer;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && pts[l].x == pts[r].x) r++;
		std::vector<PT> nxt;
		for(int i = l; i < r; i++) {
			nxt.push_back(pts[i]);
		}
		assert(buffer.size() <= 1);
		while(!buffer.empty()) {
			int ans = 0;
			for(int i = 1; i < (int) nxt.size(); i++) {
				if(nxt[i].dist(buffer.back()) < nxt[ans].dist(buffer.back())) {
					ans = i;
				}
			}
			std::cout << buffer.back().id << ' ' << nxt[ans].id << '\n';
			nxt.erase(nxt.begin() + ans);
			buffer.pop_back();
		}
		for(int xl = 0, xr = 0; xl < (int) nxt.size(); xl = xr) {
			while(xr < (int) nxt.size() && nxt[xl].y == nxt[xr].y) xr++;
			std::vector<PT> buf(nxt.begin() + xl, nxt.begin() + xr);
			assert(buffer.size() <= 1);
			while(!buffer.empty()) {
				int ans = 0;
				for(int i = 1; i < (int) buf.size(); i++) {
					if(buf[i].dist(buffer.back()) < buf[ans].dist(buffer.back())) {
						ans = i;
					}
				}
				std::cout << buffer.back().id << ' ' << buf[ans].id << '\n';
				buf.erase(buf.begin() + ans);
				buffer.pop_back();
			}
			// now greedy with rest
			while(buf.size() > 1) {
				int i = buf[buf.size() - 1].id;
				int j = buf[buf.size() - 2].id;
				std::cout << i << ' ' << j << '\n';
				buf.pop_back();
				buf.pop_back();
			}
			buffer = buf;
		}
	}
}