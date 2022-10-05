// stop setting trivial polynomial problems.
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
const int MAXN = 2.5e5;
const int pr = 3;
const int ipr = 332748118;
const int MOD = 998244353;
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int n, deg[MAXN + 5], cnt[MAXN + 5], res = 0, fac[MAXN + 5], ifac[MAXN + 5], dp[MAXN + 5];
void init_fac(int n) {
	for (int i = (fac[0] = ifac[0] = ifac[1] = 1) + 1; i <= n; i++) ifac[i] = 1ll * ifac[MOD % i] * (MOD - MOD / i) % MOD;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % MOD, ifac[i] = 1ll * ifac[i - 1] * ifac[i] % MOD;
}
int rev[1048585];
void NTT(vector<int> &a, int len, int type) {
	int lg = 31 - __builtin_clz(len);
	for (int i = 0; i < len; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << lg - 1);
	for (int i = 0; i < len; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int i = 2; i <= len; i <<= 1) {
		int W = qpow((type < 0) ? ipr : pr, (MOD - 1) / i);
		for (int j = 0; j < len; j += i) {
			int w = 1;
			for (int k = 0; k < (i >> 1); k++, w = 1ll * w * W % MOD) {
				int X = a[j + k], Y = 1ll * a[(i >> 1) + j + k] * w % MOD;
				a[j + k] = (X + Y) % MOD; a[(i >> 1) + j + k] = (X - Y + MOD) % MOD;
			}
		}
	}
	if (!~type) {
		int iv = qpow(len, MOD - 2);
		for (int i = 0; i < len; i++) a[i] = 1ll * a[i] * iv % MOD;
	}
}
vector<int> conv(vector<int> a, vector<int> b) {
	int nd = a.size() + b.size() - 1;
	int LEN = 1; while (LEN < a.size() + b.size()) LEN <<= 1;
	a.resize(LEN, 0); b.resize(LEN, 0);
	NTT(a, LEN, 1); NTT(b, LEN, 1);
	for (int i = 0; i < LEN; i++) a[i] = 1ll * a[i] * b[i] % MOD;
	NTT(a, LEN, -1); while (a.size() > nd) a.ppb();
	return a;
}
vector<int> solve(int l, int r) {
	if (l == r) return vector<int>{1, deg[l] - (l != 1)};
	int mid = l + r >> 1;
	return conv(solve(l, mid), solve(mid + 1, r));
}
int main() {
	scanf("%d", &n); dp[0] = 1; init_fac(MAXN);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), deg[u]++, deg[v]++;
	vector<int> dp = solve(1, n);
	int res = 0;
	for (int i = 0; i <= n; i++) {
		if ((i & 1)) res = (res - 1ll * dp[i] * fac[n - i] % MOD + MOD) % MOD;
		else res = (res + 1ll * dp[i] * fac[n - i]) % MOD;
	}
	printf("%d\n", res);
	return 0;
}