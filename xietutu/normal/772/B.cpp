#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef pair<ld, ld> point;
typedef unsigned int ui;
#define PB push_back
#define MP make_pair
#define X first
#define Y second
const int maxn = 2010;
int n;
inline ld sqr(ld x) {
	return x * x;
}
point operator-(const point& a, const point& b) {
	return point(a.X - b.X, a.Y - b.Y);
}
ld det(const point& a, const point& b) {
	return a.X * b.Y - a.Y * b.X;
}
ld dist(const point& a, const point& b) {
	return sqrt(sqr(a.X - b.X) + sqr(a.Y - b.Y));
}
ld dis_point_segment(const point& p, const point& s, const point& t) {
	return fabs(det(s - p, t - p) / dist(s, t));
}
point a[maxn];
ld ans;
int main() {
	//freopen("B.in","r",stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[i].X = x; a[i].Y = y;
		a[n + i] = a[i];
	}
	ans = 1e20;
	for (int i = 3; i <= n + 3; ++i) {
		ans = min(ans, dis_point_segment(a[i], a[i - 1], a[i + 1]) / 2);
		//ans = min(ans, dis_point_segment(a[i], a[i + 1], a[i + 2]) );
		//ans = min(ans, dis_point_segment(a[i], a[i - 2], a[i - 1]) );
	}
	double Ans = ans;
	printf("%.10lf\n", Ans);
}