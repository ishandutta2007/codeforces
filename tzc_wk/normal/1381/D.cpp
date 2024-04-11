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
const int MAXN = 1e5;
const int LOG_N = 17;
int n, A, B, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0, R;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
void clear() {for (int i = 1; i <= n; i++) hd[i] = 0; ec = 0; R = 0;}
int fa[MAXN + 5], dep[MAXN + 5], mxdep[MAXN + 5], mxdep_out[MAXN + 5], DIS;
int FA[MAXN + 5][LOG_N + 2];
void dfs1(int x, int f) {
	fa[x] = f; dep[x] = dep[f] + 1; mxdep[x] = 0;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dfs1(y, x); chkmax(mxdep[x], mxdep[y] + 1);
	}
}
void dfs2(int x, int f) {
	multiset<int> st; st.insert(0);
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e];
		if (y == f) st.insert(mxdep_out[x]);
		else st.insert(mxdep[y] + 1);
	}
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		st.erase(st.find(mxdep[y] + 1));
		mxdep_out[y] = (*st.rbegin()) + 1;
		st.insert(mxdep[y] + 1); dfs2(y, x);
	}
}
int getlca(int x, int y) {
	while (dep[x] > dep[y]) x = fa[x];
	while (dep[y] > dep[x]) y = fa[y];
	while (x ^ y) x = fa[x], y = fa[y];
	return x;
}
int get_kanc(int x, int k) {
	for (int i = LOG_N; ~i; i--) if (k >> i & 1) x = FA[x][i];
	return x;
}
void solve() {
	scanf("%d%d%d", &n, &A, &B); clear();
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
	dfs1(1, 0); dfs2(1, 0); DIS = dep[A] + dep[B] - dep[getlca(A, B)] * 2;
//	printf("mxdep: "); for (int i = 1; i <= n; i++) printf("%d%c", mxdep[i], " \n"[i == n]);
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int e = hd[i]; e; e = nxt[e]) {
			if (to[e] == fa[i]) sum += (mxdep_out[i] >= DIS);
			else sum += (mxdep[to[e]] + 1 >= DIS); 
		}
//		printf("! %d %d\n", i, sum);
		if (sum >= 3) R = i;
	}
	if (!R) return puts("NO"), void(); dfs1(R, 0);
	int lc = getlca(A, B);
	if (lc == A || lc == B) return puts("YES"), void();
	for (int i = 1; i <= n; i++) FA[i][0] = fa[i];
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j <= n; j++)
		FA[j][i] = FA[FA[j][i - 1]][i - 1];
	int depA = dep[A], depB = dep[B], cur = 0, stp = 0;
	while (depA > dep[lc] && depB > dep[lc] && stp <= n) {
		if (cur) {
			int can = mxdep[get_kanc(B, dep[B] - depB)];
			depB += can; depA -= can;
		} else {
			int can = mxdep[get_kanc(A, dep[A] - depA)];
			depA += can; depB -= can;
		}
		cur ^= 1; ++stp;
	}
	if (depA <= dep[lc] || depB <= dep[lc]) return puts("YES"), void();
	depA = dep[A], depB = dep[B], cur = 1, stp = 0;
	while (dep[A] > dep[lc] && dep[B] > dep[lc] && stp <= n) {
		if (cur) {
			int can = mxdep[get_kanc(B, dep[B] - depB)];
			depB += can; depA -= can;
		} else {
			int can = mxdep[get_kanc(A, dep[A] - depA)];
			depA += can; depB -= can;
		}
		cur ^= 1; ++stp;
	}
	if (depA <= dep[lc] || depB <= dep[lc]) return puts("YES"), void();
	puts("NO");
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}