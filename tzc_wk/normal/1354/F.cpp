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
const int MAXN = 75;
int n, k;
struct dat {
	int a, b, id;
	bool operator < (const dat &rhs) {
		return b < rhs.b;
	}
} a[MAXN + 5];
int dp[MAXN + 5][MAXN + 5], pre[MAXN + 5][MAXN + 5];
bool book[MAXN + 5];
void work(int n, int k) {
	if (!n) return;
	work(n - 1, pre[n][k]);
	if (k != pre[n][k]) book[n] = 1;
}
void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].a, &a[i].b), a[i].id = i;
	sort(a + 1, a + n + 1);
	memset(dp, 192, sizeof(dp)); dp[0][0] = 0;
	memset(pre, 0, sizeof(pre)); memset(book, 0, sizeof(book));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j != k) {
				if (dp[i + 1][j + 1] < dp[i][j] + a[i + 1].a + a[i + 1].b * j) {
					dp[i + 1][j + 1] = dp[i][j] + a[i + 1].a + a[i + 1].b * j;
					pre[i + 1][j + 1] = j;
				}
			}
			if (dp[i + 1][j] < dp[i][j] + a[i + 1].b * (k - 1)) {
				dp[i + 1][j] = dp[i][j] + a[i + 1].b * (k - 1);
				pre[i + 1][j] = j;
			}
		}
	}
	work(n, k);
	vector<int> res, id;
//	for (int i = 1; i <= n; i++) printf("%d%c", book[i], " \n"[i == n]);
	for (int i = 1; i <= n; i++) if (book[i]) id.pb(i);
	for (int i = 0; i + 1 < id.size(); i++) res.pb(a[id[i]].id);
	for (int i = 1; i <= n; i++) if (!book[i]) {
		res.pb(a[i].id); res.pb(-a[i].id);
	}
	res.pb(a[id.back()].id);
	printf("%d\n", res.size());
	for (int x : res) printf("%d ", x);
	printf("\n");
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}