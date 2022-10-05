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
const int MAXN = 60;
const int MAXP = 32768;
const int MOD = 1e9 + 7;
int n, a[MAXN + 5], f[MAXN + 5], deg[MAXN + 5];
int res = 1, prd = 1, sumc = 0;
int fac[MAXN + 5], ifac[MAXN + 5];
void init_fac(int n) {
	for (int i = (fac[0] = ifac[0] = ifac[1] = 1) + 1; i <= n; i++)
		ifac[i] = 1ll * ifac[MOD % i] * (MOD - MOD / i) % MOD;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % MOD;
		ifac[i] = 1ll * ifac[i - 1] * ifac[i] % MOD;
	}
}
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
void merge(int x, int y) {x = find(x); y = find(y); if (x != y) f[x] = y;}
vector<int> pts[MAXN + 5];
int st[MAXN + 5], sum[MAXP + 5], dp[MAXP + 5][MAXN + 5];
int calc(vector<int> vec) {
	vector<int> S;
	for (int x : vec) if (!deg[x]) S.pb(x);
	memset(st, 0, sizeof(st)); memset(sum, 0, sizeof(sum));
	int tot = -1;
	for (int x : vec) if (deg[x]) {
		tot++;
		for (int y = 0; y < S.size(); y++) {
			if (a[x] % a[S[y]] == 0) st[x] |= (1 << y);
		}
	}
	if (tot == -1) return 1;
	prd = 1ll * prd * ifac[tot] % MOD; sumc += tot;
	for (int x : vec) if (deg[x]) sum[st[x]]++;
	for (int i = 0; i < S.size(); i++) for (int j = 0; j < (1 << S.size()); j++)
		if (j >> i & 1) sum[j] += sum[j ^ (1 << i)];
	memset(dp, 0, sizeof(dp)); dp[0][0] = 1;
	for (int i = 0; i < (1 << S.size()); i++) for (int j = 0; j <= tot + 1; j++)
		if (dp[i][j]) {
			dp[i][j + 1] = (dp[i][j + 1] + 1ll * dp[i][j] * (sum[i] - j)) % MOD;
			for (int k : vec) if (deg[k] && ((st[k] & i) != st[k]) && ((st[k] & i) || (i == 0)))
				dp[i | st[k]][j + 1] = (dp[i | st[k]][j + 1] + dp[i][j]) % MOD;
		}
	return dp[(1 << S.size()) - 1][tot + 1];
}
int main() {
	scanf("%d", &n); init_fac(MAXN);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		if (i != j && a[j] % a[i] == 0) {deg[j]++; merge(i, j);}
	for (int i = 1; i <= n; i++) pts[find(i)].pb(i);
	for (int i = 1; i <= n; i++) if (!pts[i].empty()) res = 1ll * res * calc(pts[i]) % MOD;
	printf("%d\n", 1ll * res * prd % MOD * fac[sumc] % MOD);
	return 0;
}