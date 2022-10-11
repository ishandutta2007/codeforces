#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

struct Fraction {
	typedef long long T;

	T p, q;

	Fraction(T a = 0, T b = 1) : p(a), q(b) {
		simplify();
	}

	void simplify() {
		return;
		long long g = gcd(p < 0 ? -p : p, q);
		p /= g;
		q /= g;
	}

	Fraction operator *(T op) {
		return *this * Fraction(op);
	}

	Fraction operator *(Fraction f) {
		Fraction ans(p * f.p, q * f.q);
		ans.simplify();
		return ans;
	}

	Fraction operator +(Fraction f) {
		Fraction ans(p * f.q + f.p * q, q * f.q);
		ans.simplify();
		return ans;
	}

	Fraction operator -(Fraction f) {
		return *this + Fraction(-f.p, f.q);
	}

	int cmp(Fraction f) {
		long long wut = p * f.q - f.p * q;
		//print(); std::cout << ' '; f.print(); std::cout << std::endl;
		//std::cout << "wut is " << wut << std::endl;
		if(wut < 0) return -1;
		else if(wut == 0) return 0;
		else return 1;
	}

	bool operator <(Fraction f) { return cmp(f) < 0; }
	bool operator !=(Fraction f){ return cmp(f) != 0;}
	bool operator ==(Fraction f){ return cmp(f) == 0;}
	bool operator >(Fraction f) { return cmp(f) > 0; }
	bool operator >(T f) { return cmp(Fraction(f)) > 0; }
	void print() {
		return;
		std::cout << p << "/" << q;
	}
};

struct PT {
	typedef Fraction T;
	T x, y;
	int id;
	PT(T xx = 0, T yy = 0) : x(xx), y(yy){}
	PT operator +(PT p) { return PT(x+p.x,y+p.y); }
	PT operator -(PT p) { return PT(x-p.x,y-p.y); }
	PT operator *(T c)  { return PT(x*c,y*c);     }
	//PT operator /(double c)    const { return PT(x/c,y/c);     }
	T operator *(PT p) { return x*p.x+y*p.y;     }
	T operator %(PT p) { return x*p.y-y*p.x;     }
	//double operator !()        const { return sqrt(x*x+y*y);   }
	//double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
	void print() {
		return;
		x.print();
		std::cout << ", ";
		y.print();
		std::cout << " id is " << id << std::endl;
	}
};

long long cross(PT o, PT a, PT b) {
	long long ay = a.y.q, ax = a.x.q;
	long long by = b.y.q, bx = b.x.q;
	long long oy = o.y.q, ox = o.x.q;
	return (ay*bx)*(ox-ax)*(oy-by) - (ax*by)*(oy-ay)*(ox-bx);
}

std::vector<PT> ConvexHull (std::vector<PT> pts) {
	if(pts.size() <= 1) return pts;
	std::sort(pts.begin(), pts.end(), [](PT a, PT b) -> bool { return a.x != b.x ? a.x < b.x : a.y < b.y; });
	//pts.resize(std::unique(pts.begin(), pts.end(), [](PT a, PT b) -> bool { return a.x == b.x && a.y == b.y; }) - pts.begin());
	std::vector<PT> ans(2 * pts.size());
	int s = 0;
	int pos = 0;
	for(int i = 0; i < (int) pts.size(); i++) {
		if(pts[i].y < pts[pos].y) {
			pos = i;
		}
	}
	for(int i = 0; i <= pos; i++) {
		while(s > 1 && cross(ans[s-2], pts[i], ans[s-1]) > 0) {
			s--;
		}
		ans[s++] = pts[i];
	}
	ans.resize(s);
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<PT> ori;
	std::map<std::pair<int, int>, int> first;
	std::vector<std::vector<int>> others(n);
	for(int i = 0; i < n; i++) {
		int x, y;
		std::cin >> x >> y;
		if(first.count({x, y})) {
			others[first[{x, y}]].push_back(i);
			continue;
		}
		first[{x, y}] = i;
		ori.emplace_back(Fraction(1, x), Fraction(1, y));
		ori.back().id = i;
	}
	if(ori.size() == 1) {
		for(int i = 1; i <= n; i++) {
			std::cout << i << (i == n ? '\n' : ' ');
		}
		return 0;
	}
	auto hull = ConvexHull(ori);
	std::vector<int> ans;
	std::vector<bool> got(n, false);
	for(int i = 0; i < (int) hull.size(); i++) {
		got[hull[i].id] = true;
	}
	for(int i = 0; i < n; i++) {
		if(got[i]) {
			ans.push_back(i + 1);
			for(auto o : others[i]) {
				ans.push_back(o + 1);
			}
		}
	}
	std::sort(ans.begin(), ans.end());
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}