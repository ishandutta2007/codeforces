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
const int LOG_N = 22;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
int n, m, pw[MAXN + 5];
struct graph{
	int hd[MAXN + 5], nxt[MAXN + 5], to[MAXN + 5], ec = 0;
	void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
} g, rev;
struct dat {
	int c, dis, cnt;
	dat(int _c = 0, int _dis = 0, int _cnt = 0): c(_c), dis(_dis), cnt(_cnt){}
	bool operator < (dat rhs) const {return mp(c, cnt) < mp(rhs.c, rhs.cnt);}
	bool operator > (dat rhs) const {
		return rhs < *this;
	}
	dat operator ~() const {return dat(c + 1, (dis + pw[c]) % MOD, cnt);}
	dat operator +(const int &rhs) {return dat(c, (dis + rhs) % MOD, cnt + rhs);}
	void print() {printf("{c = %d, dis = %d, cnt = %d}\n", c, dis, cnt);}
};
int d[MAXN + 5][LOG_N + 2];
void calc_dp() {
	memset(d, 63, sizeof(d)); d[1][0] = 0;
	for (int i = 0; i < LOG_N; i++) {
		priority_queue<pii, vector<pii>, greater<pii> > q;
		for (int j = 1; j <= n; j++) q.push(mp(d[j][i], j));
		while (!q.empty()) {
			pii p = q.top(); q.pop();
			int x = p.se; graph &G = (i & 1) ? rev : g;
			for (int e = G.hd[x]; e; e = G.nxt[e]) {
				int y = G.to[e];
				if (d[y][i] > d[x][i] + 1) {
					d[y][i] = d[x][i] + 1;
					q.push(mp(d[y][i], y));
				}
			}
		}
		for (int j = 1; j <= n; j++) chkmin(d[j][i + 1], d[j][i] + pw[i]);
	}
}
dat dp[MAXN + 5][2];
void dijkstra() {
	for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = dat(INF, 0, 0);
	dp[1][0] = dat(0, 0, 0);
	#define pdi pair<dat, int>
	priority_queue<pdi, vector<pdi>, greater<pdi> > q;
	q.push(mp(dp[1][0], 1));
	while (!q.empty()) {
		auto p = q.top(); q.pop();
		int x = p.se; dat d = p.fi;
		if (dp[x][(d.c ^ 1) & 1] > (~dp[x][d.c & 1])) {
			dp[x][(d.c ^ 1) & 1] = (~dp[x][d.c & 1]);
			q.push(mp(dp[x][(d.c ^ 1) & 1], x));
		}
		graph &G = (d.c & 1) ? rev : g;
		for (int e = G.hd[x]; e; e = G.nxt[e]) {
			int y = G.to[e];
			if (dp[y][d.c & 1] > dp[x][d.c & 1] + 1) {
				dp[y][d.c & 1] = dp[x][d.c & 1] + 1;
				q.push(mp(dp[y][d.c & 1], y));
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = (pw[0] = 1); i <= MAXN; i++) pw[i] = 2 * pw[i - 1] % MOD;
	for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), g.adde(u, v), rev.adde(v, u);
	calc_dp(); int mn = INF;
	for (int i = 0; i <= LOG_N; i++) chkmin(mn, d[n][i]);
	if (mn < INF) printf("%d\n", mn);
	else {
		dijkstra();
		printf("%d\n", min(dp[n][0], dp[n][1]).dis);
	}
	return 0;
}