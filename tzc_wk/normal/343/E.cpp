// Created time: 2022/5/4 15:29:01
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
const int MAXN = 200;
const int MAXM = 1000;
const int INF = 0x3f3f3f3f;
int n, m, k;
struct edge {int u, v, w;} e[MAXM + 5], ee[MAXN + 5];
namespace MaxFlow {
	const int MAXV = MAXN;
	const int MAXE = MAXM << 2;
	int hd[MAXV + 5], to[MAXE + 5], nxt[MAXE + 5], cap[MAXE + 5], ec = 1;
	void adde(int u, int v, int f) {
		to[++ec] = v; cap[ec] = f; nxt[ec] = hd[u]; hd[u] = ec;
		to[++ec] = u; cap[ec] = 0; nxt[ec] = hd[v]; hd[v] = ec;
	}
	void init() {
		memset(hd, 0, sizeof(hd)); ec = 1;
		for (int i = 1; i <= m; i++) {
			adde(e[i].u, e[i].v, e[i].w);
			adde(e[i].v, e[i].u, e[i].w);
		}
	}
	int dep[MAXV + 5], now[MAXV + 5];
	bool getdep(int S, int T) {
		memset(dep, -1, sizeof(dep));
		dep[S] = 0; queue<int> q; q.push(S);
		while (!q.empty()) {
			int x = q.front(); q.pop(); now[x] = hd[x];
			for (int e = hd[x]; e; e = nxt[e]) {
				int y = to[e], z = cap[e];
				if (z && !~dep[y]) {dep[y] = dep[x] + 1; q.push(y);}
			}
		}
		return ~dep[T];
	}
	int getflow(int x, int T, int f) {
		if (x == T) return f; int ret = 0;
		for (int &e = now[x]; e; e = nxt[e]) {
			int y = to[e], z = cap[e];
			if (z && dep[y] == dep[x] + 1) {
				int w = getflow(y, T, min(f - ret, z));
				cap[e] -= w; cap[e ^ 1] += w; ret += w;
				if (f == ret) return ret;
			}
		}
		return ret;
	}
	int dinic(int S, int T) {
		int ret = 0;
		while (getdep(S, T)) ret += getflow(S, T, INF);
		return ret;
	}
	int calc(int S, int T) {init(); return dinic(S, T);}
}
void build(vector<int> vec) {
	if (vec.size() == 1) return;
	int S = vec[0], T = vec[1];
	ee[++k] = {S, T, MaxFlow :: calc(S, T)};
	vector<int> L, R;
	for (int x : vec) {
		if (~MaxFlow :: dep[x]) L.pb(x);
		else R.pb(x);
	}
	build(L); build(R);
}
ll ret = 0;
int hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0, bel[MAXN + 5];
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
void dfsput(int x, int f, int c) {
	bel[x] = c;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dfsput(y, x, c);
	}
}
vector<int> work(vector<int> vec) {
	if (vec.size() == 1) return vec;
	bool in[MAXN + 5]; memset(in, 0, sizeof(in));
	for (int x : vec) in[x] = 1;
	pii mn = mp(INF, 0);
	for (int i = 1; i <= k; i++) if (in[ee[i].u] && in[ee[i].v])
		chkmin(mn, mp(ee[i].w, i));
	memset(hd, 0, sizeof(hd)); ec = 0;
	for (int i = 1; i <= k; i++) if (in[ee[i].u] && in[ee[i].v] && i != mn.se)
		adde(ee[i].u, ee[i].v), adde(ee[i].v, ee[i].u);
	dfsput(ee[mn.se].u, 0, 1); dfsput(ee[mn.se].v, 0, 2);
	ret += ee[mn.se].w; vector<int> A, B, rA, rB;
	for (int x : vec) {
		if (bel[x] == 1) A.pb(x);
		else B.pb(x);
	}
	rA = work(A); rB = work(B);
	for (int x : rB) rA.pb(x);
	return rA;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	vector<int> vec; for (int i = 1; i <= n; i++) vec.pb(i);
	build(vec);
//	for (int i = 1; i <= k; i++) printf("%d %d %d\n", ee[i].u, ee[i].v, ee[i].w);
	vector<int> res = work(vec); printf("%lld\n", ret);
	for (int x : res) printf("%d ", x);
	return 0;
}