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
		x = 0; char c = getchar(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getchar();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
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
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 5e5;
const int DLT = 1e6 + 3;
const int MOD = 1e9 + 7;
const int INV2 = 5e8 + 4;
int n, c[MAXN + 5], d[DLT * 2 + 5], fac[MAXN + 5];
int getsum(int l, int r) {
	return 1ll * (0ll + l + r) * (r - l + 1) % MOD * INV2 % MOD;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		d[-c[i] + 1 + DLT]++;
		d[c[i] + 1 + DLT]--;
	}
	int sum = 0, res = 1, ss = 0;
	for (int i = (fac[0] = 1); i <= MAXN; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
	for (int i = -1e6; i <= 1e6; i++) d[i + DLT] += d[i - 2 + DLT];
	for (int i = -1e6; i <= 1e6; i++) {
		res = 1ll * res * fac[d[i + DLT]] % MOD;
		ss = (ss + 1ll * (i + MOD) * getsum(sum + 1, sum + d[i + DLT])) % MOD;
		sum = (sum + d[i + DLT]) % MOD;
	}
	printf("%d %d\n", ss, res);
	return 0;
}