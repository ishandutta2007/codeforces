#include <bits/stdc++.h>

using namespace std; 
int a00,a01,a10,a11; 
int a0, a1; 

int main() {
	scanf( "%d%d%d%d", &a00, &a01, &a10, &a11 ); 
	if ( a00 + a01 + a10 + a11 == 0 ) {
		printf( "0\n" ); 
		return 0; 
	}
	if ( a00 == 0 ) {
		if ( a01 + a10 > 0 ) a0 = 1; 
		else a0 = 0; 
	}
	else {
		for ( a0 = 1; a0 * (a0-1) / 2 < a00; ++a0 ); 
		if ( a0 * (a0-1) / 2 != a00 ) {
			printf( "Impossible\n" ); 
			return 0; 
		}
	}
	if ( a11 == 0 ) {
		if ( a01 + a10 > 0 ) a1 = 1; 
		else a1 = 0; 
	}
	else {
		for ( a1 = 1; a1 * (a1-1) / 2 < a11; ++a1 ); 
		if ( a1 * (a1-1) / 2 != a11 ) {
			printf( "Impossible\n" ); 
			return 0; 
		}
	}
	if ( a01 + a10 != a0 * a1 ) {
		printf( "Impossible\n" ); 
		return 0; 
	}
	if ( a1 == 0 ) {
		for (int i = 1; i <= a0; ++i) printf( "0" ); 
		printf( "\n" ); 
		return 0; 
	}
	for (int i = 1; i <= a01 / a1; ++i) {
		printf( "0" ); 
		a0--; 
	}
	for (int i = 1; i <= a1 - a01 % a1; ++i) printf( "1" ); 
	if ( a0 > 0 ) { printf( "0" ); a0--; }
	for (int i = 1; i <= a01 % a1; ++i) printf( "1" ); 
	for (int i = 1; i <= a0; ++i) printf( "0" ); 
	printf( "\n" ); 
}