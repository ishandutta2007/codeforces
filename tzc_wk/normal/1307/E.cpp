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
		x = 0; char c = getc(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getc();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getc();
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
	void readstr(char *s) {
		char c = getc();
		while (c <= 32 || c >= 127) c = getc();
		while (c > 32 && c < 127) s[0] = c, s++, c = getc();
		(*s) = 0;
	}
	void printstr(string s) {
		for (int i = 0; i < s.size(); i++) putc(s[i]);
	}
	void printstr(char *s) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) putc(s[i]);
	}
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 5000;
const int MOD = 1e9 + 7;
int n, m, a[MAXN + 5], cnt[MAXN + 5][MAXN + 5], cntl[MAXN + 5], cntr[MAXN + 5];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1, f, h; i <= m; i++) scanf("%d%d", &f, &h), cnt[f][h]++;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		cnt[i][j] += cnt[i][j - 1];
	int res_num = 0, res_way = 0;
	for (int i = 1; i <= n; i++) cntr[a[i]]++;
	for (int i = 0; i <= n; i++) {
		if (i) cntl[a[i]]++, cntr[a[i]]--;
		int way = 1, num = 0;
		if (i) {
			int cl = cntl[a[i]], cr = cntr[a[i]];
			int sl = cnt[a[i]][cl] - cnt[a[i]][cl - 1], sr = cnt[a[i]][cr];
			if (cr >= cl) sr--;
			if (!sl) continue;
			if (sr) num += 2, way = 1ll * way * sl % MOD * sr % MOD;
			else num++, way = 1ll * way * sl % MOD;
		}
		for (int j = 1; j <= n; j++) if (a[i] != j) {
			int cl = cntl[j], cr = cntr[j];
			int sl = cnt[j][cl], sr = cnt[j][cr];
			if (!sl && !sr) continue;
			else if (!sl || !sr) num++, way = 1ll * way * (sl + sr) % MOD;
			else if (sl == 1 && sr == 1) num++, (way <<= 1) %= MOD;
			else num += 2, way = 1ll * way * (sr * sl - min(sl, sr)) % MOD;
		}
		if (num > res_num) res_num = num, res_way = way;
		else if (num == res_num) res_way = (res_way + way) % MOD;
//		printf("%d %d\n", num, way);
	}
	if (!res_num) puts("0 1");
	else printf("%d %d\n", res_num, res_way);
	return 0;
}