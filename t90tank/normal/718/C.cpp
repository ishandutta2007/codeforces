#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
const ll mod = 1000000007; 
const int maxn = 200000; 

struct data {
	ll mat[2][2]; 
	data operator*(const data &b) {
		data c{};
		for (int k = 0; k < 2; ++k) 
			for (int i = 0; i < 2; ++i) 
				for (int j = 0; j < 2; ++j) 
					c.mat[i][j] = ( c.mat[i][j] + mat[i][k] * b.mat[k][j] ) % mod; 
		return c; 
	}
	data operator+(const data &b) {
		data c{};
		for (int i = 0; i < 2; ++i) 
			for (int j = 0; j < 2; ++j) 
				c.mat[i][j] = ( mat[i][j] + b.mat[i][j] ) % mod; 
		return c; 
	}
}; 

struct node {
	data sum, add;
}tree[maxn*3]; 

int n, m;
int a[maxn]; 
data E = { { {1,0}, {0,1} } }; 
data Fi = { { {0,1}, {1,1} } }; 

data getmul( int k ) {
	if ( k == 0 ) return E; 
	data ret = getmul( k / 2 ); 
	ret = ret * ret; 
	if ( k % 2 == 1 ) ret = ret * Fi; 
	return ret; 
}

void Update( int T ) {
	tree[T].sum = tree[T*2].sum * tree[T*2].add + tree[T*2+1].sum * tree[T*2+1].add; 
}

void ReFresh( int T ) {
	tree[T*2].add = tree[T*2].add * tree[T].add; 
	tree[T*2+1].add = tree[T*2+1].add * tree[T].add; 
	tree[T].sum = tree[T].sum * tree[T].add; 
	tree[T].add = E; 
}

void Build(int T, int l, int r) {
	tree[T].add = E; 
	if ( l == r ) {
		tree[T].sum = getmul( a[l] ); 
		return; 
	}
	int m = ( l + r ) / 2; 
	Build( T*2, l, m ); 
	Build( T*2+1, m+1, r ); 
	Update( T ); 
}

void Relax( int T, int l, int r, int a, int b, data x ) {
	if ( a <= l && b >= r ) {
		tree[T].add = tree[T].add * x; 
		return; 
	}
	int m = ( l + r ) / 2; 
	ReFresh( T ); 
	if ( a <= m ) Relax( T*2, l, m, a, b, x ); 
	if ( b > m ) Relax( T*2+1, m+1, r, a, b, x ); 
	Update( T ); 
}

data Count( int T, int l, int r, int a, int b ) {
	if ( a <= l && b >= r ) return tree[T].sum * tree[T].add; 
	int m = ( l + r ) / 2; 
	ReFresh( T ); 
	data ans{}; 
	if ( a <= m ) ans = ans + Count( T*2, l, m, a, b ); 
	if ( b > m ) ans = ans + Count( T*2+1, m+1, r, a, b ); 
	return ans; 
}

int main() {
	int n, m; 
	scanf( "%d%d", &n, &m ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] ); 
	Build( 1, 1, n ); 
	for (int i = 1; i <= m; ++i) {
		int tp; 
		int l, r, x; 
		scanf( "%d", &tp ); 
		if ( tp == 1 ) {
			scanf( "%d%d%d", &l, &r, &x ); 
			Relax( 1, 1, n, l, r, getmul(x) ); 
		}
		else {
			scanf( "%d%d", &l, &r ); 
			printf( "%I64d\n", Count( 1, 1, n, l, r ).mat[1][0] ); 
		}
	}
}