#include <bits/stdc++.h>
using namespace std; 

const int maxn = 2000000;
using ll = long long;  

int n, q, b;
int a[maxn]; 
int g[maxn];
int d[maxn]; 
ll t[maxn]; 
ll S;  

int main() {
	scanf( "%d", &n ); 
	scanf( "%d", &q );
	S = 0;  
	t[0] = 0; 
	for (int i = 1; i <= n; ++i) { 
		scanf( "%d", &a[i] ); 
		t[i] = t[i-1] + a[i]; 
		S += a[i]; 
	}
	while ( q-- ) {
		scanf( "%d", &b ); 
		if ( b >= S ) { printf( "1\n" ); continue; }
		int j = 1;
		ll sum = a[1]; 
		while ( j < n && sum + a[j+1] <= b ) {
			++j; 
			sum += a[j]; 
		}
		int tj = j; 
		g[1] = j+1; 
		//cout<<"j="<<j<<endl; 
		for (int i = 2; i <= n; ++i) {
			sum -= a[i-1]; 
			while ( j < n && sum + a[j+1] <= b ) {
				++j; 
				sum += a[j]; 
			}
			g[i] = j+1; 
		}
		int dep = 0, x = 1; 
		while ( x != n+1 ) {
			dep++; 
			x = g[x]; 
		}
		for (int i = n; i >= 1; --i) {
			if ( g[i] == n+1  ) {
				d[i] = 0; 
				g[i] = i; 
			}
			else {
				d[i] = d[g[i]] + 1; 
				g[i] = g[g[i]]; 
			}
		}
		bool flag = false; 
		bool u = false; 
		//printf( "g[1]=%d\n", g[1] ); 
		for (int i = 2; i <= tj+1; ++i) {
		//	printf( "g[%d]=%d,d[%d]=%d\n", i, g[i], i, d[i] ); 
			if ( d[i] < dep - 1 && ( t[n] - t[g[i]-1] + t[i-1] - t[0] <= b ) ) flag = true;   
		}
		if ( flag ) printf( "%d\n", dep-1 ); 
		else printf( "%d\n", dep ); 
	}
}