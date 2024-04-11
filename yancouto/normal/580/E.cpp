#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

inline int l(int i) { return i << 1; }
inline int r(int i) { return l(i) + 1; }
const int MAX = 100009;
char d[MAX];
ll tree[MAX << 2], lazy[MAX << 2];
ll pot[MAX];

ll join(ll a, ll b, int from, int mid, int to) {
	return mod(a + b * mod(pot[mid - from + 1] - pot[mid - from] + modn));
}

void build_tree(int i, int from, int to) {
	lazy[i] = 0;
	if(from == to) {
		tree[i] = d[from];
		return;
	}
	int mid = (from + to) / 2;
	build_tree(l(i), from, mid);
	build_tree(r(i), mid + 1, to);
	tree[i] = join(tree[l(i)], tree[r(i)], from, mid, to);
}

void unlaze(int i, int from, int to) {
	if(!lazy[i]) return;
	tree[i] = mod(pot[to - from] * lazy[i]);
	if(from != to)
		lazy[l(i)] = lazy[r(i)] = lazy[i];
	lazy[i] = 0;
}

void set_tree(int i, int from, int to, int ql, int qr, int c) {
	unlaze(i, from, to);
	if(qr < from || ql > to) return;
	if(from >= ql && to <= qr) {
		lazy[i] = c;
		unlaze(i, from, to);
		return;
	}
	int mid = (from + to) / 2;
	set_tree(l(i), from, mid, ql, qr, c);
	set_tree(r(i), mid + 1, to, ql, qr, c);
	tree[i] = join(tree[l(i)], tree[r(i)], from, mid, to);
}

ll query_tree(int i, int from, int to, int ql, int qr) {
	unlaze(i, from, to);
	if(qr < from || ql > to) return 0;
	if(from >= ql && to <= qr) return tree[i];
	int mid = (from + to) / 2;
	return join(query_tree(l(i), from, mid, ql, qr), query_tree(r(i), mid + 1, to, ql, qr), from, mid, to);
}

void pre() {
	pot[0] = 1ll;
	for(int i = 1; i < MAX; i++)
		pot[i] = mod(pot[i - 1] * 263ll);
	for(int i = 1; i < MAX; i++)
		pot[i] = mod(pot[i] + pot[i - 1]);
}

int main() {
	pre();
	int i, n, m, k, op, l, r, c;
	scanf("%d %d %d", &n, &m, &k);
	for(i = 0; i < n; i++)
		scanf(" %c", &d[i]);
	build_tree(1, 0, n - 1);
	for(i = 0; i < m + k; i++) {
		scanf("%d %d %d %d", &op, &l, &r, &c);
		if(op == 1)
			set_tree(1, 0, n - 1, l - 1, r - 1, c + '0');
		else {
			if(r - l + 1 <= c) { puts("YES"); continue; }
			ll a = query_tree(1, 0, n - 1, l - 1, r - 1 - c);
			ll b = query_tree(1, 0, n - 1, l - 1 + c, r - 1);
			a = mod(a * (pot[c] - pot[c - 1] + modn));
			if(a == b) puts("YES");
			else puts("NO");
		}
	}
}