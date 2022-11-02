#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

#define double long double

const int MAXN = 10000;
const double INF = 1E18;
const double EPS = 1E-10;

int dcmp(double x) {
	return fabs(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

struct point{
	int x, y; point() {}
	point(int _x, int _y) : x(_x), y(_y) {}
	
	friend point operator + (point a, point b) {return point(a.x + b.x, a.y + b.y);}
	friend point operator - (point a, point b) {return point(a.x - b.x, a.y - b.y);}
	friend int operator * (point a, point b) {return a.x*b.x + a.y*b.y;}
	friend int operator ^ (point a, point b) {return a.x*b.y - b.x*a.y;}
	
	friend bool operator < (point a, point b) {
		return (a.x == b.x ? a.y < b.y : a.x < b.x);
	}
};

double cot(point p, point q) {return 1.0 * (p * q) / (p ^ q);}
point a[MAXN + 5], b[MAXN + 5]; int n, m;
bool get(point p1, point p2) {
	double l = -INF, r = INF;
	for(int i=1;i<=n;i++) {
		if( ((p1 - a[i]) ^ (p2 - a[i])) == 0 ) {
			if( ((p1 - a[i]) * (p2 - a[i])) > 0 ) return false;
		}
		else {
			double k = cot(p1 - a[i], p2 - a[i]);
			if( ((p1 - a[i]) ^ (p2 - a[i])) > 0 )
				l = max(l, k);
			else r = min(r, k);
		}
	}
	for(int i=1;i<=m;i++) {
		if( ((p1 - b[i]) ^ (p2 - b[i])) == 0 ) {
			if( ((p1 - b[i]) * (p2 - b[i])) <= 0 ) return false;
		}
		else {
			double k = cot(p1 - b[i], p2 - b[i]);
			if( ((p1 - b[i]) ^ (p2 - b[i])) > 0 )
				r = min(r, k);
			else l = max(l, k);
		}
	}
	return dcmp(r - l) > 0;
}

bool solve(int l, int r) {
	if( get(a[l], a[r]) ) return true;
	if( l + 1 == r ) return false;
	
	int p = l + 1;
	for(int i=l+1;i<=r-1;i++)
		if( dcmp(cot(a[r] - a[i], a[l] - a[i]) - cot(a[r] - a[p], a[l] - a[p])) < 0 )
			p = i;
	return solve(l, p) || solve(p, r);
}

bool check(point *p, int _n, point *q, int _m) {
	n = 0; int o = 1;
	for(int i=1;i<=_n;i++) {
		while( n > o && ((a[n - 1] - a[n]) ^ (p[i] - a[n])) <= 0 )
			n--;
		a[++n] = p[i];
	}
	o = n;
	for(int i=_n-1;i>=1;i--) {
		while( n > o && ((a[n - 1] - a[n]) ^ (p[i] - a[n])) <= 0 )
			n--;
		a[++n] = p[i];
	}
	n--;
	for(int i=1;i<=_m;i++) b[i] = q[i]; m = _m;
	
	return solve(1, n);
}

point M[MAXN + 5], S[MAXN + 5];
int main() {
	int _n, _m; scanf("%d%d", &_n, &_m);
	for(int i=1;i<=_n;i++) scanf("%d%d", &M[i].x, &M[i].y);
	for(int i=1;i<=_m;i++) scanf("%d%d", &S[i].x, &S[i].y);
	sort(M + 1, M + _n + 1), sort(S + 1, S + _m + 1);
	puts(_n == 1 || _m == 1 || check(M, _n, S, _m) || check(S, _m, M, _n) ? "YES" : "NO"); 
}