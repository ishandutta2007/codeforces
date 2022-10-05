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
const int LOG_N = 17;
const int MAXN = 131072;
int n, k, a[MAXN + 5], dp[LOG_N + 2][MAXN + 5][2][2];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1, x; i <= k; i++) scanf("%d", &x), a[x - 1] = 1;
	memset(dp, 0xcf, sizeof(dp));
	for (int i = 0; i < (1 << n - 1); i++) {
		dp[1][i][a[i << 1]][a[i << 1 | 1]] = a[i << 1] | a[i << 1 | 1];
		dp[1][i][a[i << 1 | 1]][a[i << 1]] = a[i << 1] | a[i << 1 | 1];
	}
	for (int i = 2; i <= n; i++) for (int j = 0; j < (1 << n - i); j++)
		for (int k1 = 0; k1 < 2; k1++) for (int k2 = 0; k2 < 2; k2++)
			for (int k3 = 0; k3 < 2; k3++) for (int k4 = 0; k4 < 2; k4++) {
				chkmax(dp[i][j][k1 | k3][k2 | k4], dp[i - 1][j << 1][k1][k2] + dp[i - 1][j << 1 | 1][k3][k4] + (k1 | k3) + (k2 | k4) * 2);
				if (k1 | k3) chkmax(dp[i][j][k1 + k3 - 1][1], dp[i - 1][j << 1][k1][k2] + dp[i - 1][j << 1 | 1][k3][k4] + 2 + (k2 | k4));
			}
	int mx = 0;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
		chkmax(mx, dp[n][0][i][j] + (i | j));
	printf("%d\n", mx);
	return 0;
}