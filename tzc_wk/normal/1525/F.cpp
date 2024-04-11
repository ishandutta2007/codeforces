// Created time: 2022/4/28 11:00:19
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
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
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
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
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
const int MAXN = 50;
const int MAXM = 1225;
const int INF = 0x3f3f3f3f;
int n, m, k, X[MAXN + 5], Y[MAXN + 5]; pii p[MAXM + 5];
bool book[MAXN * 2 + 5];
namespace MaxFlow {
	const int MAXV = 102;
	const int MAXE = 1e4;
	int S, T, hd[MAXV + 5], to[MAXE + 5], nxt[MAXE + 5], cap[MAXE + 5], ec = 1;
	void init() {memset(hd, 0, sizeof(hd)); ec = 1;}
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
			if (z && dep[y] == dep[x] + 1) {
				int w = getflow(y, min(f - ret, z));
				cap[e] -= w; cap[e ^ 1] += w; ret += w;
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
}
int calc() {
	MaxFlow :: init();
	for (int i = 1; i <= n; i++) if (!book[i]) MaxFlow :: adde(MaxFlow :: S, i, 1);
	for (int i = n + 1; i <= n * 2; i++) if (!book[i]) MaxFlow :: adde(i, MaxFlow :: T, 1);
	for (int i = 1; i <= m; i++) if (!book[p[i].fi] && !book[p[i].se + n])
		MaxFlow :: adde(p[i].fi, p[i].se + n, 1);
	return n - MaxFlow :: dinic();
}
vector<int> vec, res; int lim[MAXN + 5];
ll dp[MAXN + 5][MAXN + 5]; int prv[MAXN + 5][MAXN + 5];
void work(int x, int y) {
	if (!x) return;
	work(x - 1, prv[x][y]);
	for (int i = prv[x][y]; i < y; i++) res.pb(vec[i]);
	res.pb(0);
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	MaxFlow :: T = (MaxFlow :: S = n << 1 | 1) + 1;
	for (int i = 1; i <= m; i++) scanf("%d%d", &p[i].fi, &p[i].se);
	for (int i = 1; i <= k; i++) scanf("%d%d", &X[i], &Y[i]);
	int cur = calc();
	for (int i = cur; i <= k; i++) lim[i] = i - cur + 1;
	while (cur <= k) {
		for (int i = 1; i <= n * 2; i++) if (!book[i]) {
			book[i] = 1;
			if (calc() == cur + 1) {vec.pb((i <= n) ? i : (-(i - n))); cur++; break;}
			else book[i] = 0;
		}
	}
	memset(dp, 0xcf, sizeof(dp)); dp[0][0] = 0;
	for (int i = 0; i < k; i++) for (int j = lim[i]; j <= vec.size(); j++)
		if (dp[i][j] >= 0) for (int l = 0; l + j <= vec.size(); l++) if (l + j >= lim[i + 1]) {
			ll val = dp[i][j] + max(0ll, X[i + 1] - 1ll * l * Y[i + 1]);
			if (dp[i + 1][j + l] < val) dp[i + 1][j + l] = val, prv[i + 1][j + l] = j;
		}
	work(k, vec.size());
	printf("%d\n", res.size());
	for (int id : res) printf("%d ", id);
	return 0;
}