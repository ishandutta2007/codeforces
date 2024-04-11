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
const int MAXN = 2e5;
const int MAXQ = 1.1e6;
const int MAXV = 5.1e6;
const int INF = 0x3f3f3f3f;
int n, qu, a[MAXN + 5], b[MAXN + 5], mnp[MAXV + 5];
int pr[MAXV / 7 + 5], prcnt = 0, vis[MAXV + 5];
vector<int> pfac[MAXN + 5];
int L[MAXQ + 5], R[MAXQ + 5], res[MAXQ + 5];
void sieve(int n) {
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) pr[++prcnt] = i, mnp[i] = i;
		for (int j = 1; j <= prcnt && pr[j] * i <= n; j++) {
			vis[pr[j] * i] = 1; mnp[pr[j] * i] = pr[j];
			if (i % pr[j] == 0) break;
		}
	}
}
vector<int> qr[MAXN + 5];
int pos[8][MAXV + 5], mx[17];
int main() {
	read(n); read(qu); sieve(MAXV);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) {
		int tmp = a[i]; b[i] = 1;
		while (tmp ^ 1) {
			int p = mnp[tmp], cnt = 0;
			while (tmp % p == 0) tmp /= p, cnt ^= 1;
			if (cnt) b[i] *= p, pfac[i].pb(p);
		}
	}
	for (int i = 1; i <= qu; i++) read(L[i]), read(R[i]), qr[R[i]].pb(i);
	for (int i = 1; i <= n; i++) {
//		for (int p : pfac[i]) printf("%d ", p); printf("\n");
		for (int j = 0; j < (1 << pfac[i].size()); j++) {
			int mul = 1;
			for (int k = 0; k < pfac[i].size(); k++)
				if (j >> k & 1) mul *= pfac[i][k];
			for (int k = 0; k <= 7; k++)
				chkmax(mx[pfac[i].size() + k - 2 * __builtin_popcount(j)], pos[k][mul]);
		}
//		for (int j = 0; j <= 14; j++) printf("%d%c", mx[j], " \n"[j == 14]);
		for (int j = 0; j < (1 << pfac[i].size()); j++) {
			int mul = 1;
			for (int k = 0; k < pfac[i].size(); k++)
				if (j >> k & 1) mul *= pfac[i][k];
//			printf("pos %d %d\n", __builtin_popcount(j), mul);
			chkmax(pos[pfac[i].size()][mul], i);
		}
		for (int id : qr[i]) {
			res[id] = INF;
			for (int j = 0; j <= 14; j++) if (mx[j] >= L[id])
				chkmin(res[id], j);
		}
	}
	for (int i = 1; i <= qu; i++) print(res[i], '\n');
	print_final();
	return 0;
}