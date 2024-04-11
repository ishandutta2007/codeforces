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
const int MAXN = 500;
int n, k, a[MAXN + 5], b[MAXN + 5];
ll dp[MAXN + 5][MAXN + 5];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
	memset(dp, 0xcf, sizeof(dp)); dp[0][0] = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = (sum + a[i]) % k; sum = (sum + b[i]) % k;
		for (int R = 0; R < k; R++) if (dp[i][R] >= 0) {
			int B = (sum - R + k) % k;
			for (int nd_r = 0; nd_r <= min(a[i + 1], k - 1); nd_r++) {
				int nd_b = (k - nd_r) % k;
				if (nd_b <= b[i + 1]) {
					int could = (a[i + 1] - nd_r) / k + (b[i + 1] - nd_b) / k;
					int lft_r = (a[i + 1] - nd_r) % k;
					int lft_b = (b[i + 1] - nd_b) % k;
					chkmax(dp[i + 1][(R + lft_r) % k],
					dp[i][R] + could + (nd_r > 0) + (R + lft_r >= k) + (B + lft_b >= k));
				}
			}
		}
	}
	ll res = 0;
	for (int i = 0; i < k; i++) chkmax(res, dp[n][i]);
	printf("%lld\n", res);
	return 0;
}