#include <bits/stdc++.h>
using namespace std;
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
		if (x<0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void readstr(char *s) {
		char c = getc();
		while (c <= 32 || c >= 127) c = getc();
		while (c > 32 && c < 127) s[0] = c, s++, c = getc();
		(*++s) = 0;
	}
	void printstr(string s) {
		for (int i = 0; i < s.size(); i++) putc(s[i]);
	}
	void printstr(char *s) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) putc(s[i]);
	}
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 3000;
const double Pi = acos(-1);
int n, R, x[MAXN + 5], y[MAXN + 5];
bool is[MAXN + 5][MAXN + 5];
double dis(int p, int q) {return sqrt(1.0 * (x[p] - x[q]) * (x[p] - x[q]) + 1.0 * (y[p] - y[q]) * (y[p] - y[q]));}
double ang(int p, int q) {return atan2(y[q] - y[p], x[q] - x[p]);}
void deal(double &theta) {
	if (theta < 0) theta += 2 * Pi;
	if (theta >= 2 * Pi) theta -= 2 * Pi;
}
int main() {
	scanf("%d%d", &n, &R);
	for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
	for (int i = 1; i <= n; i++) {
		double L1 = 0, R1 = 2 * Pi, L2 = 0, R2 = 2 * Pi;
		for (int j = 1; j <= n; j++) {
			if (dis(i, j) > R) {
				double leg = R, hyp = dis(i, j);
				double theta = asin(leg / hyp);
				double lw = ang(i, j) - theta;
				double hi = ang(i, j) + theta;
				deal(lw); deal(hi);
				if (lw > hi) {
					chkmax(L1, lw);
					chkmin(R2, hi);
				} else {
					chkmax(L1, lw); chkmin(R1, hi);
					chkmax(L2, lw); chkmin(R2, hi);
				}
			}
		}
		for (int j = 1; j <= n; j++) if (i != j) {
			double theta = ang(i, j); deal(theta);
			if (L1 <= theta && theta <= R1) is[i][j] = 1;
			if (L2 <= theta && theta <= R2) is[i][j] = 1;
		}
//		printf("i = %d, %.5lf %.5lf %.5lf %.5lf\n", i, L1, R1, L2, R2);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++)
		res += (is[i][j] && is[j][i]);
	printf("%d\n", res);
	return 0;
}