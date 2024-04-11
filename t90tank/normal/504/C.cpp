#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std; 

typedef long long ll; 

int n; 
int a[1000000]; 
int c[1000000]; 

int main() 
{
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] ); 
	int x = 0; 
	while ( x < (n+1)/2 && a[x+1] == a[n-x] ) x++; 
	if ( x == (n+1)/2 ) { cout<<ll(n)*(n+1)/2<<endl; return 0; } 
	int s = x+1, e = n-s+1; 
	memset( c, 0, sizeof( c ) ); 
	for (int i = s; i <= e; ++i) c[a[i]]++; 
	int tot = 0; 
	for (int i = 1; i <= n; ++i)
		if ( c[i] % 2 == 1 ) tot++;  
	if ( n % 2 != tot ) 
	{ printf( "0\n" ); return 0; }
	ll ans = 0; 
	int buf = e+1; 
	for (int i = e; i >= s; --i) 
	{
		buf = i; 
		if ( i > n-i+1 ) {
			c[a[i]] -= 2; 
			if ( c[a[i]] < 0 ) break; 
		}
		else if ( i == n-i+1 ) {
			c[a[i]]--; 
			if ( c[a[i]] < 0 ) break; 
		}
		else if ( a[i] != a[n-i+1] ) break; 
	}
	ans += max( 0, e-buf ) * ll(s);  
//	cout<<buf<<' '<<ans<<endl; 
	memset( c, 0, sizeof( c ) ); 
	for (int i = s; i <= e; ++i) c[a[i]]++; 
	buf = s-1; 
	for (int i = s; i <= e; ++i) 
	{
		buf = i; 
		if ( i < n-i+1 ) {
			c[a[i]] -= 2; 
			if ( c[a[i]] < 0 ) break; 
		}
		else if ( i == n-i+1 ) {
			c[a[i]]--; 
			if ( c[a[i]] < 0 ) break; 
		}
		else if ( a[i] != a[n-i+1] ) break; 
	}
	ans += max( 0, buf-s ) * ll(s); 
	if ( n % 2 == tot) ans += ll(s) * s; 
	cout<<ans<<endl; 	
}