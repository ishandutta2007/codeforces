#include <bits/stdc++.h>
using namespace std; 

using ll = long long; 
ll n; 
ll f[10000]; 

int main() {
	f[1] = 2; 
	f[2] = 3; 
	cin>>n; 
	if ( n == 2 ) printf( "1\n" ); 
	else if ( n == 3 ) printf( "2\n" ); 
	else {
		for (int i = 3; i < 10000; ++i) {
			f[i] = f[i-1] + f[i-2]; 
			if ( f[i] > n ) {
				cout<<i-1<<endl; 
				break; 
			}
		}
	}
}