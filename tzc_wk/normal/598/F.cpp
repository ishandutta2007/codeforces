#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/hash_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
template <typename T1, typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1, typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
const int MAXN = 1000;
const ld EPS = 1e-9;
const ld Pi = acos(-1);
int n, qu;
int sgn(ld x) {return ((x > EPS) ? 1 : ((x < -EPS) ? -1 : 0));}
bool eq(ld x, ld y) {return sgn(x - y) == 0;}
struct point {
	ld x, y;
	point() {x = y = 0;}
	point(ld _x, ld _y) {x = _x; y = _y;}
	point operator + (const point &rhs) {return point(x + rhs.x, y + rhs.y);}
	point operator - (const point &rhs) {return point(x - rhs.x, y - rhs.y);}
	point operator * (const ld &rhs) {return point(x * rhs, y * rhs);}
	ld operator | (const point &rhs) {return 1.0 * x * rhs.y - 1.0 * y * rhs.x;}
	ld operator ~ () {return sqrt(x * x + y * y);}
	ld operator ! () {return atan2(y, x);} 
	bool operator == (const point &rhs) const {return eq(x, rhs.x) && eq(y, rhs.y);}
	bool operator < (const point &rhs) const {return sgn(x - rhs.x) < 0 || (sgn(x - rhs.x) == 0 && sgn(y - rhs.y) < 0);}
} p[MAXN + 5];
bool parallel(point A1, point B1, point A2, point B2) {
	ld arg1 = !(B1 - A1), arg2 = !(B2 - A2);
	return eq(arg1, arg2) || eq(fabs(arg1 - arg2), Pi);
}
point inter(point A1, point B1, point A2, point B2) {
	if (parallel(A1, B1, A2, B2)) return point(1e9, 1e9);
	ld lft = (B1 - A1) | (A2 - A1), rit = (B1 - A1) | (B2 - A1);
	return (B2 - A2) * (lft / (lft - rit)) + A2;
}
bool on_line(point A, point B, point C) {return sgn((C - A) | (B - A)) == 0;}
bool on_seg(point A, point B, point C) {
	return sgn(C.x - min(A.x, B.x)) >= 0 && sgn(C.x - max(A.x, B.x)) <= 0 &&
		   sgn(C.y - min(A.y, B.y)) >= 0 && sgn(C.y - max(A.y, B.y)) <= 0;
}
int main() {
	scanf("%d%d", &n, &qu);
	for (int i = 1; i <= n; i++) scanf("%Lf%Lf", &p[i].x, &p[i].y);
	while (n > 3) {
		bool flg = 0;
		for (int i = 1; i <= n; i++) {
			if (parallel(p[i], p[(i - 2 + n) % n + 1], p[i], p[i % n + 1])) {
				flg = 1;
				for (int j = i + 1; j <= n; j++) swap(p[j], p[j - 1]);
				p[n] = point(0, 0); --n; break;
			}
		}
		if (!flg) break;
	}
	while (qu--) {
		point A, B; scanf("%Lf%Lf%Lf%Lf", &A.x, &A.y, &B.x, &B.y);
		vector<pair<point, int> > vec;
		vector<pair<point, point> > seg;
		vector<int> has;
		for (int i = 1; i <= n; i++) {
			point C = inter(A, B, p[i], p[i % n + 1]);
			if (on_seg(p[i], p[i % n + 1], C)) {
				int op = -1;
				if (C == p[i]) op = (sgn((B - A) | (p[i % n + 1] - p[i])) > 0);
				if (C == p[i % n + 1]) op = (sgn((B - A) | (p[i] - p[i % n + 1])) > 0);
				vec.pb(mp(C, op));
			}
		}
		for (int i = 1; i <= n; i++) if (on_line(A, B, p[i]) && on_line(A, B, p[i % n + 1]))
			seg.pb(mp(max(p[i], p[i % n + 1]), min(p[i], p[i % n + 1])));
		sort(vec.begin(), vec.end()); sort(seg.begin(), seg.end());
		has.resize(vec.size(), 0); ld res = 0; int cur = 0;
		for (int i = 1, j = 0; i < vec.size(); i++) {
			pair<point, point> pp = mp(vec[i].fi, vec[i - 1].fi);
			while (j < seg.size() && seg[j] < pp) ++j;
			has[i] = (j < seg.size() && seg[j] == pp);
		}
		for (int i = 0; i + 1 < vec.size(); i++) {
			cur ^= 1;
			if (i && vec[i - 1].se + vec[i].se == 1 && (vec[i].fi == vec[i - 1].fi || has[i])) cur ^= 1;
			if (cur || has[i + 1]) res += (~(vec[i + 1].fi - vec[i].fi));
		}
		printf("%.10Lf\n", res);
	}
	return 0;
}