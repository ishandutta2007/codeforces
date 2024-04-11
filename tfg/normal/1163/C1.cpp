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
};

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

struct Segment {
	typedef long long T;
	PT p1, p2;
	T a, b, c;

	Segment() {}

	Segment(PT st, PT en) {
		p1 = st, p2 = en;
		a = -(st.y - en.y);
		b = st.x - en.x;
		c = a * en.x + b * en.y;
		long long g = gcd(std::max(a, -a), gcd(std::max(b, -b), std::max(c, -c)));
		a /= g;
		b /= g;
		c /= g;
		if(a < 0) {
			a = -a;
			b = -b;
			c = -c;
		}
		if(b < 0) {
			a = -a;
			b = -b;
			c = -c;
		}
	}

	bool operator < (Segment o) const {
		if(a != o.a) return a < o.a;
		if(b != o.b) return b < o.b;
		return c < o.c;
	}

	bool operator == (Segment o) const {
		return a == o.a && b == o.b && c == o.c;
	}
};



int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<Segment> segs;
	std::vector<PT> pts(n);
	for(int i = 0; i < n; i++) {
		std::cin >> pts[i].x >> pts[i].y;
	}
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			segs.emplace_back(pts[i], pts[j]);
		}
	}
	std::sort(segs.begin(), segs.end());
	segs.erase(std::unique(segs.begin(), segs.end()), segs.end());
	long long ans = (long long) segs.size() * ((int) segs.size() - 1) / 2;
	for(int l = 0, r = 0; l < (int) segs.size(); l = r) {
		while(r < (int) segs.size() && segs[l].a == segs[r].a && segs[l].b == segs[r].b) {
			r++;
		}
		ans -= (long long) (r - l) * (r - l - 1) / 2;
	}
	std::cout << ans << '\n';
}