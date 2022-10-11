#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define derr if(0) cerr
#define f first
#define s second
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;


template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};

typedef Point<double> p;

template<class P>
int segmentIntersection(const P& s1, const P& e1,
		const P& s2, const P& e2, P& r1, P& r2) {
	if (e1==s1) {
		if (e2==s2) {
			if (e1==e2) { r1 = e1; return 1; } //all equal
			else return 0; //different point segments
		} else return segmentIntersection(s2,e2,s1,e1,r1,r2);//swap
	}
	//segment directions and separation
	P v1 = e1-s1, v2 = e2-s2, d = s2-s1;
	auto a = v1.cross(v2), a1 = v1.cross(d), a2 = v2.cross(d);
	if (a == 0) { //if parallel
		auto b1=s1.dot(v1), c1=e1.dot(v1),
		     b2=s2.dot(v1), c2=e2.dot(v1);
		if (a1 || a2 || max(b1,min(b2,c2))>min(c1,max(b2,c2)))
			return 0;
		r1 = min(b2,c2)<b1 ? s1 : (b2<c2 ? s2 : e2);
		r2 = max(b2,c2)>c1 ? e1 : (b2>c2 ? s2 : e2);
		return 2-(r1==r2);
	}
	if (a < 0) { a = -a; a1 = -a1; a2 = -a2; }
	if (0<a1 || a<-a1 || 0<a2 || a<-a2)
		return 0;
	r1 = s1-v1*a2/a;
	return 1;
}

void die() {
  cout << "-1\n";
  exit(0);
}

void solve() {
  int n;
  cin >> n;
  p a,b; // corners
  // CB
  // AD
  cin >> a.x >> a.y >> b.x >> b.y;
  double EPS = 1e-9;
  a.x += EPS;
  a.y += EPS;
  b.x -= EPS;
  b.y -= EPS;
  if(a.x > b.x || a.y > b.y) die();
  p c(a.x, b.y);
  p d(b.x, a.y);
  vector<pair<double, double>> pdd;
  for(int i = 0; i < n; i++) {
    p start, v;
    cin >> start.x >> start.y >> v.x >> v.y;
    p speed = v;
    v = v.unit();
    vector<p> ints;
    if(a.x <= start.x && start.x <= b.x && a.y <= start.y && start.y <= b.y) {
      ints.push_back(start);
      if(speed.dist() < EPS) {
        continue;
      }
    }
    p lhs, rhs;
    int amt;
    amt = segmentIntersection(start, start + v * 1e6, a, c, lhs, rhs);
    if(amt >= 1) ints.push_back(lhs);
    if(amt >= 2) ints.push_back(rhs);
    amt = segmentIntersection(start, start + v * 1e6, b, c, lhs, rhs);
    if(amt >= 1) ints.push_back(lhs);
    if(amt >= 2) ints.push_back(rhs);
    amt = segmentIntersection(start, start + v * 1e6, b, d, lhs, rhs);
    if(amt >= 1) ints.push_back(lhs);
    if(amt >= 2) ints.push_back(rhs);
    amt = segmentIntersection(start, start + v * 1e6, a, d, lhs, rhs);
    if(amt >= 1) ints.push_back(lhs);
    if(amt >= 2) ints.push_back(rhs);
    if(sz(ints) == 0) die();
    double mind = 1e18;
    double maxd = 0;
    for(p out: ints) {
      double dd = (out - start).dist();
      mind = min(mind, dd);
      maxd = max(maxd, dd);
    }
    mind /= speed.dist();
    maxd /= speed.dist();
    // cerr << mind << " " << maxd << endl;
    pdd.emplace_back(mind, maxd);
  }
  if(sz(pdd) == 0) {
    cout << "0\n";
    return;
  }
  sort(all(pdd));
  double cand = pdd.back().f;
  for(auto out: pdd) {
    if(out.f - EPS <= cand && cand <= out.s + EPS) continue;
    die();
  }
  cout << fixed << setprecision(12) << cand << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}