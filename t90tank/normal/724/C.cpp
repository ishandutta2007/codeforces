#include <bits/stdc++.h>

using namespace std; 

const int maxn = 400000; 

typedef long long ll;
const ll oo = ll(1000000000)*1000000000; 
int n, m, k;
ll p[maxn]; 
ll maxt; 

ll solve(int x, int y) {
	//cout<<x<<' '<<y<<' '<<(y-x+(2*m))%(2*m)<<endl; 
	return p[((y-x)%(2*m)+(2*m))%(2*m)]+x; 
}

int main() {
	scanf( "%d%d%d", &n, &m, &k ); 
	for (int i = 0; i <= 2*m; ++i) p[i] = oo; 
	for (int i = 0; i <= 2*m; ++i) {
		p[(ll(i)*2*n)%(2*m)] = min( p[(ll(i)*2*n)%(2*m)], ll(i)*2*n ); 
		//cout<<(ll(i)*2*n)%(2*m)<<endl; 
	}
	maxt = min( min( solve(n, 0), solve(0, m) ), solve(n, m) );
	for (int i = 1; i <= k; ++i) {
		int x, y; 
		scanf( "%d%d", &x, &y ); 
		ll ans = min( min( solve(x, y), solve(2*n-x, y) ), min( solve(x, 2*m-y), solve(2*n-x, 2*m-y) ) );
		if ( ans < maxt ) printf( "%I64d\n", ans );  
		else printf( "-1\n" ); 
	}
}