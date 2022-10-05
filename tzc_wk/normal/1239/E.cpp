// Created time: 2022/5/1 8:59:05
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
const int MAXN = 50;
const int MAXS = 2.5e6;
int n, a[MAXN + 5], sum;
bitset<MAXS + 5> dp[MAXN + 5][MAXN / 2 + 5];
vector<int> v1, v2;
void work(int x, int y, int z) {
	if (x == 2) return;
	if (z >= a[x] && dp[x - 1][y - 1][z - a[x]]) v1.pb(a[x]), work(x - 1, y - 1, z - a[x]);
	else v2.pb(a[x]), work(x - 1, y, z);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n * 2; i++) scanf("%d", &a[i]), sum += a[i];
	sort(a + 1, a + n * 2 + 1);
	memset(dp, 0, sizeof(dp)); dp[2][1][a[2]] = 1;
	for (int i = 2; i < n * 2; i++) for (int j = 1; j <= n; j++) for (int k = 0; k <= sum; k++)
		if (dp[i][j][k]) {
			if (j < n) dp[i + 1][j + 1][k + a[i + 1]] = 1;
			dp[i + 1][j][k] = 1;
		}
	int pos = 0, mn = 1e9;
	for (int j = 0; j <= sum; j++) if (dp[n * 2][n][j]) {
		if (mn > max(j + a[1], sum - j + a[2])) pos = j, mn = max(j + a[1], sum - j + a[2]);
	}
	v1.pb(a[2]); v2.pb(a[1]); work(n * 2, n, pos);
	sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end(), greater<int>());
	for (int x : v1) printf("%d ", x); printf("\n");
	for (int x : v2) printf("%d ", x); printf("\n");
	return 0;
}