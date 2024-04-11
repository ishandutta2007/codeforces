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
const int MAXN = 15000;
const int MAGIC = 280;
const int INF = 0x3f3f3f3f;
int n, a[MAXN + 5];
int dpl[MAXN + 5][MAGIC + 2], dpr[MAXN + 5][MAGIC + 2];
struct fenwick_mn {
	int t[MAXN + 5];
	void init() {for (int i = 1; i <= n; i++) t[i] = INF;}
	void add(int x, int v) {for (int i = x; i; i -= (i & (-i))) chkmin(t[i], v);}
	int query(int x) {int ret = INF; for (int i = x; i <= n; i += (i & (-i))) chkmin(ret, t[i]); return ret;}
} mn[MAGIC + 2];
struct fenwick_mx {
	int t[MAXN + 5];
	void init() {for (int i = 1; i <= n; i++) t[i] = 0;}
	void add(int x, int v) {for (int i = x; i <= n; i += (i & (-i))) chkmax(t[i], v);}
	int query(int x) {int ret = 0; for (int i = x; i; i &= (i - 1)) chkmax(ret, t[i]); return ret;}
} mx[MAGIC + 2];
void clear() {
	for (int i = 1; i <= n; i++) for (int j = 1; j <= MAGIC; j++)
		dpl[i][j] = INF, dpr[i][j] = 0;
	for (int i = 1; i <= MAGIC; i++) mx[i].init(), mn[i].init();
}
int calc(int op) {
	for (int i = n - 1; i; i--) {
		for (int j = op; j <= MAGIC; j++) {
			mn[j - 1].add(a[i + 1], dpl[i + 1][j - 1]);
			mx[j - 1].add(a[i + 1], dpr[i + 1][j - 1]);
			if (i + j - 1 <= n) {
				mn[j - 1].add(dpr[i + j - 1][j - 1], a[i + j - 1]);
				mx[j - 1].add(dpl[i + j - 1][j - 1], a[i + j - 1]);
			}
			dpl[i][j] = mn[j - 1].query(a[i] + 1);
			dpr[i][j] = mx[j - 1].query(a[i] - 1);
		}
	}
	int res = 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= MAGIC; j++) {
		if (dpl[i][j] <= n) chkmax(res, j);
		if (dpr[i][j]) chkmax(res, j);
	}
	return res;
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	clear();
	dpl[n][1] = dpr[n][1] = a[n];
	int res = calc(2);
	clear();
	for (int i = 1; i <= n; i++) dpl[i][2] = dpr[i][2] = a[i];
	chkmax(res, calc(3) - 1);
	printf("%d\n", res);
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}