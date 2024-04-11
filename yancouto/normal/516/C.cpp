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
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
const int MAX = 100009 * 2;
struct tr {
	ll bd;
	int rb; ll rd;
	int lb; ll ld;
	ll sz;
} tree[MAX << 2];
ll h[MAX], d[MAX];

tr join(tr a, tr b) {
	if(a.sz == -1) return b;
	if(b.sz == -1) return a;
	tr c;
	c.bd = max(a.bd, b.bd);
	c.bd = max(c.bd, 2ll * h[a.rb] + 2ll * h[b.lb] + a.rd + b.ld);
	c.rb = a.rb; c.rd = a.rd + b.sz;
	if(2ll * h[b.rb] + b.rd > 2ll * h[c.rb] + c.rd) { c.rb = b.rb; c.rd = b.rd; }
	c.lb = b.lb; c.ld = b.ld + a.sz;
	if(2ll * h[a.lb] + a.ld > 2ll * h[c.lb] + c.ld) { c.lb = a.lb; c.ld = a.ld; }
	c.sz = a.sz + b.sz;
	return c;
}

inline int l(int i) { return i << 1; }
inline int r(int i) { return l(i) + 1; }
void build_tree(int i, int from, int to) {
	tr &t = tree[i];
	if(from == to) {
		t.bd = -1;
		t.rb = from; t.rd = d[from];
		t.lb = from; t.ld = 0;
		t.sz = d[from];
		return;
	}
	int mid = (from + to) / 2;
	build_tree(l(i), from, mid);
	build_tree(r(i), mid + 1, to);
	t = join(tree[l(i)], tree[r(i)]);
}
tr query_tree(int i, int from, int to, int ql, int qr) {
	if(from > qr || to < ql) return {-1, -1, -1, -1, -1, -1};
	if(from >= ql && to <= qr) return tree[i];
	int mid = (from + to) / 2;
	return join(query_tree(l(i), from, mid, ql, qr),
	           query_tree(r(i), mid + 1, to, ql, qr));
}


int main() {
	int i, n, q, a, b, ql, qr;
	scanf("%d %d", &n, &q);
	for(i = 0; i < n; i++)
		scanf("%I64d", &d[i]);
	for(i = 0; i < n; i++)
		scanf("%I64d", &h[i]);
	for(i = n; i < 2 * n; i++) {
		d[i] = d[i - n];
		h[i] = h[i - n];
	}
	build_tree(1, 0, 2*n - 1);
	for(i = 0; i < q; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		if(a > b) { ql = b + 1; qr = a - 1; }
		else { ql = b + 1; qr = a - 1 + n; }
		printf("%I64d\n", query_tree(1, 0, 2*n - 1, ql, qr).bd);
	}
}