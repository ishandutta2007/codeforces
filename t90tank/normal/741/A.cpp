#include <bits/stdc++.h>
using namespace std; 

using ll = long long; 

int n;
bool v[200];  
int a[200]; 

int main() {
	scanf( "%d", &n ); 
	memset(v, false, sizeof(v)); 
	bool flag = false; 
	for (int i = 1; i <= n; ++i) {
		scanf( "%d", &a[i] ); 
		if (v[a[i]]) flag = true; 
		v[a[i]] = true; 
	}
	if (flag) {
		cout<<-1<<endl; 
		return 0; 
	}
	ll ans = 2; 
	for (int i = 1; i <= n; ++i) 
		if (v[i]) {
			int s = 1; 
			v[i] = false;
			int x; 
			for (x=i; a[x]!=i; x=a[x],s++)
				v[x] = false; 
			v[x] = false; 
			ll r = __gcd(ans,(ll)s); 
			ans = ans/r*s; 
		}
	cout<<ans/2<<endl; 
}