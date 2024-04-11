#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const double EPS = 1E-7;
const double START = 1;
struct point{
	double x, y;
	point(double _x=0, double _y=0):x(_x), y(_y){}
};
double pw2(double x) {return x*x;}
point operator + (point a, point b) {return point(a.x + b.x, a.y + b.y);}
point operator - (point a, point b) {return point(a.x - b.x, a.y - b.y);}
point operator * (point a, double k) {return point(a.x * k, a.y * k);}
point operator / (point a, double k) {return point(a.x / k, a.y / k);}
double length(point a) {return sqrt(pw2(a.x) + pw2(a.y));}
point unit(point a) {double l = length(a); return point(a.x/l, a.y/l);}
int cmp(double x) {return (-EPS < x && x < EPS) ? 0 : (x > EPS ? 1 : -1);}
point c[3], nw; double r[3], k[3], ans;
double get_ans(point p) {
	for(int i=0;i<3;i++)
		k[i] = r[i]/length(p - c[i]);
	return (pw2(k[0] - k[1]) + pw2(k[0] - k[2]) + pw2(k[1] - k[2]))/3;
}
bool accept(point p) {
	double del = get_ans(p) - ans;
	if( del < 0 ) {
		ans += del;
		return true;
	}
	else return false;
}
int main() {
	int cnt = 0;
	for(int i=0;i<3;i++) {
		scanf("%lf%lf%lf", &c[i].x, &c[i].y, &r[i]);
		nw = nw + c[i];
	}
	nw = nw / 3, ans = get_ans(nw);
	for(double T=START;T>=EPS&&cnt<=100000;) {
		bool tag = false;
		if( accept(nw + point(-T, 0)) ) nw = nw + point(-T, 0), tag = true;
		if( accept(nw + point(0, -T)) ) nw = nw + point(0, -T), tag = true;
		if( accept(nw + point(T, 0)) ) nw = nw + point(T, 0), tag = true;
		if( accept(nw + point(0, T)) ) nw = nw + point(0, T), tag = true;
		if( !tag ) T /= 2; cnt++;
	}
	if( cmp(ans) == 0 )
		printf("%lf %lf\n", nw.x, nw.y);
	return 0;
}