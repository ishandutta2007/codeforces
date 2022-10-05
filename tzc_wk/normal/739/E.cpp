// Created time: 2022/5/4 13:53:20
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
const int MAXN = 2000;
const int MAXV = 2050;
const int MAXE = 1e5;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;
int n, a, b; double p[MAXN + 5], q[MAXN + 5];
int S, T, SS, TT, hd[MAXV + 5], to[MAXE + 5], cap[MAXE + 5], nxt[MAXE + 5], ec = 1; double cst[MAXE + 5];
void adde(int u, int v, int f, double c) {
	to[++ec] = v; cap[ec] = f; cst[ec] = c; nxt[ec] = hd[u]; hd[u] = ec;
	to[++ec] = u; cap[ec] = 0; cst[ec] = -c; nxt[ec] = hd[v]; hd[v] = ec;
}
double dis[MAXV + 5]; int flw[MAXV + 5], pre[MAXV + 5], lste[MAXV + 5];
bool inq[MAXV + 5];
bool getdis() {
	fill(dis, dis + MAXV + 1, INF); memset(flw, 0, sizeof(flw));
	flw[S] = INF; dis[S] = 0; queue<int> q; q.push(S); inq[S] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop(); inq[x] = 0;
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e], z = cap[e]; double w = cst[e];
			if (z && dis[y] > dis[x] + w + EPS) {
				dis[y] = dis[x] + w; flw[y] = min(flw[x], z);
				pre[y] = x; lste[y] = e;
				if (!inq[y]) q.push(y), inq[y] = 1;
			}
		}
	}
	return dis[T] < INF - EPS;
}
pair<int, double> mcmf() {
	int mxfl = 0; double mncst = 0;
	while (getdis()) {
		mxfl += flw[T]; mncst += flw[T] * dis[T];
		for (int i = T; i ^ S; i = pre[i]) {
			cap[lste[i]] -= flw[T]; cap[lste[i] ^ 1] += flw[T];
		}
	}
	return mp(mxfl, mncst);
}
int main() {
	scanf("%d%d%d", &n, &a, &b);
	T = (S = (TT = (SS = n + 1) + 1) + 1) + 1;
	for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
	for (int i = 1; i <= n; i++) scanf("%lf", &q[i]);
	adde(S, SS, a, 0); adde(S, TT, b, 0);
	for (int i = 1; i <= n; i++) {
		adde(SS, i, 1, -p[i]); adde(TT, i, 1, -q[i]);
		adde(i, T, 1, 0); adde(i, T, 1, p[i] * q[i]);
	}
	printf("%.10lf\n", -mcmf().se);
	return 0;
}