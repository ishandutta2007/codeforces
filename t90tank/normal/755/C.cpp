#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000; 

int n; 
int f[maxn]; 

int getf(int v) {
	if (v=f[v]) return v; 
	f[v] = getf(v); 
	return f[v]; 
}

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) f[i] = i; 
	for (int i = 1; i <= n; ++i) {
		int p; scanf( "%d", &p ); 
		f[getf(i)] = getf(p); 
	}
	int ans = 0; 
	for (int i = 1; i <= n; ++i) 
		if (f[i] == i) ans++; 
	cout<<ans<<endl; 
}