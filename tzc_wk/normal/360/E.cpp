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
const int MAXN = 1e4;
const int MAXM = 2e4;
int n, m, k, s1, s2, f, op[MAXM + 5];
struct edge {int u, v, l, r;} e[MAXM + 5];
int hd[MAXN + 5], to[MAXM * 2 + 5], nxt[MAXM * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
ll d1[MAXN + 5], d2[MAXN + 5];
void dijkstra(int s, ll *d) {
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
	memset(d, 63, sizeof(d1)); d[s] = 0; q.push(mp(0, s));
	while (!q.empty()) {
		pair<ll, int> p = q.top(); q.pop();
		int x = p.se;
		for (int E = hd[x]; E; E = nxt[E]) {
			int y = to[E], w = (op[E] ? e[E].l : e[E].r);
			if (d[y] > d[x] + w) {
				d[y] = d[x] + w;
				q.push(mp(d[y], y));
			}
		}
	}
}
bool solve(int lim) {
	while(1) {
		dijkstra(s1, d1); dijkstra(s2, d2); bool flg = 0;
		for (int i = m + 1; i <= m + k; i++) if (!op[i] && d1[e[i].u] < d2[e[i].u] + lim) {
			flg = 1; op[i] = 1;
		}
		if (!flg) break;
	}
	return d1[f] < d2[f] + lim;
}
int main() {
	scanf("%d%d%d%d%d%d", &n, &m, &k, &s1, &s2, &f);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].l); e[i].r = e[i].l;
		adde(e[i].u, e[i].v);
	}
	for (int i = m + 1; i <= m + k; i++) {
		scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].l, &e[i].r);
		adde(e[i].u, e[i].v);
	}
	if (solve(0)) {
		puts("WIN");
		for (int i = m + 1; i <= m + k; i++)
			printf("%d%c", op[i] ? e[i].l : e[i].r, " \n"[i == m + k]);
		return 0;
	}
	if (solve(1)) {
		puts("DRAW");
		for (int i = m + 1; i <= m + k; i++)
			printf("%d%c", op[i] ? e[i].l : e[i].r, " \n"[i == m + k]);
		return 0;
	}
	puts("LOSE");
	return 0;
}