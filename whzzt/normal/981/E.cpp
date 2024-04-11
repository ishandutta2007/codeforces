#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> PI;
typedef vector <int> VI;

namespace io {
	const int L = (1 << 21) + 1;
	char ibuf[L], *iS, *iT, obuf[L], *oS = obuf, *oT = obuf + L - 1, c, qu[55]; int f, qr;
#ifdef whzzt
	#define gc() getchar()
#else
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, L, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
#endif
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout); oS = obuf; }
	inline void putc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	template <class I>
	inline void gi (I & x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0', x /= 10;
		while (qr) putc (qu[qr --]);
	}
	struct IOC { ~ IOC () { flush (); } } _ioc_;
};
using io :: gi;
using io :: putc;
using io :: print;

const int N = 10005, P = 998244353, Q = 1e9 + 7, R = 1e9 + 9;

int n, q, f1[N], f2[N], f3[N];
vector <int> e[N][2], lis;
bool ok[N];

int main () {
	int i, j, l, r, x;
	scanf ("%d%d", &n, &q);
	for (i = 1; i <= q; i ++) {
		scanf ("%d%d%d", &l, &r, &x);
		e[l][0].pb (x), e[r + 1][1].pb (x);
	}
	f1[0] = f2[0] = f3[0] = 1;
	for (i = 1; i <= n; i ++) {
		for (int v : e[i][0]) {
			for (j = n; j >= v; j --) {
				(f1[j] += f1[j - v]) < P ? : f1[j] -= P;
				(f2[j] += f2[j - v]) < Q ? : f2[j] -= Q;
				(f2[j] += f3[j - v]) < R ? : f3[j] -= R;
			}
		}
		for (int v : e[i][1]) {
			for (j = v; j <= n; j ++) {
				(f1[j] -= f1[j - v]) >= 0 ? : f1[j] += P;
				(f2[j] -= f2[j - v]) >= 0 ? : f2[j] += Q;
				(f2[j] -= f3[j - v]) >= 0 ? : f3[j] += R;
			}
		}
		for (j = 1; j <= n; j ++) ok[j] |= f1[j] > 0 || f2[j] > 0 || f3[j] > 0;
	}
	for (i = 1; i <= n; i ++) if (ok[i]) lis.pb (i);
	printf ("%u\n", (unsigned)lis.size());
	for (int v : lis) printf ("%d ", v);
	return 0;
}