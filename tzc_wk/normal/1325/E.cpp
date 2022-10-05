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
		x = 0; char c = getc(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getc();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getc();
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
	void readstr(char *s) {
		char c = getc();
		while (c <= 32 || c >= 127) c = getc();
		while (c > 32 && c < 127) s[0] = c, s++, c = getc();
		(*s) = 0;
	}
	void printstr(string s) {
		for (int i = 0; i < s.size(); i++) putc(s[i]);
	}
	void printstr(char *s) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) putc(s[i]);
	}
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 1e5;
const int MAXV = 1e6;
const int MAX_PR = MAXV / 6;
const int SQRT = 250;
const int INF = 0x1f1f1f1f;
int n, a[MAXN + 5]; bool vis[MAXV + 5];
int mnp[MAXV + 5], pr[MAX_PR + 5], prcnt = 0, id[MAXV + 5];
vector<int> fac[MAXN + 5];
void sieve(int n) {
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) pr[++prcnt] = i, id[i] = prcnt, mnp[i] = i;
		for (int j = 1; j <= prcnt && pr[j] * i <= n; j++) {
			vis[pr[j] * i] = 1; mnp[pr[j] * i] = pr[j];
			if (i % pr[j] == 0) break;
		}
	}
}
int hd[MAX_PR + 5], to[MAX_PR * 2 + 5], nxt[MAX_PR * 2 + 5], ec = 1;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
bool is[MAX_PR + 5]; map<int, bool> has[MAX_PR + 5];
int dis[MAX_PR + 5];
int main() {
	sieve(MAXV); scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]); int tmp = a[i];
		vector<int> fc;
		while (tmp ^ 1) {
			int p = mnp[tmp], cnt = 0;
			while (tmp % p == 0) tmp /= p, cnt ^= 1;
			if (cnt) fc.pb(id[p]);
		}
		if (fc.size() == 0) return puts("1"), 0;
		else fac[i] = fc;
	}
	for (int i = 1; i <= n; i++) {
		if (fac[i].size() == 1) {
			if (is[fac[i][0]]) return puts("2"), 0;
			adde(fac[i][0], prcnt + 1); adde(prcnt + 1, fac[i][0]);
			is[fac[i][0]] = 1;
		} else {
			adde(fac[i][0], fac[i][1]); adde(fac[i][1], fac[i][0]);
			if (has[fac[i][0]][fac[i][1]]) return puts("2"), 0;
			has[fac[i][0]][fac[i][1]] = has[fac[i][1]][fac[i][0]] = 1;
		}
	}
	int lim = 1;
	while (pr[lim] * pr[lim] <= MAXV) ++lim;
	lim--;
	int res = INF;
	for (int i = 1; i <= lim; i++) {
		memset(dis, -1, sizeof(dis)); dis[i] = 0;
		queue<pii> q; q.push(mp(i, 0));
		while (!q.empty()) {
			auto p = q.front(); q.pop();
			int x = p.fi, ee = p.se;
			for (int e = hd[x]; e; e = nxt[e]) {
				if (e == (ee ^ 1)) continue;
				int y = to[e];
				if (!~dis[y]) {
					dis[y] = dis[x] + 1;
					q.push(mp(y, e));
				} else {
					chkmin(res, dis[x] + dis[y] + 1);
				}
			}
		}
	}
	printf("%d\n", (res == INF) ? -1 : res);
	return 0;
}