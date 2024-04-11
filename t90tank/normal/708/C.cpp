#include <bits/stdc++.h>

using namespace std; 

const int maxn = 1000000; 

int n,o; 
vector<int> e[maxn]; 
int s[maxn]; 
int ans[maxn]; 

void dfs( int x, int f ) {
	s[x] = 1; 
	for (auto i : e[x]) 
		if ( i != f ) {
			dfs( i, x ); 
			s[x] += s[i]; 
		}
}

void Find( int x, int f ) {
	bool flag = true; 
	for (auto i : e[x]) 
		if ( i != f && s[i] * 2 > n ) {
			Find( i, x ); 
			flag = false; 
		}
	if ( flag ) o = x; 
}

void solve( int x, int f, int c ) {
	if ( (n - s[x] - c) * 2 > n ) ans[x] = 0; 
	else ans[x] = 1; 
	for (auto i : e[x]) 
		if ( i != f ) solve( i, x, c ); 
}

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i < n; ++i) {
		int u, v; 
		scanf( "%d%d", &u, &v ); 
		e[u].push_back( v ); 
		e[v].push_back( u ); 
	}
	dfs( 1, 0 ); 
	Find( 1, 0 );
	dfs( o, 0 ); 
	int a = 0, b = 0; 
	ans[o] = 1; 
	for (auto i : e[o]) {
		if ( s[i] > a ) { b = a; a = s[i]; }
		else if ( s[i] > b ) b = s[i];  
	}
	for (auto i : e[o]) {
		if ( s[i] * 2 == n ) solve( i, o, n / 2 ); 
		else if ( s[i] == a ) solve( i, o, b ); 
		else solve( i, o, a ); 
	}
	for (int i = 1; i < n; ++i) printf( "%d ", ans[i] ); 
	printf( "%d\n", ans[n] ); 
}