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
const int MAXV = 4e5;
const int MAXE = 1e7;
const int MAXN = 2e5;
const int INF = 0x3f3f3f3f;
int n1, n2, m, qu;
int S, T, hd[MAXV + 5], to[MAXE + 5], nxt[MAXE + 5], cap[MAXE + 5], ec = 1;
void adde(int u, int v, int f) {
	to[++ec] = v; cap[ec] = f; nxt[ec] = hd[u]; hd[u] = ec;
	to[++ec] = u; cap[ec] = 0; nxt[ec] = hd[v]; hd[v] = ec;
}
int dep[MAXV + 5], now[MAXV + 5];
bool getdep() {
	memset(dep, -1, sizeof(dep)); dep[S] = 0;
	queue<int> q; q.push(S);
	while (!q.empty()) {
		int x = q.front(); q.pop(); now[x] = hd[x];
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e], z = cap[e];
			if (z && !~dep[y]) dep[y] = dep[x] + 1, q.push(y);
		}
	}
	return ~dep[T];
}
int getflow(int x, int f) {
	if (x == T) return f; int ret = 0;
	for (int &e = now[x]; e; e = nxt[e]) {
		int y = to[e], z = cap[e];
		if (dep[y] == dep[x] + 1 && z) {
			int w = getflow(y, min(f - ret, z));
			ret += w; cap[e] -= w; cap[e ^ 1] += w;
			if (f == ret) return ret;
		}
	}
	return ret;
}
int dinic() {
	int ret = 0;
	while (getdep()) ret += getflow(S, INF);
	return ret;
}
int mchl[MAXN + 5], mchr[MAXN + 5], mche[MAXN + 5], vis[MAXV + 5];
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &n1, &n2, &m, &qu); T = (S = n1 + n2 + 1) + 1;
	for (int i = 1, x, y; i <= m; i++) scanf("%d%d", &x, &y), adde(x, y + n1, 1);
	for (int i = 1; i <= n1; i++) adde(S, i, 1);
	for (int i = 1; i <= n2; i++) adde(i + n1, T, 1);
	int fl = dinic(); vector<int> vec;
	for (int i = 1; i <= n1 + n2; i++) {
		if (i <= n1 && !~dep[i]) vec.pb(i);
		if (i > n1 && ~dep[i]) vec.pb(n1 - i);
	}
	for (int i = 1; i <= n1; i++) for (int e = hd[i]; e; e = nxt[e])
		if (to[e] != S && cap[e ^ 1]) {
			mchl[i] = to[e] - n1; mchr[to[e] - n1] = i; mche[i] = e >> 1;
		}
	ll sum = 0;
	for (int i = 1; i <= n1; i++) if (mchl[i]) sum += mche[i];
	while (qu--) {
		int opt; scanf("%d", &opt);
		if (opt == 1) {
			int id = vec.back(); vec.ppb();
			if (id > 0) sum -= mche[id];
			else sum -= mche[mchr[-id]];
			cout << 1 << endl << id << endl << sum << endl;
			vis[(id > 0) ? id : (n1 - id)] = 1;
		} else {
			vector<int> vec;
			for (int i = 1; i <= n1; i++) if (mchl[i] && !vis[i] && !vis[mchl[i] + n1])
				vec.pb(mche[i]);
			cout << vec.size() << endl;
			for (int x : vec) cout << x << " "; cout << endl;
		}
	}
	return 0;
}