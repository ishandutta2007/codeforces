#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000;  

int c[maxn]; 
int a[maxn]; 
int b[maxn]; 
int d[maxn]; 

int n; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i < n; ++i) scanf( "%d%d", &a[i], &b[i] ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &c[i] ); 
	int s = 0; 
	for (int i = 1; i < n; ++i) 
		if (c[a[i]] != c[b[i]]) {
			d[a[i]]++; 
			d[b[i]]++;
			s++;  
		}
	int x = 0; 
	for (int i = 1; i <= n; ++i)
		if (d[i] == s) x = i; 
	if (x == 0) printf( "NO\n" ); 
	else printf( "YES\n%d\n", x ); 
}