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
const int MAXV = 1e5;
const int LOG_N = 18;
const int MAXC = MAXV << 4;
int pr[MAXV / 6 + 5], mu[MAXV + 5], prcnt = 0;
int smu[MAXV + 5]; ll sm[MAXV + 5];
bool vis[MAXV + 5];
int hd[MAXV + 5], val[MAXC + 5], nxt[MAXC + 5], item_n = 0;
void ins(int x, int y) {val[++item_n] = y; nxt[item_n] = hd[x]; hd[x] = item_n;}
void sieve(int n) {
	mu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) mu[i] = -1, pr[++prcnt] = i;
		for (int j = 1; j <= prcnt && pr[j] * i <= n; j++) {
			vis[pr[j] * i] = 1; if (i % pr[j] == 0) break;
			mu[pr[j] * i] = -mu[i];
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
			ins(j, i);
	for (int i = 1; i <= n; i++) smu[i] = smu[i - 1] + mu[i];
	for (int i = 1; i <= n; i++) {
		sm[i] = sm[i - 1];
		for (int e = hd[i]; e; e = nxt[e]) {
			int f = val[e];
			sm[i] -= 1ll * mu[f] * (i / f - 1) * (i / f - 1);
			sm[i] += 1ll * mu[f] * (i / f) * (i / f);
		}
	}
}
ll dp[LOG_N + 2][MAXV + 5];
struct node {ll mn, lz;} s[MAXV * 4 + 5];
void pushup(int k) {s[k].mn = min(s[k << 1].mn, s[k << 1 | 1].mn) + s[k].lz;}
void build(int k, int l, int r, int lv) {
	s[k].lz = 0; if (l == r) return s[k].mn = 2 * dp[lv][l], void();
	int mid = l + r >> 1; build(k << 1, l, mid, lv); build(k << 1 | 1, mid + 1, r, lv);
	pushup(k);
}
void tag(int k, ll v) {s[k].lz += v; s[k].mn += v;}
void modify(int k, int l, int r, int p, ll v) {
	if (l >= p) return tag(k, v), void();
	int mid = l + r >> 1;
	if (p <= mid) modify(k << 1, l, mid, p, v), tag(k << 1 | 1, v);
	else modify(k << 1 | 1, mid + 1, r, p, v);
	pushup(k);
}
int main() {
	sieve(MAXV); memset(dp, 0x1f, sizeof(dp)); dp[0][0] = 0;
	for (int i = 1; i <= MAXV; i++) dp[1][i] = 1ll * i * (i + 1) / 2;
	for (int i = 2; i <= LOG_N; i++) {
		build(1, 0, MAXV, i - 1);
		for (int j = 1; j <= MAXV; j++) {
			for (int e = hd[j]; e; e = nxt[e]) {
				int f = val[e];
				ll ori = ((j / f == 1) ? 0 : 1) + sm[j / f - 1];
				ll cur = 1 + sm[j / f];
				modify(1, 0, MAXV, f, ori - cur);
			}
			dp[i][j] = ((s[1].mn + s[1].lz) / 2) + 1ll * j * (j + 1) / 2;
//			printf("%d %d %lld\n", i, j, dp[i][j]);
		}
	}
	int qu; read(qu);
	while (qu--) {
		int n, k; read(n); read(k);
		if (k > LOG_N) print(n, '\n');
		else print(dp[k][n], '\n');
	}
	print_final();
	return 0;
}