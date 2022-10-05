// Created time: 2022/7/27 15:41:40
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
const int MAXL = 800;
const int MAXP = 16000;
const int MAXN = 2000;
char L[MAXL + 5], R[MAXL + 5]; int sl, sr, n;
int ch[MAXP + 5][11], ncnt, g[MAXP + 5][MAXN + 5], fail[MAXP + 5];
int hd[MAXP + 5], to[MAXP + 5], nxt[MAXP + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
void getfail() {
	queue<int> q;
	for (int i = 0; i < 10; i++) if (ch[0][i]) q.push(ch[0][i]);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < 10; i++) {
			if (ch[x][i]) fail[ch[x][i]] = ch[fail[x]][i], q.push(ch[x][i]);
			else ch[x][i] = ch[fail[x]][i];
		}
	}
}
void dfs(int x) {
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e];
		for (int i = 0; i <= n; i++) g[y][i] += g[x][i];
		dfs(y);
	}
}
int dp[MAXN + 5][MAXP + 5], mark[MAXN + 5][MAXP + 5];
int main() {
	scanf("%s%s%d", L + 1, R + 1, &n);
	sl = strlen(L + 1); sr = strlen(R + 1); 
	if (sl == sr) {
		int cur = 0, cpos = 0;
		while (cur < sl && L[cur + 1] == R[cur + 1]) ++cur;
		for (int i = 0; i <= sl; i++) {
			if (i) {
				if (!ch[cpos][L[i] - '0']) ch[cpos][L[i] - '0'] = ++ncnt;
				cpos = ch[cpos][L[i] - '0'];
			}
			if (i != sl) {
				int _l = L[i + 1] - '0', _r = (i <= cur) ? (R[i + 1] - '0') : 10;
				for (int j = _l + 1; j < _r; j++) {
					if (!ch[cpos][j]) ch[cpos][j] = ++ncnt;
					g[ch[cpos][j]][sl - i - 1]++;
				}
			}
		}
		g[cpos][0]++;
		if (cur != sl) {
			cpos = 0;
			for (int i = 1; i <= sr; i++) {
				if (!ch[cpos][R[i] - '0']) ch[cpos][R[i] - '0'] = ++ncnt;
				cpos = ch[cpos][R[i] - '0'];
				if (i > cur && i != sr) {
					for (int j = 0; j < R[i + 1] - '0'; j++) {
						if (!ch[cpos][j]) ch[cpos][j] = ++ncnt;
						g[ch[cpos][j]][sl - i - 1]++;
					}
				}
			}
			g[cpos][0]++;
		}
	} else {
		for (int i = sl + 1; i < sr; i++) g[0][i]++;
		int cpos = 0;
		for (int i = 0; i <= sl; i++) {
			if (i) {
				if (!ch[cpos][L[i] - '0']) ch[cpos][L[i] - '0'] = ++ncnt;
				cpos = ch[cpos][L[i] - '0'];
			}
			if (i != sl) {
				for (int j = L[i + 1] - '0' + 1; j <= 9; j++) {
					if (!ch[cpos][j]) ch[cpos][j] = ++ncnt;
					g[ch[cpos][j]][sl - i - 1]++;
				}
			}
		}
		g[cpos][0]++; cpos = 0;
		for (int i = 0; i <= sr; i++) {
			if (i) {
				if (!ch[cpos][R[i] - '0']) ch[cpos][R[i] - '0'] = ++ncnt;
				cpos = ch[cpos][R[i] - '0'];
			}
//			printf("! %d %d\n", i, ncnt);
			if (i != sr) {
				for (int j = (i == 0) ? 1 : 0; j < R[i + 1] - '0'; j++) {
					if (!ch[cpos][j]) ch[cpos][j] = ++ncnt;
					g[ch[cpos][j]][sr - i - 1]++;
				}
			}
		}
		g[cpos][0]++;
	}
	getfail();
	for (int i = 1; i <= ncnt; i++) adde(fail[i], i); dfs(0);
	for (int i = 0; i <= ncnt; i++) for (int j = 1; j <= n; j++) g[i][j] += g[i][j - 1];
	memset(dp, 192, sizeof(dp)); dp[0][0] = g[0][n];
	for (int i = 0; i < n; i++) for (int j = 0; j <= ncnt; j++) {
//		printf("%d %d %d\n", i, j, dp[i][j]);
		for (int k = 0; k < 10; k++) chkmax(dp[i + 1][ch[j][k]], dp[i][j] + g[ch[j][k]][n - i - 1]);
	}
	int mx = 0;
	for (int i = 0; i <= ncnt; i++) chkmax(mx, dp[n][i]);
	for (int i = 0; i <= ncnt; i++) if (dp[n][i] == mx) mark[n][i] = 1;
	for (int i = n - 1; ~i; i--) for (int j = 0; j <= ncnt; j++) for (int k = 0; k < 10; k++)
		if (dp[i + 1][ch[j][k]] == dp[i][j] + g[ch[j][k]][n - i - 1])
			mark[i][j] |= mark[i + 1][ch[j][k]];
	printf("%d\n", mx); int cur = 0;
	for (int i = 1; i <= n; i++) for (int j = 0; j < 10; j++)
		if (dp[i][ch[cur][j]] == dp[i - 1][cur] + g[ch[cur][j]][n - i] && mark[i][ch[cur][j]]) {
			printf("%d", j); cur = ch[cur][j]; break;
		}
	printf("\n");
	return 0;
}