#include <bits/stdc++.h>
using namespace std;

using ll = long long;  

int n; 
int a[200000]; 
bool v[200000]; 

bool dfs(int dep, ll s) {
	if ( dep == n ) return true; 
	v[s] = false; 
	for (int i = dep; i < n; ++i) {
		swap( a[dep], a[i] ); 
		if (v[s*a[dep] % n]) 
			if (dfs(dep+1, s*a[dep]%n)) return true; 
		swap( a[dep], a[i] ); 
	}
	v[s] = true; 
	return false; 
}

ll getmul( ll a, ll k ) {
	if ( k == 0 ) return 1; 
	ll ret = getmul( a, k/2 ); 
	ret = ( ret * ret ) % n; 
	if ( k % 2 == 1 ) ret = ( ret * a ) % n; 
	return ret; 
}

int main() {
	cin>>n; 
	if ( n == 4 ) {
		printf( "YES\n1\n3\n2\n4\n" ); 
	}
	else if ( n == 1 ) {
		printf( "YES\n1\n" ); 
	}
	else {
		bool flag = true; 
		for (int i = 2; i < n; ++i) 
			if ( n % i == 0 ) {
				flag = false; 
				break; 
			}
		if ( flag ) {/*
			memset( v, true, sizeof( v ) ); 
			for (int i = 1; i <= n; ++i) a[i] = i; 
			v[0] = false; 
			if ( dfs( 2, 1 ) ) {
				for (int i = 1; i <= n; ++i) printf( "%d ", a[i] );
				printf( "\n" ); 
			}
			else printf( "NO\n" ); 
		}
		else printf( "NO\n" ); */
			printf( "YES\n" ); 
			printf( "1\n" ); 
			for (int i = 2; i < n; ++i) {
				printf( "%d\n", int(getmul(i-1, n-2) * i % n) ); 
			}
			printf( "%d\n", n ); 
		}
		else printf( "NO\n" ); 
	}
}