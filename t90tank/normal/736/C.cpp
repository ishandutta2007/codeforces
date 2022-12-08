#include <bits/stdc++.h>
using namespace std; 

using ll = long long; 
const ll mod = 1000000007; 

ll f[106][26][26]; 
ll g[26][26]; 
int n, k; 
vector<int> e[106]; 

void dfs(int x, int fa) {
	f[x][1][k+1] = 1; 
	f[x][0][0] = 1; 
	for (auto v : e[x]) 
		if ( v != fa ) {
			dfs( v, x ); 
			memset( g, 0, sizeof( g ) ); 
			for (int a = 0; a <= k+1; ++a) 
				for (int b = 0; b <= k+1; ++b)
					for (int c = 0; c <= k; ++c) 
						for (int d = 0; d <= k+1; ++d) 
							( g[max(c+(c!=0),a)][min(d+(d!=k+1),b)] += f[x][a][b] * f[v][c][d] ) %= mod; 
			for (int a = 0; a <= k+1; ++a) 
				for (int b = 0; b <= k+1; ++b) {
					f[x][a][b] = g[a][b]; 
				}
		}
	for (int a = 1; a <= k+1; ++a) 
		for (int b = 0; b <= k+1; ++b) 
			if (a-1+b <= k) {
				( f[x][0][b] += f[x][a][b] ) %= mod; 
				f[x][a][b] = 0; 
			}
}

int main() {
	scanf( "%d%d", &n, &k ); 
	for (int i = 1; i < n; ++i) {
		int a, b; 
		scanf( "%d%d", &a, &b ); 
		e[a].push_back( b ); 
		e[b].push_back( a ); 
	}
	memset( f, 0, sizeof( f ) ); 
	dfs( 1, 0 ); 
	ll ans = 0; 
	for (int b = 0; b <= k+1; ++b) ans = ( ans + f[1][0][b] ) % mod; 
	cout<<ans<<endl; 
}