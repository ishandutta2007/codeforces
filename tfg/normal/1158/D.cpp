#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

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
	//double operator !()        const { return sqrt(x*x+y*y);   }
	//double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
	bool operator == (const PT &p) const { return x == p.x && y == p.y; }
};

std::vector<PT> ConvexHull (std::vector<PT> pts) {
	if(pts.size() <= 1) return pts;
	std::sort(pts.begin(), pts.end(), [](PT a, PT b) -> bool { return a.x != b.x ? a.x < b.x : a.y < b.y; });
	//pts.resize(std::unique(pts.begin(), pts.end(), [](PT a, PT b) -> bool { return a.x == b.x && a.y == b.y; }) - pts.begin());
	std::vector<PT> ans(2 * pts.size());
	int s = 0;
	for(int i = 0; i < (int) pts.size(); i++) {
		while(s > 1 && (pts[i] - ans[s - 2]) % (ans[s - 1] - ans[s - 2]) >= 0) {
			s--;
		}
		ans[s++] = pts[i];
	}
	for(int i = (int) pts.size() - 1, t = s + 1; i > 0; i--) {
		while(s >= t && (pts[i - 1] - ans[s - 2]) % (ans[s - 1] - ans[s - 2]) >= 0) {
			s--;
		}
		ans[s++] = pts[i - 1];
	}
	ans.resize(s - 1);
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<PT> pts(n);
	std::vector<bool> used(n, false);
	std::vector<int> ans;
	for(int i = 0; i < n; i++) {
		std::cin >> pts[i].x >> pts[i].y;
	}
	auto hull = ConvexHull(pts);
	PT cur = hull[0];
	std::string str;
	std::cin >> str;
	str += 'R';
	str += 'R';
	int ch = 0;
	while(1) {
		// finding index
		for(int i = 0; i < n; i++) {
			if(pts[i] == cur) {
				ans.push_back(i + 1);
				used[i] = true;
			}
		}
		if((int) ans.size() == n) {
			break;
		}
		// finding index in convex hull
		int id = 0;
		while(!(hull[id] == cur)) {
			id++;
		}
		char turn = str[ch++];
		if(turn == 'L') {
			cur = hull[(id+1)%hull.size()];
		} else {
			cur = hull[(id-1+(int)hull.size())%hull.size()];
		}
		hull.clear();
		for(int i = 0; i < n; i++) {
			if(!used[i]) {
				hull.push_back(pts[i]);
			}
		}
		hull = ConvexHull(hull);
	}
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}