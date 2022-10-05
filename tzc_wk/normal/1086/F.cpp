// Created time: 2022/6/5 20:12:37
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
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
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
const int MAXN = 2000;
const int MOD = 998244353;
const int INV2 = MOD + 1 >> 1;
const int INV6 = (MOD + 1) / 6;
int n, t, x[MAXN + 5], y[MAXN + 5], res = 0;
namespace CalcUnion {
	int sum[MAXN * 2 + 5][MAXN * 2 + 5];
	int kx[MAXN * 2 + 5], ky[MAXN * 2 + 5], ux[MAXN * 2 + 5], uy[MAXN * 2 + 5], nx, ny, cx, cy;
	int calc() {
		cx = cy = nx = ny = 0; kx[0] = ky[0] = -1e9;
		for (int i = 1; i <= n; i++) {
			kx[++cx] = x[i] - t; kx[++cx] = x[i] + t + 1;
			ky[++cy] = y[i] - t; ky[++cy] = y[i] + t + 1;
		}
		sort(kx + 1, kx + cx + 1); sort(ky + 1, ky + cy + 1);
		for (int i = 1; i <= cx; i++) if (kx[i] != kx[i - 1]) ux[++nx] = kx[i];
		for (int i = 1; i <= cy; i++) if (ky[i] != ky[i - 1]) uy[++ny] = ky[i];
		for (int i = 1; i <= nx; i++) for (int j = 1; j <= ny; j++) sum[i][j] = 0;
		for (int i = 1; i <= n; i++) {
			int lx = lower_bound(ux + 1, ux + nx + 1, x[i] - t) - ux;
			int rx = lower_bound(ux + 1, ux + nx + 1, x[i] + t + 1) - ux;
			int ly = lower_bound(uy + 1, uy + ny + 1, y[i] - t) - uy;
			int ry = lower_bound(uy + 1, uy + ny + 1, y[i] + t + 1) - uy;
			sum[lx][ly]++; sum[lx][ry]--; sum[rx][ly]--; sum[rx][ry]++;
		}
		int ret = 0;
		for (int i = 1; i <= nx; i++) for (int j = 1; j <= ny; j++)
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		for (int i = 1; i <= nx; i++) for (int j = 1; j <= ny; j++) {
			if (sum[i][j]) ret = (ret + 1ll * (ux[i + 1] - ux[i]) * (uy[j + 1] - uy[j])) % MOD;
		} 		
		return ret;
	}
}
int getsum2(int x) {return 1ll * x * (x + 1) % MOD * (2 * x + 1) % MOD * INV6 % MOD;}
int getsum2(int l, int r) {return (getsum2(r) - getsum2(l - 1) + MOD) % MOD;}
int getsum1(int x) {return 1ll * x * (x + 1) % MOD * INV2 % MOD;}
int getsum1(int l, int r) {return (getsum1(r) - getsum1(l - 1) + MOD) % MOD;}
namespace CalcInter {
	int calc(vector<int> vec) {
		for (int x : vec) if (!x) return 0;
		int mnx = 1e9, mxx = -1e9, mny = 1e9, mxy = -1e9;
		for (int id : vec) {
			chkmin(mnx, x[id]); chkmax(mxx, x[id]);
			chkmin(mny, y[id]); chkmax(mxy, y[id]);
		}
		int lim = max(mxx - mnx + 1, mxy - mny + 1) / 2;
		int V1 = mxx - mnx - 1, V2 = mxy - mny - 1;
		if (lim <= t) {
			// \sum\limits_{i=lim}^t(2i-V1)(2i-V2)
			int sum = (4ll * getsum2(lim, t) % MOD -
					2ll * (V1 + V2) * getsum1(lim, t) % MOD +
					1ll * V1 * V2 % MOD * (t - lim + 1) % MOD +
					MOD) % MOD;
			return sum;
		} else return 0;
	}
}
int ord[MAXN + 5];
void solve() {
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
	res = 1ll * CalcUnion :: calc() * (t + 1) % MOD;
	for (int i = 1; i <= n; i++) res = (res - CalcInter :: calc({i}) + MOD) % MOD;
	for (int i = 1; i <= n; i++) ord[i] = i;
	sort(ord + 1, ord + n + 1, [&](int a, int b) {
		if (x[a] != x[b]) return x[a] < x[b];
		if (y[a] != y[b]) return y[a] < y[b];
		return a < b;
	});
	for (int i = 1; i <= n; i++) {
		set<pii> st; st.insert(mp(-1e9, 0)); st.insert(mp(1e9, 0));
		int id = ord[i]; st.insert(mp(y[id], id));
		for (int j = i + 1; j <= n; j++) {
			st.insert(mp(y[ord[j]], ord[j]));
			auto it1 = st.find(mp(y[id], id));
			auto it2 = st.find(mp(y[ord[j]], ord[j]));
			if (it1 == next(it2)) {
				res = (res + CalcInter :: calc({id, ord[j]})) % MOD;
				res = (res - CalcInter :: calc({id, ord[j], prev(it2) -> se}) + MOD) % MOD;
				res = (res - CalcInter :: calc({id, ord[j], next(it1) -> se}) + MOD) % MOD;
				res = (res + CalcInter :: calc({id, ord[j], next(it1) -> se, prev(it2) -> se})) % MOD;
			}
			if (it2 == next(it1)) {
				res = (res + CalcInter :: calc({id, ord[j]})) % MOD;
				res = (res - CalcInter :: calc({id, ord[j], prev(it1) -> se}) + MOD) % MOD;
				res = (res - CalcInter :: calc({id, ord[j], next(it2) -> se}) + MOD) % MOD;
				res = (res + CalcInter :: calc({id, ord[j], next(it2) -> se, prev(it1) -> se})) % MOD;
			}
		}
	}
	printf("%d\n", res);
}
int main() {
// 	freopen("fire.in", "r", stdin);
// 	freopen("fire.out", "w", stdout);
	int qu = 1;
	while (qu--) solve();	
	return 0;
}