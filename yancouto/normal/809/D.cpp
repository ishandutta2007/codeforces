#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif


const int N = 612345;

int en = 1, root = 0;
int Y[N], X[N], sz[N], L[N], R[N], lz[N];

int mx(int u) { while(R[u]) u = R[u]; return u; }

// atualize os valores associados aos nos que podem ser calculados a partir dos filhos
void calc(int u) {
	sz[u] = sz[L[u]] + 1 + sz[R[u]];
}

void unlaze(int u) {
	if(!u) return;
	X[u] += lz[u];
	if(L[u]) lz[L[u]] += lz[u];
	if(R[u]) lz[R[u]] += lz[u];
	lz[u] = 0;
}

// divida a treap entre (valores <= x, valores > x)
void split_val(int u, int x, int &l, int &r) {
	unlaze(u);
	if(!u) return (void) (l = r = 0);
	if(X[u] <= x) split_val(R[u], x, l, r), R[u] = l, l = u;
	else split_val(L[u], x, l, r), L[u] = r, r = u;
	calc(u);
}

// divida a treap entre (primeiros s elementos, resto)
void split_sz(int u, int s, int &l, int &r) {
	unlaze(u);
	if(!u) return (void) (l = r = 0);
	if(sz[L[u]] < s) split_sz(R[u], s - sz[L[u]] - 1, l, r), R[u] = l, l = u;
	else split_sz(L[u], s, l, r), L[u] = r, r = u;
	calc(u);
}

// junte duas treaps, sendo que elementos l <= elementos r
int merge(int l, int r) {
	unlaze(l); unlaze(r);
	if(!l || !r) return l + r;
	int u;
	if(Y[l] > Y[r]) R[l] = merge(R[l], r), u = l;
	else L[r] = merge(l, L[r]), u = r;
	calc(u);
	return u;
}

// chame isso 1 vez no inicio. Para implicita e so nao usar o X
void init() {
	for(int i = 1; i < N; i++) Y[i] = i, sz[i] = 1;
	random_shuffle(Y, Y + N);
}

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

void deb(int u) {
	if(!u) return;
	printf("(");
	deb(L[u]);
	printf("%d[%d] ", X[u], sz[u]);
	deb(R[u]);
	printf(")");
}

int n;

int main() {
	int i, j;
	rd(n);
	int root = 0;
	init();
	for(i = 0; i < n; i++) {
		int l, r;
		rd(l); rd(r);
		int a, b, c, d = 0;
		split_val(root, l - 1, a, b);
		split_val(b, r - 1, b, c);
		if(c) split_sz(c, 1, c, d);
		if(b) lz[b]++;
		X[en] = l;
		root = merge(a, merge(en++, merge(b, d)));
	}
	printf("%d\n", sz[root]);
}