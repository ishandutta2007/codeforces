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
const int MAXN = 2e5 + 2;
int n, m, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 1;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int dep[MAXN + 5], vis[MAXN + 5], fa[MAXN + 5]; vector<tuple<int, int, int> > te;
void dfs(int x, int f) {
	vis[x] = 1; fa[x] = f;
	for (int e = hd[x]; e; e = nxt[e]) {
		if (!vis[to[e]]) dep[to[e]] = dep[x] + 1, dfs(to[e], x);
		else if (dep[to[e]] < dep[x] && to[e] != f) te.pb(mt(x, to[e], e >> 1));
	}
}
char res[MAXN + 5];
void solve() {
	scanf("%d%d", &n, &m); for (int i = 1; i <= n; i++) hd[i] = 0; ec = 1; te.clear();
	for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
	for (int i = 1; i <= n; i++) vis[i] = 0; dfs(1, 0);
	set<int> st;
	for (auto t : te) st.insert(get<0>(t)), st.insert(get<1>(t));
	res[m + 1] = 0;
	if (st.size() != 3) {
		for (int i = 1; i <= m; i++) res[i] = '0';
		for (auto t : te) res[get<2>(t)] = '1';
	} else {
		for (int i = 1; i <= m; i++) res[i] = '0';
		for (auto t : te) res[get<2>(t)] = '1';
		res[get<2>(te[0])] = '0';
		int x = get<0>(te[0]);
		for (int e = hd[x]; e; e = nxt[e]) if (to[e] == fa[x]) res[e >> 1] = '1';
	}
	printf("%s\n", res + 1);
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int qu; cin >> qu;
	while (qu--) solve();
	return 0;
}