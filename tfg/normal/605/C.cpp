#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct PT {
	typedef long long T;
	T x, y;
	PT(T _x = 0, T _y = 0) : x(_x), y(_y){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
	//double operator !()        const { return sqrt(x*x+y*y);   }
	//double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
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
	int p, q;
	std::cin >> n >> p >> q;
	std::vector<PT> hull(n);
	for(int i = 0; i < n; i++) {
		std::cin >> hull[i].x >> hull[i].y;
	}
	hull = ConvexHull(hull);
	long double ans = 1e18;
	for(int i = 0; i < (int) hull.size(); i++) {
		long double l = 0, r = 1.0;
		for(int j = 0; j < 80; j++) {
			long double l1 = l + (r - l) / 3;
			long double l2 = l + (r - l) / 3 * 2;
			long double ans1, ans2;
			{
				long double x = hull[i].x * l1 + hull[(i+1)%n].x * (1 - l1);
				long double y = hull[i].y * l1 + hull[(i+1)%n].y * (1 - l1);
				ans1 = std::max(p / x, q / y);
			}
			{
				long double x = hull[i].x * l2 + hull[(i+1)%n].x * (1 - l2);
				long double y = hull[i].y * l2 + hull[(i+1)%n].y * (1 - l2);
				ans2 = std::max(p / x, q / y);
			}
			ans = std::min(ans, ans1);
			ans = std::min(ans, ans2);
			if(ans1 > ans2) {
				l = l1;
			} else {
				r = l2;
			}
		}
	}
	std::cout << std::fixed << std::setprecision(10) << (double) ans << '\n';
}