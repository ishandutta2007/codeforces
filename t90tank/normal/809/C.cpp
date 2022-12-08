#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
const ll mod = (ll)1e9+7; 

ll f[40][2][2][2]; 
ll g[40][2][2][2]; 

ll getbit(ll x, ll k) {
	return (x>>k)&1; 
}

void ud(ll &x, ll y) {
	(x += y) %= mod; 
}

ll solve(ll x, ll y, ll k) {
	if (x == 0 || y == 0) return 0; 
	//cout<<x<<' '<<y<<' '<<k<<endl; 
	x--; y--; k--; 
	memset(f, 0, sizeof(f)); 
	memset(g, 0, sizeof(g)); 
	x++; y++; k++; 
	f[0][0][0][0] = 1; 
	g[0][0][0][0] = 0; 
	for (ll i = 1; i <= 31; ++i) {
		for (ll xi = 0; xi <= 1; ++xi) 
		for (ll yi = 0; yi <= 1; ++yi) 
		for (ll ki = 0; ki <= 1; ++ki) {
			for (ll tx = 0; tx <= 1; ++tx) 
				if (xi*2+tx <= 2+getbit(x,i-1)) 
					for (ll ty = 0; ty <= 1; ++ty) 
						if (yi*2+ty <= 2+getbit(y,i-1)) {
							ll tk = (tx^ty); 
							if (ki*2+tk <= 2+getbit(k,i-1)) {
								int xj = (xi*2+tx == 2+getbit(x,i-1)); 
								int yj = (yi*2+ty == 2+getbit(y,i-1)); 
								int kj = (ki*2+tk == 2+getbit(k,i-1)); 
								ud( f[i][xi][yi][ki], f[i-1][xj][yj][kj] ); 
								ud( g[i][xi][yi][ki], g[i-1][xj][yj][kj]+f[i-1][xj][yj][kj]*((tk<<(i-1)) % mod) ); 
							}
						}
					
			//if (i<=4) {
				//printf( "f[%lld][%lld][%lld][%lld]=%lld\n", i,xi,yi,ki,f[i][xi][yi][ki] ); 
				//printf( "g[%lld][%lld][%lld][%lld]=%lld\n", i,xi,yi,ki,g[i][xi][yi][ki] ); 
			//}
		}
	}
	//cout<<x<<' '<<y<<' '<<k<<' '<<(g[31][1][1][1] + f[31][1][1][1]) % mod<<endl;
	return (g[31][1][1][1] + f[31][1][1][1]) % mod; 
}

int q;
ll X1, Y1, X2, Y2, k; 

int main() {
	//cout<<solve(2,4,5)<<endl; 
	scanf( "%d", &q ); 
	for (int i = 1; i <= q; ++i) {
		scanf( "%lld%lld%lld%lld%lld", &X1, &Y1, &X2, &Y2, &k ); 
		ll ans = solve(X2,Y2,k) - solve(X1-1,Y2,k) - solve(X2,Y1-1,k) + solve(X1-1,Y1-1,k); 
		cout<<(ans%mod+mod) % mod<<endl; 
	}
	return 0;
	
}