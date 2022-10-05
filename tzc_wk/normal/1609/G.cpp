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
		(*s) = 0;
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
const int MAXN = 100;
const int MAXM = 1e5;
int n, m, qu; u64 a[MAXN + 5], b[MAXM + 5];
struct node {int l, r; u64 lz, sum, rit;} s[MAXM * 4 + 5];
void pushup(int k) {
	s[k].sum = s[k << 1].sum + s[k << 1 | 1].sum;
	s[k].rit = s[k << 1 | 1].rit;
}
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; if (l == r) return s[k].sum = s[k].rit = b[l + 1] - b[l], void();
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	pushup(k);
}
void tag(int k, u64 v) {
	s[k].rit += v; s[k].lz += v;
	s[k].sum += 1ull * (s[k].r - s[k].l + 1) * v;
}
void pushdown(int k) {if (s[k].lz) tag(k << 1, s[k].lz), tag(k << 1 | 1, s[k].lz), s[k].lz = 0;}
int walk(int k, u64 v) {
	if (s[k].rit <= v) return m;
	if (s[k].l == s[k].r) return s[k].l; pushdown(k);
	if (s[k << 1].rit <= v) return walk(k << 1 | 1, v);
	else return walk(k << 1, v);
}
void modify(int k, int l, int r, u64 v) {
	if (l <= s[k].l && s[k].r <= r) return tag(k, v), void();
	pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) modify(k << 1, l, r, v);
	else if (l > mid) modify(k << 1 | 1, l, r, v);
	else modify(k << 1, l, mid, v), modify(k << 1 | 1, mid + 1, r, v);
	pushup(k);
}
int pt[MAXN + 5];
void calc() {
	pt[0] = 1;
	for (int i = 1; i < n; i++) pt[i] = walk(1, a[i + 1] - a[i]);
	pt[n] = m;
//	for (int i = 1; i <= n; i++) printf("%d%c", pt[i], " \n"[i == n]);
}
struct fenwick {
	u64 t[MAXM + 5];
	void add(int x, u64 v) {for (int i = x; i <= m; i += (i & (-i))) t[i] += v;}
	u64 query(int x) {u64 ret = 0; for (int i = x; i; i &= (i - 1)) ret += t[i]; return ret;}
} t0, t1, t2;
void mdf(int l, u64 a, u64 b) {
	t2.add(l, b);
	t1.add(l, 2 * a + b);
	t0.add(l, 2 * a * (1 - l) + b * l * (1 - l));
}
u64 query(int x) {
	return (1ull * x * x * t2.query(x) + 1ull * x * t1.query(x) + t0.query(x)) / 2;
}
u64 query(int l, int r) {return query(r) - query(l - 1);}
u64 calcans() {
//	static ll A[MAXN + 5][MAXM + 5];
//	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
//		A[i][j] = a[i] + b[j];
//	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
//		printf("%lld%c", A[i][j], " \n"[j == m]);
//	int cx = 1, cy = 1; u64 res = A[cx][cy];
//	while (cx != n || cy != m) {
//		if (cx == n) cy++;
//		else if (cy == m) cx++;
//		else if (A[cx + 1][cy] - A[cx][cy] < A[cx][cy + 1] - A[cx][cy])
//			cx++;
//		else cy++;
//		res += A[cx][cy];
//	}
//	return res;
	u64 res = 0;
	for (int i = 1; i <= n; i++)
		res += 1ull * a[i] * (pt[i] - pt[i - 1] + 1) + query(pt[i - 1], pt[i]);
	return res;
}
int main() {
	scanf("%d%d%d", &n, &m, &qu);
	for (int i = 1; i <= n; i++) scanf("%llu", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%llu", &b[i]), t0.add(i, 2 * b[i]);
	build(1, 1, m - 1);
	while (qu--) {
		int typ, d, v; scanf("%d%d%d", &typ, &d, &v);
		if (typ == 1) {
			for (int i = 1; i <= d; i++)
				a[n - d + i] += 1ull * i * v;
		} else {
//			for (int i = 1; i <= d; i++)
//				b[m - d + i] += 1ull * i * v;
			mdf(m - d + 1, -1ull * (m - d) * v, v);
			modify(1, m - d, m - 1, v);
		}
		calc();
		printf("%llu\n", calcans());
	}
	return 0;
}