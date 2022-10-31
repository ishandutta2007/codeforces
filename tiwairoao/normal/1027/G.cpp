#include <bits/stdc++.h>

typedef long long ll;

ll qmul(ll x, ll y, ll m) {
	return (x * y - (ll)((long double)x / m * y) * m + m) % m;
}
ll mpow(ll b, ll p, ll m) {
	ll r; for(r = 1; p; p >>= 1, b = qmul(b, b, m))
		if( p & 1 ) r = qmul(r, b, m);
	return r;
}

std::map<ll, ll>phi, pw;

ll p[3700]; int a[3700], c;
void divide(ll m) {
	for(int i=1;i<=c;i++) {
		while( m % p[i] == 0 ) m /= p[i];
	}
	ll sq = (ll)sqrt(m);
	for(int i=2;i<=sq;i++) if( m % i == 0 ) {
		p[++c] = i;
		while( m % i == 0 ) m /= i, a[c]++;
	}
	if( m != 1 ) p[++c] = m, a[c] = 1;
}
void dfs(int d, ll n, ll k) {
	if( d > c ) {phi[n] = k; return ;}
	
	dfs(d + 1, n, k);
	
	k *= (p[d] - 1), n *= p[d];
	for(int i=1;i<=a[d];i++,n*=p[d],k*=p[d])
		dfs(d + 1, n, k);
}

ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
int main() {
	ll m, x; scanf("%lld%lld", &m, &x);
	divide(m), dfs(1, 1, 1);
	
	int c1 = c;
	for(int i=1;i<=c1;i++)
		divide(p[i] - 1);
	
	ll ans = 0;
	for(auto it = phi.rbegin(); it != phi.rend(); it++) {
		ll s = it->first, t = it->second, k = t;
		for(int i=1;i<=c1;i++) if( s <= m / p[i] && phi.count(s * p[i]) )
			k = gcd(k, phi[s * p[i]]);
		
		for(int i=1;i<=c;i++) {
			while( k % p[i] == 0 ) {
				if( !pw.count(k / p[i]) ) pw[k / p[i]] = mpow(x, k / p[i], m);
				
				if( pw[k / p[i]] % s == 1 ) k /= p[i];
				else break;
			}
		}
		
		ans += t / k, phi[it->first] = k;
	}
	printf("%lld\n", ans);
}