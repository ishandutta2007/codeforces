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
namespace fastio {
	#define FILE_SIZE 1 << 23
	char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
	inline char getc() {
		return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1: *p1++;
	}
	inline void putc(char x) {(*p3++ = x);}
	template <typename T> void read(T &x) {
		x = 0; char c = getc(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getc();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getc();
		if (neg) x = (~x) + 1;
	}
	template <typename T> void recursive_print(T x) {
		if (!x) return;
		recursive_print (x / 10);
		putc (x % 10 ^ 48);
	}
	template <typename T> void print(T x) {
		if (!x) putc('0');
		if (x < 0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void readstr(char *s) {
		char c = getc();
		while (c <= 32 || c >= 127) c = getc();
		while (c > 32 && c < 127) s[0] = c, s++, c = getc();
		(*s) = 0;
	}
	void printstr(string s) {
		for (int i = 0; i < s.size(); i++) putc(s[i]);
	}
	void printstr(char *s) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) putc(s[i]);
	}
	void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
}
const int MAXN = 1e5;
const double EPS = 1e-5;
int n;
int sgn(double x) {return ((x > EPS) ? 1 : ((x < -EPS) ? -1 : 0));}
struct point {
	double x, y;
	point(double _x = 0, double _y = 0): x(_x), y(_y) {}
	point operator + (const point &rhs) {return point(x + rhs.x, y + rhs.y);}
	point operator - (const point &rhs) {return point(x - rhs.x, y - rhs.y);}
	double operator | (const point &rhs) {return 1.0 * x * rhs.y - 1.0 * y * rhs.x;}
	double operator ^ (const point &rhs) {return 1.0 * x * rhs.x + 1.0 * y * rhs.y;}
} p[MAXN + 5];
bool cmp(point A, point B) {return (sgn(A.x - B.x) < 0) || (sgn(A.x - B.x) == 0 && sgn(A.y - B.y) < 0);}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y), p[i].y -= 1.0 * p[i].x * p[i].x;
	sort(p + 1, p + n + 1, cmp);
	static int stk[MAXN + 5]; int tp = 0;
	for (int l = 1, r; l <= n; l = r) {
		r = l; while (r <= n && sgn(p[r].x - p[l].x) == 0) ++r;
		while (tp > 1 && ((p[stk[tp - 1]] - p[stk[tp]]) | (p[r - 1] - p[stk[tp]])) <= 0) --tp;
		stk[++tp] = r - 1;
	}
	printf("%d\n", tp - 1);
	return 0;
}