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
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 1064
#endif
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
const int MAXN = 3e5;
const int LOG_N = 18;
int n, qu, lg[MAXN + 5], p[MAXN + 5], a[MAXN + 5], b[MAXN + 5], k, flg;
int key[MAXN * 2 + 5], cnt, uni[MAXN * 2 + 5], num;
bool res[MAXN + 5]; pii q[MAXN + 5];
int get(int x) {return lower_bound(uni + 1, uni + num + 1, x) - uni;}
pii st[LOG_N + 2][MAXN + 5];
pii query_st(int l, int r) {
	int k = lg[r - l + 1];
	return max(st[k][l], st[k][r - (1 << k) + 1]);
}
int ch[MAXN + 5][2], rt;
int build(int l, int r) {
	if (l > r) return 0; int p = query_st(l, r).se;
	ch[p][0] = build(l, p - 1); ch[p][1] = build(p + 1, r);
	return p;
}
int mx[MAXN + 5], mn[MAXN + 5];
void dfs(int x) {
	if (a[x]) chkmin(mn[x], a[x]);
	if (ch[x][0]) mn[ch[x][0]] = mn[x], dfs(ch[x][0]);
	if (ch[x][1]) mn[ch[x][1]] = mn[x], dfs(ch[x][1]);
	if (a[x] && (a[x] < mx[ch[x][0]] || a[x] < mx[ch[x][1]])) flg = 1;
	mx[x] = max(mx[ch[x][0]], mx[ch[x][1]]);
	chkmax(mx[x], a[x]);
}
vector<int> qv[MAXN * 2 + 5];
bool has[MAXN * 2 + 5];
struct node {int l, r, mn, lz;} s[MAXN * 8 + 5];
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; s[k].mn = s[k].lz = 0; if (l == r) return;
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
}
void tag(int k, int v) {s[k].mn += v; s[k].lz += v;}
void pushdown(int k) {if (s[k].lz) tag(k << 1, s[k].lz), tag(k << 1 | 1, s[k].lz), s[k].lz = 0;}
void modify(int k, int l, int r, int v) {
	if (l <= s[k].l && s[k].r <= r) return tag(k, v), void();
	pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) modify(k << 1, l, r, v);
	else if (l > mid) modify(k << 1 | 1, l, r, v);
	else modify(k << 1, l, mid, v), modify(k << 1 | 1, mid + 1, r, v);
	s[k].mn = min(s[k << 1].mn, s[k << 1 | 1].mn);
}
int walk(int k) {
	if (s[k].l == s[k].r) return s[k].l; pushdown(k);
	if (s[k << 1].mn == -1) return walk(k << 1); else return walk(k << 1 | 1);
}
void solve() {
	scanf("%d%d", &n, &qu); cnt = num = k = flg = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i]) key[++cnt] = a[i];
		else ++k;
	}
	for (int i = 1; i < k; i++) scanf("%d", &b[i]), key[++cnt] = b[i];
	for (int i = 1; i <= qu; i++) scanf("%d", &q[i].fi), q[i].se = i, key[++cnt] = q[i].fi;
	sort(key + 1, key + cnt + 1);
	for (int i = 1; i <= cnt; i++) if (key[i] != key[i - 1]) uni[++num] = key[i];
	for (int i = 1; i <= n; i++) if (a[i]) a[i] = get(a[i]);
	for (int i = 1; i < k; i++) b[i] = get(b[i]);
	for (int i = 1; i <= qu; i++) q[i].fi = get(q[i].fi);
	for (int i = 1; i <= n; i++) st[0][i] = mp(p[i], i);
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j + (1 << i) - 1 <= n; j++)
		st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
	for (int i = 1; i <= n; i++) ch[i][0] = ch[i][1] = 0;
	rt = build(1, n); mn[rt] = num; dfs(rt);
	if (flg) {
		while (qu--) puts("NO");
		return;
	}
	vector<pii> vec;
	for (int i = 1; i <= n; i++) if (!a[i]) vec.pb(mp(max(mx[i], 1), mn[i]));
	for (int i = 1; i <= num; i++) qv[i].clear(), has[i] = 0;
	for (pii p : vec) qv[p.fi].pb(p.se);
	for (int i = 1; i < k; i++) has[b[i]] = 1;
	build(1, 1, num);
	int L = 1, R = num;
	for (int i = num; i; i--) {
		for (int r : qv[i]) modify(1, r, num, -1);
		if (has[i]) modify(1, i, num, 1);
		if (s[1].mn <= -2) {
			while (qu--) puts("NO");
			return;
		}
		if (s[1].mn == -1) chkmax(L, i), chkmin(R, walk(1));
	}
	for (int i = 1; i <= qu; i++) printf("%s\n", (L <= q[i].fi && q[i].fi <= R) ? "YES" : "NO");
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	for (int i = 2; i <= MAXN; i++) lg[i] = lg[i >> 1] + 1;
	int qu; scanf("%d", &qu); while (qu--) solve();
	return 0;
}