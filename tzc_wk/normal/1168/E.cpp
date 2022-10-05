#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
		if (x < 0) putc('-'), x = -x;
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
	void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
}
const int MAXN = 4096;
int k, a[MAXN + 5], pp[MAXN + 5];
int vis[MAXN + 5], mch[MAXN + 5], mcha[MAXN + 5];
int main() {
	scanf("%d", &k); int sum = 0; srand(time(0));
	for (int i = 0; i < (1 << k); i++) scanf("%d", &a[i]), sum ^= a[i];
	if (sum) return puts("Fou"), 0; puts("Shi");
	fill1(mch); fill1(vis); fill1(mcha);
	while (1) {
		vector<int> vec, can;
		for (int i = 0; i < (1 << k); i++) if (!~mcha[i]) vec.pb(i);
		if (vec.empty()) break;
		int v = vec[rand() % vec.size()];
		bool flg = 0;
		for (int j = 0; j < (1 << k); j++) {
			if (!~vis[j ^ a[v]] && !~mch[j]) {
				vis[j ^ a[v]] = j; mch[j] = v;
				mcha[v] = j; flg = 1; break;
			}
			else if (!~mch[j]) can.pb(j);
		}
		if (!flg) {
			int x = can[rand() % can.size()];
			int pos = vis[x ^ a[v]];
			mcha[mch[pos]] = -1; mch[pos] = -1;
			vis[x ^ a[v]] = -1;
			if (~mch[x]) {
				vis[x ^ a[mch[x]]] = -1;
				mcha[mch[x]] = -1; mch[x] = -1;
			}
			vis[x ^ a[v]] = x; mch[x] = v; mcha[v] = x;
		}
	}
	for (int i = 0; i < (1 << k); i++) pp[mch[i]] = i;
//	for (int i = 0; i < (1 << k); i++) printf("%d ", mch[i]); printf("\n");
	for (int i = 0; i < (1 << k); i++) printf("%d ", pp[i]); printf("\n");
	for (int i = 0; i < (1 << k); i++) printf("%d ", pp[i] ^ a[i]); printf("\n");
	return 0;
}//