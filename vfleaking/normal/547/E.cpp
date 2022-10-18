#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxSN = 200000;
const int MaxSL = 200000;

namespace SA {
	const int MaxN = MaxSN + MaxSL;
	const int NLetter = 256;
	
	int n;
	char s[MaxN + 1];
	
	int sa[MaxN];
	int rank[MaxN];
	int height[MaxN];
	
	inline bool sa_init_equal(int *y, int k, int i, int j) {
		return y[i] == y[j]
				&& (i + k < n ? y[i + k] : -1) == (j + k < n ? y[j + k] : -1);
	}
	
	void sa_init() {
		int *x = rank, *y = height;
		static int w[MaxN];
		fill(w, w + NLetter, 0);
		for (int i = 0; i < n; i++)
			w[s[i]]++;
		for (int i = 1; i < NLetter; i++)
			w[i] += w[i - 1];
		for (int i = n - 1; i >= 0; i--)
			sa[--w[s[i]]] = i;
	
		int nR = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0 || s[sa[i]] != s[sa[i - 1]])
				nR++;
			y[sa[i]] = nR - 1;
		}
		for (int k = 1; nR < n; k <<= 1, swap(x, y)) {
			int len = 0;
			for (int i = n - k; i < n; i++)
				x[len++] = i;
			for (int i = 0; i < n; i++)
				if (sa[i] >= k)
					x[len++] = sa[i] - k;
			fill(w, w + nR, 0);
			for (int i = 0; i < n; i++)
				w[y[x[i]]]++;
			for (int i = 1; i < nR; i++)
				w[i] += w[i - 1];
			for (int i = n - 1; i >= 0; i--)
				sa[--w[y[x[i]]]] = x[i];
	
			nR = 0;
			for (int i = 0; i < n; i++) {
				if (i == 0 || !sa_init_equal(y, k, sa[i], sa[i - 1]))
					nR++;
				x[sa[i]] = nR - 1;
			}
		}
	
		if (y != rank)
			copy(y, y + n, rank);
	
		for (int i = 0, j = 0; i < n; i++) {
			if (j > 0)
				j--;
			if (rank[i] + 1 == n)
				continue;
			int p = sa[rank[i] + 1];
			while (i + j < n && p + j < n && s[i + j] == s[p + j])
				j++;
			height[rank[i]] = j;
		}
	}
}

struct node {
	long long sum;
	node *lc, *rc;
};

inline node *seg_insert(node *p, int pL, int pR, int v, int d) {
	node *np = new node;
	if (p) {
		*np = *p;
	} else {
		np->sum = 0;
		np->lc = np->rc = NULL;
	}
	np->sum += d;
	
	if (pL == pR) {
		return np;
	}
	
	int pM = (pL + pR) / 2;
	if (v <= pM) {
		np->lc = seg_insert(np->lc, pL, pM, v, d);
	} else {
		np->rc = seg_insert(np->rc, pM + 1, pR, v, d);
	}
	return np;
}
inline long long seg_query(node *p, int pL, int pR, int qL, int qR) {
	if (!p) {
		return 0;
	}
	if (qL <= pL && pR <= qR) {
		return p->sum;
	}
	
	int pM = (pL + pR) / 2;
	long long res = 0;
	if (qL <= pM) {
		res += seg_query(p->lc, pL, pM, qL, qR);
	}
	if (pM < qR) {
		res += seg_query(p->rc, pM + 1, pR, qL, qR);
	}
	return res;
}

int main() {
	int n, nQ;
	static int sl[MaxSN];
	static int bel[SA::MaxN];
	
	cin >> n >> nQ;
	for (int i = 0; i < n; i++) {
		scanf("%s", SA::s + SA::n);
		int l = strlen(SA::s + SA::n);
		sl[i] = l;
		for (int k = 0; k < l; k++) {
			bel[SA::n + k] = i;
		}
		
		SA::n += l;
		
		bel[SA::n] = -1;
		SA::s[SA::n++] = '$';
	}
	
	SA::sa_init();
	
	static int pos[MaxSN];
	for (int i = 0; i < SA::n; i++) {
		int p = SA::sa[i];
		if (bel[p] != -1 && (p == 0 || bel[p - 1] == -1)) {
			pos[bel[p]] = i;
		}
	}
	
	static int posl[MaxSN], posr[MaxSN];
	
	int q_n;
	static int q[SA::MaxN];
	
	q_n = 0;
	for (int i = 0; i < SA::n; i++) {
		int p = bel[SA::sa[i]];
		if (p != -1 && pos[p] == i) {
			int le = 0, ri = q_n;
			while (le != ri) {
				int mi = (le + ri) / 2;
				if (SA::height[q[mi]] < sl[p]) {
					le = mi + 1;
				} else {
					ri = mi;
				}
			}
			posl[p] = le == 0 ? 0 : q[le - 1] + 1;
		}

		while (q_n > 0 && SA::height[q[q_n - 1]] >= SA::height[i]) {
			q_n--;
		}
		q[q_n++] = i;
	}
	
	q_n = 0;
	for (int i = SA::n - 1; i >= 0; i--) {
		while (q_n > 0 && SA::height[q[q_n - 1]] >= SA::height[i]) {
			q_n--;
		}
		q[q_n++] = i;

		int p = bel[SA::sa[i]];
		if (p != -1 && pos[p] == i) {
			int le = 0, ri = q_n;
			while (le != ri) {
				int mi = (le + ri) / 2;
				if (SA::height[q[mi]] < sl[p]) {
					le = mi + 1;
				} else {
					ri = mi;
				}
			}
			posr[p] = le == 0 ? SA::n - 1 : q[le - 1];
		}
	}
	
	static node *seg[SA::MaxN + 1];
	for (int i = 0; i < SA::n; i++)
		seg[i + 1] = bel[SA::sa[i]] == -1 ? seg[i] : seg_insert(seg[i], 0, n - 1, bel[SA::sa[i]], 1);
	
	while (nQ--) {
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		l--, r--, k--;
		
		long long res = seg_query(seg[posr[k] + 1], 0, n - 1, l, r) - seg_query(seg[posl[k]], 0, n - 1, l, r);
		cout << res << endl;
	}
	
	return 0;
}