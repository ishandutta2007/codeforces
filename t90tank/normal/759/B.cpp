#include <bits/stdc++.h>
using namespace std;

const int maxn = 300000; 

int a, b; 
int n; 
int t[maxn]; 
int f[maxn]; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &t[i] ); 
	f[0] = 0; 
	t[0] = -10000; 
	a = 0; b = 0; 
	for (int i = 1; i <= n; ++i) {
		while (t[a+1]+90 <= t[i]) a++; 
		while (t[b+1]+1440 <= t[i]) b++;  
		f[i] = min(f[i-1]+20, f[a]+50); 
		f[i] = min(f[i], f[b]+120);  
		printf( "%d\n", f[i]-f[i-1] ); 
	}
}