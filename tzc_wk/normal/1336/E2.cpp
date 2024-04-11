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
const int LOG_V = 53;
const int MOD = 998244353;
int n, m, pw; ll a[MAXN + 5];
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
struct lbase {
	int dim; ll b[LOG_V + 2];
	void ins(ll v) {
		for (int i = m - 1; ~i; i--) if (v >> i & 1) {
			if (!b[i]) return b[i] = v, dim++, void();
			else v ^= b[i];
		}
	}
} A;
namespace sol1 {
	int res[LOG_V + 2];
	void dfs(int x, ll sum) {
		if (x == m) return res[__builtin_popcountll(sum)]++, void();
		dfs(x + 1, sum); if (A.b[x]) dfs(x + 1, sum ^ A.b[x]);
	}
	void solve() {
		dfs(0, 0);
		for (int i = 0; i <= m; i++) printf("%d%c", 1ll * res[i] * pw % MOD, " \n"[i == m]);
	}
}
namespace sol2 {
	lbase B;
	int pos[LOG_V + 2], poscnt = 0, id[LOG_V + 2];
	ll nw[LOG_V + 2];
	void construct() {
		for (int i = 0; i < m; i++) if (A.b[i]) {
			for (int j = i + 1; j < m; j++) if (A.b[j] && (A.b[j] >> i & 1))
				A.b[j] ^= A.b[i];
		}
//		for (int i = 0; i < m; i++) printf("%lld\n", A.b[i]); 
		for (int i = 0; i < m; i++) if (A.b[i]) pos[poscnt] = i, id[i] = poscnt++;
		for (int i = 0; i < m; i++) if (!A.b[i]) pos[poscnt] = i, id[i] = poscnt++;
		for (int i = 0; i < m; i++) if (A.b[i])
			for (int j = 0; j < m; j++) if (!A.b[j] && (A.b[i] >> j & 1))
				nw[id[j] - A.dim] |= 1ll << i;
		for (int i = 0; i < m; i++) if (!A.b[i]) nw[id[i] - A.dim] |= 1ll << i;
		for (int i = 0; i < m - A.dim; i++) B.ins(nw[i]);
//		for (int i = 0; i < m - A.dim; i++) printf("%lld\n", nw[i]);
	}
	int C[LOG_V + 5][LOG_V + 5];
	int resb[LOG_V + 5], resa[LOG_V + 5];
	void dfs(int x, ll sum) {
		if (x == m) return resb[__builtin_popcountll(sum)]++, void();
		dfs(x + 1, sum); if (B.b[x]) dfs(x + 1, sum ^ B.b[x]);
	}
	void solve() {
		for (int i = 0; i <= LOG_V; i++) for (int j = (C[i][0] = 1); j <= i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		construct(); dfs(0, 0);
		for (int c = 0; c <= m; c++) for (int d = 0; d <= m; d++) for (int i = 0; i <= min(c, d); i++) {
			if (~i & 1) resa[c] = (resa[c] + 1ll * resb[d] * C[d][i] % MOD * C[m - d][c - i]) % MOD;
			else resa[c] = (resa[c] - 1ll * resb[d] * C[d][i] % MOD * C[m - d][c - i] % MOD + MOD) % MOD;
		}
		int iv = qpow(2, MOD - 1 - (m - A.dim));
		for (int i = 0; i <= m; i++) printf("%d%c", 1ll * resa[i] * pw % MOD * iv % MOD, " \n"[i == m]);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), A.ins(a[i]);
	pw = qpow(2, n - A.dim);
	if (A.dim * 2 <= m) sol1 :: solve();
	else sol2 :: solve();
	return 0;
}