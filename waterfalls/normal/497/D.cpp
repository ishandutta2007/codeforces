#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long double ld;

ld sq(ld x) { return x*x; }
ld EPS = 1e-18;

struct Point {
	ld x,y;
	ld dist(Point o) { return sqrt(sq(x-o.x)+sq(y-o.y)); }
	ld norm() { return dist({0,0}); }
	Point operator-(Point o) { return {x-o.x,y-o.y}; }
	void operator-=(Point o) { x-=o.x, y-=o.y; }
};
struct Segment {
	Point a,b;
	bool vert() { return fabs(a.x-b.x)<EPS; }
	ld slope() { return (b.y-a.y)/(b.x-a.x); }
	ld yint() { return a.y-slope()*a.x; }
	bool on(Point o) {
		if (o.x+EPS<min(a.x,b.x) || o.x-EPS>max(a.x,b.x)) return false;
		if (o.y+EPS<min(a.y,b.y) || o.y-EPS>max(a.y,b.y)) return false;
		return true;
	}
};

bool check(Point p, vector<Segment> A, Point origin, Point center) {
	p-=origin;
	for (Segment& s: A) s.a-=origin, s.b-=origin;
	center-=origin;
    Point around = p-center;
    p-=around;
    ld dist = p.norm();
    for (Segment s: A) {
		s.a-=around;
		s.b-=around;
		ld close = min(s.a.norm(),s.b.norm());
		if (s.vert()) {
			if (s.on({s.a.x,0})) close = min(close,fabs(s.a.x));
		} else {
			ld x = -s.yint()/(s.slope()+1/s.slope());
			Point res = {x,s.slope()*x+s.yint()};
			if (s.on(res)) close = min(close,res.norm());
		}
		ld far = max(s.a.norm(),s.b.norm());
		if (close<dist+EPS && dist-EPS<far) return true;
    }
    return false;
}

double x,y;
vector<Point> read(int len) {
	vector<Point> res;
	for (int i=0;i<len;i++) {
		scanf("%lf%lf",&x,&y);
		Point p = {x,y};
		res.push_back(p);
	}
	return res;
}

int m,n;
Point P,Q;
vector<Point> Ap,Bp;
vector<Segment> A,B;

int main() {
	scanf("%lf%lf",&x,&y);
	P = {x,y};
	scanf("%d",&n);
	Ap = read(n);
	for (int i=0;i<n;i++) A.push_back({Ap[i],Ap[(i+1)%n]});
	scanf("%lf%lf",&x,&y);
	Q = {x,y};
	scanf("%d",&m);
	Bp = read(m);
	for (int i=0;i<m;i++) B.push_back({Bp[i],Bp[(i+1)%m]});
	int found = 0;
	for (Point p: Bp) if (check(p,A,P,Q)) found = 1;
	for (Point p: Ap) if (check(p,B,Q,P)) found = 1;
	printf("%s\n",found ? "YES" : "NO");

	return 0;
}