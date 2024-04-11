#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
const int MOD = 1e9 + 7;
const int INV2 = MOD + 1 >> 1;
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
struct line {
	int k, b;
	line() {k = b = 0;}
	line(int _k, int _b): k(_k), b(_b) {}
	int at(int x) {return (1ll * x * k + b) % MOD;}
	line operator + (const line &rhs) {return line((k + rhs.k) % MOD, (b + rhs.b) % MOD);}
	line operator - (const line &rhs) {return line((k - rhs.k + MOD) % MOD, (b - rhs.b + MOD) % MOD);}
	void print() {printf("y = %dx + %d\n", k, b);}
};
line merge(line F, line G) {//G(F(x))
	return line(1ll * F.k * G.k % MOD, (1ll * G.k * F.b + G.b) % MOD);
}
line getinv(line F) {
	int iv = qpow(F.k, MOD - 2);
	return line(iv, (MOD - 1ll * iv * F.b % MOD) % MOD);
}
line qpow_l(line x, int e) {
	line res = line(1, 0);
	for (; e; e >>= 1, x = merge(x, x)) if (e & 1) res = merge(res, x);
	return res;
}
line getsum(line x, int e) {
	if (!e) return line(0, 0);
	if (x.k == 1) return line(e, 1ll * e * (e + 1) / 2 % MOD * x.b % MOD);
	line pw = qpow_l(x, e + 1) - x;
	line res; res.k = 1ll * pw.k * qpow(x.k - 1, MOD - 2) % MOD;
	res.b = 1ll * x.b * (res.k - e + MOD) % MOD * qpow(x.k - 1, MOD - 2) % MOD;
	return res;
}
int solve(int n, int k, line A, line B, line F1, line F2) {
	if (!k) {
		int E1 = 1ll * A.b * qpow((1 - A.k + MOD) % MOD, MOD - 2) % MOD;
//		printf("%d %d\n", E1, F2.at(E1));
		return F2.at(E1);
	}
	line f1 = F1 + merge(getsum(A, n / k), F2);
	line f2 = F1 + merge(getsum(A, n / k - 1), F2);
//	printf("%d %d %d %d\n", f1.k, f1.b, f2.k, f2.b);
	line a = merge(getinv(B), qpow_l(getinv(A), n / k - 1));
	line b = merge(getinv(B), qpow_l(getinv(A), n / k));
	return (solve(k, n % k, a, b, line(f1.k, 0), line(f2.k, 0)) + 1ll * (n % k) * f1.b + 1ll * (k - n % k) * f2.b) % MOD;
}
int main() {
//	getsum(line(3, 1), 2).print();
	int qu; scanf("%d", &qu);
	while (qu--) {
		int n, k; scanf("%d%d", &n, &k); int d = __gcd(n, k); n /= d; k /= d;
		printf("%d\n", 1ll * solve(n, k, line(1, 1), line(INV2, 1), line(1, 0), line(1, 0)) * qpow(n, MOD - 2) % MOD);
	}
	return 0;
}