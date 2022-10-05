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
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 1064
#endif
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {if (x > y) x = y;}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {if (x < y) x = y;}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
#define FILE_SIZE 1 << 23
char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
#ifdef LOCAL
inline char getc() {return getchar();}
inline void putc(char c) {putchar(c);}
#else
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
#endif
template<typename T> void read(T &x) {
	x = 0; char c = getc(); T neg = 0;
	while (!isdigit(c)) neg |= (c == '-'), c = getc();
	while (isdigit(c)) x = x * 10 + (c - '0'), c = getc();
	if (neg) x = -x;
}
template<typename T> void recursive_print(T x) {
	if (!x) return;
	recursive_print(x / 10); putc(x % 10 ^ 48);
}
template<typename T> void print(T x) {
	if (!x) putc('0'); if (x < 0) putc('-'), x = -x;
	recursive_print(x);
}
template<typename T> void print(T x, char c) {print(x); putc(c);}
void readstr(char *s) {
	char c = getc();
	while (c <= 32 || c >= 127) c = getc();
	while (c > 32 && c < 127) s[0] = c, s++, c = getc();
	(*s) = 0;
}
void printstr(string s) {for (int i = 0; i < s.size(); i++) putc(s[i]);}
void printstr(char *s) {
	int len = strlen(s);
	for (int i = 0; i < len; i++) putc(s[i]);
}
void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
#endif
const int MAXN = 1e5;
const int MAXV = 2e4;
const int BLK = 316;
const int L1 = 18;
const int L2 = 2262;
const int S = 2000;
int n, m, c, qu, a[MAXN + 5], sum[L1 + 3][MAXN + 5], pos[MAXN + 5];
int pr[MAXN + 5], prcnt = 0, vis[MAXN + 5], mxp[MAXN + 5], mu[MAXN + 5], msk[MAXN + 5];
void sieve(int n) {
	mu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) pr[++prcnt] = i, mu[i] = -1, mxp[i] = prcnt;
		for (int j = 1; j <= prcnt && pr[j] * i <= n; j++) {
			vis[pr[j] * i] = 1; mxp[pr[j] * i] = mxp[i];
			if (i % pr[j] == 0) break;
			mu[pr[j] * i] = -mu[i];
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= L1; j++) if (i % pr[j] == 0) msk[i] |= 1 << j - 1;
	for (int i = 2; i <= n; i++) pos[i] = pos[i - 1] + (!vis[i]);
}
int num[MAXN + 5], num_cnt = 0;
void dfs(int x, ll prd) {
	if (prd > MAXN) return;
	if (x == L1 + 1) return num[++num_cnt] = prd, void();
	dfs(x + 1, prd); dfs(x + 1, prd * pr[x]);
}
int L[BLK + 5], R[BLK + 5], bel[MAXN + 5], blk_cnt, blk_sz;
struct qry {
	int l, r, id;
	bool operator < (const qry &rhs) {return mp(bel[l], bel[r]) < mp(bel[rhs.l], bel[rhs.r]);}
} q[MAXN + 5];
int res[MAXN + 5], buc[MAXN + 5], msks[MAXN + 5];
void push(int x) {
	if (mxp[a[x]] > L1) buc[mxp[a[x]]]++;
	if (mxp[a[x]] && mxp[a[x] / pr[mxp[a[x]]]] > L1) buc[mxp[a[x] / pr[mxp[a[x]]]]]++;
}
void pop(int x) {
	if (mxp[a[x]] > L1) buc[mxp[a[x]]]--;
	if (mxp[a[x]] && mxp[a[x] / pr[mxp[a[x]]]] > L1) buc[mxp[a[x] / pr[mxp[a[x]]]]]--;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &m, &c, &qu); sieve(MAXN);
	blk_sz = (int)sqrt(n); blk_cnt = (n - 1) / blk_sz + 1;
	for (int i = 1; i <= blk_cnt; i++) {
		L[i] = (i - 1) * blk_sz + 1; R[i] = min(i * blk_sz, n);
		for (int j = L[i]; j <= R[i]; j++) bel[j] = i;
	}
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= L1; i++) for (int j = 1; j <= n; j++)
		sum[i][j] = sum[i][j - 1] + (a[j] % pr[i] == 0);
	dfs(1, 1); sort(num + 1, num + num_cnt + 1);
	for (int i = 1; i <= qu; i++) {
		scanf("%d%d", &q[i].l, &q[i].r); msks[i] = 0; q[i].id = i;
		for (int j = 1; j <= L1; j++) if (sum[j][q[i].r] - sum[j][q[i].l - 1]) msks[i] |= (1 << j - 1);
		for (int j = 1; j <= num_cnt; j++) if ((msk[num[j]] & msks[i]) == msk[num[j]])
			res[i] += mu[num[j]] * (c / num[j]);
	}
	sort(q + 1, q + qu + 1); int cl = 1, cr = 0;
	for (int i = 1; i <= qu; i++) {
		while (cr < q[i].r) push(++cr);
		while (cl > q[i].l) push(--cl);
		while (cl < q[i].l) pop(cl++);
		while (cr > q[i].r) pop(cr--);
		int id = q[i].id; static int ss[S + 5], sbuc[L2 + 5];
		for (int j = 1; j <= S; j++) ss[j] = ss[j - 1] + ((msk[j] & msks[id]) == 0);
		for (int j = L1 + 1; j <= L2; j++) if (buc[j]) res[id] -= ss[c / pr[j]];
		for (int j = 1; j <= L2; j++) sbuc[j] = sbuc[j - 1] + (!!buc[j]);
		for (int j = L1 + 1; pr[j] * pr[j] <= c; j++) if (buc[j]) {
			int V = c / pr[j];
			for (int L = pr[j + 1], R; L * pr[j] <= c; L = R + 1) {
				R = V / (V / L);
				res[id] += ss[V / L] * (sbuc[pos[R]] - sbuc[pos[L - 1]]);
			}
		}
	}
	for (int i = 1; i <= qu; i++) printf("%d\n", res[i]);
	return 0;
}
/*
5 20000 1000 3
149 151 298 453 10
1 4
1 2
3 5
*/
/*
6 20000 10000 6
149 1057 942 298 453 10
1 4
1 2
3 6
1 6
1 1
2 3
*/