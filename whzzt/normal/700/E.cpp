#include <bits/stdc++.h>

using namespace std;

const int N = 200005, M = 20, SIGMA = 26, inf = 0x7FFFFFFF;

int _getchar (){
	char c;
	for (c = getchar(); c < 'a' || c > 'z'; c = getchar());
	return c - 'a' + 1;
}

namespace SA {
	int n, m, rk[N], sa[N], x[N], y[N], w[N], st[M][N], lg2[N];
	int rmq (int x, int y) {
		int d = lg2[y - x + 1];
		return min (st[d][x], st[d][y - (1 << d) + 1]);
	}
	int lcp (int x, int y) {
		if (x == y) return n - x + 1;
		if (rk[x] > rk[y]) swap (x, y);
		return rmq (rk[x], rk[y] - 1);
	}
	void build (int s[N], int len) {
		m = SIGMA, n = len;
		memcpy (rk + 1, s + 1, n << 2);
		for (int l = 1; l <= n; l <<= 1) {
			memset (x, 0, m + 1 << 2);
			for (int i = 1; i <= n; i ++) x[w[i] = i <= n - l ? rk[i + l] : 0] ++;
			for (int i = 1; i <= m; i ++) x[i] += x[i - 1];
			for (int i = n; i >= 1; i --) y[x[w[i]]--] = i;
			
			memset (x, 0, m + 1 << 2);
			for (int i = 1; i <= n; i ++) x[rk[i]] ++;
			for (int i = 1; i <= m; i ++) x[i] += x[i - 1];
			for (int i = n; i >= 1; i --) sa[x[rk[y[i]]] --] = y[i];
			
			y[sa[1]] = m = 1;
			for (int i = 2; i <= n; i ++)
				y[sa[i]] = rk[sa[i]] == rk[sa[i-1]] && w[sa[i]] == w[sa[i-1]] ? m : ++ m;
			memcpy (rk + 1, y + 1, n << 2);
			
			if (m == n) break;
		}
		for (int i = 2; i <= n; i ++) lg2[i] = lg2[i - 1] + !(i & i - 1);
		for (int i = 1, j = 0; i <= n; i ++, j -= !!j) {
			while (s[i + j] == s[sa[rk[i]+1] + j]) j ++;
			st[0][rk[i]] = j;
		}
		for (int l = 2, i = 1; l <= n; l <<= 1, i ++) {
			for (int j = 1; j <= n - l + 1; j ++) {
				st[i][j] = min (st[i - 1][j], st[i - 1][j + (l >> 1)]);
			}
		}
	}
	int findl (int p, int w) {
	//	cerr << "L " << p << ' ' << w << " = ";
		int l = 1, r = rk[p], mid = (l + r) >> 1;
		while (l < r) {
			if (lcp (sa[mid], p) >= w)
				r = mid;
			else
				l = mid + 1;
			mid = (l + r) >> 1;
		}
	//	cerr << mid << endl;
		return mid;
	}
	int findr (int p, int w) {
	//	cerr << "R " << p << ' ' << w << " = ";
		int l = rk[p], r = n, mid = (l + r + 1) >> 1;
		while (l < r) {
			if (lcp (sa[mid], p) >= w)
				l = mid;
			else
				r = mid - 1;
			mid = (l + r + 1) >> 1;
		}
	//	cerr << mid << endl;
		return mid;
	}
} ;
using SA :: rk;
using SA :: findl;
using SA :: findr;

namespace ST1 {
	int tag[N << 2], *c;
	int comp (int x, int y) {
		if (!x || !y) return x | y;
		return c[x] < c[y] ? y : x;
	}
	void cover (int x, int l, int r, int s, int t, int u) {
		if (l == s && r == t) {tag[x] = comp (tag[x], u); return;}
		int ls = x << 1, rs = ls | 1, mid = (l + r) >> 1;
		if (t <= mid) cover (ls, l, mid, s, t, u);
		else if (s > mid) cover (rs, mid + 1, r, s, t, u);
		else cover (ls, l, mid, s, mid, u), cover (rs, mid + 1, r, mid + 1, t, u);
	}
	int check (int x, int l, int r, int p) {
		if (l == r) return tag[x];
		int ls = x << 1, rs = ls | 1, mid = (l + r) >> 1;
		if (p <= mid) return comp (tag[x], check (ls, l, mid, p));
		return comp (tag[x], check (rs, mid + 1, r, p));
	}
} ;

namespace ST2 {
	int minv[N << 2];
	void build (int x, int l, int r) {
		minv[x] = inf; if (l == r) return ;
		int ls = x << 1, rs = ls | 1, mid = (l + r) >> 1;
		build (ls, l, mid), build (rs, mid + 1, r);
	}
	void modify (int x, int l, int r, int p, int u) {
		if (l == r) {minv[x] = u; return ;}
		int ls = x << 1, rs = ls | 1, mid = (l + r) >> 1;
		if (p <= mid) modify (ls, l, mid, p, u);
		else modify (rs, mid + 1, r, p, u);
		minv[x] = min(minv[ls], minv[rs]);
	}
	int check (int x, int l, int r, int s, int t) {
		if (l == s && r == t) return minv[x];
		int ls = x << 1, rs = ls | 1, mid = (l + r) >> 1;
		if (t <= mid) return check (ls, l, mid, s, t);
		if (s > mid) return check (rs, mid + 1, r, s, t);
		return min (check (ls, l, mid, s, mid), check (rs, mid + 1, r, mid + 1, t));
	}
} ;

int n, str[N], dep[N], ans, len[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) str[i] = _getchar();
	SA :: build (str, n);
	ST2 :: build (1, 1, n);
	ST1 :: c = dep;
	for (int i = n; i >= 1; i --) {
		int f = ST1 :: check (1, 1, n, rk[i]);
		if (f) {
			dep[i] = dep[f] + 1;
			len[i] = len[f] + ST2 :: check (1, 1, n, findl(i, len[f]), findr(i, len[f])) - i;
		} else dep[i] = len[i] = 1;
		ST2 :: modify (1, 1, n, rk[i], i);
	//	cerr << i << ' ' << findl(i, len[i]) << ' ' << findr(i, len[i]) << endl;
		ST1 :: cover (1, 1, n, findl(i, len[i]), findr(i, len[i]), i);
		ans = max (ans, dep[i]);
	//	cerr << i << ' ' << dep[i] << ' ' << len[i] << endl; 
	}
	printf ("%d\n", ans);
	return 0;
}