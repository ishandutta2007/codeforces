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
const int MAXN = 3e5;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
int n, a[MAXN + 5], rit[MAXN + 5];
ll s0[MAXN + 5], s1[MAXN + 5], key[MAXN + 5], uni[MAXN + 5], num = 0;
vector<int> pos[MAXN + 5];
int get(ll v) {return lower_bound(uni + 1, uni + num + 1, v) - uni;}
struct segtree {
	int op;
	struct node {int l, r; ll mn, mx, lz;} s[MAXN * 4 + 5];
	void pushup(int k) {s[k].mn = min(s[k << 1].mn, s[k << 1 | 1].mn);}
	void build(int k, int l, int r) {
		s[k].l = l; s[k].r = r;
		s[k].mn = ((l & 1) == op) ? 0 : (INF);
		if (l == r) return; int mid = l + r >> 1;
		build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
		pushup(k);
	}
	void tag(int k, ll v) {s[k].lz += v; s[k].mn += v;}
	void pushdown(int k) {if (s[k].lz) tag(k << 1, s[k].lz), tag(k << 1 | 1, s[k].lz), s[k].lz = 0;}
	void modify(int k, int l, int r, int x) {
		if (l <= s[k].l && s[k].r <= r) return tag(k, x), void();
		pushdown(k); int mid = s[k].l + s[k].r >> 1;
		if (r <= mid) modify(k << 1, l, r, x);
		else if (l > mid) modify(k << 1 | 1, l, r, x);
		else modify(k << 1, l, mid, x), modify(k << 1 | 1, mid + 1, r, x);
		pushup(k);
	}
	ll querymn(int k, int l, int r) {
		if (l <= s[k].l && s[k].r <= r) return s[k].mn;
		pushdown(k); int mid = s[k].l + s[k].r >> 1;
		if (r <= mid) return querymn(k << 1, l, r);
		else if (l > mid) return querymn(k << 1 | 1, l, r);
		else return min(querymn(k << 1, l, mid), querymn(k << 1 | 1, mid + 1, r));
	}
} T0, T1;//T0: even - odd, T1: odd - even
int walk(int k, int p) {
	if (min(T0.s[k].mn, T1.s[k].mn) >= 0) return n + 1;
	if (T1.s[k].l == T1.s[k].r) return T1.s[k].l;
	T0.pushdown(k); T1.pushdown(k);
	int mid = T1.s[k].l + T1.s[k].r >> 1;
	if (p > mid) return walk(k << 1 | 1, p);
	else {
		int res = walk(k << 1, p);
		if (res == n + 1) res = walk(k << 1 | 1, p);
		return res;
	}
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		s0[i] = s0[i - 1] + ((~i & 1) ? a[i] : 0);
		s1[i] = s1[i - 1] + ((i & 1) ? a[i] : 0);
	}
	ll res = 0;
	T0.op = 0; T1.op = 1;
	T0.build(1, 1, n); T1.build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		if (i & 1) T0.modify(1, i, n, -a[i]), T1.modify(1, i, n, a[i]);
		else T0.modify(1, i, n, a[i]), T1.modify(1, i, n, -a[i]);
	}
	for (int i = 1; i <= n; i++) {
		rit[i] = max(walk(1, i) - 1, i);
		if (i & 1) T0.modify(1, i, n, a[i]), T1.modify(1, i, n, -a[i]);
		else T0.modify(1, i, n, -a[i]), T1.modify(1, i, n, a[i]);
//		printf("%d %d\n", i, rit[i]);
	}
	for (int i = 0; i <= n; i++) key[i + 1] = s1[i] - s0[i];
	sort(key + 1, key + n + 2); key[0] = -1e18;
	num = 0;
	for (int i = 1; i <= n + 1; i++) if (key[i] != key[i - 1]) uni[++num] = key[i];
	for (int i = 1; i <= num; i++) pos[i].clear();
	for (int i = 0; i <= n; i++) pos[get(s1[i] - s0[i])].pb(i);
	for (int i = 1; i <= n; i++) {
		int v = get(s1[i - 1] - s0[i - 1]);
		int pl = lower_bound(pos[v].begin(), pos[v].end(), i) - pos[v].begin();
		int pr = upper_bound(pos[v].begin(), pos[v].end(), rit[i]) - pos[v].begin();
		res += pr - pl;
	}
	printf("%lld\n", res);
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}