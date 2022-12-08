#include <bits/stdc++.h>
using namespace std; 

using ll = long long; 
ll n;  

bool check( ll n ) {
	for (ll i = 2; i * i <= n; ++i) 
		if ( n % i == 0 ) return false; 
	return true; 
}

int main() {
	cin>>n; 
	if (check( n )) cout<<"1\n"; 
	else if (n % 2 == 0) cout<<"2\n"; 
	else if (check(n - 2)) cout<<"2\n";
	else cout<<"3\n"; 
}