#include <bits/stdc++.h>
using namespace std; 

const int maxn = 200000; 
typedef long long ll; 
const ll maxp = 1000000007; 

int n, m; 
struct data {
	int adj, p, p_; 
}; 
vector<data> e[maxn]; 
bool v[maxn]; 
ll f[maxn][2][2][2]; 
int con[maxn][2]; 

void dfs( int x ) {
	v[x] = false;  
	bool flag = false; 
	for (auto y : e[x])  
		if (v[y.adj]) {
			dfs( y.adj ); 
			flag = true; 
			for (int i = 0; i < 2; ++i) 
			for (int j = 0; j < 2; ++j) 
			for (int k = 0; k < 2; ++k) 
			for (int l = 0; l < 2; ++l) 
				( f[x][i][k][l^((y.p^i)|(y.p_^j))^con[x][i]] += f[y.adj][j][k][l] ) %= maxp; 
		}
	if ( !flag ) {
//		cout<<"haha\n"<<endl; 
		f[x][1][1][con[x][1]] = 1; 
		f[x][0][0][con[x][0]] = 1; 
	}
}

int ind[maxn]; 

int main() {
	scanf( "%d%d", &m, &n ); 
	memset( ind, 0, sizeof( ind ) ); 
	for (int i = 1; i <= m; ++i) {
		int k; 
		scanf( "%d", &k ); 
		int a, b; 
		if ( k == 1 ) {
			scanf( "%d", &a ); 
			if ( a < 0 ) con[-a][0] ^= 1; 
			else con[a][1] ^= 1; 
		}
		else {
			scanf( "%d%d", &a, &b ); 
			int p1 = 0, p2 = 0; 
			if ( a < 0 ) { p1 = 1; a = -a; }
			if ( b < 0 ) { p2 = 1; b = -b; } 
			e[a].push_back( {b,p1,p2} ); 
			e[b].push_back( {a,p2,p1} );
			ind[a]++; ind[b]++;
		} 
	}
	memset( v, true, sizeof( v ) ); 
	memset( f, 0, sizeof( f ) ); 
	ll ans[2], tmp[2]; 
	ans[0] = 1; 
	ans[1] = 0;
	int ab = 3;  
	for (int i = 1; i <= n; ++i) 
		if ( v[i] && (ind[i] == 1 || ind[i] == 0) ) {
			dfs( i ); 
			tmp[0] = ans[0]; tmp[1] = ans[1]; 
			ans[0] = 0; ans[1] = 0; 
			for (int p1 = 0; p1 < 2; ++p1) 
				for (int p2 = 0; p2 < 2; ++p2) 
					for (int u = 0; u < 2; ++u) 
						for (int v = 0; v < 2; ++v) 
							( ans[p1^p2] += tmp[p1] * f[i][u][v][p2] ) %= maxp; 
		}
	for (int i = 1; i <= n; ++i) 
		if ( v[i] ) {
			dfs( i ); 
			tmp[0] = ans[0]; tmp[1] = ans[1]; 
			ans[0] = 0; ans[1] = 0; 
			int p = e[i][1].p, p_ = e[i][1].p_; 
			for (int p1 = 0; p1 < 2; ++p1) 
				for (int p2 = 0; p2 < 2; ++p2) 
					for (int u = 0; u < 2; ++u) 
						for (int v = 0; v < 2; ++v) {
							( ans[p1^p2^((u^p)|(v^p_))] += tmp[p1] * f[i][u][v][p2] ) %= maxp; 
						}
		}
	cout<<ans[1]<<endl; 
}