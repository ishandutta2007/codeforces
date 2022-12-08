#include <bits/stdc++.h>
using namespace std; 

const int maxn = 30; 

int a[maxn][maxn]; 
int b[maxn][maxn]; 
int p[maxn]; 
int n, m; 

bool check() {
	//for (int i = 1; i <= m; ++i) printf( "%d\n", p[i] ); 
	for (int i = 1; i <= n; ++i) {
		int sum = 0; 
		for (int j = 1; j <= m; ++j) 
			if ( a[i][j] != p[j] ) ++sum; 
		if ( sum > 2 ) return false; 
	}
	return true; 
}

int main() {
	scanf( "%d%d", &n, &m ); 
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) scanf( "%d", &a[i][j] );
	for (int i = 1; i <= m; ++i) p[i] = i; 
	bool ans = check(); 
	for (int i = 1; i < m; ++i) 
		for (int j = i+1; j <= m; ++j) {
			swap( p[i], p[j] ); 
			ans = (ans | check() ); 
			swap( p[i], p[j] ); 
		}
	if ( ans ) printf( "YES\n" ); 
	else printf( "NO\n" ); 
}