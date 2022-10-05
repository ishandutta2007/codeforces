// Created time: 2022/6/22 9:34:35
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
#ifdef LOCAL
inline char getc() {return getchar();}
inline void putc(char c) {putchar(c);}
#else
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
#endif
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
const int MAXN = 1e5;
const int MAXL = 2e5;
const int LOG_N = 18;
int n, m, qu, lg[262145];
int hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
char val[MAXN * 2 + 5];
void adde(int u, int v, char w) {to[++ec] = v; val[ec] = w; nxt[ec] = hd[u]; hd[u] = ec;}
string str[MAXN + 5];
namespace Suffix_Array {
	int s[MAXL + 5], bel[MAXL + 5], len = 0, sgm = 122;
	int sa[MAXL + 5], rk[MAXL + 5], buc[MAXL + 5], seq[MAXL + 5];
	void getsa() {
		memset(buc, 0, sizeof(buc)); int vmax = sgm, gr = 0;
		for (int i = 1; i <= len; i++) buc[s[i]]++;
		for (int i = 1; i <= vmax; i++) buc[i] += buc[i - 1];
		for (int i = len; i; i--) sa[buc[s[i]]--] = i;
		for (int i = 1; i <= len; i++) {
			if (s[sa[i]] != s[sa[i - 1]]) ++gr;
			rk[sa[i]] = gr;
		}
		vmax = gr;
		for (int k = 1; k <= len; k <<= 1) {
			static pii x[MAXL + 5];
			for (int i = 1; i <= len; i++) {
				if (i + k <= len) x[i] = mp(rk[i], rk[i + k]);
				else x[i] = mp(rk[i], 0);
			}
			memset(buc, 0, sizeof(buc)); int num = 0; gr = 0;
			for (int i = len - k + 1; i <= len; i++) seq[++num] = i;
			for (int i = 1; i <= len; i++) if (sa[i] > k) seq[++num] = sa[i] - k;
			for (int i = 1; i <= len; i++) buc[x[i].fi]++;
			for (int i = 1; i <= vmax; i++) buc[i] += buc[i - 1];
			for (int i = len; i; i--) sa[buc[x[seq[i]].fi]--] = seq[i];
			for (int i = 1; i <= len; i++) {
				if (x[sa[i]] != x[sa[i - 1]]) ++gr;
				rk[sa[i]] = gr;
			}
			vmax = gr; if (vmax == len) break;
		}
	}
	void init_sa() {
		for (int i = 1; i <= m; i++) {
			s[++len] = ++sgm;
			for (int j = 0; j < str[i].size(); j++) {
				s[++len] = str[i][j];
				bel[len] = i;
			}
		}
		s[++len] = ++sgm; getsa();
	}
}
using namespace Suffix_Array;
namespace Treework {
	int dep[MAXN + 5], fa[MAXN + 5][LOG_N + 2], faw[MAXN + 5];
	int mxdep[MAXN + 5], dson[MAXN + 5], top[MAXN + 5];
	void dfs(int x, int f) {
		fa[x][0] = f;
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e], z = val[e]; if (y == f) continue;
			faw[y] = z; dep[y] = dep[x] + 1; dfs(y, x);
			if (mxdep[y] + 1 > mxdep[x]) mxdep[x] = mxdep[y] + 1, dson[x] = y;
		}
	}
	void dfs_chn(int x, int tp) {
		top[x] = tp; if (dson[x]) dfs_chn(dson[x], tp);
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e]; if (y == fa[x][0] || y == dson[x]) continue;
			dfs_chn(y, y);
		}
	}
	vector<int> up[MAXN + 5], dw[MAXN + 5];
	int get_kanc(int x, int k) {
		if (!k) return x;
		int stp = lg[k]; x = fa[x][stp]; k -= (1 << stp);
		k -= dep[x] - dep[top[x]]; x = top[x];
		return (k > 0) ? up[x][k] : dw[x][-k];
	}
	int getlca(int x, int y) {
		if (dep[x] < dep[y]) swap(x, y);
		for (int i = LOG_N; ~i; i--) if (dep[x] - (1 << i) >= dep[y])
			x = fa[x][i];
		if (x == y) return x;
		for (int i = LOG_N; ~i; i--) if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
		return fa[x][0];
	}
	void init_tree() {
		dfs(1, 0); dfs_chn(1, 1);
		for (int i = 1; i <= LOG_N; i++) for (int j = 1; j <= n; j++)
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
		for (int i = 1; i <= n; i++) if (top[i] == i) {
			for (int x = i, y = i, stp = mxdep[i], j = 0; j <= stp; j++, x = fa[x][0], y = dson[y])
				up[i].pb(x), dw[i].pb(y);
		}
	}
}
using namespace Treework;
namespace Hash {
	const int BS = 19260817;
	const int MOD = 1004535809;
	int qpow(int x, int e, int mod) {
		int ret = 1;
		for (; e; e >>= 1, x = 1ll * x * x % mod)
			if (e & 1) ret = 1ll * ret * x % mod;
		return ret;
	}
	const int ivBS = qpow(BS, MOD - 2, MOD);
	int hs[MAXL + 5], pw[MAXL + 5], pw_iv[MAXL + 5]; // hash on sequence
	int gethash(int l, int r) {return (hs[r] - 1ll * hs[l - 1] * pw[r - l + 1] % MOD + MOD) % MOD;}
	int hs1[MAXN + 5], hs2[MAXN + 5];
	void dfshash(int x, int f) {
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e], z = val[e]; if (y == f) continue;
			hs1[y] = (hs1[x] + 1ll * z * pw[dep[x]]) % MOD;
			hs2[y] = (1ll * hs2[x] * BS + z) % MOD;
			dfshash(y, x);
		}
	}
	int gethash1(int u, int v) { // v is ancestor of u
		return 1ll * pw_iv[dep[v]] * (hs1[u] - hs1[v] + MOD) % MOD;
	}
	int gethash2(int u, int v) { // u is ancestor of v
		return (hs2[v] - 1ll * hs2[u] * pw[dep[v] - dep[u]] % MOD + MOD) % MOD;
	}
	void init_hash() {
		for (int i = 1; i <= len; i++) hs[i] = (1ll * hs[i - 1] * BS + s[i]) % MOD;
		for (int i = (pw[0] = pw_iv[0] = 1); i <= MAXL; i++) {
			pw[i] = 1ll * pw[i - 1] * BS % MOD;
			pw_iv[i] = 1ll * pw_iv[i - 1] * ivBS % MOD;
		}
		dfshash(1, 0);
	}
}
using namespace Hash;
int getlcp(int x, int u, int v, int lc) {
	int A = dep[u] - dep[lc], B = dep[v] - dep[lc];
	int l = 1, r = min(len - x + 1, A + B), p = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		int hs1 = gethash(x, x + mid - 1), hs2;
		if (mid <= A) hs2 = gethash1(u, get_kanc(u, mid));
		else {
			int X = gethash1(u, lc), Y = gethash2(lc, get_kanc(v, B - (mid - A)));
			hs2 = (1ll * X * pw[mid - A] + Y) % MOD;
		}
		if (hs1 == hs2) p = mid, l = mid + 1;
		else r = mid - 1;
	}
	return p;
}
struct qry {int l, r, L, R;} q[MAXN + 5];
int getcmp(int x, int u, int v, int lc) {
	int L = getlcp(x, u, v, lc);
	int len1 = len - x + 1, A = dep[u] - dep[lc], B = dep[v] - dep[lc], len2 = A + B;
	if (L == len1 || L == len2) {
		if (len1 == len2) return 0;
		else if (L == len1) return -1;
		else return 1;
	} else {
		int c1 = s[x + L], c2 = (L < A) ? faw[get_kanc(u, L)] : faw[get_kanc(v, B - (L - A + 1))];
		return (c1 < c2) ? -1 : 1;
	}
}
vector<pii> qv[MAXL + 5];
int t[MAXN + 5], res[MAXN + 5];
void add(int x, int v) {for (int i = x; i <= m; i += (i & (-i))) t[i] += v;}
int query(int x) {int ret = 0; for (int i = x; i; i &= (i - 1)) ret += t[i]; return ret;}
int main() {
	for (int i = 0; i <= LOG_N; i++) lg[1 << i] = 1; lg[0] = -1;
	for (int i = 1; i <= 262144; i++) lg[i] += lg[i - 1];
	cin >> n >> m >> qu;
	for (int i = 1; i < n; i++) {
		int u, v; char w; cin >> u >> v >> w;
		adde(u, v, w); adde(v, u, w);
	}
	for (int i = 1; i <= m; i++) cin >> str[i];
	init_sa(); init_tree(); init_hash();
	for (int i = 1, u, v; i <= qu; i++) {
		cin >> u >> v >> q[i].l >> q[i].r;
		int lc = getlca(u, v);
		int L = 1, R = len, p = 0;
		while (L <= R) {
			int mid = L + R >> 1;
			if (getcmp(sa[mid], u, v, lc) < 0) p = mid, L = mid + 1;
			else R = mid - 1;
		}
		q[i].L = p + 1; L = p + 1, R = len;
		while (L <= R) {
			int mid = L + R >> 1;
			if (getlcp(sa[mid], u, v, lc) == dep[u] + dep[v] - dep[lc] * 2)
				p = mid, L = mid + 1;
			else R = mid - 1;
		}
		q[i].R = p;
		qv[q[i].L - 1].pb(mp(i, -1)); qv[q[i].R].pb(mp(i, 1));
	}
	for (int i = 1; i <= len; i++) {
		if (bel[sa[i]]) add(bel[sa[i]], 1);
		for (pii p : qv[i]) res[p.fi] += p.se * (query(q[p.fi].r) - query(q[p.fi].l - 1));
	}
	for (int i = 1; i <= qu; i++) printf("%d\n", res[i]);
	return 0;
}