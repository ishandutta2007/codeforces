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

using Pll = pair<ll, ll>;

// Base class of versions for ints and doubles
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

// Version for integer coordinates (long long)
struct vec2i : bvec2<ll, vec2i> {
	vec2i() : bvec2{0, 0} {}
	vec2i(ll a, ll b) : bvec2{a, b} {}

	bool operator==(vec2i r) const {
		return x == r.x && y == r.y;
	}

	// Sort by angle, length if angles equal
	bool operator<(vec2i r) const {
		if (upper() != r.upper()) return upper();
		auto t = cross(r);
		return t > 0 || (!t && len2() < r.len2());
	}

	bool upper() const {
		return y > 0 || (y == 0 && x >= 0);
	}
};

using vec2 = vec2i;

// Find convex hull of points; time: O(n)
// Points are returned counter-clockwise.
vector<vec2> convexHull(vector<vec2> points) {
	auto pivot = mp(points[0].y, points[0].x);
	each(p,points) pivot=min(pivot, mp(p.y,p.x));
	each(p,points) p = p-vec2(pivot.y, pivot.x);

	sort(all(points));
	vector<vec2> hull;

	each(p, points) {
		while (sz(hull) >= 2) {
			vec2 prev = hull.back()-hull[sz(hull)-2];
			vec2 cur = p - hull.back();
			if (prev.cross(cur) > 0) break;
			hull.pop_back();
		}
		hull.pb(p);
	}
	return hull;
}

// KMP algorithm; helper function
// Use functions below.
template<class T>
void kmp(const T& cur, const T& prev, Vi& ps) {
	each(x, cur) {
		int k = ps.back();
		while (k >= 0 && prev[k] != x) k = ps[k];
		ps.pb(k+1);
	}
}

// Finds occurences of pat in vec; time: O(n)
// Returns starting indices of matches.
// `neutral` is separator to be used for concat
template<class T>
Vi match(const T& str, const T& pat) {
	Vi ret, ps; ps.pb(-1);
	kmp(pat, pat, ps);
	kmp(str, pat, ps);
	rep(i, sz(ps)-sz(str), sz(ps)) {
		if (ps[i]==sz(pat)) ret.pb(i-2*sz(pat)-1);
	}
	return ret;
}

// ---

vector<Pll> readHull(int n) {
	vector<vec2> points(n);
	each(p, points) cin >> p.x >> p.y;

	auto hull = convexHull(points);
	vector<Pll> str;
	n = sz(hull);

	rep(i, 0, n) {
		int j = (i+1 < n ? i+1 : 0);
		int k = (j+1 < n ? j+1 : 0);
		vec2 prev = hull[j] - hull[i];
		vec2 cur = hull[k] - hull[j];

		ll side = prev.len2();
		double ang = acos(double(prev.dot(cur)) / prev.len() / cur.len());
		str.pb({side, ll(ang*1e7)});
	}

	return str;
}

void run() {
	int n, m; cin >> n >> m;
	auto hull1 = readHull(n);
	auto hull2 = readHull(m);

	auto str = hull1;
	str.insert(str.end(), all(hull1));

	if (match(str, hull2).empty()) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}