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
#define int long long
const int MAXN = 2e5;
const int LOG_N = 18;
int n, t, g[MAXN + 5], c[MAXN + 5], d[MAXN + 5];
struct dat {
	int l, r;
	dat(int _l, int _r) {l = _l; r = _r;}
	friend bool operator < (const dat &X, const dat &Y) {return X.l < Y.l;}
};
set<dat> st;
void split(int x) {
	set<dat> :: iterator it = st.upper_bound(dat(x, 0));
	if (it == st.begin()) return; --it;
	int L = it -> l, R = it -> r;
	if (L <= x && x < R) {
		st.erase(it); st.insert(dat(L, x));
		st.insert(dat(x + 1, R));
	}
}
ll res = 1e18, dp[MAXN + 5];
struct itvl {
	vector<pii> vec;
	itvl() {vec.clear();}
	bool check(int x) {
		for (pii p : vec) if (p.fi <= x && x <= p.se) return 1;
		return 0;
	}
	friend itvl operator & (const itvl &X, const itvl &Y) {
		itvl res;
		for (pii p1 : X.vec) for (pii p2 : Y.vec) if (max(p1.fi, p2.fi) <= min(p1.se, p2.se))
			res.vec.pb(mp(max(p1.fi, p2.fi), min(p1.se, p2.se)));
		return res;
	}
};
itvl ss[LOG_N + 2][MAXN + 5];
int lg[MAXN + 5];
itvl query(int l, int r) {
	int k = lg[r - l + 1];
	return ss[k][l] & ss[k][r - (1 << k) + 1];
}
bool check(int l, int r, int x) {return query(l, r).check(x);}
int key[MAXN + 5], uni[MAXN + 5], num;
struct node {int l, r, v;} s[MAXN * 4 + 5];
void tag(int k, int v) {s[k].v = v;}
void pushdown(int k) {if (~s[k].v) tag(k << 1, s[k].v), tag(k << 1 | 1, s[k].v), s[k].v = -1;}
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; s[k].v = n + 1; if (l == r) return;
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
}
void modify(int k, int l, int r, int v) {
	if (l > r) return;
	if (l <= s[k].l && s[k].r <= r) return tag(k, v), void();
	pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) modify(k << 1, l, r, v);
	else if (l > mid) modify(k << 1 | 1, l, r, v);
	else modify(k << 1, l, mid, v), modify(k << 1 | 1, mid + 1, r, v);
}
int ask(int k, int v) {
	if (s[k].l == s[k].r) return s[k].v; pushdown(k);
	int mid = s[k].l + s[k].r >> 1;
	if (v <= mid) return ask(k << 1, v); else return ask(k << 1 | 1, v);
}
signed main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%lld%lld", &n, &t); ll sd = 0;
	for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
	for (int i = 1; i <= n; i++) scanf("%lld%lld", &g[i], &c[i]);
	for (int i = 2; i <= n; i++) scanf("%lld", &d[i]), sd += d[i];
	for (int i = 2; i <= n; i++) d[i] = (d[i - 1] + d[i]) % t;
	for (int i = 1; i <= n; i++) d[i] = (d[i] + c[i]) % t;
	for (int i = 1; i <= n; i++) {
		int L = (0 - d[i] + t) % t, R = (g[i] - 1 - d[i] + t) % t;
		if (L <= R) ss[0][i].vec.pb(mp(L, R));
		else ss[0][i].vec.pb(mp(0, t - 1));
	}
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j + (1 << i) - 1 <= n; j++)
		ss[i][j] = ss[i - 1][j] & ss[i - 1][j + (1 << i - 1)];
	for (int i = 1; i <= n; i++) key[i] = (t - d[i]) % t; key[0] = -1;
	sort(key + 1, key + n + 1);
	for (int i = 1; i <= n; i++) if (key[i] != key[i - 1]) uni[++num] = key[i];
	build(1, 1, num);
	for (int i = n; i; i--) {
		int V = lower_bound(uni + 1, uni + num + 1, (t - d[i]) % t) - uni, lst = ask(1, V);
		int L = i + 1, R = lst - 1, p = lst;
		while (L <= R) {
			int mid = L + R >> 1;
			if (!check(i + 1, mid, (t - d[i]) % t)) p = mid, R = mid - 1;
			else L = mid + 1;
		}
		if (p == n + 1) dp[i] = 0;
		else {
			int tim = (d[p] - d[i] + t) % t;
			dp[i] = dp[p] + t - tim;
		}
		L = (0 - d[i] + t) % t, R = (g[i] - 1 - d[i] + t) % t;
		if (L > R) {
			swap(L, R); L++; R--;
			int posl = lower_bound(uni + 1, uni + num + 1, L) - uni;
			int posr = upper_bound(uni + 1, uni + num + 1, R) - uni - 1;
			modify(1, posl, posr, i);
		}
	}
	st.insert(dat(0, t - 1));
	for (int i = 1; i <= n; i++) {
		int L = (g[i] - d[i] + t) % t, R = (t - 1 - d[i] + t) % t;
		auto upd = [&](int l, int r, int lim) {
			split(l - 1); split(r);
			while (1) {
				set<dat> :: iterator it = st.lower_bound(dat(l, 0));
				if (it == st.end() || (it -> l) > r) break;
				chkmin(res, (lim - (it -> r)) + dp[i]);
				st.erase(it);
			}
		};
		if (L <= R) upd(L, R, R + 1);
		else {
			upd(0, R, R + 1);
			upd(L, t - 1, t + R + 1);
		}
	}
	if (!st.empty()) res = 0;
	printf("%lld\n", res + sd);
	return 0;
}