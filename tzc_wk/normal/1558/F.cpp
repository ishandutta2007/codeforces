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
const int MAXN = 2e5;
const int INF = 0x3f3f3f3f;
int n, p[MAXN + 5], pos[MAXN + 5];
struct node {int l, r, mx, lz;} s[MAXN * 4 + 5];
void pushup(int k) {s[k].mx = max(s[k << 1].mx, s[k << 1 | 1].mx);}
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; s[k].mx = -INF; s[k].lz = 0; if (l == r) return;
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
}
void tag(int k, int v) {s[k].lz += v; s[k].mx += v;}
void pushdown(int k) {
	if (s[k].lz) {
		tag(k << 1, s[k].lz); tag(k << 1 | 1, s[k].lz);
		s[k].lz = 0;
	}
}
void modify(int k, int l, int r, int v) {
	if (l <= s[k].l && s[k].r <= r) return tag(k, v), void();
	pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) modify(k << 1, l, r, v);
	else if (l > mid) modify(k << 1 | 1, l, r, v);
	else modify(k << 1, l, mid, v), modify(k << 1 | 1, mid + 1, r, v);
	pushup(k);
}
int query(int k, int l, int r) {
	if (l > r) return -INF;
	if (l <= s[k].l && s[k].r <= r) return s[k].mx;
	pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) return query(k << 1, l, r);
	else if (l > mid) return query(k << 1 | 1, l, r);
	else return max(query(k << 1, l, mid), query(k << 1 | 1, mid + 1, r));
}
int suf[MAXN + 5], pre[MAXN + 5];
void solve() {
	scanf("%d", &n); build(1, 1, n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]), pos[p[i]] = i;
	suf[n + 1] = n + 1; int res = 0;
	for (int i = n; i; i--) suf[i] = min(suf[i + 1], pos[i]);
	for (int i = 1; i <= n; i++) pre[i] = max(pre[i - 1], pos[i]);
	for (int i = 1; i <= n; i++) {
		modify(1, pos[i], pos[i], INF + pos[i] + (pos[i] & 1));
		modify(1, pos[i], n, -2);
		chkmax(res, query(1, suf[i + 1], pre[i]) + i);
	}
	printf("%d\n", res);
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}