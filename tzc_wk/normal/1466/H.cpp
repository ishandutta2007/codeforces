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
const int MAXN = 40;
const int MAXS = 1440;
const int MOD = 1e9 + 7;
int n, p[MAXN + 5], cnt[MAXN + 5]; bool vis[MAXN + 5];
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
int way[MAXN + 5][MAXN + 5];
int idcnt = 0; vector<int> states[MAXS + 5];
vector<int> cur;
void dfs(int x) {
	if (x == n + 1) {states[++idcnt] = cur; return;}
	for (int i = 0; i <= cnt[x]; i++) {cur.pb(i); dfs(x + 1); cur.ppb();}
}
int dp[MAXS + 5];
int main() {
	scanf("%d", &n); init_fac(MAXN);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		int sz = 0, cur = i;
		while (!vis[cur]) vis[cur] = 1, sz++, cur = p[cur];
		cnt[sz]++;
	}
	for (int i = 0; i <= n; i++) {
		int sum = 0, pw = 1;
		for (int j = 0; j <= i; j++) sum = (sum + 1ll * binom(i, j) * fac[j] % MOD * fac[n - 1 - j]) % MOD;
		for (int j = 0; j <= n; j++) way[i][j] = pw, pw = 1ll * pw * sum % MOD;
	}
	cur.pb(0); dfs(1); dp[1] = 1;
	for (int i = 2; i <= idcnt; i++) {
		for (int j = 1; j <= idcnt; j++) { // j: in degree != 0
			if (i == j) continue; bool flg = 1;
			for (int k = 1; k <= n; k++) flg &= (states[j][k] <= states[i][k]);
			if (!flg) continue; int sumS = 0, sumT = 0, cntt = 0, prd = 1;
			for (int k = 1; k <= n; k++) {
				sumS += states[j][k] * k;
				sumT += (states[i][k] - states[j][k]) * k;
				cntt += states[i][k] - states[j][k];
				prd = 1ll * prd * binom(states[i][k], states[j][k]) % MOD;
			}
//			printf("%d %d %d\n", sumS, sumT, way[sumS][sumT]);
			if (~cntt & 1) dp[i] = (dp[i] - 1ll * dp[j] * way[sumS][sumT] % MOD * prd % MOD + MOD) % MOD;
			else dp[i] = (dp[i] + 1ll * dp[j] * way[sumS][sumT] % MOD * prd) % MOD;
		}
//		printf("dp[%d] = %d\n", i, dp[i]);
	}
	printf("%d\n", dp[idcnt]);
	return 0;
}