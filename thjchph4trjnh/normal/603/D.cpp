#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-12
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

struct Point {
	ld x, y;
	Point() {}
	Point(ld x, ld y) : x(x), y(y) {}
	Point(const Point& p) : x(p.x), y(p.y) {}
	bool operator < (const Point& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
	bool operator == (const Point& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
	Point operator + (const Point& p) const {return Point(x + p.x, y + p.y);}
	Point operator - (const Point& p) const {return Point(x - p.x, y - p.y);}
	Point operator * (ld c) const {return Point(x * c, y * c);}
	Point operator / (ld c) const {return Point(x / c, y / c);}
};

ld cross(Point p, Point q) {return p.x * q.y - p.y * q.x;}
ld area(Point a, Point b, Point c) {return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;}
ld area2(Point a, Point b, Point c) {return cross(a, b) + cross(b, c) + cross(c, a);}
ld dot(Point p, Point q) {return p.x * q.x + p.y * q.y;}
ld dist(Point p, Point q) {return sqrt(dot(p - q, p - q));}
ld dist2(Point p, Point q) {return dot(p - q, p - q);}

Point RotateCCW90(Point p) {return Point(-p.y, p.x);}
Point RotateCW90(Point p) {return Point(p.y, -p.x);}
Point RotateCCW(Point p, ld t) {return Point(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));}

Point ProjectPointLine(Point a, Point b, Point c) {
	return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
#define PT Point

const int maxn = 2010;
int n;
PT p[maxn];

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		PT q[2];
		if (a) {
			q[0] = PT(1.0 * c / a, 0);
			q[1] = PT(1.0 * (c - b) / a, 1);
		}
		else {
			q[0] = PT(0, 1.0 * c / b);
			q[1] = PT(1, 1.0 * (c - a) / b);
		}
		p[i] = ProjectPointLine(q[0], q[1], PT(0, 0));
	}
	
	ll ans = 0;
	FOR(i, 0, n) {
		int s = 0, t = 0;
		vector<PT> vp;
		FOR(j, i + 1, n) if (i != j) {
			PT r = p[j] - p[i];
			ld u = r.x;
			ld v = r.y;
			if (u == 0) {
				if (v < 0) {
					u *= -1;
					v *= -1;
				}
			}
			else if (u < 0) {
				u *= -1;
				v *= -1;
			}
			if (fabs(u) < EPS && fabs(v) < EPS) s++;
			else {
				if (fabs(u) < EPS) {
					u = 0;
					v = 1;
				}
				else if (fabs(v) < EPS) {
					u = 1;
					v = 0;
				}
				else {
					u /= v;
					v = 1;
				}
				t++; vp.pb(PT(u, v));
			}
		}
		sort(all(vp));
		int cur = 0;
		while (cur < sz(vp)) {
			int l = cur, r = sz(vp) - 1;
			while (l < r) {
				int m = (l + r + 1) >> 1;
				if (fabs(dot(vp[m] - vp[cur], vp[m] - vp[cur])) < EPS * EPS) l = m;
				else r = m - 1;
			}
			ans += 1LL * (l - cur + 1) * (l - cur) / 2;
			cur = l + 1;
		}
		ans += 1LL * s * (s - 1) / 2;
		ans += 1LL * s * t;
	}
	cout<<ans;
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}