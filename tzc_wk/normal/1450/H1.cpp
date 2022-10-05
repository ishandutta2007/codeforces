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
const int MAXN = 4e5;
const int MOD = 998244353;
const int INV2 = MOD + 1 >> 1;
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int n, fac[MAXN + 5], ifac[MAXN + 5]; char s[MAXN + 5];
void init_fac(int n) {
	for (int i = (fac[0] = ifac[0] = ifac[1] = 1) + 1; i <= n; i++)
		ifac[i] = 1ll * ifac[MOD % i] * (MOD - MOD / i) % MOD;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % MOD;
		ifac[i] = 1ll * ifac[i - 1] * ifac[i] % MOD;
	}
}
int binom(int n, int k) {
	if (n < k || n < 0 || k < 0) return 0;
	return 1ll * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}
int main() {
	scanf("%d%*d%s", &n, s + 1); init_fac(MAXN);
	int ca = 0, cb = 0, cc = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'b') {
			if (i & 1) ca++;
			else ca--;
		} else if (s[i] == '?') {
			if (i & 1) cb++;
			else cc++;
		}
	}
	int x = cc - ca, cnt = cb + cc, res = 0;
	if (cnt <= 1) {
		for (int i = 0; i <= cnt; i++) if ((x - i) % 2 == 0)
			res = (res + 1ll * abs(x - i) * binom(cnt, i)) % MOD;
	} else {
		for (int i = 0; i <= x; i++) res = (res + 2ll * (x + MOD) * binom(cnt - 1, i)) % MOD;
		for (int i = 0; i < x; i++) res = (res - 2ll * cnt * binom(cnt - 2, i) % MOD + MOD) % MOD;
		for (int i = 0; i < cnt; i++) res = (res + 1ll * cnt * binom(cnt - 2, i)) % MOD;
		for (int i = 0; i < cnt; i++) res = (res - 1ll * (x + MOD) * binom(cnt - 1, i) % MOD + MOD) % MOD;
	}
	printf("%d\n", 1ll * res * qpow(INV2, cb + cc) % MOD);
	return 0;
}