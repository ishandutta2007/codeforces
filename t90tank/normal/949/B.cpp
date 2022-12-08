#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
using pii = pair<int,int>;
#define pb push_back
#define fir first
#define sec second

ll n; 

ll solve(ll x) {
	if (x & 1) return x / 2 + 1; 
	return solve(x+n-x/2); 
}

int main() {
	int q; 
	cin>>n>>q; 
	while (q--) {
		ll x; 
		scanf( "%lld", &x ); 
		printf( "%lld\n", solve(x)); 
	}
}