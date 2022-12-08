#include <bits/stdc++.h>
using namespace std;

const int maxn = 300000; 
struct node {
	int mind, add; 
}; 

node e[maxn*4]; 

void refresh(int T) {
	e[T].mind = min( e[T*2].mind+e[T*2].add, e[T*2+1].mind+e[T*2+1].add ); 
}

void relax(int T) {
	e[T].mind += e[T].add; 
	e[T*2].add += e[T].add; 
	e[T*2+1].add += e[T].add; 
	e[T].add = 0; 
}

void build(int T, int l, int r) {
	if (l == r) {
		e[T].mind = 0; 
		e[T].add = 0; 
		return; 
	}
	int m = (l+r)/2; 
	build(T*2, l, m); 
	build(T*2+1, m+1, r);
	refresh( T );  
}

void update(int T, int l, int r, int a, int b, int d) {
	if (a <= l && b >= r) {
		e[T].add += d; 
		return; 
	}
	int m = (l+r)/2; 
	relax( T ); 
	if (a <= m) update(T*2,l,m,a,b,d); 
	if (b > m) update(T*2+1,m+1,r,a,b,d); 
	refresh( T ); 
}

int findZero(int T, int l, int r) {
	if (l == r) return l; 
	int m = (l+r)/2; 
	relax(T); 
	if (e[T*2+1].mind+e[T*2+1].add <= 0) return findZero(T*2+1,m+1,r); 
	return findZero(T*2,l,m); 
}

int n; 
int ans[maxn]; 

int main() {
	scanf( "%d", &n ); 
	build(1, 1, n+1); 
	update(1,1,n+1,1,n+1,1); 
	for (int i = 1; i <= n; ++i) {
		int p, t, x; 
		scanf( "%d%d", &p, &t ); 
		if (t == 0) update(1,1,n+1,1,p,1); 
		else {
			scanf( "%d", &x ); 
			ans[p] = x; 
			update(1,1,n+1,1,p,-1); 
		}
		if (e[1].mind+e[1].add <= 0) printf( "%d\n", ans[findZero(1,1,n+1)] ); 
		else printf( "-1\n" ); 
	}
}