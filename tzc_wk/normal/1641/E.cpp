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
const int MAXP = 1048576;
const int pr = 3;
const int ipr = 332748118;
const int MOD = 998244353;
const int INV2 = 499122177;
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int n, m, a[MAXN + 5], c[MAXP + 5], sum[MAXP + 5], p[MAXN + 5];
int rev[MAXP + 5];
void NTT(vector<int> &a, int len, int type) {
	int lg = 31 - __builtin_clz(len);
	for (int i = 0; i < len; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << lg - 1);
	for (int i = 0; i < len; i++) if (rev[i] < i) swap(a[i], a[rev[i]]);
	for (int i = 2; i <= len; i <<= 1) {
		int W = qpow((type < 0) ? ipr : pr, (MOD - 1) / i);
		for (int j = 0; j < len; j += i) {
			for (int k = 0, w = 1; k < (i >> 1); k++, w = 1ll * w * W % MOD) {
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
	int LEN = 1, nd = a.size() + b.size() - 1; while (LEN < a.size() + b.size()) LEN <<= 1;
	a.resize(LEN, 0); b.resize(LEN, 0); NTT(a, LEN, 1); NTT(b, LEN, 1);
	for (int i = 0; i < LEN; i++) a[i] = 1ll * a[i] * b[i] % MOD;
	NTT(a, LEN, -1); while (a.size() > nd) a.ppb();
	return a;
}
int A[MAXN * 2 + 5], B[MAXN * 2 + 5], C[MAXP + 5];
void solve(int l, int r, int *x, int *y, int *z) {
	if (l == r) return; int mid = l + r >> 1;
	solve(l, mid, x, y, z); solve(mid + 1, r, x, y, z);
	vector<int> vec1, vec2;
	for (int i = l; i <= mid; i++) vec1.pb(x[i]);
	for (int i = mid + 1; i <= r; i++) vec2.pb(y[i]);
	vector<int> prd = conv(vec1, vec2);
	for (int i = 0; i < prd.size(); i++) z[l + mid + 1 + i] = (z[l + mid + 1 + i] + prd[i]) % MOD;
}
void clcprd(int *x, int *y, int *z) {
	// z[i] = sum {a + b = i, a < b} x[a] * y[b]
	memset(z, 0, sizeof(C));
	solve(1, n * 2, x, y, z);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1, x; i <= m; i++) scanf("%d", &x), c[x] = 1;
	for (int i = 1; i <= (n << 1); i++) sum[i] = sum[i - 1] + c[i];
	for (int i = 1; i <= n; i++) A[i] = 1ll * c[i] * qpow(2, sum[i]) % MOD * INV2 % MOD;
	for (int i = 1; i <= n << 1; i++) B[i] = qpow(INV2, sum[i - 1]);
	clcprd(A, B, C);
	for (int i = 1; i <= n; i++) p[i] = (p[i] + 1ll * C[i * 2] * i) % MOD;
	// left i
	for (int i = 1; i <= n; i++) A[i] = 1ll * A[i] * i % MOD;
	clcprd(A, B, C);
	for (int i = 1; i <= n; i++) p[i] = (p[i] - C[i * 2] + MOD) % MOD;
	// left -j
	memset(A, 0, sizeof(A)); memset(B, 0, sizeof(B));
	for (int i = 1; i <= n; i++) A[i + n] = 1ll * INV2 * c[i] % MOD * qpow(INV2, sum[i - 1]) % MOD;
	for (int i = 1; i <= n; i++) B[i] = 1;
	for (int i = n + 1; i <= n << 1; i++) B[i] = qpow(2, sum[i - n - 1]);
	clcprd(B, A, C);
	for (int i = 1; i <= n; i++) p[i] = (p[i] - 1ll * i * C[i * 2 + n * 2] % MOD + MOD) % MOD;
	// right -i
	for (int i = 1; i <= n; i++) A[i + n] = 1ll * A[i + n] * i % MOD;
	clcprd(B, A, C);
	for (int i = 1; i <= n; i++) p[i] = (p[i] + C[i * 2 + n * 2]) % MOD;
	// right j
	int ss = 0;
	for (int i = 1; i <= n; i++) ss = (ss + 1ll * p[i] * a[i]) % MOD;
	printf("%d\n", 1ll * ss * qpow(2, m) % MOD * qpow(qpow(2, m) - 1, MOD - 2) % MOD);
	return 0;
}