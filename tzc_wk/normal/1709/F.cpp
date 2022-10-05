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
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 1064
#endif
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
const int MAXN = 15;
const int MAXP = 524288;
const int MAXK = 2e5;
const int pr = 3;
const int ipr = 332748118;
const int MOD = 998244353;
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int n, f, k; vector<int> dp[MAXN + 3];
int rev[MAXP + 5];
void NTT(vector<int> &a, int len, int type) {
	int lg = 31 - __builtin_clz(len);
	for (int i = 0; i < len; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << lg - 1);
	for (int i = 0; i < len; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int i = 2; i <= len; i <<= 1) {
		int W = qpow((type < 0) ? ipr : pr, (MOD - 1) / i);
		for (int j = 0; j < len; j += i) {
			for (int k = 0, w = 1; k < (i >> 1); k++, w = 1ll * w * W % MOD) {
				int X = a[j + k], Y = 1ll * a[(i >> 1) + j + k] * w % MOD;
				a[j + k] = (X + Y) % MOD; a[(i >> 1) + j + k] = (X - Y + MOD) % MOD;
			}
		}
	}
	if (type < 0) {
		int iv = qpow(len, MOD - 2);
		for (int i = 0; i < len; i++) a[i] = 1ll * a[i] * iv % MOD;
	}
}
vector<int> conv(vector<int> a, vector<int> b) {
	int LEN = 1; while (LEN < a.size() + b.size()) LEN <<= 1;
	a.resize(LEN, 0); b.resize(LEN, 0); NTT(a, LEN, 1); NTT(b, LEN, 1);
	for (int i = 0; i < LEN; i++) a[i] = 1ll * a[i] * b[i] % MOD;
	NTT(a, LEN, -1);
	while (a.size() > k + 1) {
		int v = a.back(); a.ppb();
		a[k] = (a[k] + v) % MOD;
	}
	return a;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &k, &f); if (f > k * 2) return puts("0"), 0;
	dp[1].resize(k + 1); for (int i = 0; i <= k; i++) dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		vector<int> tmp = conv(dp[i - 1], dp[i - 1]); static int suf[MAXK + 5];
		for (int j = k; ~j; j--) suf[j] = (suf[j + 1] + tmp[j]) % MOD;
		dp[i].resize(k + 1);
		for (int j = 0; j <= k; j++) dp[i][j] = 1ll * (k - j + 1) * suf[j] % MOD;
		for (int j = 0; j < k; j++) dp[i][j] = (dp[i][j] - dp[i][j + 1] + MOD) % MOD;
	}
	int res = 0;
	for (int i = 0; i <= f; i++) if (i <= k && f - i <= k)
		res = (res + 1ll * dp[n][i] * dp[n][f - i]) % MOD;
	printf("%d\n", res);
	return 0;
}