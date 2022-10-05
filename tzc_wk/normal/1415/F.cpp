// It's like a dream
// what's the f**k?
// /px/px/px
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
const int INF = 0x3f3f3f3f;
int n, pre[MAXN + 5];
ll x[MAXN + 5], t[MAXN + 5], dp[MAXN + 5][2];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld%lld", &t[i], &x[i]);
	for (int i = 1; i <= n; i++) pre[i] = (x[i] != x[i - 1]) ? (i - 1) : pre[i - 1];
	static bool ok[MAXN + 5];
	for (int i = 1; i <= n; i++) ok[i] = (abs(x[i] - x[i - 1]) <= t[i] - t[i - 1]);
	int orz = n; while(ok[orz]) --orz;
	memset(dp, 63, sizeof(dp)); dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		if (x[i] == x[i - 1]) {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
		} else {
			if (i > 1 && max(max(t[pre[i - 1]] + abs(x[pre[i - 1]] - x[i]), dp[i - 1][0] + abs(x[i - 1] - x[i])), t[i - 1]) <= t[i])
				chkmin(dp[i][1], max(max(t[pre[i - 1]] + abs(x[pre[i - 1]] - x[i]), dp[i - 1][0] + abs(x[i - 1] - x[i])), t[i - 1]));
			if (max(abs(x[i - 1] - x[i]) + dp[i - 1][1], t[i - 1]) <= t[i])
				chkmin(dp[i][1], max(abs(x[i - 1] - x[i]) + dp[i - 1][1], t[i - 1]));
		}
		int pret = INF, prex = 0;
		if (x[i] != x[i - 1]) pret = t[i - 1], prex = x[i - 1];
		for (int j = i - 2; j >= 0; j--) {
			if (x[i] != x[j]) {
				if (j > 1 && max(t[j], max(dp[j][0] + abs(x[j] - x[i]), t[pre[j]] + abs(x[pre[j]] - x[i]))) + abs(x[i] - x[j + 1]) <= t[j + 1])
					chkmin(dp[i][0], max(t[j], max(dp[j][0] + abs(x[j] - x[i]), t[pre[j]] + abs(x[pre[j]] - x[i]))));
				if (max(t[j], dp[j][1] + abs(x[j] - x[i])) + abs(x[i] - x[j + 1]) <= t[j + 1])
					chkmin(dp[i][0], max(t[j], dp[j][1] + abs(x[j] - x[i])));
				if (abs(prex - x[j]) > pret - t[j]) break;
				pret = t[j], prex = x[j];
			} else {
				if (j > 1 && max(dp[j][0] + abs(x[j] - x[j + 1]), t[pre[j]] + abs(x[pre[j]] - x[j + 1])) <= t[j + 1])
					chkmin(dp[i][0], dp[j][0]);
				if (dp[j][1] + abs(x[j] - x[j + 1]) <= t[j + 1])
					chkmin(dp[i][0], dp[j][1]);
			}
		}
		if (i >= orz && (dp[i][0] <= t[i] || dp[i][1] <= t[i]))
			return puts("YES"), 0;
//		printf("%lld %lld\n", dp[i][0], dp[i][1]);
	}
	puts("NO");
	return 0;
}