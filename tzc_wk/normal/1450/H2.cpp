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
int n, qu, fac[MAXN + 5], ifac[MAXN + 5];
char s[MAXN + 5]; int coef[MAXN + 5];
void init_fac(int n) {
	for (int i = (fac[0] = ifac[0] = ifac[1] = 1) + 1; i <= n; i++)
		ifac[i] = 1ll * ifac[MOD % i] * (MOD - MOD / i) % MOD;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % MOD;
		ifac[i] = 1ll * ifac[i - 1] * ifac[i] % MOD;
	}
}
int binom(int n, int k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return 1ll * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}
struct solver {
	int x, cnt, sum;
	void rework() {
		sum = 0;
		for (int i = 0; i <= min(x, cnt); i++) sum = (sum + binom(cnt, i)) % MOD;
	}
	solver(int _x, int _cnt) {x = _x; cnt = _cnt; rework();}
	void incx() {
		x++; sum = (sum + binom(cnt, x)) % MOD;
		if (min(x, cnt) <= 3) rework();
	}
	void decx() {
		sum = (sum - binom(cnt, x) + MOD) % MOD; x--;
		if (min(x, cnt) <= 3) rework();
	}
	void inccnt() {
		sum = (2ll * sum % MOD - binom(cnt, x) + MOD) % MOD; cnt++;
		if (min(x, cnt) <= 3) rework();
	}
	void deccnt() {
		--cnt; sum = 1ll * INV2 * (sum + binom(cnt, x)) % MOD;
		if (min(x, cnt) <= 3) rework();
	}
} A(0, -1), B(-1, -2), C(-1, -2), D(-1, -1);
int x = 0, cnt = 0;
void incx() {A.incx(); B.incx(); x++;}
void decx() {A.decx(); B.decx(); x--;}
void inccnt() {A.inccnt(); B.inccnt(); C.inccnt(); C.incx(); D.inccnt(); D.incx(); cnt++;}
void deccnt() {A.deccnt(); B.deccnt(); C.decx(); C.deccnt(); D.decx(); D.deccnt(); cnt--;}
void inc_cc() {incx(); inccnt();}
void dec_cc() {deccnt(); decx();}
void inc_cb() {inccnt();}
void dec_cb() {deccnt();}
void inc_ca() {decx();}
void dec_ca() {incx();}
int getans() {
//	printf("%d %d %d %d %d %d\n", x, cnt, A.sum, B.sum, C.sum, D.sum);
//	printf("%d %d %d\n", A.x, A.cnt, A.sum);
//	printf("%d %d %d\n", B.x, B.cnt, B.sum);
//	printf("%d %d %d\n", C.x, C.cnt, C.sum);
//	printf("%d %d %d\n", D.x, D.cnt, D.sum);
	if (cnt <= 1) {
		int res = 0;
		for (int i = 0; i <= cnt; i++) if ((i - x) % 2 == 0)
			res = (res + 1ll * abs(i - x) * binom(cnt, i)) % MOD;
		return res;
	}
	int res = 0;
	res = (res + 2ll * (x + MOD) * A.sum) % MOD;
	res = (res - 2ll * cnt * B.sum % MOD + MOD) % MOD;
	res = (res + 1ll * cnt * C.sum % MOD) % MOD;
	res = (res - 1ll * (x + MOD) * D.sum % MOD + MOD) % MOD;
	return res;
}
int main() {
	init_fac(MAXN);
	scanf("%d%d%s", &n, &qu, s + 1); 
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'b') {
			if (i & 1) inc_ca();
			else dec_ca();
		} else if (s[i] == '?') {
			if (i & 1) inc_cb();
			else inc_cc();
		}
	}
	printf("%d\n", 1ll * getans() * qpow(INV2, cnt) % MOD);
	while (qu--) {
		int x; char c; scanf("%d %c", &x, &c);
		if (s[x] == 'b') {
			if (x & 1) dec_ca();
			else inc_ca();
		} else if (s[x] == '?') {
			if (x & 1) dec_cb();
			else dec_cc();
		}
		s[x] = c;
		if (s[x] == 'b') {
			if (x & 1) inc_ca();
			else dec_ca();
		} else if (s[x] == '?') {
			if (x & 1) inc_cb();
			else inc_cc();
		}
		printf("%d\n", 1ll * getans() * qpow(INV2, cnt) % MOD);
	}
	return 0;
}
/*
10 0
?w????wb??
*/