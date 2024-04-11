#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
int cmp(double a, double b, double eps=1e-9) { return (a>b+eps) - (a+eps<b); }

template<class T, class S> struct bvec2 {
	T x, y;
	S operator+(S r) const {return{x+r.x,y+r.y};}
	S operator-(S r) const {return{x-r.x,y-r.y};}
	S operator*(T r) const { return {x*r, y*r}; }
	S operator/(T r) const { return {x/r, y/r}; }

	T dot(S r)   const { return x*r.x+y*r.y; }
	T cross(S r) const { return x*r.y-y*r.x; }
	T len2()     const { return x*x + y*y; }
	double len() const { return sqrt(len2()); }
	S perp()     const { return {-y,x}; } //90deg

	double angle() const { //[0;2*PI] CCW from OX
		double a = atan2(y, x);
		return (a < 0 ? a+2*M_PI : a);
	}
};

struct vec2d : bvec2<double, vec2d> {
	vec2d() : bvec2{0, 0} {}
	vec2d(double a, double b) : bvec2{a, b} {}

	vec2d unit() const { return *this/len(); }
	vec2d rotate(double a) const { // CCW
		return {x*cos(a) - y*sin(a),
			      x*sin(a) + y*cos(a)};
	}

	bool operator==(vec2d r) const {
		return !cmp(x, r.x) && !cmp(y, r.y);
	}

	// Sort by angle, length if angles equal
	bool operator<(vec2d r) const {
		int t = cmp(angle(), r.angle());
		return t < 0 || (!t && len2()<r.len2());
	}
};

template<class T, class P, class S>
struct bline2 { // norm*point == off
	P norm; // Normal vector [A; B]
	T off;  // Offset (C parameter of equation)

	// Line through 2 points
	static S through(P a, P b) {
		return { (b-a).perp(), b.cross(a) };
	}

	// Parallel line through point
	static S parallel(P a, S b) {
		return { b.norm, b.norm.dot(a) };
	}

	// Perpendicular line through point
	static S perp(P a, S b) {
		return { b.norm.perp(), b.norm.cross(a) };
	}

	// Distance from point to line
	double distFrom(P a) {
		return fabs(norm.dot(a)-off) / norm.len();
	}
};

struct line2d : bline2<double, vec2d, line2d> {
	line2d() : bline2{{}, 0} {}
	line2d(vec2d n, double c) : bline2{n, c} {}

	int side(vec2d a) {
		return cmp(norm.dot(a), off);
	}

	bool intersect(line2d a, vec2d& out) {
		double d = norm.cross(a.norm);
		if (cmp(d, 0) == 0) return false;
		out = (norm*a.off-a.norm*off).perp() / d;
		return true;
	}
};

template<class P, class S> struct bseg2 {
	P a, b; // Endpoints
};

struct seg2d : bseg2<vec2d, seg2d> {
	seg2d() {}
	seg2d(vec2d c, vec2d d) : bseg2{c, d} {}

	bool contains(vec2d p) {
		return cmp((a-p).dot(b-p), 0) <= 0 &&
		       cmp((a-p).cross(b-p), 0) == 0;
	}
};

using vec2 = vec2d;
using line2 = line2d;
using seg2 = seg2d;

int gcd(int a, int b) {
	a = abs(a);
	b = abs(b);

	while (b != 0) {
		int x = a%b;
		a = b;
		b = x;
	}
	return a;
}

void run() {
	int n; cin >> n;
	vector<seg2> segs(n);

	int ans = 0;

	rep(i, 0, n) {
		auto& cur = segs[i];
		cin >> cur.a.x >> cur.a.y >> cur.b.x >> cur.b.y;

		set<Pii> seen;
		ans += gcd(lround(cur.a.x-cur.b.x), lround(cur.a.y-cur.b.y)) + 1;

		line2 our = line2::through(cur.a, cur.b);

		rep(j, 0, i) {
			auto& seg = segs[j];
			line2 other = line2::through(seg.a, seg.b);
			vec2 inter;

			if (our.intersect(other, inter)) {
				int x = lround(inter.x), y = lround(inter.y);

				if (cur.contains({x, y}) && seg.contains({x, y})) {
					seen.insert({x, y});
				}
			}
		}

		ans -= sz(seen);
	}

	cout << ans << endl;
}