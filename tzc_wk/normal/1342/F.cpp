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
const int MAXN = 15;
const int MAXP = 1 << 15;
const int INF = 0x3f3f3f3f;
int n, a[MAXN + 5], sum[MAXP + 5], hib[MAXP + 5];
int dp[MAXP + 5][MAXN + 5][MAXN + 5], nt[MAXP + 5][MAXN + 5];
pii pv[MAXP + 5][MAXN + 5][MAXN + 5];
vector<pii> res;
bool vis[MAXN + 5];
int getind(int x) {
	int sum = 0;
	for (int i = 1; i <= x; i++) sum += (!vis[i]);
	return sum;
}
void prt(int S, int c, int k) {
	if (!S) return; int curS = pv[S][c][k].fi, ori_k = pv[S][c][k].se;
	for (int j = 1; j <= n; j++) if ((curS >> (j - 1) & 1) && j != k)
		res.pb(mp(getind(j), getind(k))), vis[j] = 1;
	prt(S ^ curS, c - 1, ori_k);
}
void solve() {
	scanf("%d", &n); memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < (1 << n); i++) {
		int lwb = i & (-i);
		sum[i] = sum[i ^ lwb] + a[hib[lwb] + 1];
	}
	for (int i = 0; i < (1 << n); i++) for (int j = 0; j <= n; j++)
		for (int k = 0; k <= n; k++) dp[i][j][k] = INF, pv[i][j][k] = mp(0, 0);
	dp[0][0][0] = 0;
	for (int i = 0; i < (1 << n); i++) for (int j = 0; j <= n; j++)
		for (int k = 0; k <= n; k++) if (dp[i][j][k] < INF) {
//			printf("%d %d %d %d\n", i, j, k, dp[i][j][k]);
			int rst = ((1 << n) - 1) ^ i;
			for (int S = rst; S; --S &= rst) {
				if (sum[S] > dp[i][j][k] && ~nt[S][k]) {
//					printf("%d %d %d\n", S, k, nt[S][k]);
					if (dp[i | S][j + 1][nt[S][k]] > sum[S]) {
						dp[i | S][j + 1][nt[S][k]] = sum[S];
						pv[i | S][j + 1][nt[S][k]] = mp(S, k);
					}
				}
			}
		}
	for (int i = n; i; i--) for (int j = 1; j <= n; j++) if (dp[(1 << n) - 1][i][j] < INF) {
		res.clear(); prt((1 << n) - 1, i, j); printf("%u\n", res.size());
		for (pii p : res) printf("%d %d\n", p.fi, p.se);
		return;
	}
}
int main() {
	for (int i = 0; i < (1 << MAXN); i++) {
		for (int j = 0; j <= MAXN; j++) {
			nt[i][j] = -1;
			for (int k = 1; k <= MAXN; k++) if ((i >> (k - 1) & 1) && (k > j)) {
//				printf("%d %d %d\n", i, j, k);
				nt[i][j] = k; break;
			}
		}
	}
	for (int i = 1; i <= MAXN; i++) hib[1 << i] = i;
	int qu; scanf("%d", &qu); while (qu--) solve();
	return 0;
}