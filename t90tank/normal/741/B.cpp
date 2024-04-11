#include <bits/stdc++.h>
using namespace std; 

using ll = long long; 

const int maxn = 2000; 

int f[2][maxn]; 
int t; 
int n,m,W;  
vector<int> e[maxn]; 
bool v[maxn]; 
int sw, sb; 
int w[maxn], b[maxn]; 

void dfs(int x) {
	for (int i = 0; i <= W-w[x]; ++i) 
		f[t][i+w[x]] = max(f[t][i+w[x]], f[1-t][i]+b[x]); 
	v[x] = true; 
	for (auto i : e[x]) 
		if (!v[i]) dfs(i); 
	sw += w[x]; 
	sb += b[x]; 
}

int main() {
	scanf( "%d%d%d", &n,&m,&W ); 
	memset( v, false, sizeof(v) ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &w[i] ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &b[i] ); 
	for (int i = 1; i <= m; ++i) {
		int x, y; 
		scanf( "%d%d", &x,&y ); 
		e[x].push_back( y ); 
		e[y].push_back( x ); 
	}
	memset( f, 0, sizeof(f) ); 
	t = 0; 
	for (int i = 1; i <= n; ++i) 
		if (!v[i]) {
			t = 1-t; 
			for (int j = 0; j <= W; ++j) f[t][j] = f[1-t][j]; 
			sw = sb = 0; 
			dfs( i ); 
			for (int j = 0; j <= W-sw; ++j) 
				f[t][j+sw] = max(f[t][j+sw], f[1-t][j]+sb); 
		}
	cout<<f[t][W]<<endl; 
}