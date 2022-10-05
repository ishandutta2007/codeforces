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
const int MAXN = 20000;
const int LOG_N = 15;
const int MAXK = 30;
const int INF = 0x3f3f3f3f;
int n, qu, a[MAXN + 5], to[LOG_N + 2][MAXK + 3][MAXN + 5];
int st[MAXK + 3][LOG_N + 2][MAXN + 5], lg[32769];
int res[MAXN + 5], l[MAXN + 5], r[MAXN + 5], k[MAXN + 5];
void build(int x, int y) {
	for (int i = 1; i <= n + 1; i++) st[y][0][i] = to[x][y][i];
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j + (1 << i) - 1 <= n + 1; j++)
		st[y][i][j] = max(st[y][i - 1][j], st[y][i - 1][j + (1 << i - 1)]);
}
int query(int y, int l, int r) {
	int k = lg[r - l + 1];
	return max(st[y][k][l], st[y][k][r - (1 << k) + 1]);
}
int dp[MAXN + 5][MAXK + 5];
int main() {
	scanf("%d%d", &n, &qu);
	for (int i = 1; i <= 15; i++) lg[1 << i] = 1;
	for (int i = 1; i <= 32768; i++) lg[i] += lg[i - 1];
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]); a[n + 1] = 1;
	for (int i = 1; i <= n + 1; i++) for (int j = 0; j <= MAXK; j++)
		to[0][j][i] = min(a[i] + j + i, n + 1);
	for (int i = 0; i <= MAXK; i++) build(0, i);
	for (int i = 1; i <= LOG_N; i++) {
		for (int j = 1; j <= n + 1; j++) for (int k1 = 0; k1 <= MAXK; k1++) for (int k2 = 0; k2 + k1 <= MAXK; k2++)
			chkmax(to[i][k1 + k2][j], query(k2, j, to[i - 1][k1][j]));
		for (int j = 0; j <= MAXK; j++) build(i, j);
	}
	for (int i = 1; i <= qu; i++) {
		scanf("%d%d%d", &l[i], &r[i], &k[i]);
		for (int j = 0; j <= k[i]; j++) dp[i][j] = l[i];
	}
	for (int i = LOG_N; ~i; i--) {
		for (int j = 0; j <= MAXK; j++) build(i, j);
		for (int id = 1; id <= qu; id++) if (l[id] != r[id]) {
			static int ndp[MAXK + 5]; memset(ndp, 0, sizeof(ndp));
			for (int k1 = 0; k1 <= k[id]; k1++) for (int k2 = 0; k2 + k1 <= k[id]; k2++) {
				int mx = query(k2, l[id], dp[id][k1]);
				chkmax(ndp[k1 + k2], mx);
			}
			if (ndp[k[id]] < r[id]) {
				res[id] |= (1 << i);
				for (int j = 0; j <= k[id]; j++) dp[id][j] = ndp[j];
			}
		}
	}
	for (int i = 1; i <= qu; i++) {
		if (l[i] == r[i]) puts("0");
		else printf("%d\n", res[i] + 1);
	}
	return 0;
}