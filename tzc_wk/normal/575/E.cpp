#define FASTIO
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
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {if (x > y) x = y;}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {if (x < y) x = y;}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
#define FILE_SIZE 1 << 23
char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
#ifdef LOCAL
inline char getc() {return getchar();}
inline void putc(char c) {putchar(c);}
#else
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
#endif
template<typename T> void read(T &x) {
	x = 0; char c = getc(); T neg = 0;
	while (!isdigit(c)) neg |= (c == '-'), c = getc();
	while (isdigit(c)) x = x * 10 + (c - '0'), c = getc();
	if (neg) x = -x;
}
template<typename T> void recursive_print(T x) {
	if (!x) return;
	recursive_print(x / 10); putc(x % 10 ^ 48);
}
template<typename T> void print(T x) {
	if (!x) putc('0'); if (x < 0) putc('-'), x = -x;
	recursive_print(x);
}
template<typename T> void print(T x, char c) {print(x); putc(c);}
void readstr(char *s) {
	char c = getc();
	while (c <= 32 || c >= 127) c = getc();
	while (c > 32 && c < 127) s[0] = c, s++, c = getc();
	(*s) = 0;
}
void printstr(string s) {for (int i = 0; i < s.size(); i++) putc(s[i]);}
void printstr(char *s) {
	int len = strlen(s);
	for (int i = 0; i < len; i++) putc(s[i]);
}
void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
#endif
double EPS = 1e-12;
const double Pi = acos(-1);
int sgn(double x) {return ((x < -EPS) ? -1 : ((x < EPS) ? 0 : 1));}
struct point {
	double x, y;
	point() {x = y = 0;}
	point(double _x, double _y) {x = _x; y = _y;}
	friend point operator + (const point &X, const point &Y) {return point(X.x + Y.x, X.y + Y.y);}
	friend point operator - (const point &X, const point &Y) {return point(X.x - Y.x, X.y - Y.y);}
	friend point operator * (const point &X, const double &Y) {return point(X.x * Y, X.y * Y);}
	friend double operator | (const point &X, const point &Y) {return X.x * Y.y - X.y * Y.x;}
	friend double operator ^ (const point &X, const point &Y) {return X.x * Y.x + X.y * Y.y;}
	friend bool operator == (const point &X, const point &Y) {return sgn(X.x - Y.x) == 0 && sgn(X.y - Y.y) == 0;}
	friend bool operator != (const point &X, const point &Y) {return sgn(X.x - Y.x) != 0 || sgn(X.y - Y.y) != 0;}
	friend int get_dir(point u, point v) {return sgn(u | v);} // v is on clockwise of u
	double operator ~ () const {return sqrt(x * x + y * y);}
	double operator ! () const {return atan2(y, x);}
};
bool cmp_ang(point u, point v) {
	auto up = [&](point u) {return sgn(u.y) > 0 || (sgn(u.y) == 0 && sgn(u.x) > 0);};
	bool U = up(u), V = up(v); return (U == V) ? (get_dir(u, v) > 0) : U;
}
bool cmp_xy(point u, point v) {return sgn(u.x - v.x) ? (sgn(u.x - v.x) < 0) : (sgn(u.y - v.y) < 0);}
struct line { // directed ray
	point A, B; double ang;
	line() {}
	line(point _A, point _B) {A = _A; B = _B; ang = atan2(B.y - A.y, B.x - A.x);}
	int dir(point x) {return get_dir(B - A, x - A);} // 0: on line, 1: left of A -> B, -1: right of A -> B
	friend bool para(line x, line y) {return get_dir(x.B - x.A, y.B - y.A) == 0;}
	friend bool same_ang(line x, line y) {return sgn(x.ang - y.ang) == 0;}
	friend bool coin(line x, line y) {return para(x, y) && x.dir(y.A) == 0;}
	friend point inter(line x, line y) {
		if (para(x, y)) {fprintf(stderr, "bad line intersection!\n"); exit(-1);}
		double U = ((y.B - x.A) | (y.A - x.A)), V = ((y.B - x.B) | (y.A - x.B));
		return x.A + (x.B - x.A) * (U / (U - V));
	}
	friend bool operator < (const line &x, const line &y) {
		if (!same_ang(x, y)) return cmp_ang(x.B - x.A, y.B - y.A);
		return get_dir(x.A - y.A, x.B - y.A) < 0;
	} 
};
struct segment {
	point A, B;
	segment() {}
	segment(point _A, point _B) {A = _A; B = _B;}
	operator line() const {return line(A, B);}
	friend bool para(segment x, segment y) {return para(line(x), line(y));}
	bool on_seg(point x) {
		return line(*this).dir(x) == 0 && sgn(x.x - min(A.x, B.x)) >= 0 && sgn(x.x - max(A.x, B.x)) <= 0 &&
		sgn(x.y - min(A.y, B.y)) >= 0 && sgn(x.y - max(A.y, B.y)) <= 0;
	}
	friend bool has_inter(segment x, segment y) {
		if (para(x, y)) return 0;
		point p = inter(line(x), line(y));
		if (!x.on_seg(p) || !y.on_seg(p)) return 0;
		return 1;
	}
	friend point get_inter(segment x, segment y) {
		if (!has_inter(x, y)) {fprintf(stderr, "bad segment intersection!\n"); exit(-1);}
		return inter(line(x), line(y));
	}
};
double area(point x, point y, point z) { // multiplied by 2
	return fabs((z - x) | (y - x));
}
struct convex {
	vector<point> v, up, dw;
	convex() {}
	void construct(vector<point> vec) {
		sort(vec.begin(), vec.end(), cmp_xy); vector<point> nvec;
		for (int i = 0; i < vec.size(); i++) if (i == 0 || vec[i] != vec[i - 1]) nvec.pb(vec[i]);
		vec = nvec; v.clear(); up.clear(), dw.clear();
		vector<int> stk; stk.pb(0);
		for (int i = 1; i < vec.size(); i++) {
			while (stk.size() > 1 && get_dir(vec[i] - vec[stk.back()], vec[stk[stk.size() - 2]] - vec[stk.back()]) != 1) stk.ppb();
			stk.pb(i);
		}
		for (int i = 0; i < stk.size(); i++) v.pb(vec[stk[i]]), dw.pb(vec[stk[i]]);
		stk.clear(); stk.pb(0);
		for (int i = 1; i < vec.size(); i++) {
			while (stk.size() > 1 && get_dir(vec[i] - vec[stk.back()], vec[stk[stk.size() - 2]] - vec[stk.back()]) != -1) stk.ppb();
			stk.pb(i);
		}
		for (int i = (int)(stk.size()) - 2; i >= 1; i--) v.pb(vec[stk[i]]);
		for (int i = 0; i < stk.size(); i++) up.pb(vec[stk[i]]);
	}
	convex(vector<point> vec) {construct(vec);}
	double poly_area() {
		double res = 0;
		for (int i = 1; i + 1 < v.size(); i++) res += area(v[0], v[i], v[i + 1]);
		return res;
	}
	bool in(point x) {
		if (get_dir(v[1] - v[0], x - v[0]) < 0) return 0;
		if (get_dir(v.back() - v[0], x - v[0]) > 0) return 0;
		if (v.size() == 2) return segment(v[0], v[1]).on_seg(x);
		int l = 2, r = v.size() - 2, p = 1;
		while (l <= r) {
			int mid = l + r >> 1;
			if (get_dir(v[mid] - v[0], x - v[0]) > 0) p = mid, l = mid + 1;
			else r = mid - 1;
		}
		return get_dir(v[p + 1] - v[p], x - v[p]) >= 0;
	}
} H;
convex merge_convex(convex v1, convex v2) {
	vector<point> pt1, pt2;
	for (int i = 1; i < v1.v.size(); i++) pt1.pb(v1.v[i] - v1.v[i - 1]); pt1.pb(v1.v[0] - v1.v.back());
	for (int i = 1; i < v2.v.size(); i++) pt2.pb(v2.v[i] - v2.v[i - 1]); pt2.pb(v2.v[0] - v2.v.back());
	int p1 = 0, p2 = 0, cur = 0; vector<point> pt; pt.pb(v1.v[0] + v2.v[0]);
	while (p1 < pt1.size() && p2 < pt2.size()) {
		if (get_dir(pt1[p1], pt2[p2]) > 0) pt.pb(pt[cur] + pt1[p1++]), cur++;
		else pt.pb(pt[cur] + pt2[p2++]), cur++;
	}
	while (p1 < pt1.size()) pt.pb(pt[cur] + pt1[p1++]), cur++;
	while (p2 < pt2.size()) pt.pb(pt[cur] + pt2[p2++]), cur++;
	pt.ppb(); convex res; res.construct(pt); return res;
}
const int MAXN = 1e5;
int n;
vector<point> vec;
bool in(int x, int y) {return (x >= 0 && x <= MAXN && y >= 0 && y <= MAXN);}
void work(int x, int y) {
	if (in(x, y)) vec.pb(point(x, y));
	else if (x < 0) {
		if (in(0, y + x)) vec.pb(point(0, y + x)); else vec.pb(point(0, 0));
		if (in(0, y - x)) vec.pb(point(0, y - x)); else vec.pb(point(0, MAXN));
	} else if (y < 0) {
		if (in(x + y, 0)) vec.pb(point(x + y, 0)); else vec.pb(point(0, 0));
		if (in(x - y, 0)) vec.pb(point(x - y, 0)); else vec.pb(point(MAXN, 0));
	} else if (x > MAXN) {
		if (in(MAXN, y + (x - MAXN))) vec.pb(point(MAXN, y + (x - MAXN))); else vec.pb(point(MAXN, MAXN));
		if (in(MAXN, y - (x - MAXN))) vec.pb(point(MAXN, y - (x - MAXN))); else vec.pb(point(MAXN, 0));
	} else {
		if (in(x + (y - MAXN), MAXN)) vec.pb(point(x + (y - MAXN), MAXN)); else vec.pb(point(MAXN, MAXN));
		if (in(x - (y - MAXN), MAXN)) vec.pb(point(x - (y - MAXN), MAXN)); else vec.pb(point(0, MAXN));
	}
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	read(n);
	for (int i = 1, x, y, v; i <= n; i++) {
		read(x); read(y); read(v);
		work(x - v, y); work(x, y - v); work(x + v, y); work(x, y + v);
	}
	convex H; H.construct(vec); double mx = -1; int pos = -1;
	// for (point p : H.v) printf("%.10lf %.10lf\n", p.x, p.y);
	for (int i = 0; i < H.v.size(); i++) {
		point A = H.v[i], B = H.v[(i + 1) % H.v.size()], C = H.v[(i + 2) % H.v.size()];
		double a = (~(B - C)), b = (~(A - C)), c = (~(A - B)), p = (a + b + c) / 2.0;
		double r = a * b * c / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
		if (r > mx) mx = r, pos = i;
	}
	printf("%.0lf %.0lf\n%.0lf %.0lf\n%.0lf %.0lf\n",
	H.v[pos].x, H.v[pos].y, H.v[(pos + 1) % H.v.size()].x, H.v[(pos + 1) % H.v.size()].y,
	H.v[(pos + 2) % H.v.size()].x, H.v[(pos + 2) % H.v.size()].y);
	return 0;
}