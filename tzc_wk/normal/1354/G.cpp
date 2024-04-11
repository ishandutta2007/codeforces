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
int n, k;
int query(vector<int> a, vector<int> b) {//0: a < b, 1: a > b, 2: a = b
	if (a == b) return 2;
	printf("? %llu %llu\n", a.size(), b.size());
	for (int x : a) printf("%d ", x); printf("\n");
	for (int x : b) printf("%d ", x); printf("\n");
	fflush(stdout); string ss; cin >> ss;
	if (ss == "WASTED") exit(0xfe);
	if (ss == "SECOND") return 0;
	if (ss == "FIRST") return 1;
	return 2;
}
int calc(int l, int r) {
	int L = l, R = r, p = 0;
	while (L <= R) {
		int mid = L + R >> 1;
		vector<int> A, B;
		for (int i = l; i <= mid; i++) A.pb(i - l + 1), B.pb(i);
		if (query(A, B) != 2) p = mid, R = mid - 1;
		else L = mid + 1;
	}
	return p;
}
int solve() {
	int T = 20, cur = 1;
	while (T--) {
		int x = rand() % n + 1;
		while (x == cur) x = rand() % n + 1;
		if (query(vector<int>{x}, vector<int>{cur})) cur = x;
	}
	if (query(vector<int>{1}, vector<int>{cur}) != 2)
		return 1;
	int L;
	for (L = 2; L <= n; L <<= 1) {
		vector<int> A, B;
		for (int j = 1; j <= (L >> 1); j++) A.pb(j);
		for (int j = 1; j <= (L >> 1); j++) B.pb(j + (L >> 1));
		if (query(A, B) != 2) return calc((L >> 1) + 1, L);
	}
	L >>= 1;
	return calc(L + 1, n);
}
int main() {
	srand(time(0));
	int qu; scanf("%d", &qu);
	while (qu--) {
		scanf("%d%d", &n, &k); int res = solve();
		printf("! %d\n", res); fflush(stdout);
	}
	return 0;
}