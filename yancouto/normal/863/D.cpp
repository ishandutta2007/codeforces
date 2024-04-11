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
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

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

const int N = 212345;
typedef int num;

int en = 1;
int Y[N], sz[N], L[N], R[N];
int swp[N];
num X[N];

// atualize os valores associados aos nos que podem ser calculados a partir dos filhos
void calc(int u) {
	sz[u] = sz[L[u]] + 1 + sz[R[u]];
}

void unlaze(int u) {
	if(!u) return;
	// Faca seus lazy aqui
	if(swp[u]) {
		swap(L[u], R[u]);
		if(L[u]) swp[L[u]] = !swp[L[u]];
		if(R[u]) swp[R[u]] = !swp[R[u]];
		swp[u] = 0;
	}
}

// divida a treap entre (valores <= x, valores > x)
void split_val(int u, num x, int &l, int &r) {
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
	assert(l != r);
	unlaze(l); unlaze(r);
	if(!l || !r) return l + r;
	int u;
	if(Y[l] > Y[r]) R[l] = merge(R[l], r), u = l;
	else L[r] = merge(l, L[r]), u = r;
	calc(u);
	return u;
}

// chame isso 1 vez no inicio. Para implicita e so nao usar o X
void init(int n=N-1) {
	en = 1;
	for(int i = 1; i <= n; i++) Y[i] = i, sz[i] = 1, L[i] = R[i] = 0;
	random_shuffle(Y + 1, Y + n + 1);
}

void deb(int u) {
	if(!u) return;
	if(swp[u]) {
		deb(R[u]);
		printf("%d ", X[u]);
		deb(L[u]);
	} else {
		deb(L[u]);
		printf("%d ", X[u]);
		deb(R[u]);
	}
}

int main() {
	int i, j;
	int n, m, q;
	rd(n); rd(q); rd(m);
	init(n);
	int root = 0;
	for(i = 0; i < n; i++) {
		rd(X[en]);
		root = merge(root, en++);
	}
	for(i = 0; i < q; i++) {
		int t, l, r;
		rd(t); rd(l); rd(r);
		int a, b, c;
		split_sz(root, l - 1, a, b);
		split_sz(b, r - l + 1, b, c);
		if(t == 1) {
			int b1, b2;
			split_sz(b, r - l, b1, b2);
			b = merge(b2, b1);
		} else {
			swp[b] = 1;
			unlaze(b);
		}
		root = merge(merge(a, b), c);
	}
	for(i = 0; i < m; i++) {
		rd(j);
		int a, b, c;
		split_sz(root, j, b, c);
		split_sz(b, j - 1, a, b);
		printf("%d ", X[b]);
		root = merge(merge(a, b), c);
	}
	putchar('\n');
}