#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
#ifndef ONLINE_JUDGE
#	define debug(args...) {fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");}
#else
#	define debug(args...) {}
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
const int MAX = 100009;
int n;
int tree[26][MAX << 2];
int lazy[26][MAX << 2];
char str[MAX];

inline int l(int i) { return i << 1; }
inline int r(int i) { return (i << 1) + 1; }

int build_tree(int ind, int i, int from, int to) {
	int &t = tree[ind][i];
	if(from == to) {
		t = ((str[from] - 'a') == ind);
		return t;
	}
	int mid = (from + to) / 2;
	t = 
		build_tree(ind, l(i), from, mid) +
		build_tree(ind, r(i), mid + 1, to);
	return t;
}

void unlaze(int ind, int i, int from, int to) {
	if(!lazy[ind][i]) return;
	tree[ind][i] = (lazy[ind][i] - 1) * (to - from + 1);
	if(from != to) {
		lazy[ind][l(i)] = lazy[ind][i];
		lazy[ind][r(i)] = lazy[ind][i];
	}
	lazy[ind][i] = 0;
}

int query_tree(int ind, int i, int from, int to, int ql, int qr) {
	unlaze(ind, i, from, to);
	if(qr < from || ql > to) return 0;
	if(from >= ql && to <= qr) return tree[ind][i];	
	int mid = (from + to) / 2;
	return query_tree(ind, l(i), from, mid, ql, qr) +
		query_tree(ind, r(i), mid + 1, to, ql, qr);
}

void set_tree(int ind, int i, int from, int to, int ql, int qr, int val) {
	unlaze(ind, i, from, to);
	if(qr < from || ql > to) return;
	if(from >= ql && to <= qr) {
		lazy[ind][i] = val + 1;
		unlaze(ind, i, from, to);
		return;
	}
	int mid = (from + to) / 2;
	set_tree(ind, l(i), from, mid, ql, qr, val);
	set_tree(ind, r(i), mid + 1, to, ql, qr, val);
	tree[ind][i] = tree[ind][l(i)] + tree[ind][r(i)];
}

int main() {
	int i, j, s, e, inc, q;
	scanf("%d %d %s", &n, &q, str);
	for(i = 0; i < 26; i++)
		build_tree(i, 1, 0, n - 1);
	for(i = 0; i < q; i++) {
		scanf("%d %d %d", &s, &e, &inc); s--; e--;
		int ind = s;
		if(inc) {
			for(j = 0; j < 26; j++) {
				int res = query_tree(j, 1, 0, n - 1, s, e);
				set_tree(j, 1, 0, n - 1, s, e, 0);
				if(res)
					set_tree(j, 1, 0, n - 1, ind, ind + res - 1, 1);
				ind += res;
			}
		} else {
			for(j = 25; j >= 0; j--) {
				int res = query_tree(j, 1, 0, n - 1, s, e);
				set_tree(j, 1, 0, n - 1, s, e, 0);
				if(res)
					set_tree(j, 1, 0, n - 1, ind, ind + res - 1, 1);
				ind += res;
			}
		}
	}
	for(i = 0; i < 26; i++)
		for(j = 0; j < n; j++)
			if(query_tree(i, 1, 0, n - 1, j, j))
				str[j] = 'a' + i;
	printf("%s\n", str);
	return 0;
}