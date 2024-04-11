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
	//PT operator /(double c)    const { return PT(x/c,y/c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
	//double operator !()        const { return sqrt(x*x+y*y);   }
	//double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
	bool operator < (const PT &p) const { return x != p.x ? x < p.x : y < p.y; }
	bool operator == (const PT &p)const { return x == p.x && y == p.y; }
};

void ConvexHull (std::vector<PT> &pts) {
	if(pts.size() <= 1) return;
	int s = 0;
	for(int i = 0; i < (int) pts.size(); i++) {
		while(s > 1 && (pts[i] - pts[s - 2]) % (pts[s - 1] - pts[s - 2]) <= 0) {
			s--;
		}
		pts[s++] = pts[i];
	}
	pts.resize(s);
}

const int bs = 330;
const int ms = 110000 + bs;

struct Solution {
	struct Bucket {
		std::vector<PT> hull;
		int lazy = 0;
		int vals[bs];
		int pt = 0;

		Bucket() {
			for(int i = 0; i < bs; i++) {
				vals[i] = 0;
			}
		}

		void build(int st) {
			hull.clear();
			for(int i = 0; i < bs; i++) {
				hull.emplace_back(st + i, (long long) (st + i) * vals[i]);
			}
			ConvexHull(hull);
		}

		std::pair<long long, int> qry() {
			if(hull.empty()) return std::pair<long long, int>(0, 0);
			PT dir(lazy, 1);
			while(pt + 1 < (int) hull.size() && hull[pt] * dir <= hull[pt+1] * dir) pt++;
			PT got = hull[pt];
			return std::pair<long long, int>(got * PT(lazy, 1), (int) got.x);
		}

		void upd(int pos) {
			for(int i = 0; i <= pos % bs; i++) {
				vals[i]++;
			}
			build(pos / bs * bs);
			pt = 0;
		}
	};

	Bucket bt[ms / bs];

	void upd(int x) {
		int b = x / bs;
		for(int i = 0; i < b; i++) {
			bt[i].lazy++;
		}
		bt[b].upd(x);
	}

	std::pair<long long, int> qry() {
		std::pair<long long, int> ans(0, 0);
		for(int i = 0; i < ms / bs; i++) {
			ans = std::max(ans, bt[i].qry());
		}
		return ans;
	}
};

Solution ha;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, w;
	std::cin >> n >> w;
	std::vector<std::vector<int>> person(ms);
	int mx = 0;
	int got = n;
	while(n--) {
		int a, b;
		std::cin >> a >> b;
		person[b].push_back(a);
		mx = std::max(mx, b);
	}
	for(int i = 0; i <= mx + 1; i++) {
		// get ans
		auto haha = ha.qry();
		//std::cout << "got " << haha.first << ", " << haha.second << "\n";
		haha.first = haha.first + (long long) got * i * w;
		std::cout << haha.first << ' ' << haha.second << '\n';
		// update
		for(auto p : person[i]) {
			got--;
			ha.upd(p);
		}
	}
}