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
const int MAXN = 3600;
const int MOD = 998244353;
int n, m, k; bool visx[MAXN + 5], visy[MAXN + 5];
int dpx[MAXN + 5][MAXN + 5], dpy[MAXN + 5][MAXN + 5], dp[MAXN + 5][MAXN + 5];
int wayx[MAXN + 5][MAXN + 5], wayy[MAXN + 5][MAXN + 5];
int lenx[MAXN + 5], cx, leny[MAXN + 5], cy;
int fac[MAXN + 5], ifac[MAXN + 5];
void init_fac(int n) {
	for (int i = (fac[0] = ifac[0] = ifac[1] = 1) + 1; i <= n; i++)
		ifac[i] = 1ll * ifac[MOD % i] * (MOD - MOD / i) % MOD;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % MOD;
		ifac[i] = 1ll * ifac[i - 1] * ifac[i] % MOD;
	}
}
int binom(int n, int k) {return 1ll * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;}
int main() {
	scanf("%d%d%d", &n, &m, &k); init_fac(MAXN);
	for (int i = 1, x1, y1, x2, y2; i <= k; i++) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		visx[x1] = visx[x2] = visy[y1] = visy[y2] = 1;
	}
	visx[0] = visx[n + 1] = visy[0] = visy[m + 1] = 1;
	int pre = 0, totx = 0, toty = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (visx[i]) {
			if (pre != i - 1) lenx[++cx] = i - pre - 1;
			pre = i;
		} else totx++;
	}
	pre = 0;
	for (int i = 1; i <= m + 1; i++) {
		if (visy[i]) {
			if (pre != i - 1) leny[++cy] = i - pre - 1;
			pre = i;
		} else toty++;
	}
//	printf("%d %d\n", cx, cy);
	dpx[0][0] = dpy[0][0] = dp[0][0] = 1;
	for (int i = 1; i <= MAXN; i++) for (int j = 0; j * 2 <= i; j++)
		dp[i][j] = (dp[i - 1][j] + ((i >= 2 && j >= 1) ? dp[i - 2][j - 1] : 0)) % MOD;
	for (int i = 1; i <= cx; i++) for (int j = 0; j <= n; j++) {
		for (int k = 0; k * 2 <= lenx[i] && k <= j; k++)
			dpx[i][j] = (dpx[i][j] + 1ll * dp[lenx[i]][k] * dpx[i - 1][j - k]) % MOD;
	}
	for (int i = 1; i <= cy; i++) for (int j = 0; j <= m; j++) {
		for (int k = 0; k * 2 <= leny[i] && k <= j; k++)
			dpy[i][j] = (dpy[i][j] + 1ll * dp[leny[i]][k] * dpy[i - 1][j - k]) % MOD;
	}
	for (int i = 0; i <= n; i++) for (int j = 0; j <= totx - i * 2; j++)
		wayx[i][j] = 1ll * dpx[cx][i] * binom(totx - i * 2, j) % MOD;
	for (int i = 0; i <= m; i++) for (int j = 0; j <= toty - i * 2; j++)
		wayy[i][j] = 1ll * dpy[cy][i] * binom(toty - i * 2, j) % MOD;
	int res = 0;
	for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++)
		res = (res + 1ll * wayx[i][j] * wayy[j][i] % MOD * fac[i] % MOD * fac[j]) % MOD;
	printf("%d\n", res);
	return 0;
}