#include <bits/stdc++.h>

const int N = 100000;

struct point{
	double x, y;

	friend point operator + (const point &a, const point &b) {return (point){a.x + b.x, a.y + b.y};}
	friend point operator - (const point &a, const point &b) {return (point){a.x - b.x, a.y - b.y};}
	friend point operator * (const point &a, double k) {return (point){a.x * k, a.y * k};}
	friend point operator / (const point &a, double k) {return (point){a.x / k, a.y / k};}
	
	void read() {scanf("%lf%lf", &x, &y);}
}p[N + 5]; int n;

struct poly{
	double A, B, C;
	friend poly operator + (const poly &a, const poly &b) {
		return (poly){a.A + b.A, a.B + b.B, a.C + b.C};
	}
	friend poly operator += (poly &a, const poly &b) {return a = a + b;}
	double calc(double x) {return (A * x + B) * x + C;}
}pl[2*N + 5]; double ans[2*N + 5];

void update1(point p1, point p2, double coef) {
	if( p1.x > p2.x ) std::swap(p1.x, p2.x);
	
	int x1 = (int)ceil(p1.x) + N, x2 = (int)ceil(p2.x) + N;
	
	double dx = fabs(p2.x - p1.x), dy = fabs(p2.y - p1.y), s = dx * dy / 2;
	if( dx > 1E-9 ) {
		double k = s / dx / dx;
		pl[x1].A += k * coef, pl[x1].B -= 2 * k * p1.x * coef, pl[x1].C += k * p1.x * p1.x * coef;
		pl[x2].A -= k * coef, pl[x2].B += 2 * k * p1.x * coef, pl[x2].C -= k * p1.x * p1.x * coef;
	}
	pl[x2].B += dy * coef, pl[x2].C += (s - p2.x * dy) * coef;
}
void update(point p1, point p2, point p3, point p4) {
	/*
	puts("");
	printf("! %lf %lf %lf %lf\n", p1.x, p1.y, p2.x, p2.y);
	printf("! %lf %lf %lf %lf\n", p3.x, p3.y, p4.x, p4.y);
	puts("");
	*/
	
	point p5 = (p1 + p3) / 2, p6 = (p2 + p4) / 2;
	update1(p1, p2, -1), update1(p3, p4, -1), update1(p5, p6, 2);
	pl[0].C += fabs((p3.x - p1.x) + (p4.x - p2.x)) * (p1.y - p2.y) / 2;
}

point get1(point p1, point p2, double y) {
	return p1 + (p2 - p1) * ((y - p1.y) / (p2.y - p1.y));
}
int nxt(int x) {return x + 1 == n ? 0 : x + 1;}
int lst(int x) {return x == 0 ? n - 1 : x - 1;}
int main() {
	int q; scanf("%d%d", &n, &q);
	for(int i=0;i<n;i++) p[i].read();
	
	int mx = 0; for(int i=0;i<n;i++) if( p[i].y > p[mx].y ) mx = i;
	int p1 = mx, p2 = mx; point lst1 = p[mx], lst2 = p[mx];
	while( true ) {
		if( nxt(p1) == lst(p2) ) {
			update(lst1, p[nxt(p1)], lst2, p[lst(p2)]);
			break;
		} else if( p[nxt(p1)].y > p[lst(p2)].y ) {
			point pt = get1(lst2, p[lst(p2)], p[nxt(p1)].y);
			update(lst1, p[nxt(p1)], lst2, pt);
			lst1 = p[p1 = nxt(p1)], lst2 = pt;
		} else {
			point pt = get1(lst1, p[nxt(p1)], p[lst(p2)].y);
			update(lst1, pt, lst2, p[lst(p2)]);
			lst1 = pt, lst2 = p[p2 = lst(p2)];
		}
	}
	
	for(int i=1;i<=2*N;i++) pl[i] += pl[i - 1], ans[i] = pl[i].calc(i - N);
	for(int i=1,x;i<=q;i++) scanf("%d", &x), printf("%.9f\n", ans[N + x]);
}