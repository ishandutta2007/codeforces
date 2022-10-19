#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int MXNode = N * 45;

// think twice,code once

typedef unsigned long long ull; // 

int ch[MXNode][2], sz, rt[N]; // rt 
ull h[MXNode], R[N];
#define lc(x) ch[x][0]
#define rc(x) ch[x][1]

int n, q, A[N], u, v, l, r, fir[N], ne[N * 2], to[N * 2], cnt = 1;

void add(int x, int y) {
	ne[++ cnt] = fir[x];
	fir[x] = cnt;
	to[cnt] = y;
}

void link(int x, int y) {
	add(x, y);
	add(y, x);
}

#define Foreachson(i, x) for(int i = fir[x]; i; i = ne[i])

ull RAND() {
	return 1ull * rand() * ((ull)RAND_MAX + 1) + rand();
}

ull Rand() {
	ull now = RAND_MAX + 1;
	if(now == 32768) {
		return (ull)RAND() * 32768ull * 32768ull + (ull)RAND();
	} else {
		return (ull)RAND();
	}
}

int st[N][20], dep[N]; //dep 

int newnode(int x) {
	++ sz;
	lc(sz) = lc(x);
	rc(sz) = rc(x);
	h[sz] = h[x];
	return sz;
}

void add(int &x, int y, int l, int r, int who, ull it) {
	x = newnode(y);
	h[x] ^= it;
	if(l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	if(who <= mid) 
	add(lc(x), lc(y), l, mid, who, it);
	else add(rc(x), rc(y), mid + 1, r, who, it);
}

void dfs(int x, int f) {
	st[x][0] = f;
	for(int i = 1; i < 20; ++ i)
	st[x][i] = st[st[x][i - 1]][i - 1];
	dep[x] = dep[f] + 1;
	add(rt[x], rt[f], 1, n, A[x], R[A[x]]);
//	cerr << x <<' ' << A[x] << ' ' << f <<' ' << h[rt[x]] << endl;
	Foreachson(i, x) {
		int V = to[i];
		if(V == f) continue;
		dfs(V, x);
	} 
}

int LCA(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 19; i >= 0; -- i)
	if(dep[st[u][i]] >= dep[v])
	u = st[u][i];
	if(u == v) return u;
	for(int i = 19; i >= 0; -- i)
	if(st[u][i] != st[v][i])
	u = st[u][i], v = st[v][i];
	return st[u][0];
}

int getans(int u, int v, int L, int R, int l, int r) {
	if(l > r) return -1;
//	cerr << u << ' ' << v <<' ' << h[u] <<' ' << h[v] << ' ' << L <<' ' << R <<' ' << l <<' ' << r << endl;
	if(h[u] == h[v]) return -1;
	int mid = (L + R) >> 1;
	if(L == R) {
//		cerr << L <<' ' << R << endl;
		return L;
	}
	if(r <= mid) return getans(lc(u), lc(v), L, mid, l, r);
	else if(l > mid) return getans(rc(u), rc(v), mid + 1, R, l, r);
	else {
		int now = getans(lc(u), lc(v), L, mid, l, mid);
		if(now != -1) return now;
		return getans(rc(u), rc(v), mid + 1, R, mid + 1, r);
	}
}

int main() {
	cin >> n >> q;
	
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &A[i]); R[i] = Rand();
	}
	
	for (int i = 1; i < n; ++ i) {
		scanf("%d%d", &u, &v);
		link(u, v);
	}
	
	dfs(1, 0);
	
	for( ; q --;) {
		scanf("%d%d%d%d", &u, &v, &l, &r);
		int lca = LCA(u, v);
		
		if(A[lca] < l || A[lca] > r) {
			int h = getans(rt[u], rt[v], 1, n, l, r);
			printf("%d\n", h);
		} else {
//			cerr << "HERE" << endl;
			int h1 = getans(rt[u], rt[v], 1, n, l, A[lca] - 1), h2 = getans(rt[u], rt[v], 1, n, A[lca] + 1, r),
			h3 = getans(rt[u], rt[v], 1, n, A[lca], A[lca]);
			if(h1 != -1) {
				printf("%d\n", h1);
			} else if(h2 != -1) {
				printf("%d\n", h2);
			} else if(h3 == -1) {
				printf("%d\n", A[lca]);
			} else puts("-1");
		}
	}
}