#include <bits/stdc++.h>
using namespace std; 

using ll = long long; 

ll c, hr, hb, wr, wb; 

ll gcd( ll a, ll b ) {
	return __gcd( a,b ); 
}

int main() {
	//again
	cin>>c>>hr>>hb>>wr>>wb; 
	if ( wr < wb ) {
		swap( hr, hb ); 
		swap( wr, wb ); 
	}
	ll lcm = wr * wb / gcd( wr, wb ); 
	ll g = max( lcm / wr * hr , lcm / wb * hb ); 
	ll d = c / lcm; 
	if ( d > 3 ) d -= 3; 
	else d = 0; 
	c -= d * lcm;
	ll ans = 0; 
	for (ll i = 0; i <= c; i += wr) 
		ans = max( ans, i / wr * hr + ( c - i ) / wb * hb );  
	cout<<ans+d*g<<endl;
}