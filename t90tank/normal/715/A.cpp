#include <bits/stdc++.h>
using namespace std; 

int n; 

typedef long long ll; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) {
			if ( i == 1 ) printf( "2\n" ); 
			else {
				ll x = (i+1); 
				printf( "%I64d\n", x*x*i-(i-1) ); 
			}
	}
}