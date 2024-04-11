// Created time: 2022/7/13 12:53:16
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
const int MAXN = 1e6;
const int MOD = 1e9 + 7;
const int INV2 = 5e8 + 4;
int n, res;
struct point {
	int x, y;
	point() {x = y = 0;}
	point(int _x, int _y) {x = _x; y = _y;}
	friend point operator + (const point &X, const point &Y) {return point(X.x + Y.x, X.y + Y.y);}
	friend point operator - (const point &X, const point &Y) {return point(X.x - Y.x, X.y - Y.y);}
	friend ll operator | (const point &X, const point &Y) {return 1ll * X.x * Y.y - 1ll * X.y * Y.x;}
} p[MAXN + 5];
ll area(int x, int y, int z) {return (p[z] - p[x]) | (p[y] - p[x]);}
int s1[MAXN + 5], s2[MAXN + 5], s3[MAXN + 5];
// s1: sum of k*(x[k+1]y[k]-x[k]y[k+1])
// s2: sum of k*(x[k+1]-x[k])
// s3: sum of k*(y[k+1]-y[k])
int getsum(int *s, int l, int r) {return (s[r] - ((!l) ? 0 : s[l - 1]) + MOD) % MOD;}
int calc(int x, int l, int r) {return ((getsum(s1, l, r) + 1ll * p[x].x * getsum(s3, l, r) - 1ll * p[x].y * getsum(s2, l, r)) % MOD + MOD) % MOD;}
int main() {
	scanf("%d", &n); ll sum = 0, tot = 0;
	for (int i = 0; i < n; i++) scanf("%d%d", &p[i].x, &p[i].y), p[i + n] = p[i];
	for (int i = 2; i < n; i++) tot += area(0, i - 1, i);
	for (int i = 0; i < n * 2; i++) {
		s1[i] = (1ll * (1ll * p[i + 1].x * p[i].y - 1ll * p[i].x * p[i + 1].y) % MOD * i % MOD + MOD) % MOD;
		s2[i] = (1ll * i * (p[i + 1].x - p[i].x) % MOD + MOD) % MOD;
		s3[i] = (1ll * i * (p[i + 1].y - p[i].y) % MOD + MOD) % MOD;
	}
	for (int i = 1; i < n * 2; i++) {
		s1[i] = (s1[i - 1] + s1[i]) % MOD;
		s2[i] = (s2[i - 1] + s2[i]) % MOD;
		s3[i] = (s3[i - 1] + s3[i]) % MOD;
	}
	for (int i = 0, j = 1; i < n; i++) {
		while (j < n * 2 - 1 && sum < tot - sum) {sum += area(i, j, j + 1); ++j;}
		--j; sum -= area(i, j, j + 1);
		res = (res + tot % MOD * (n - 3)) % MOD;
		res = (res - (sum % MOD) * j * 2) % MOD;
		res = (res + (tot - sum) % MOD * j * 2) % MOD;
		res = (res + 2ll * calc(i, i + 1, j - 1)) % MOD;
		res = (res - 2ll * calc(i, j, i + n - 2)) % MOD;
		sum -= area(i, i + 1, j);
	}
	printf("%d\n", 1ll * INV2 * (res + MOD) % MOD);
	return 0;
}