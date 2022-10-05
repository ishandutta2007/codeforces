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
const int MAXN = 21;
const int MAXP = 2097152;
const int MOD = 31607;
const int INV2 = 15804;
void add(int &x, int y) {((x += y) >= MOD) && (x -= MOD);}
void sub(int &x, int y) {((x -= y) < 0) && (x += MOD);}
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int n, a[MAXN + 5][MAXN + 5], iv[MAXN + 5][MAXN + 5];
int iv10000 = qpow(10000, MOD - 2), P[2][2][MAXP + 5], dp[2][2][MAXP + 5];
void FWTand(int *a, int len, int type) {
	for (int i = 2; i <= len; i <<= 1) {
		for (int j = 0; j < len; j += i) {
			for (int k = 0; k < (i >> 1); k++) {
				if (type == 1) add(a[j + k], a[(i >> 1) + j + k]);
				else sub(a[j + k], a[(i >> 1) + j + k]);
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		scanf("%d", &a[i][j]), a[i][j] = 1ll * iv10000 * a[i][j] % MOD;
		iv[i][j] = 1ll * a[i][j] * qpow((1 - a[i][j] + MOD) % MOD, MOD - 2) % MOD;
	}
	dp[1][1][(1 << n) - 1] = 1;
	FWTand(dp[1][1], 1 << n, 1);
	for (int i = 1; i <= n; i++) {
		memset(P, 0, sizeof(P)); P[0][0][0] = 1;
		for (int j = 1; j <= n; j++)
			P[0][0][0] = 1ll * P[0][0][0] * (1 - a[j][i] + MOD) % MOD;
		for (int j = 1; j < (1 << n) - 1; j++) {
			int lwb = j & (-j), k = 32 - __builtin_clz(lwb);
			int nw = j ^ lwb;
			P[j >> (i - 1) & 1][j >> (n - i) & 1][j] = 1ll *
			P[nw >> (i - 1) & 1][nw >> (n - i) & 1][nw] * iv[k][i] % MOD;
		}
		for (int x = 0; x < 2; x++) for (int y = 0; y < 2; y++)
			FWTand(P[x][y], 1 << n, 1);
		static int tmp[2][2][MAXP + 5];
		memset(tmp, 0, sizeof(tmp));
		for (int x = 0; x < 2; x++) for (int y = 0; y < 2; y++)
			for (int j = 0; j < (1 << n); j++) if (dp[x][y][j])
				for (int p = 0; p < 2; p++) for (int q = 0; q < 2; q++)
					tmp[x & p][y & q][j] = (tmp[x & p][y & q][j] + 1ll * dp[x][y][j] * P[p][q][j]) % MOD;
		memcpy(dp, tmp, sizeof(tmp));
	}
	FWTand(dp[0][0], 1 << n, MOD - 1);
	printf("%d\n", (1 - dp[0][0][0] + MOD) % MOD);
	return 0;
}
/*
21
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/