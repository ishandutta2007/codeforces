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
template <typename T1,typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1,typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio {
	#define FILE_SIZE 1<<23
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
const int MAXN = 1e6;
const int LOG_N = 20;
const int MOD = 1e9 + 7;
int n, dp[MAXN + 5][LOG_N + 2][2];
int main() {
	scanf("%d", &n);
	if (n == 1) return puts("1"), 0;
	if (n == 2) return puts("1"), 0;
	int k = 1; for (; (1 << k) <= n; k++); k--;
	int kk = 1; for (; (1 << kk) <= n / 3; kk++); kk--;
	int res = 0;
	if (k == max(k, kk + 1)) {
		dp[1][k][0] = 1;
		for (int i = 1; i < n; i++) for (int j = 0; j <= k; j++)
			if (dp[i][j][0]) {
				dp[i + 1][j][0] = (dp[i + 1][j][0] + 1ll * dp[i][j][0] * ((n >> j) - i)) % MOD;
				if (j) dp[i + 1][j - 1][0] = (dp[i + 1][j - 1][0] + 1ll * dp[i][j][0] * ((n >> (j - 1)) - (n >> j))) % MOD;
			}
		res = (res + dp[n][0][0]) % MOD;
	} if (kk + 1 == max(k, kk + 1)) {
		memset(dp, 0, sizeof(dp)); dp[1][kk][1] = 1;
		for (int i = 1; i < n; i++) for (int j = 0; j <= kk; j++)
			for (int l = 0; l < 2; l++) if (dp[i][j][l]) {
				int cnt = (n >> j) / ((l) ? 3 : 1);
				dp[i + 1][j][l] = (dp[i + 1][j][l] + 1ll * dp[i][j][l] * (cnt - i)) % MOD;
				if (l) dp[i + 1][j][0] = (dp[i + 1][j][0] + 1ll * dp[i][j][l] * ((n >> j) - cnt)) % MOD;
				if (j) dp[i + 1][j - 1][l] = (dp[i + 1][j - 1][l] + 1ll * dp[i][j][l] * ((n >> (j - 1)) / ((l) ? 3 : 1) - cnt)) % MOD;
			}
		res = (res + dp[n][0][0]) % MOD;
	}
	printf("%d\n", res);
	return 0;
}