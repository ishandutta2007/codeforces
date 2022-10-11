#include <iostream>
#include <vector>
#include <algorithm>

int norm(int x) {
	if(x < 0) return -1;
	else if(x > 0) return 1;
	else return 0;
}

struct PT {
	typedef long long T;
	T x, y;
	PT(T x = 0, T y = 0) : x(x), y(y){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	PT operator /(double c)    const { return PT(x/c,y/c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
	
	PT normalize() { return PT(norm(x), norm(y)); }
	//double operator !()        const { return sqrt(x*x+y*y);   }
	//double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
};

std::vector<PT> ConvexHull (std::vector<PT> pts) {
	if(pts.size() <= 1) return pts;
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
	for(int i = pts.size() - 1, t = s + 1; i > 0; i--) {
		while(s >= t && (pts[i - 1] - ans[s - 2]) % (ans[s - 1] - ans[s - 2]) >= 0) {
			s--;
		}
		ans[s++] = pts[i - 1];
	}
	ans.resize(s - 1);
	return ans;
}

bool isInside(const std::vector<PT> &hull, PT point) {
	//std::cout << "(" << point.x << ", " << point.y << ")\n";
	int n = hull.size();
	if((point - hull[0]) % (hull[1] - hull[0]) > 0 || (point - hull[0]) % (hull[n-1] - hull[0]) < 0) {
		return false;
	}
	int l = 1, r = n - 1;
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if((point - hull[0]) % (hull[mid] - hull[0]) < 0) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return (hull[(l+1)%n] - hull[l]) % (point - hull[l]) >= 0;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<PT> hull(4);
	for(int i = 0; i < 4; i++) {
		std::cin >> hull[i].x >> hull[i].y;
		hull[i] = hull[i] * 4;
	}
	hull = ConvexHull(hull);
	std::vector<PT> other(4);
	for(int i = 0; i < 4; i++) {
		std::cin >> other[i].x >> other[i].y;
		other[i] = other[i] * 4;
	}
	other = ConvexHull(other);
	for(int i = 0; i < 4; i++) {
		PT dir = (hull[(i+1)%4] - hull[i]).normalize();
		PT cur = hull[i];
		if(isInside(other, cur) || isInside(hull, other[i])) {
			//std::cout << "broke in " << cur.x << ", " << cur.y << std::endl;
			std::cout << "YES\n";
			return 0;
		}
		while(cur.x != hull[(i+1)%4].x || cur.y != hull[(i+1)%4].y) {
			if(isInside(other, cur)) {
				std::cout << "YES\n";
				return 0;
			}
			cur = cur + dir;
		}
	}
	std::cout << "NO\n";
}