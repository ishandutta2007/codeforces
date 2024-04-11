#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

struct PT {
	typedef long long T;
	T x, y;
	int idx;
	bool get;
	PT(T x = 0, T y = 0) : x(x), y(y){ get = false; }
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	PT operator /(double c)    const { return PT(x/c,y/c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
	T operator !()        const { return *this * *this;   }
	//double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
};

PT eval(std::vector<PT> &pts) {
	PT p;
	for(auto pt : pts) {
		if(pt.get) {
			p = p + pt;
		} else {
			p = p - pt;
		}
	}
	//std::cout << p.x << ", " << p.y << std::endl;
	return p;
}

int main() {
	srand(time(0));
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<PT> pts(n);
	for(int i = 0; i < n; i++) {
		std::cin >> pts[i].x >> pts[i].y;
		pts[i].idx = i;
		if(i == 1) pts[i].get = false;
	}
	const long long INF = 1.5e6;
	//std::cout << INF * INF << std::endl;

	//std::cout << "got " << !(eval(pts)) << std::endl;
	while(!(eval(pts)) > INF * INF) {
		//std::cout << "got " << !(eval(pts)) << std::endl;
		PT p;
		for(int i = 0; i < n; i++) {
			auto &pt = pts[i];
			if(!(p + pt) <= !(p - pt)) {
				p = p + pt;
				pt.get = true;
			} else {
				p = p - pt;
				pt.get = false;
			}
			//std::cout << pt.idx << ": " << pts[i].get << std::endl;
		}
		std::random_shuffle(pts.begin(), pts.end());
	}
	//std::cout << "got " << !(eval(pts)) << std::endl;
	std::vector<bool> ans(n);
	for(auto p : pts) {
		ans[p.idx] = p.get;
	}
	for(int i = 0; i < n; i++) {
		std::cout << (ans[i] ? 1 : -1) << (i + 1 == n ? '\n' : ' ');
	}
}