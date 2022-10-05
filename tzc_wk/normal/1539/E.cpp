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
template <typename T1,typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1,typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio {
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
	inline char getc() {
		return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1: *p1++;
	}
	inline void putc(char x) {(*p3++ = x);}
	template <typename T> void read(T &x) {
		x = 0; char c = getchar(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getchar();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
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
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 1e5;
const int LOG_N = 17;
int n, v[MAXN + 5], mnl[MAXN + 5], mxl[MAXN + 5], mnr[MAXN + 5], mxr[MAXN + 5];
int dp[MAXN + 5][2], lst[MAXN + 5][2];
struct stable {
	int op, st[LOG_N + 2][MAXN + 5];
	int query(int l, int r) {
		int k = 31 - __builtin_clz(r - l + 1);
		return (op) ? max(st[k][l], st[k][r - (1 << k) + 1]) : min(st[k][l], st[k][r - (1 << k) + 1]);
	}
	void build() {
		for (int i = 1; i <= LOG_N; i++) for (int j = 0; j + (1 << i) - 1 <= n; j++) {
			st[i][j] = (op) ? max(st[i - 1][j], st[i - 1][j + (1 << i - 1)]) : min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
		}
	}
} la, ra, lb, rb;
bool oka[MAXN + 5], okb[MAXN + 5];
int lfta[MAXN + 5], lftb[MAXN + 5];
int getrit0(int x) {
	int l = x + 1, r = n, p = x;
	while (l <= r) {
		int mid = l + r >> 1;
		if (la.query(x, mid) <= v[x] && v[x] <= ra.query(x, mid)) p = mid, l = mid + 1;
		else r = mid - 1;
	}
	return p;
}
int getrit1(int x) {
	int l = x + 1, r = n, p = x;
	while (l <= r) {
		int mid = l + r >> 1;
		if (lb.query(x, mid) <= v[x] && v[x] <= rb.query(x, mid)) p = mid, l = mid + 1;
		else r = mid - 1;
	}
	return p;
}
struct fenwick {
	int t[MAXN + 5];
	fenwick() {memset(t, 0xcf, sizeof(t));}
	void add(int x, int v) {for (int i = x; i; i &= (i - 1)) chkmax(t[i], v);}
	int query(int x) {int ret = 0xcfcfcfcf; for (int i = x; i <= n; i += (i & (-i))) chkmax(ret, t[i]); return ret;}
} t0, t1;
int res[MAXN + 5];
void dump(int p, int x) {
	if (!p) return; dump(lst[p][x], x ^ 1);
	for (int i = lst[p][x] + 1; i <= p; i++) res[i] = x;
}
int main() {
	scanf("%d%*d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d%d%d%d", &v[i], &mnl[i], &mxl[i], &mnr[i], &mxr[i]);
	la.op = lb.op = 1;
	for (int i = 0; i <= n; i++) {
		oka[i] = (mnl[i] <= v[i] && v[i] <= mxl[i]);
		okb[i] = (mnr[i] <= v[i] && v[i] <= mxr[i]);
	}
	int pre = -1;
	for (int i = 0; i <= n; i++) {
		if (oka[i]) lfta[i] = pre + 1;
		else pre = i;
	}
	pre = -1;
	for (int i = 0; i <= n; i++) {
		if (okb[i]) lftb[i] = pre + 1;
		else pre = i;
	}
	for (int i = 1; i <= n; i++) {
		la.st[0][i] = mnl[i]; ra.st[0][i] = mxl[i];
		lb.st[0][i] = mnr[i]; rb.st[0][i] = mxr[i];
	}
	la.build(); lb.build(); ra.build(); rb.build();
	dp[0][0] = dp[0][1] = 1;
	t0.add(getrit0(0), 0); t1.add(getrit1(0), 0);
//	for (int i = 1; i <= n; i++) printf("%d%c", oka[i], " \n"[i == n]);
//	for (int i = 1; i <= n; i++) printf("%d%c", okb[i], " \n"[i == n]);
	for (int i = 1; i <= n; i++) {
		if (oka[i]) {
			int posb = t1.query(i);
			if (posb >= lfta[i] - 1) {
				dp[i][0] = 1;
				lst[i][0] = posb;
			}
		}
		if (okb[i]) {
			int posa = t0.query(i);
			if (posa >= lftb[i] - 1) {
				dp[i][1] = 1;
				lst[i][1] = posa;
			}
		}
		if (dp[i][0]) t0.add(getrit0(i), i);
		if (dp[i][1]) t1.add(getrit1(i), i);
//		printf("%d %d\n", dp[i][0], dp[i][1]);
	}
	if (!dp[n][0] && !dp[n][1]) puts("No");
	else {
		puts("Yes");
		if (dp[n][0]) dump(n, 0);
		else if (dp[n][1]) dump(n, 1);
		for (int i = 1; i <= n; i++) printf("%d%c", res[i], " \n"[i == n]);
	}
	return 0;
}