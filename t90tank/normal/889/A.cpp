#include <bits/stdc++.h>
using namespace std; 

const int maxn = 300006; 

bool v[maxn]; 
int n; 

int main() {
	memset(v, false, sizeof(v)); 
	int ans = 1; 
	v[0] = true; 
	cin>>n; 
	for (int i = 1; i <= n; ++i) {
		int t; 
		scanf( "%d", &t ); 
		if (v[t]) v[t] = false; 
		else ans++; 
		v[i] = true; 
	}
	cout<<ans<<endl; 
}