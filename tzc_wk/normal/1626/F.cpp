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
const int MAXN = 1e7;
const int MAXK = 17;
const int MAXV = 720720;
const int MOD = 998244353;
int n, a[MAXN + 5], x, y, k, mod, res = 0, pwn[MAXK + 3];
int dp[MAXK + 3][MAXV + 5];
void add(int &x, int y) {((x += y) >= MOD) && (x -= MOD);}
int main() {
	scanf("%d%d%d%d%d%d", &n, &a[0], &x, &y, &k, &mod);
	for (int i = 1; i < n; i++) a[i] = (1ll * x * a[i - 1] + y) % mod;
	for (int i = (pwn[0] = 1); i <= k; i++) pwn[i] = 1ll * pwn[i - 1] * n % MOD;
	for (int i = 0; i < n; i++) {
		int lim = a[i] / MAXV * MAXV;
		res = (res + 1ll * pwn[k - 1] * lim % MOD * k) % MOD;
		dp[0][a[i] % MAXV]++;
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < MAXV; j++) if (dp[i][j]) {
			res = (res + 1ll * j * pwn[k - i - 1] % MOD * dp[i][j]) % MOD;
			add(dp[i + 1][j], 1ll * (n - 1) * dp[i][j] % MOD);
			add(dp[i + 1][j - (j % (i + 1))], dp[i][j]);
		}
	}
	printf("%d\n", res);
	return 0;
}