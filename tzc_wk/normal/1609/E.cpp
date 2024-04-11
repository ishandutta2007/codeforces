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
const int MAXN = 2e5;
const int INF = 0x3f3f3f3f;
int n, qu; char str[MAXN + 5];
struct mat {
	int a[3][3];
	mat() {memset(a, 63, sizeof(a));}
	mat operator *(const mat &rhs) {
		mat res;
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++) chkmin(res.a[i][j], a[i][k] + rhs.a[k][j]);
		return res;
	}
} A[3];
struct node {int l, r; mat v;} s[MAXN * 4 + 5];
void pushup(int k) {s[k].v = s[k << 1].v * s[k << 1 | 1].v;}
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; if (l == r) return s[k].v = A[str[l] - 'a'], void();
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	pushup(k);
}
void modify(int k, int p, int c) {
	if (s[k].l == s[k].r) return s[k].v = A[c], void();
	int mid = s[k].l + s[k].r >> 1;
	(p <= mid) ? modify(k << 1, p, c) : modify(k << 1 | 1, p, c);
	pushup(k);
}
int main() {
	A[0].a[0][0] = 1; A[0].a[0][1] = 0; A[0].a[0][2] = INF;
	A[0].a[1][0] = INF; A[0].a[1][1] = 0; A[0].a[1][2] = INF;
	A[0].a[2][0] = INF; A[0].a[2][1] = INF; A[0].a[2][2] = 0;
	A[1].a[0][0] = 0; A[1].a[0][1] = INF; A[1].a[0][2] = INF;
	A[1].a[1][0] = INF; A[1].a[1][1] = 1; A[1].a[1][2] = 0;
	A[1].a[2][0] = INF; A[1].a[2][1] = INF; A[1].a[2][2] = 0;
	A[2].a[0][0] = 0; A[2].a[0][1] = INF; A[2].a[0][2] = INF;
	A[2].a[1][0] = INF; A[2].a[1][1] = 0; A[2].a[1][2] = INF;
	A[2].a[2][0] = INF; A[2].a[2][1] = INF; A[2].a[2][2] = 1;
	scanf("%d%d%s", &n, &qu, str + 1); build(1, 1, n);
	while (qu--) {
		int p; char c; scanf("%d %c", &p, &c);
		modify(1, p, c - 'a');
		printf("%d\n", min(s[1].v.a[0][0], min(s[1].v.a[0][1], s[1].v.a[0][2])));
	}
	return 0;
}