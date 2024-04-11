#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cmath>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

struct PT {
	typedef long long T;
	T x, y;
	PT(T xx = 0, T yy = 0) : x(xx), y(yy){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
	bool operator<(const PT &p)const { return x == p.x ? y < p.y : x < p.x; }

	T simplify() {
		T g = gcd(std::max(x, -x), std::max(y, -y));
		x /= g;
		y /= g;
		return g;
	}

	void read() {
		std::cin >> x >> y;
	}
};

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
	}

	bool inLine(PT p) { return (p - p1) % (p2 - p1) == 0; }
	bool inSegment(PT p) {
		return inLine(p) && (p1 - p2) * (p - p2) >= 0 && (p2 - p1) * (p - p1) >= 0;
	}

	PT lineIntersection(Segment s) {
		long double A = a, B = b, C = c;
		long double D = s.a, E = s.b, F = s.c;
		long double x = (long double) C * E - (long double) B * F;
		long double y = (long double) A * F - (long double) C * D;
		long double tmp = (long double) A * E - (long double) B * D;
		x /= tmp;
		y /= tmp;
		return PT(round(x), round(y));
	}

	void read() {
		p1.read();
		p2.read();
		*this = Segment(p1, p2);
	}

	long long points() {
		return (p2 - p1).simplify() + 1;
	}
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<Segment> segs;
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		//std::cout << "solving for " << i << std::endl;
		Segment curSeg;
		curSeg.read();
		ans += curSeg.points();
		std::set<PT> st;
		for(int j = 0; j < i; j++) {
			PT cand = curSeg.lineIntersection(segs[j]);
			if(curSeg.inSegment(cand) && segs[j].inSegment(cand)) {
				st.insert(cand);
			}
		}
		ans -= st.size();
		segs.push_back(curSeg);
	}
	std::cout << ans << std::endl;
}