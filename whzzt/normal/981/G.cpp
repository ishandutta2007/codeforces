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

const int N = 800005, P = 998244353;

namespace DS {
	int add[N], mul[N], sum[N];
	void inc (int u, int l, int r, int v) {
		add[u] = (add[u] + v) % P;
		sum[u] = (sum[u] + (ll)(r - l + 1) * v) % P;
	}
	void mult (int u, int l, int r, int v) {
		mul[u] = (ll)mul[u] * v % P;
		add[u] = (ll)add[u] * v % P;
		sum[u] = (ll)sum[u] * v % P;
	}
	void pushdown (int u, int l, int r) {
		int ls = u << 1, rs = ls | 1, mid = (l + r) >> 1;
		if (mul[u] != 1) {
			mult (ls, l, mid, mul[u]);
			mult (rs, mid + 1, r, mul[u]);
			mul[u] = 1;
		}
		if (add[u]) {
			inc (ls, l, mid, add[u]);
			inc (rs, mid + 1, r, add[u]);
			add[u] = 0;
		}
	}
	void build (int u, int l, int r) {
		mul[u] = 1;
		if (l == r) return ;
		int ls = u << 1, rs = ls | 1, mid = (l + r) >> 1;
		build (ls, l, mid), build (rs, mid + 1, r);
	}
	void update (int u, int l, int r, int s, int t, int a, int b) {
		if (l == s && r == t) {
			mult (u, l, r, a), inc (u, l, r, b);
			return ;
		}
		pushdown (u, l, r);
		int ls = u << 1, rs = ls | 1, mid = (l + r) >> 1;
		if (t <= mid) update (ls, l, mid, s, t, a, b);
		else if (s > mid) update (rs, mid + 1, r, s, t, a, b);
		else update (ls, l, mid, s, mid, a, b), update (rs, mid + 1, r, mid + 1, t, a, b);
		sum[u] = (sum[ls] + sum[rs]) % P;
	}
	int query (int u, int l, int r, int s, int t) {
		if (l == s && r == t) return sum[u];
		pushdown (u, l, r);
		int ls = u << 1, rs = ls | 1, mid = (l + r) >> 1;
		if (t <= mid) return query (ls, l, mid, s, t);
		if (s > mid) return query (rs, mid + 1, r, s, t);
		return (query (ls, l, mid, s, mid) + query (rs, mid + 1, r, mid + 1, t)) % P;
	}
}

int n, q;
set <PI> odt[N];

void make (int x, int p) {
	auto it = odt[x].upper_bound (PI (p, N));
	if (it != odt[x].begin()) {
		-- it;
		if (it -> se > p) {
			int a = it -> fi, b = it -> se;
			odt[x].erase (it);
			odt[x].insert (PI (a, p));
			odt[x].insert (PI (p + 1, b));
		}
	}
}

int main () {
	int i, op, l, r, x;
	scanf ("%d%d", &n, &q);
	DS :: build (1, 1, n);
	for (i = 1; i <= q; i ++) {
		scanf ("%d%d%d", &op, &l, &r);
		if (op == 1) {
			scanf ("%d", &x);
			make (x, l - 1), make (x, r);
			auto beg = odt[x].lower_bound (PI (l, 0));
			vector <PI> ers;
			int low = l;
			while (beg != odt[x].end() && beg -> se <= r) {
				ers.pb (*beg);
				if (low < beg -> fi) DS :: update (1, 1, n, low, beg -> fi - 1, 1, 1);
				DS :: update (1, 1, n, beg -> fi, beg -> se, 2, 0);
				low = beg -> se + 1;
				++beg;
			}
			if (low <= r) DS :: update (1, 1, n, low, r, 1, 1);
			for (auto &t : ers) odt[x].erase (t);
			odt[x].insert (PI (l, r));
		} else {
			printf ("%d\n", DS :: query (1, 1, n, l, r));
		}
	}
	return 0;
}