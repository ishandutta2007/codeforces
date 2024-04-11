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
using namespace fastio;
const int MAXN = 2e5;
const int INF = 0x3f3f3f3f;
int n, a[MAXN + 5], hd[MAXN + 5], nxt[MAXN * 2 + 5], to[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
void clear() {for (int i = 1; i <= n; i++) hd[i] = 0; ec = 0;}
int dp[MAXN + 5][2];
bool dfs(int x, int f, int mid) {
	if (a[x] != 1) dp[x][1] = 0;
	if (a[x] != 2) dp[x][0] = 0;
	int mx[2] = {0};
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		if (!dfs(y, x, mid)) return 0;
		for (int i = 0; i < 2; i++) {
			int mn = INF;
			for (int j = 0; j < 2; j++)
				chkmin(mn, dp[x][i] + dp[y][j] + (i != j));
			chkmax(mx[i], mn);
		}
		for (int i = 0; i < 2; i++) {
			int mn = INF;
			for (int j = 0; j < 2; j++) chkmin(mn, dp[y][j] + (i != j));
			chkmax(dp[x][i], mn);
		}
	}
	if (mx[0] > mid) dp[x][0] = INF;
	if (mx[1] > mid) dp[x][1] = INF;
//	printf("mx %d %d\n", mx[0], mx[1]);
//	printf("%d %d %d\n", x, dp[x][0], dp[x][1]);
	if (dp[x][0] > mid && dp[x][1] > mid) return 0;
	return 1;
}
bool check(int mid) {
	for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = INF;
	return dfs(1, 0, mid);
}
void solve() {
	read(n); clear();
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1, u, v; i < n; i++) read(u), read(v), adde(u, v), adde(v, u);
	int l = 0, r = n, p = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) p = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", (p + 3 >> 1));
}
int main() {
	int qu; read(qu);
	while (qu--) solve();
	return 0;
}