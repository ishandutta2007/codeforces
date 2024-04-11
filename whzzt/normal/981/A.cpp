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

const int N = 55;
char s[N];
int n, m;

int main () {
	int i, j;
	scanf ("%s", s + 1);
	n = strlen (s + 1);
	for (m = n; m >= 1; m --) {
		for (i = 1; i + m - 1 <= n; i ++) {
			bool flag = true;
			for (j = 1; j <= m; j ++) {
				if (s[i + j - 1] != s[i + (m - j + 1) - 1]) {
					flag = false;
					break;
				}
			}
			if (!flag) goto next;
		}
	}
	next : ;
	printf ("%d\n", m);
	return 0;
}