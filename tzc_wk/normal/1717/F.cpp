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
const int MAXN = 1e4;
const int MAXV = 5e4;
const int MAXE = 1e6;
const ll INF = 1e18;
int s, t;
int hd[MAXV + 5], to[MAXE + 5], nxt[MAXE + 5], cap[MAXE + 5], ec = 1;
void adde(int u, int v, int f) {
	to[++ec] = v; cap[ec] = f; nxt[ec] = hd[u]; hd[u] = ec;
	to[++ec] = u; cap[ec] = 0; nxt[ec] = hd[v]; hd[v] = ec;
}
int dep[MAXV + 5], now[MAXV + 5];
bool getdep() {
	memset(dep, -1, sizeof(dep)); queue<int> q; q.push(s); dep[s] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop(); now[x] = hd[x];
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e], z = cap[e];
			if (z && !~dep[y]) {dep[y] = dep[x] + 1; q.push(y);}
		}
	}
	return ~dep[t];
}
ll getflow(int x, ll f) {
	if (x == t) return f; ll ret = 0;
	for (int &e = now[x]; e; e = nxt[e]) {
		int y = to[e], z = cap[e];
		if (z && dep[y] == dep[x] + 1) {
			ll w = getflow(y, min(f - ret, (ll)z));
			ret += w; cap[e] -= w; cap[e ^ 1] += w;
			if (f == ret) return ret;
		}
	}
	return ret;
}
ll dinic() {
	ll ret = 0;
	while (getdep()) ret += getflow(s, INF);
	return ret;
}
int n, m, p[MAXN + 5], a[MAXN + 5], u[MAXN + 5], v[MAXN + 5];
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> u[i] >> v[i];
	for (int i = 1; i <= m; i++) {
		if (!p[u[i]] && !p[v[i]]) continue;
		if (p[u[i]] && !p[v[i]]) swap(u[i], v[i]);
		if (!p[u[i]] && p[v[i]]) a[v[i]]++;
		if (p[u[i]] && p[v[i]]) a[u[i]]++, a[v[i]]++;
	}
	for (int i = 1; i <= n; i++) if (a[i] < 0 || (a[i] & 1)) return puts("NO"), 0;
	s = n + m + 1, t = n + m + 2;
	for (int i = 1; i <= m; i++) {
		if (!p[u[i]] && !p[v[i]]) continue;
		if (!p[u[i]] && p[v[i]]) adde(s, i + n, 1), adde(i + n, v[i], 1);
		else adde(s, i + n, 1), adde(i + n, u[i], 1), adde(i + n, v[i], 1);
	}
	int ss = 0;
	for (int i = 1; i <= n; i++) adde(i, t, a[i] >> 1), ss += a[i] >> 1;
	if (dinic() != ss) return puts("NO"), 0;
	puts("YES");
	for (int i = 1; i <= m; i++) {
		if (!p[u[i]] && !p[v[i]]) printf("%d %d\n", u[i], v[i]);
		else if (!p[u[i]]) {
			for (int e = hd[i + n]; e; e = nxt[e]) if (to[e] == s) {
				if (cap[e]) printf("%d %d\n", u[i], v[i]);
				else printf("%d %d\n", v[i], u[i]);
			}
		} else {
			for (int e = hd[i + n]; e; e = nxt[e]) if (to[e] != s && cap[e ^ 1]) {
				if (to[e] == u[i]) printf("%d %d\n", v[i], u[i]);
				else printf("%d %d\n", u[i], v[i]);
			}
		}
	}
	return 0;
}