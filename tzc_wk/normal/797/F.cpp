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
const int MAXN = 5000;
const ll INFll = 0x3f3f3f3f3f3f3f3fll;
int n, m, x[MAXN + 5]; pii p[MAXN + 5];
ll sum[MAXN + 5], dp[2][MAXN + 5];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
	for (int i = 1; i <= m; i++) scanf("%d%d", &p[i].fi, &p[i].se);
	sort(x + 1, x + n + 1); sort(p + 1, p + m + 1);
	memset(dp, 63, sizeof(dp)); dp[0][0] = 0;
	int pre = 0, cur = 1;
	for (int i = 1; i <= m; i++) {
		memset(dp[cur], 63, sizeof(dp[cur])); dp[cur][0] = 0;
		static int q[MAXN + 5]; int hd = 1, tl = 1;
		memset(sum, 0, sizeof(sum));
		for (int j = 1; j <= n; j++) sum[j] = sum[j - 1] + abs(x[j] - p[i].fi);
		for (int j = 1; j <= n; j++) {
			while (hd <= tl && dp[pre][j] - sum[j] <= dp[pre][q[tl]] - sum[q[tl]]) --tl;
			q[++tl] = j;
			while (hd <= tl && q[hd] < j - p[i].se) ++hd;
			dp[cur][j] = dp[pre][q[hd]] + sum[j] - sum[q[hd]];
		} swap(pre, cur);
	}
	if (dp[pre][n] >= INFll) printf("-1\n");
	else printf("%lld\n", dp[pre][n]);
	return 0;
}
/*
4 3
1 2 3 4
1 1
2 1
3 1
*/