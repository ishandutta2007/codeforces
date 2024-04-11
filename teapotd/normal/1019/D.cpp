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

// Base class of versions for ints and doubles
template<class T, class S> struct bvec2 {
	T x, y;
	S operator+(S r) const {return{x+r.x,y+r.y};}
	S operator-(S r) const {return{x-r.x,y-r.y};}
	S operator*(T r) const { return {x*r, y*r}; }
	S operator/(T r) const { return {x/r, y/r}; }
	S operator-()    const { return {-x, -y}; }

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

// ---

ll n, S;
vector<vec2> points;
Vi links;
vector<pair<vec2, Pii>> segments;

void run() {
	cin >> n >> S;
	points.resize(n);
	each(p, points) cin >> p.x >> p.y;

	sort(all(points), [](vec2 l, vec2 r) { return mp(l.y, l.x) < mp(r.y, r.x); });
	links.resize(n);
	iota(all(links), 0);

	rep(i, 0, n) rep(j, i+1, n) {
		vec2 line = points[j]-points[i];
		if (line.upper()) segments.pb({ line, {i,j} });
		else              segments.pb({ -line, {j,i} });
	}

	sort(all(segments));
	deb(S, points, segments);

	each(seg, segments) {
		int &i = links[seg.y.x], &j = links[seg.y.y];
		assert(i+1 == j);

		auto iter = lower_bound(all(points), S*2, [&](vec2 l, ll r) {
			return seg.x.cross(l-points[i]) < r;
		});

		if (iter != points.end() && seg.x.cross(*iter-points[i]) == S*2) {
			cout << "Yes\n";
			cout << points[i].x << ' ' << points[i].y << '\n';
			cout << points[j].x << ' ' << points[j].y << '\n';
			cout << iter->x << ' ' << iter->y << '\n';
			return;
		}

		swap(i, j);
		swap(points[i], points[j]);
	}

	cout << "No\n";
}