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
const int MAXN = 3e5;
int n, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int dp[MAXN + 5], fa[MAXN + 5], sfa[MAXN + 5];
bool is[MAXN + 5];
void dfs(int x, int f) {
	fa[x] = f;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dfs(y, x); dp[x] ^= (dp[y] + 1);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		adde(u, v); adde(v, u);
	} dfs(1, 0);
//	for (int i = 1; i <= n; i++) printf("%d%c", dp[i], " \n"[i == n]);
	printf("%d", (dp[1]) ? 1 : 2);
	for (int i = 1; i <= n; i++) {
		int ss = 0;
		for (int e = hd[i]; e; e = nxt[e]) {
			int y = to[e]; if (y == fa[i]) continue;
			ss ^= dp[y];
		}
		for (int e = hd[i]; e; e = nxt[e]) {
			int y = to[e]; if (y == fa[i]) continue;
			sfa[y] = ss ^ dp[y];
		}
	}
	int cur = dp[1], G = 0; is[1] = 1;
	for (int i = 2; i <= n; i++) {
		vector<int> vec;
		for (int j = i; !is[j]; j = fa[j]) {
			is[j] = 1; vec.pb(j);
		}
		reverse(vec.begin(), vec.end());
		for (int x : vec) {
			cur ^= dp[x] + 1;
			cur ^= dp[x];
			G ^= 1;
		}
		printf("%d", (cur ^ G) ? 1 : 2);
	}
	return 0;
}