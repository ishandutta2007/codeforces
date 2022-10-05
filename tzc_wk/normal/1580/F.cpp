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
const int MAXN = 50000;
const int MAXP = 262144;
const int pr = 3;
const int ipr = 332748118;
const int MOD = 998244353;
int n, m;
typedef vector<int> vi;
void add(int &x, int y) {((x += y) >= MOD) && (x -= MOD);}
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int rev[MAXP + 5], LEN;
void FFT(vi &a, int len, int type) {
	int lg = 31 - __builtin_clz(len);
	for (int i = 0; i < len; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << lg - 1);
	for (int i = 0; i < len; i++) if (rev[i] < i) swap(a[rev[i]], a[i]);
	static int W[MAXP + 5];
	for (int i = 0; i < len; i++) W[i] = 0; W[0] = 1;
	for (int i = 2; i <= len; i <<= 1) {
		int wW = qpow((type < 0) ? ipr : pr, (MOD - 1) / i);
		for (int j = (i >> 1) - 1; ~j; j--) W[j] = (j & 1) ? (1ll * W[j >> 1] * wW % MOD) : W[j >> 1];
		for (int j = 0; j < len; j += i) {
			for (int k = 0; k < (i >> 1); k++) {
				int X = a[j + k], Y = 1ll * W[k] * a[(i >> 1) + j + k] % MOD;
				a[j + k] = (X + Y) % MOD; a[(i >> 1) + j + k] = (X - Y + MOD) % MOD;
			}
		}
	}
	if (type < 0) {
		int ivn = qpow(len, MOD - 2);
		for (int i = 0; i < len; i++) a[i] = 1ll * a[i] * ivn % MOD;
	}
}
vi conv(vi a, vi b) {
	int LEN = 1; while (LEN < a.size() + b.size()) LEN <<= 1;
	a.resize(LEN, 0); b.resize(LEN, 0); FFT(a, LEN, 1); FFT(b, LEN, 1);
	for (int i = 0; i < LEN; i++) a[i] = 1ll * a[i] * b[i] % MOD;
	FFT(a, LEN, -1); return a;
}
vi getinv(vi a, int len) {
	vi b(len, 0); b[0] = qpow(a[0], MOD - 2);
	for (int i = 2; i <= len; i <<= 1) {
		vi c(b.begin(), b.begin() + (i >> 1));
		vi d(a.begin(), a.begin() + i);
		c = conv(c, c); d = conv(c, d);
		for (int j = 0; j < i; j++) b[j] = (2 * b[j] % MOD - d[j] + MOD) % MOD;
	}
	return b;
}
pair<vi, pii> solve(int x) {
	if (x == 1) {
		vector<int> F(n + 1);
		for (int i = 0; i <= n; i++) F[i] = 1;
		return mp(F, mp(1, 0));
		// se.fi: num of seqs with at least one adjacent numbers < floor(x/2)
		// se.se: num of seqs with no one adjacent numbers < floor(x/2)
	}
	auto T = solve(x >> 1);
	vi _F = T.fi, F(n + 1), odd(LEN), even(n + 1);
	_F[1] = x + 1 >> 1; odd[0] = 1;
	for (int j = 0; j <= n; j++) if (j & 1) odd[j] = (MOD - _F[j]) % MOD;
	vector<int> H = getinv(odd, LEN);
	for (int j = 0; j <= n; j++) if (~j & 1) even[j] = _F[j];
	vector<int> mul = conv(conv(even, even), H);
	for (int j = 0; j <= n; j++) F[j] = (mul[j] + ((j & 1) ? _F[j] : 0)) % MOD;
	int ss1 = 0, ss2 = 2ll * (T.se.fi + T.se.se) % MOD;
	for (int j = 1; j <= n; j++) if (j & 1) ss1 = (ss1 + 1ll * _F[j] * j % MOD * H[n - j]) % MOD;
	return mp(F, mp(ss1, ss2));
}
int main() {
	scanf("%d%d", &n, &m); LEN = 1; while (LEN <= n + n) LEN <<= 1;
	auto T = solve(m); printf("%d\n", (T.se.fi + (~n & 1) * T.se.se) % MOD);
	return 0;
}