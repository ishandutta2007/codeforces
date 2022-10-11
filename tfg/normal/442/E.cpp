#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const double eps = 1e-7;

struct PT {
	typedef double T;
	T x, y;
	int freq;
	PT(T xx = 0, T yy = 0) : x(xx), y(yy){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	PT operator /(T c)    const { return PT(x/c,y/c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
	T operator !()        const { return sqrt(x*x+y*y);   }
	//double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
};

struct Segment {
	typedef double T;
	PT p1, p2;
	T a, b, c;

	Segment() {}

	Segment(PT st, PT en) {
		p1 = st, p2 = en;
		a = -(st.y - en.y);
		b = st.x - en.x;
		c = a * en.x + b * en.y;
	}

	T plug(T x, T y) {
		// plug >= 0 is to the right
		return a * x + b * y - c;
	}

	T plug(PT p) {
		return plug(p.x, p.y);
	}

	bool inLine(PT p) { return (p - p1) % (p2 - p1) == 0; }
	bool inSegment(PT p) {
		return inLine(p) && (p1 - p2) * (p - p2) >= 0 && (p2 - p1) * (p - p1) >= 0;
	}

	PT lineIntersection(Segment s) {
		double A = a, B = b, C = c;
		double D = s.a, E = s.b, F = s.c;
		double x = (long double) C * E - (long double) B * F;
		double y = (long double) A * F - (long double) C * D;
		double tmp = (long double) A * E - (long double) B * D;
		x /= tmp;
		y /= tmp;
		return PT(x, y);
	}

	bool polygonIntersection(const std::vector<PT> &poly) {
		long double l = -1e18, r = 1e18;
		for(auto p : poly) {
			long double z = plug(p);
			l = std::max(l, z);
			r = std::min(r, z);
		}
		return l - r > eps;
	}
};

int w, h;

std::vector<PT> cutPolygon(std::vector<PT> poly, Segment seg) {
	int n = (int) poly.size();
	std::vector<PT> ans;
	for(int i = 0; i < n; i++) {
		double z = seg.plug(poly[i]);
		if(z > -eps) {
			ans.push_back(poly[i]);
		}
		double z2 = seg.plug(poly[(i + 1) % n]);
		if((z > eps && z2 < -eps) || (z < -eps && z2 > eps)) {
			ans.push_back(seg.lineIntersection(Segment(poly[i], poly[(i + 1) % n])));
		}
	}
	return ans;
}

Segment getBisector(PT a, PT b) {
	Segment ans(a, b);
	std::swap(ans.a, ans.b);
	ans.b *= -1;
	ans.c = ans.a * (a.x + b.x) * 0.5 + ans.b * (a.y + b.y) * 0.5;
	return ans;
}

std::vector<std::vector<PT>> getVoronoi(std::vector<PT> pts) {
	// assert(pts.size() > 0);
	int n = (int) pts.size();
	std::vector<int> p(n, 0);
	for(int i = 0; i < n; i++) {
		p[i] = i;
	}
	shuffle(p.begin(), p.end(), rng);
	std::vector<std::vector<PT>> ans(n);
	ans[0].emplace_back(0, 0);
	ans[0].emplace_back(w, 0);
	ans[0].emplace_back(w, h);
	ans[0].emplace_back(0, h);
	for(int i = 1; i < n; i++) {
		ans[i] = ans[0];
	}
	for(auto i : p) {
		for(auto j : p) {
			if(j == i) break;
			auto bi = getBisector(pts[j], pts[i]);
			if(!bi.polygonIntersection(ans[j])) continue;
			ans[j] = cutPolygon(ans[j], getBisector(pts[j], pts[i]));
			ans[i] = cutPolygon(ans[i], getBisector(pts[i], pts[j]));
		}
	}
	// BE CAREFUL!
	// the first point may be any point
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> w >> h >> n;
	std::vector<PT> pts;
	for(int i = 0; i < n; i++) {
		int x, y;
		std::cin >> x >> y;
		int id = -1;
		for(int j = 0; j < (int) pts.size(); j++) {
			if(int(pts[j].x + 0.5) == x && int(pts[j].y + 0.5) == y) {
				pts[j].freq++;
				id = j;
				break;
			}
		}
		if(id == -1) {
			PT cur(x, y);
			cur.freq = 1;
			pts.push_back(cur);
		}
	}
	double ans = 0;
	n = (int) pts.size();
	auto voronoi = getVoronoi(pts);
	for(int i = 0; i < n; i++) {
		auto cell = voronoi[i];
		if(pts[i].freq > 1) {
			for(auto end : cell) {
				ans = std::max(ans, !(end - pts[i]));
			}
			continue;
		}
		
		std::vector<PT> close;
		std::vector<bool> got(n, false);
		for(int k = 0; k < (int) cell.size(); k++) {
			PT curPT = (cell[k] + cell[(k+1)%(int)cell.size()]) / 2;
			long double cur = 1e9;
			int id = -1;
			for(int j = 0; j < n; j++) {
				if(j == i) continue;
				long double curDist = !(pts[j] - curPT);
				if(curDist < cur) {
					cur = curDist;
					id = j;
				}
			}
			if(got[id]) continue;
			got[id] = true;
			close.push_back(pts[id]);
		}
		for(int k = 0; k < (int) close.size(); k++) {
			auto curPoly = cell;
			for(int kk = 0; kk < (int) close.size(); kk++) {
				if(kk == k) continue;
				curPoly = cutPolygon(curPoly, getBisector(close[k], close[kk]));
			}
			for(auto end : curPoly) {
				ans = std::max(ans, !(close[k] - end));
			}
		}
	}
	std::cout << std::fixed << std::setprecision(15) << ans << std::endl;
}