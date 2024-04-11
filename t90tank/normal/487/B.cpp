#include <bits/stdc++.h>
using namespace std; 

const int maxn = 200000; 

int n, s, l; 
int h1[20][maxn]; 
int h2[20][maxn]; 
int a[maxn]; 
int sum[maxn]; 
int f[maxn]; 

bool check( int l, int r ) {
	int k = int( log( r - l + 1 ) / log(2) ); 
	return max( h2[k][l], h2[k][r-(1<<k)+1] ) - min( h1[k][l], h1[k][r-(1<<k)+1] ) <= s; 
}

int main() {
	scanf( "%d%d%d", &n, &s, &l ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] ); 
	for (int i = 1; i <= n; ++i) h1[0][i] = h2[0][i] = a[i]; 
	for (int i = 1; i < 20; ++i) 
		for (int j = 1; j <= n-(1<<i)+1; ++j) {
			h1[i][j] = min( h1[i-1][j], h1[i-1][j+(1<<(i-1))] ); 
			h2[i][j] = max( h2[i-1][j], h2[i-1][j+(1<<(i-1))] ); 
		}
	for (int i = 1; i <= n; ++i) f[i] = n+1; 
	f[0] = 0; 
	deque<int> Q; 
	for (int i = 1; i <= n; ++i) { 
		if ( i - l >= 0 ) {
			while( !Q.empty() && f[i-l] <= f[Q.back()] ) Q.pop_back(); 
			Q.push_back( i-l ); 
		}
		while ( !Q.empty() && !check(Q.front()+1, i) ) Q.pop_front(); 
		if ( !Q.empty() ) f[i] = f[Q.front()] + 1; 
	}
	if ( f[n] > n ) printf( "-1\n" ); 
	else printf( "%d\n", f[n] ); 
}