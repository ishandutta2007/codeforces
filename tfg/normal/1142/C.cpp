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
};

std::vector<PT> ConvexHull (std::vector<PT> pts) {
	if(pts.size() <= 2) return pts;
	std::sort(pts.begin(), pts.end(), [](PT a, PT b) -> bool { return a.x != b.x ? a.x < b.x : a.y < b.y; });
	//pts.resize(std::unique(pts.begin(), pts.end(), [](PT a, PT b) -> bool { return a.x == b.x && a.y == b.y; }) - pts.begin());
	std::vector<PT> ans(2 * pts.size());
	int s = 0;
	for(int i = 0; i < pts.size(); i++) {
		while(s > 1 && (pts[i] - ans[s - 2]) % (ans[s - 1] - ans[s - 2]) >= 0) {
			s--;
		}
		ans[s++] = pts[i];
	}
	ans.resize(s);
	while(ans.size() > 2 && ans[s-1].x == ans[s-2].x) {
		ans.pop_back();
		s--;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<PT> hull(n);
	for(int i = 0; i < n; i++) {
		std::cin >> hull[i].x >> hull[i].y;
		hull[i].y -= hull[i].x * hull[i].x;
		hull[i].y = -hull[i].y;
		//std::cout << "(" << hull[i].x << ", " << hull[i].y << ")\n";
	}
	hull = ConvexHull(hull);
	for(auto p : hull) {
		//std::cout << p.x << " " << p.y << "\n";
	}
	int ans = (int) hull.size() - 1;
	if(hull.size() >= 2 && hull[0].x == hull[1].x) ans--;
	std::cout << ans << '\n';
}