#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define border(p) (0 <= p.x && p.x <= 1E5 && 0 <= p.y && p.y <= 1E5)
#define inside(p, v, x) (fabs(x.x - p.x) + fabs(x.y - p.y) <= v)

const int MAXN = int(1E6);
const double INF = 1E10;
const double EPS = 1E-9;

int dcmp(double x) {return fabs(x) <= 0 ? 0 : (x > 0 ? 1 : -1);}

struct point{
	double x, y;
	point() : x(), y() {}
	point(double _x, double _y) : x(_x), y(_y) {}
	
	friend point operator + (point a, point b) {return point(a.x + b.x, a.y + b.y);}
	friend point operator - (point a, point b) {return point(a.x - b.x, a.y - b.y);}
	friend point operator * (point a, double k) {return point(a.x * k, a.y * k);}
	friend point operator / (point a, double k) {return point(a.x / k, a.y / k);}
	friend double operator * (point a, point b) {return a.x*b.x + a.y*b.y;}
	friend double operator ^ (point a, point b) {return a.x*b.y - a.y*b.x;}
	friend bool operator < (point a, point b) {return (a.x == b.x ? a.y < b.y : a.x < b.x);}
	friend bool operator == (point a, point b) {return (a.x == b.x) && (a.y == b.y);}
	
	friend double length(point a) {return sqrt(a * a);}
	friend double dist(point a, point b) {return length(a - b);}
	friend double area(point a, point b, point c) {return ((c - a) ^ (b - a)) / 2;}
	friend double slope(point a, point b) {
		if( a.x == b.x ) return a.y < b.y ? INF : -INF;
		else return 1.0*(a.y - b.y)/(a.x - b.x);
	}
	
	friend void read(point &a) {scanf("%lf%lf", &a.x, &a.y);}
};

point stk[MAXN + 5], t[MAXN + 5], a[MAXN + 5];
int siz, cnt, tp;
void convex() {
	sort(a + 1, a + cnt + 1);
	
	stk[tp = 1] = a[1];
	for(int i=2;i<=cnt;i++) {
		if( a[i] == a[i-1] ) continue;
		while( tp >= 2 && slope(stk[tp-1], stk[tp]) <= slope(stk[tp], a[i]) )
			tp--;
		stk[++tp] = a[i];
	}
	for(int i=1;i<=tp;i++)
		t[++siz] = stk[i];
	
	stk[tp = 1] = a[1];
	for(int i=2;i<=cnt;i++) {
		if( a[i] == a[i-1] ) continue;
		while( tp >= 2 && slope(stk[tp-1], stk[tp]) >= slope(stk[tp], a[i]) )
			tp--;
		stk[++tp] = a[i];
	}
	for(int i=tp-1;i>=2;i--)
		t[++siz] = stk[i];
}
int nxt(int x) {return (x == siz ? 1 : x + 1);}
void print(point p) {printf("%.0f %.0f\n", p.x, p.y);}
void solve() {
	convex();
	double r = 0; int p = 0;
	for(int i=1;i<=siz;i++) {
		int j = nxt(i), k = nxt(j);
		double r1 = dist(t[i],t[j])*dist(t[i],t[k])*dist(t[j],t[k])/(4*area(t[i],t[j],t[k]));
		if( dcmp(r1 - r) > 0 ) p = i, r = r1;
	}
	print(t[p]), p = nxt(p);
	print(t[p]), p = nxt(p);
	print(t[p]), p = nxt(p);
}

void update1(point p) {
	if( border(p) ) a[++cnt] = p;
}
void update2(point p, double v, point x) {
	if( inside(p, v, x) ) a[++cnt] = x;
}

int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		double x, y, v; scanf("%lf%lf%lf", &x, &y, &v);
		point p = point(x, y);
		update1(point(x + v, y)), update1(point(x - v, y));
		update1(point(x, y + v)), update1(point(x, y - v));
		if( x - v < 0 ) update1(point(0, y + (v - x))), update1(point(0, y - (v - x)));
		if( y - v < 0 ) update1(point(x + (v - y), 0)), update1(point(x - (v - y), 0));
		if( x + v > 1E5 ) update1(point(1E5, y + (v - (1E5 - x)))), update1(point(1E5, y - (v - (1E5 - x))));
		if( y + v > 1E5 ) update1(point(x + (v - (1E5 - y)), 1E5)), update1(point(x - (v - (1E5 - y)), 1E5));
		update2(p, v, point(0, 0)), update2(p, v, point(1E5, 1E5));
		update2(p, v, point(0, 1E5)), update2(p, v, point(1E5, 0));
	}
	solve();
}