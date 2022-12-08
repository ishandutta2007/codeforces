#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

ll x, y, p, q; 

int main() {
	int t; 
	cin>>t;
	while (t--) {
		cin>>x>>y>>p>>q; 
		ll r = __gcd(p, q); 
		p /= r; q /= r; 
		ll l = 0; 
		r = 0x3f3f3f3f3f3f3f3fll / q; 
		while (l + 1 < r) {
			ll m = (l+r) / 2; 
			if (m * q < y || m * p < x || m * (q-p) < y-x) l = m; 
			else r = m; 
			//cout<<l<<' '<<r<<endl; 
		}
		if (r == 0x3f3f3f3f3f3f3f3fll / q) cout<<-1<<endl; 
		else cout<<r*q-y<<endl; 
	}
	return 0;
}