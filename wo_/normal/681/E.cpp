#include<cstdio>
#include<vector>
#include<utility>
#include<cmath>
#include<cstdlib>
#include<complex>
#include<algorithm>

using namespace std;

typedef double Real;
typedef complex<Real> Point;
typedef complex<Real> Vector;

const Real eps = 1e-8;

const Real PI = acos(-1.0);

const Real ZERO = 0;

template<class T> bool eq_(T a, T b){
	return abs(a - b) < eps;
}

template<class T> bool lt_(T a, T b){
	if(eq_(a, b)) return false;
	return a < b;
}

template<class T> bool le_(T a, T b){
	if(eq_(a, b)) return true;
	return a < b;
}

inline Real normalize(Real x){
	while(x > PI) x -= PI * 2;
	while(x <= -PI) x += PI * 2;
	return x;
}

struct Circle : vector<Real> {
	Point c;
	Real r;
	Circle(){}
	Circle(Point c, Real r):c(c), r(r){}
	Point getPoint(Real ang){
		return c + Point(r * cos(ang), r * sin(ang));
	}
};

void iCC(Circle &c, Circle &c2){
	if(eq_(c.c, c2.c)) return; //same center
	Real d = abs(c.c - c2.c);
	Real r = c.r, r2 = c2.r;
	if(lt_(ZERO, d - (r + r2))) return; //not touch
	else if(eq_(ZERO, d - (r + r2))){ //out tan
		Real ang = normalize(arg(c2.c - c.c));
		c.push_back(ang);
		return;
	}else if(lt_(ZERO, d - abs(r - r2))){ //intersect at two points
		Real ang = arg(c2.c - c.c);
		Real ang2 = acos((r * r + d * d - r2 * r2) / (2.0 * r * d));
		c.push_back(normalize(ang - ang2));
		c.push_back(normalize(ang + ang2));
	}else if(eq_(ZERO, d - abs(r - r2))){ //in tan
		if(r > r2){
			c.push_back(normalize(arg(c2.c - c.c)));
		}else{
			c.push_back(normalize(-arg(c2.c - c.c)));
		}
	}else return; //contained
}

void tCP(Circle &c, Point p){
	Real d = abs(p - c.c);
	if(le_(ZERO, c.r - d)) return; //ignore ON case
	Real r = c.r;
	Real ang = arg(p - c.c);
	Real ang2 = acos(r / d);
	c.push_back(normalize(ang - ang2));
	c.push_back(normalize(ang + ang2));
}

typedef pair<Real, int> P;

vector<P> events;

Real D;
Point init_p;

void proc(Point c, Real r){
	Circle c1 = Circle(init_p, D);
	Circle c2 = Circle(c, r);
	Real d = abs(c - init_p);
	if(eq_((Real)1.0, d / r)){
		long long dx = (long long)((c - init_p).real() + 0.5);
		long long dy = (long long)((c - init_p).imag() + 0.5);
		long long d2 = dx * dx + dy * dy;
		long long rint = r + 0.5;
		if(d2 <= rint * rint){
			printf("1.0\n");
			exit(0);
		}else{
			Real ang = arg(c - init_p);
			Real a = normalize(ang - PI / 2);
			Real b = normalize(ang + PI / 2);
			if(a < b){
				events.push_back(P(a, 1));
				events.push_back(P(b, -1));
			}else{
				events.push_back(P(a, 1));
				events.push_back(P(PI, -1));
				events.push_back(P(-PI, 1));
				events.push_back(P(b, -1));
			}
			return;
		}
	}
	if(le_(abs(c - init_p), r)){
		printf("1.0\n");
		exit(0);
	}
	tCP(c2, init_p);
	if(c2.size() == 2){
		Real ang = c2[0];
		Point p = c2.getPoint(ang);
		Real d = abs(init_p - p);
		if(le_(d, D)){
			Real a = c2[0], b = c2[1];
			Point pa = c2.getPoint(a), pb = c2.getPoint(b);
			a = arg(pa - init_p), b = arg(pb - init_p);
			//printf("a %f %f\n", a, b);
			if(a > b) swap(a, b);
			if(b - a < PI){
				events.push_back(P(a, 1));
				events.push_back(P(b, -1));
			}else{
				events.push_back(P(b, 1));
				events.push_back(P(PI, -1));
				events.push_back(P(-PI, 1));
				events.push_back(P(a, -1));
			}
		}else{
			iCC(c1, c2);
			if(c1.size() >= 2){
				Real a = c1[0], b = c1[1];
				//printf("b %f %f\n", a, b);
				if(a > b) swap(a, b);
				if(b - a < PI){
					events.push_back(P(a, 1));
					events.push_back(P(b, -1));
				}else{
					events.push_back(P(b, 1));
					events.push_back(P(PI, -1));
					events.push_back(P(-PI, 1));
					events.push_back(P(a, -1));
				}
			}
		}
	}
}

double xs[100100], ys[100100], rs[100100];
int N;

void input(){
	double x0, y0, v, t;
	scanf("%lf%lf%lf%lf", &x0, &y0, &v, &t);
	D = (Real)v * t;
	init_p = Point(x0, y0);
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%lf%lf%lf", xs + i, ys + i, rs + i);
	}
}

Real solve(){
	for(int i = 0; i < N; ++i){
		proc(Point(xs[i], ys[i]), rs[i]);
	}
	sort(events.begin(), events.end());
	Real sum = 0;
	Real prv = -PI;
	int cnt = 0;
	for(int i = 0; i < events.size(); ++i){
		Real val = events[i].first;
		int c = events[i].second;
//		printf("%f %d\n", val, c);
		if(cnt > 0){
			sum += (val - prv);
		}
		cnt += c;
		prv = val;
	}
	return (sum / (PI * 2));
}

int main(){
	input();
	double ans = solve();
	printf("%.9f\n", ans);
	return 0;
}