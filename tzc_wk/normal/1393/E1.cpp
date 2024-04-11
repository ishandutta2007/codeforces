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
const int MAXN = 1e5;
const int MAXL = 1e6 + 5;
const u64 BS = 131;
const int MOD = 1e9 + 7;
int n, len[MAXN + 5]; string s[MAXN + 5];
vector<u64> hs[MAXN + 5];
vector<pii> itvl[MAXN + 5];
vector<int> ord[MAXN + 5];
vector<int> dp[MAXN + 5], sum[MAXN + 5];
u64 pw[MAXL + 5];
u64 gethash(int x, int l, int r) {return hs[x][r] - hs[x][l - 1] * pw[r - l + 1];}
int getcmp_str(int x, int y, int l1, int r1, int l2, int r2) {
	if (l1 > r1 || l2 > r2) return -1;
	int L = 1, R = r1 - l1 + 1, p = 0;
	while (L <= R) {
		int mid = L + R >> 1;
		if (gethash(x, l1, l1 + mid - 1) == gethash(y, l2, l2 + mid - 1))
			p = mid, L = mid + 1;
		else R = mid - 1;
	}
	return (p == r1 - l1 + 1) ? -1 : (s[x][l1 + p] > s[y][l2 + p]);
}
int getcmp(int x, int y, int p, int q) {
	int st = getcmp_str(x, y, 1, min(p, q) - 1, 1, min(p, q) - 1);
	if (~st) return st; st = -1;
	if (max(p, q) > min(len[x], len[y])) {
		int st = (len[x] < len[y]) ? getcmp_str(x, y, p + 1, len[x], p, len[x] - 1) :
		getcmp_str(x, y, q, len[y] - 1, q + 1, len[y]);
		if (~st) return st;
	} else {
		if (p > q) st = getcmp_str(x, y, q, p - 1, q + 1, p);
		if (p < q) st = getcmp_str(x, y, p + 1, q, p, q - 1);
		if (~st) return st; st = getcmp_str(x, y, max(p, q) + 1, min(len[x], len[y]), max(p, q) + 1, min(len[x], len[y]));
		if (~st) return st;
	}
	if (len[x] < len[y]) return 0;
	if (len[x] == len[y] || (len[x] == len[y] + 1 && p != len[x] && q == len[y])) return -1;
	return 1;
}
int main() {
	scanf("%d", &n);
	for (int i = (pw[0] = 1); i <= MAXL; i++) pw[i] = pw[i - 1] * BS;
	for (int i = 1; i <= n; i++) cin >> s[i], s[i].pb(' '), len[i] = s[i].size(), s[i] = " " + s[i] + " ";
	for (int i = 1; i <= n; i++) {
		hs[i].resize(s[i].size()); itvl[i].resize(s[i].size());
		for (int j = 1; j <= len[i]; j++)
			hs[i][j] = hs[i][j - 1] * BS + s[i][j];
		for (int l = 1, r; l <= len[i]; l = r) {
			r = l; while (r <= len[i] && s[i][r] == s[i][l]) ++r;
			for (int j = l; j < r; j++) itvl[i][j] = mp(l, r - 1);
		}
		for (int j = 1; j <= len[i]; j++) ord[i].pb(j);
		stable_sort(ord[i].begin(), ord[i].end(), [&](int x, int y) {
			return (itvl[i][x] == itvl[i][y]) ? (x < y) :
			((x < y) ? (s[i][x] > s[i][itvl[i][x].se + 1]) : (s[i][y] < s[i][itvl[i][y].se + 1]));
		});
		dp[i].resize(s[i].size()); sum[i].resize(s[i].size());
		ord[i].insert(ord[i].begin(), 0);
//		for (int x : ord[i]) printf("%d ", x); printf("\n");
//		printf("%d\n", (int)s[i].size());
	}
	for (int i = 1; i <= len[1]; i++) dp[1][i] = 1, sum[1][i] = i;
	for (int i = 2; i <= n; i++) {
		for (int j = 1, k = 1; j <= len[i]; j++) {
			while (k <= len[i - 1] && getcmp(i - 1, i, ord[i - 1][k], ord[i][j]) != 1) ++k;
			dp[i][j] = sum[i - 1][k - 1];
		}
		for (int j = 1; j <= len[i]; j++) sum[i][j] = (sum[i][j - 1] + dp[i][j]) % MOD;
	}
	printf("%d\n", sum[n][len[n]]);
	return 0;
}
/*
2
abb
bb
*/