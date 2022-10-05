// Created time: 2022/6/9 19:44:02
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
/*
typedef __int128_t i128;
const int MAXN = 58;
const i128 MOD1 = 9000000000000000041;
const i128 MOD2 = 9000000000000000053;
i128 mul(i128 x, i128 y, i128 mod) {return x * y % mod;}
i128 qpow(i128 x, i128 e, i128 mod) {
	i128 res = 1;
	for (; e; e >>= 1, x = mul(x, x, mod))
		if (e & 1) res = mul(res, x, mod);
	return res;
}
int n, qu, r[MAXN + 5], b[MAXN + 5];
vector<int> B[MAXN + 5], R[MAXN + 5];
i128 a1[MAXN + 5][MAXN + 5], a2[MAXN + 5][MAXN + 5];
vector<i128> gauss(i128 a[MAXN + 5][MAXN + 5], i128 MOD) {
	vector<i128> res(n);
	for (int i = 1; i < n; i++) {
		int p = i;
		for (int j = i; j < n; j++) if (a[j][i]) p = j;
		if (p ^ i) {
			for (int j = i; j <= n; j++) swap(a[i][j], a[p][j]);
		}
		i128 iv = qpow(a[i][i], MOD - 2, MOD);
		for (int j = i; j <= n; j++) a[i][j] = mul(a[i][j], iv, MOD);
		for (int j = i + 1; j < n; j++) {
			for (int k = i + 1; k <= n; k++)
				a[j][k] = (a[j][k] + mul(MOD - a[j][i], a[i][k], MOD)) % MOD;
			a[j][i] = 0;
		}
	}
	for (int i = n - 1; i; i--) {
		res[i] = a[i][n];
		for (int j = i + 1; j < n; j++)
			res[i] = (res[i] + mul(MOD - a[i][j], res[j], MOD)) % MOD;
	}
	return res;
}
int main() {
	freopen("transfer.in", "r", stdin);
	freopen("transfer.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &b[i], &r[i]);
		B[b[i]].pb(i); R[r[i]].pb(i);
	}
	scanf("%d", &qu);
	while (qu--) {
		int x; static char buf[MAXN + 5]; scanf("%d%s", &x, buf + 1);
		memset(a1, 0, sizeof(a1)); memset(a2, 0, sizeof(a2));
		for (int i = 1; i < n; i++) {
			a1[i][i] = a2[i][i] = 2;
			for (int p : R[i]) a1[i][p]--, a2[i][p]--;
			for (int p : B[i]) a1[i][p]--, a2[i][p]--;
			a1[i][n] = a2[i][n] = (buf[i] == 'R');
			for (int p : B[i]) a1[i][n] -= (buf[p] == 'R'), a2[i][n] -= (buf[p] == 'R');
			a1[i][n] += (i == 1); a2[i][n] += (i == 1);
			a1[i][n] -= (i == x); a2[i][n] -= (i == x);
		}
		for (int i = 1; i < n; i++) for (int j = 1; j <= n; j++) {
			if (a1[i][j] < 0) a1[i][j] += MOD1;
			if (a2[i][j] < 0) a2[i][j] += MOD2;
		}
		vector<i128> res1 = gauss(a1, MOD1);
		vector<i128> res2 = gauss(a2, MOD2);
		bool flg = 1;
		for (int i = 1; i < n; i++) if (res1[i] != res2[i]) {
			flg = 0; break;
		}
//		for (int i = 1; i < n; i++) printf("%lld %lld\n", (ll)res1[i], (ll)res2[i]);
		if (!flg) {puts("-1"); continue;}
		static bool vis[MAXN + 5]; memset(vis, 0, sizeof(vis));
		queue<int> q; q.push(x); vis[x] = 1;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : R[u]) if (buf[v] == 'R' && !vis[v]) vis[v] = 1, q.push(v);
			for (int v : B[u]) if (buf[v] == 'B' && !vis[v]) vis[v] = 1, q.push(v);
		}
		for (int i = 1; i < n; i++) if (res1[i] && !vis[i]) {flg = 0; break;}
		for (int i = 1; i < n; i++) if (!res1[i] && buf[i] == 'R') {flg = 0; break;}
		if (!flg) {puts("-1"); continue;}
		ll res = 0;
		for (int i = 1; i < n; i++) res += res1[i] + res1[i] - (buf[i] == 'R');
		printf("%lld\n", res);
	}
	return 0;
}
*/
typedef __int128_t i128;
const int MAXN = 58;
const int MAXQ = 5000;
const i128 MOD1 = 9000000000000000041;
const i128 MOD2 = 9000000000000000053;
i128 mul(i128 x, i128 y, i128 mod) {return x * y % mod;}
i128 qpow(i128 x, i128 e, i128 mod) {
	i128 res = 1;
	for (; e; e >>= 1, x = mul(x, x, mod))
		if (e & 1) res = mul(res, x, mod);
	return res;
}
int n, qu, r[MAXN + 5], b[MAXN + 5];
vector<int> B[MAXN + 5], R[MAXN + 5];
i128 a1[MAXN + 5][MAXN + MAXQ + 5], a2[MAXN + 5][MAXN + MAXQ + 5];
char buf[MAXQ + 5][MAXN + 5]; int X[MAXQ + 5];
vector<vector<i128> > gauss(i128 a[MAXN + 5][MAXN + MAXQ + 5], i128 MOD) {
	vector<vector<i128> > res(qu + 1);
	for (int i = 1; i <= qu; i++) res[i].resize(n);
	for (int i = 1; i < n; i++) {
		int p = i;
		for (int j = i; j < n; j++) if (a[j][i]) p = j;
		if (p ^ i) {
			for (int j = i; j <= n - 1 + qu; j++) swap(a[i][j], a[p][j]);
		}
		i128 iv = qpow(a[i][i], MOD - 2, MOD);
		for (int j = i; j <= n - 1 + qu; j++) a[i][j] = mul(a[i][j], iv, MOD);
		for (int j = i + 1; j < n; j++) {
			for (int k = i + 1; k <= n - 1 + qu; k++)
				a[j][k] = (a[j][k] + mul(MOD - a[j][i], a[i][k], MOD)) % MOD;
			a[j][i] = 0;
		}
	}
	for (int _ = 1; _ <= qu; _++) {
		for (int i = n - 1; i; i--) {
			res[_][i] = a[i][n - 1 + _];
			for (int j = i + 1; j < n; j++)
				res[_][i] = (res[_][i] + mul(MOD - a[i][j], res[_][j], MOD)) % MOD;
		}
	}
	return res;
}
int main() {
//	freopen("transfer.in", "r", stdin);
//	freopen("transfer.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &b[i], &r[i]);
		B[b[i]].pb(i); R[r[i]].pb(i);
	}
	scanf("%d", &qu);
	for (int i = 1; i < n; i++) {
		a1[i][i] = a2[i][i] = 2;
		for (int p : R[i]) a1[i][p]--, a2[i][p]--;
		for (int p : B[i]) a1[i][p]--, a2[i][p]--;
	}
	for (int _ = 1; _ <= qu; _++) {
		scanf("%d%s", &X[_], buf[_] + 1);
		for (int i = 1; i < n; i++) {
			a1[i][n - 1 + _] = a2[i][n - 1 + _] = (buf[_][i] == 'R');
			for (int p : B[i]) {
				a1[i][n - 1 + _] -= (buf[_][p] == 'R');
				a2[i][n - 1 + _] -= (buf[_][p] == 'R');
			}
			a1[i][n - 1 + _] += (i == 1); a2[i][n - 1 + _] += (i == 1);
			a1[i][n - 1 + _] -= (i == X[_]); a2[i][n - 1 + _] -= (i == X[_]);
		}
	}
	for (int i = 1; i < n; i++) for (int j = 1; j <= n - 1 + qu; j++) {
		if (a1[i][j] < 0) a1[i][j] += MOD1; 
		if (a2[i][j] < 0) a2[i][j] += MOD2; 
	}
	vector<vector<i128> > res1 = gauss(a1, MOD1);
	vector<vector<i128> > res2 = gauss(a2, MOD2);
	for (int _ = 1; _ <= qu; _++) {
		bool flg = 1;
		for (int i = 1; i < n; i++) if (res1[_][i] != res2[_][i]) {
			flg = 0; break;
		}
		if (!flg) {puts("-1"); continue;}
		static bool vis[MAXN + 5]; memset(vis, 0, sizeof(vis));
		queue<int> q; q.push(X[_]); vis[X[_]] = 1;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : R[u]) if (buf[_][v] == 'R' && !vis[v]) vis[v] = 1, q.push(v);
			for (int v : B[u]) if (buf[_][v] == 'B' && !vis[v]) vis[v] = 1, q.push(v);
		}
		for (int i = 1; i < n; i++) if (res1[_][i] && !vis[i]) {flg = 0; break;}
		for (int i = 1; i < n; i++) if (!res1[_][i] && buf[_][i] == 'R') {flg = 0; break;}
		if (!flg) {puts("-1"); continue;}
		ll res = 0;
		for (int i = 1; i < n; i++) res += res1[_][i] + res1[_][i] - (buf[_][i] == 'R');
		printf("%lld\n", res);
	}
	return 0;
}