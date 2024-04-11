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
#ifdef FASTIO
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
		if (x < 0) putc('-'), x = -x;
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
	void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
}
using namespace fastio;
#endif
const int MAXN = 2e5;
int n, m;
struct event {int w, u, v;} q[MAXN + 5];
struct graph {
	int hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
	void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
} G1, G2;
int col[MAXN + 5];
void dye(int x, int c) {
	if (~col[x] && col[x] != c) puts("NO"), exit(0);
	if (~col[x]) return; col[x] = c;
	for (int e = G1.hd[x]; e; e = G1.nxt[e]) {int y = G1.to[e]; dye(y, c ^ 1);}
}
int deg[MAXN + 5], vis[MAXN + 5], pos[MAXN + 5], seqlen = 0;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &q[i].w, &q[i].u, &q[i].v);
		G1.adde(q[i].u, q[i].v); G1.adde(q[i].v, q[i].u);
	}
	memset(col, -1, sizeof(col));
	for (int i = 1; i <= n; i++) if (!~col[i]) dye(i, 0);
	// 0 for L and 1 for R
	for (int i = 1; i <= m; i++) {
		if (q[i].w == 1) {
			if (col[q[i].u]) G2.adde(q[i].v, q[i].u), deg[q[i].u]++;
			else G2.adde(q[i].u, q[i].v), deg[q[i].v]++;
		} else {
			if (!col[q[i].u]) G2.adde(q[i].v, q[i].u), deg[q[i].u]++;
			else G2.adde(q[i].u, q[i].v), deg[q[i].v]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) if (!deg[i]) q.push(i);
	while (!q.empty()) {
		int x = q.front(); q.pop(); vis[x] = 1; pos[x] = ++seqlen;
		for (int e = G2.hd[x]; e; e = G2.nxt[e]) {
			int y = G2.to[e];
			if (!--deg[y]) q.push(y);
		}
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) return puts("NO"), 0;
	puts("YES");
	for (int i = 1; i <= n; i++) printf("%c %d\n", "LR"[col[i]], pos[i]);
	return 0;
}