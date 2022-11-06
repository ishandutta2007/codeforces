#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

struct Point {
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	Point(const Point& p) : x(p.x), y(p.y) {}
	bool operator < (const Point& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
	bool operator == (const Point& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
	Point operator + (const Point& p) const {return Point(x + p.x, y + p.y);}
	Point operator - (const Point& p) const {return Point(x - p.x, y - p.y);}
	Point operator * (double c) const {return Point(x * c, y * c);}
	Point operator / (double c) const {return Point(x / c, y / c);}
};
double cross(Point p, Point q) {return p.x * q.y - p.y * q.x;}
double area(Point a, Point b, Point c) {return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;}
double area2(Point a, Point b, Point c) {return cross(a, b) + cross(b, c) + cross(c, a);}
double dot(Point p, Point q) {return p.x * q.x + p.y * q.y;}
double dist(Point p, Point q) {return sqrt(dot(p - q, p - q));}
double dist2(Point p, Point q) {return dot(p - q, p - q);}

Point RotateCCW90(Point p) {return Point(-p.y, p.x);}
Point RotateCW90(Point p) {return Point(p.y, -p.x);}
Point RotateCCW(Point p, double t) {
	return Point(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}

bool LinesParallel(Point a, Point b, Point c, Point d) {
	return fabs(cross(b - a, c - d)) < EPS;
}
bool LinesCollinear(Point a, Point b, Point c, Point d) {
	return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS && fabs(cross(c - d, c - a)) < EPS;
}
bool SegmentsIntersect(Point a, Point b, Point c, Point d) {
	if (LinesCollinear(a, b, c, d)) {
		if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
		if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0) return false;
		return true;
	}
	if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return false;
	if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return false;
	return true;
}
Point ComputeLineIntersection(Point a, Point b, Point c, Point d) {
	b = b - a; d = c - d; c = c - a;
	assert(dot(b, b) > EPS && dot(d, d) > EPS);
	return a + b * cross(c, d) / cross(b, d);
}
#define PT Point

const int maxn = 1010;
int n, m;

void solve() {
	cin>>n>>m;
	vector<PT> poly;
	FOR(i, 0, n) {double x, y; cin>>x>>y; poly.pb(PT(x, y));}
	FOR(i, 0, m) {
		PT a, b; cin>>a.x>>a.y>>b.x>>b.y;
		vector<pair<PT, int> > vp;
		FOR(j, 0, n) {
			PT u = poly[j], v = poly[(j + 1) % n], w = poly[(j + n - 1) % n];
			if (!LinesParallel(a, b, u, v) && cross(u - a, b - a) * cross(v - a, b - a) < 0) {
				PT p = ComputeLineIntersection(a, b, u, v);
				if (cross(u - a, b - a) > 0) vp.pb(mp(p, 2)); else vp.pb(mp(p, -2));
			}
			if (fabs(cross(u - a, b - a)) < EPS) {
				int r = 0;
				if (cross(w - a, b - a) > EPS) r++; else if (cross(w - a, b - a) < -EPS) r--;
				if (cross(v - a, b - a) > EPS) r--; else if (cross(v - a, b - a) < -EPS) r++;
				vp.pb(mp(u, r));
			}
		}
		sort(all(vp));
		double ans = 0;
		int tot = 0;
		FOR(j, 0, sz(vp) - 1) {
			tot += vp[j].se;
			if (tot) ans += dist(vp[j].fi, vp[j + 1].fi);
		}
		cout<<fixed<<setprecision(9)<<ans<<"\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}