// Created time: 2022/7/3 22:00:55
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
const int MAXN = 5000;
const int MAXQ = 1e5;
int n, qu, res[MAXQ + 5];
struct qry {int dir, x, y, len;} q[MAXQ + 5];
struct fenwick_2d {
	int t[MAXN + 10][MAXN * 2 + 10];
	void init() {memset(t, 0, sizeof(t));}
	fenwick_2d() {init();}
	void add(int x, int y, int v) {
		x += 5; y += 5;
		for (int i = x; i < n + 10; i += (i & (-i))) for (int j = y; j < 2 * n + 10; j += (j & (-j)))
			t[i][j] += v;
	}
	int query(int x, int y) {
		x += 5; y += 5; int ret = 0;
		for (int i = x; i; i &= (i - 1)) for (int j = y; j; j &= (j - 1))
			ret += t[i][j];
		return ret;
	}
} T, rec; //  45  
int rot(int x) {return n - x + 1;}
int main() {
	scanf("%d%d", &n, &qu);
	for (int i = 1; i <= qu; i++) {
		int opt; scanf("%d", &opt);
		if (opt == 1) scanf("%d%d%d%d", &q[i].dir, &q[i].x, &q[i].y, &q[i].len);
		else scanf("%d%d", &q[i].x, &q[i].y), q[i].dir = 5;
	}
	for (int d = 0; d < 4; d++) {
		T.init(); rec.init();
		for (int i = 1; i <= qu; i++) {
			if (q[i].dir == d + 1) {
				int x = q[i].x, y = q[i].y, len = q[i].len;
				if (d & 1) y = rot(y);
				if (d >> 1) x = rot(x);
				T.add(x, x + y + len, 1); T.add(x + len + 1, x + y + len, -1);
				rec.add(x, -3, -1); rec.add(x + len + 1, -3, 1);
				rec.add(x, y, 1); rec.add(x + len + 1, y, -1);
			} else if (q[i].dir == 5) {
				int x = q[i].x, y = q[i].y;
				if (d & 1) y = rot(y);
				if (d >> 1) x = rot(x);
				res[i] += rec.query(x, y) + (T.query(x, n * 2) - T.query(x, x + y - 1));
			}
		}
	}
	for (int i = 1; i <= qu; i++) if (q[i].dir == 5) printf("%d\n", res[i]);
	return 0;
}
/*
10 10
1 1 2 3 1
2 1 1
2 1 2
2 1 3
2 1 4
2 2 1
2 2 2
2 2 3
2 2 4
2 3 1
*/