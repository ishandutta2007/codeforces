#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000; 

int main() {
	int n; 
	scanf( "%d", &n ); 
	printf( "YES\n" ); 
	for (int i = 1; i <= n; ++i) {
		int x, y; 
		scanf( "%d%d%d%d", &x,&y,&x,&y ); 
		printf( "%d\n", (x%2+2)%2*2+(y%2+2)%2+1 );  
	}
}