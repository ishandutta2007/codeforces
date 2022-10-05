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
const int MAXN = 600;
const int MAXM = 1e5;
int n, m, mod; vector<int> g[MAXN + 5];
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % mod)
		if (e & 1) ret = 1ll * ret * x % mod;
	return ret;
}
int ind[MAXN + 5], oud[MAXN + 5], idS[MAXN + 5], idT[MAXN + 5], Snum, Tnum;
int dp[MAXN + 5], tmp[MAXN + 5], A[MAXN + 5][MAXN + 5];
int main() {
	scanf("%d%d%d", &n, &m, &mod);
	for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), oud[u]++, ind[v]++, g[u].pb(v);
	for (int i = 1; i <= n; i++) if (!ind[i]) idS[i] = ++Snum;
	for (int i = 1; i <= n; i++) if (!oud[i]) idT[i] = ++Tnum;
	for (int i = 1; i <= n; i++) if (idS[i]) {
		queue<int> q; memset(dp, 0, sizeof(dp));
		for (int j = 1; j <= n; j++) tmp[j] = ind[j];
		dp[i] = 1;
		for (int j = 1; j <= n; j++) if (!tmp[j]) q.push(j);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int y : g[x]) {
				dp[y] = (dp[y] + dp[x]) % mod;
				if (!--tmp[y]) q.push(y);
			}
		}
		for (int j = 1; j <= n; j++) if (!oud[j]) A[idS[i]][idT[j]] = dp[j];
	}
	int prd = 1;
	for (int i = 1; i <= Snum; i++) {
		int t = i;
		for (int j = i + 1; j <= Snum; j++) if (A[j][i]) t = j;
		if (t != i) {
			prd = mod - prd;
			for (int j = i; j <= Snum; j++) swap(A[i][j], A[t][j]);
		}
		int iv = qpow(A[i][i], mod - 2);
		for (int j = i + 1; j <= Snum; j++) {
			int coef = mod - 1ll * A[j][i] * iv % mod;
			for (int k = i; k <= Snum; k++) A[j][k] = (A[j][k] + 1ll * A[i][k] * coef) % mod;
		}
	}
	for (int i = 1; i <= Snum; i++) prd = 1ll * prd * A[i][i] % mod;
	printf("%d\n", prd);
	return 0;
}