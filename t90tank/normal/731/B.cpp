#include <bits/stdc++.h>
using namespace std; 

int n,a;

int main() {
	scanf( "%d", &n ); 
	int g = 0; 
	bool flag = true; 
	for (int i = 1; i <= n; ++i) {
		scanf( "%d", &a ); 
		if ( a == 0 && g > 0 ) {
			flag = false; 
			break; 
		}
		g = ( a + g ) % 2; 
	}
	if ( g > 0 ) flag = false; 
	if ( flag ) printf( "YES\n" ); 
	else printf( "NO\n" ); 
}