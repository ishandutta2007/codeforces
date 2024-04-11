#include <bits/stdc++.h>

typedef long long ll;
const int N = 105;

ll n,a;
ll x[N], ans;
std::queue < ll > aria;

inline ll read () {
	ll s = 0 , w = 1;
	char ch = getchar ();
	while ( ch > '9' || ch < '0' ) { if ( ch == '-' ) w = -1; ch = getchar ();}
	while ( ch >= '0' && ch <= '9' ) { s = s * 10 + ch - '0'; ch = getchar ();}
	return s * w;
}
ll gcd(ll a,ll b) {
	if ( a == 0 )
		return b;
	if ( a > b )
		return gcd ( b , a );
	return gcd ( b % a , a );
}
ll multi ( ll a , ll b , ll p ) {
	ll ans = 0;
	while ( b ) {
		if(b & 1LL)
			ans = (ans+a)%p;
		a = ( a + a ) % p;
		b >>= 1;
	}
	return ans;
}
ll qpow ( ll a , ll b , ll p ) {
	ll ans = 1;
	while ( b ) {
		if ( b & 1LL )	
			ans = multi ( ans , a , p);
		a = multi ( a , a , p );
		b >>= 1;
	}
	return ans;
}
 
int MR ( ll n ) {
	if(n == 2)
		return true;
	int s = 20, i, t = 0;
	ll u = n-1;
	while ( ! ( u & 1 ) ) {
		t++;
		u >>= 1;
	}
	while ( s-- ) {
		ll a = rand() % ( n - 2) + 2;
		x[0] = qpow(a, u, n);
		for(i = 1; i <= t; i++){
			x[i] = multi ( x[i - 1], x[i - 1], n );
			if ( x[i] == 1 && x[i - 1] != 1 && x[i - 1] != n - 1 )
				return false;	
		}
		if(x[t] != 1)
			return false;
	}
	return true;	
}
ll Pollard_Rho ( ll n , int c ) {
	ll i = 1, k = 2, x = rand()%(n-1)+1, y = x;
	while ( 1 ) {
		i++;
		x = ( multi ( x , x , n ) + c ) % n;
		ll p = gcd ( ( y - x + n ) % n , n );
		if ( p != 1 && p != n )
			return p;
		if ( y == x )
			return n;
		if ( i == k ) {
			y = x;
			k <<= 1;
		}	
	}
}
 
void find ( ll n , int c ) {
	if ( n == 1 )
		return;
	if ( MR ( n ) ) {
		aria.push ( n ) ;
		return;
	}
	ll p = n, k = c;
	while ( p >= n ) 
		p = Pollard_Rho ( p, c-- );
	find ( p , k );
	find ( n / p , k );
	return;
}
int main ( void ) {
	n = read ();
	a=-1;
	for(int i=1;i<=n;i++) {
		ll x,y;
		x = read () , y = read ();
		if ( a == -1 )
			a = x * y;
		else a = gcd ( a , x * y );
	}
	if(a==1) {
		puts ("-1");
		return 0;
	}
	find(a,107);
	printf("%I64d\n",aria.front());
	return 0;
}