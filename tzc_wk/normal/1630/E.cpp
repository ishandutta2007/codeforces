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
const int MAXN = 1e6;
const int MOD = 998244353;
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int n, fac[MAXN + 5], ifac[MAXN + 5], inv[MAXN + 5];
int a[MAXN + 5], cnt[MAXN + 5], num[MAXN + 5], sum[MAXN + 5];
void init_fac(int n) {
	for (int i = (fac[0] = ifac[0] = inv[0] = inv[1] = 1) + 1; i <= n; i++)
		inv[i] = 1ll * inv[MOD % i] * (MOD - MOD / i) % MOD;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % MOD;
		ifac[i] = 1ll * ifac[i - 1] * inv[i] % MOD;
	}
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) cnt[i] = num[i] = sum[i] = 0;
	bool flg = 1;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt[a[i]]++, flg &= (a[i] == a[1]);
	if (flg) {puts("1"); return;}
	int d = 0; vector<int> fd;
	for (int i = 1; i <= n; i++) d = __gcd(cnt[i], d);
	for (int i = 1; i <= d; i++) if (d % i == 0) fd.pb(i);
	for (int x : fd) {
		int prd = fac[n / x];
		for (int i = 1; i <= n; i++) prd = 1ll * prd * ifac[cnt[i] / x] % MOD;
		num[x] = prd;
		for (int i = 1; i <= n; i++) if (cnt[i] / x >= 2)
			sum[x] = (sum[x] + 1ll * (n / x) * prd % MOD * ifac[n / x] % MOD * fac[n / x - 2] % MOD
			* fac[cnt[i] / x] % MOD * ifac[cnt[i] / x - 2]) % MOD;
		sum[x] = 1ll * sum[x] * x % MOD;
//		printf("! %d %d %d\n", x, num[x], sum[x]);
	}
	for (int i = (int)(fd.size()) - 1; ~i; i--) {
		for (int j = i + 1; j < fd.size(); j++) if (fd[j] % fd[i] == 0) {
			num[fd[i]] = (num[fd[i]] - num[fd[j]] + MOD) % MOD;
			sum[fd[i]] = (sum[fd[i]] - sum[fd[j]] + MOD) % MOD;
		}
	}
	int ss = 0, tot = 0;
	for (int i = 1; i <= n; i++) {
		ss = (ss + 1ll * sum[i] * inv[n / i]) % MOD;
		tot = (tot + 1ll * num[i] * inv[n / i]) % MOD;
	}
	printf("%d\n", (n - 1ll * ss * qpow(tot, MOD - 2) % MOD + MOD) % MOD);
}
int main() {
	init_fac(MAXN);
	int qu; scanf("%d", &qu); while (qu--) solve();
	return 0;
}