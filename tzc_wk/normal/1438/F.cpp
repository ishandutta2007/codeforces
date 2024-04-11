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
const int MAXN = 262144;
int n, cnt[MAXN + 5], ord[MAXN + 5];
int Rand() {return rand() * 32768 + rand();}
int main() {
	scanf("%d", &n); int lim = (1 << n) - 1; srand(20211113);
	for (int i = 1; i <= 422; i++) {
		int u, v, w;
		while (1) {
			u = Rand() % lim + 1; v = Rand() % lim + 1; w = Rand() % lim + 1;
			if (u != v && v != w && w != u) break;
		}
		printf("? %d %d %d\n", u, v, w);
		fflush(stdout);
		int x; scanf("%d", &x);
		cnt[x]++;
	}
	for (int i = 1; i <= lim; i++) ord[i] = i;
	sort(ord + 1, ord + lim + 1, [&](int x, int y) {return cnt[x] > cnt[y];});
	int X = ord[1], Y = ord[2];
	for (int i = 1; i <= lim; i++) if (X != i && Y != i) {
		printf("? %d %d %d\n", X, Y, i); fflush(stdout);
		int x; scanf("%d", &x);
		if (x == i) {
			printf("! %d\n", i);
			fflush(stdout); return 0; 
		}
	}
	return 0;
}