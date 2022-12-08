#include <bits/stdc++.h>
using namespace std; 

const int maxn = 300000; 

int n, m, k;
int c[maxn]; 
map<int,int> S; 
vector<int> e[maxn];
int sum;  
bool v[maxn]; 

void dfs(int x) {
	v[x] = false;
	S[c[x]]++;  
	sum++; 
	for (auto i : e[x]) 
		if ( v[i] ) dfs( i ); 
}

int main() {
	scanf( "%d%d%d", &n, &m, &k ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &c[i] ); 
	for (int i = 1; i <= m; ++i) {
		int a, b; 
		scanf( "%d%d", &a, &b ); 
		e[a].push_back( b ); 
		e[b].push_back( a ); 
	}
	memset( v, true, sizeof( v ) ); 
	int ans = 0; 
	for (int i = 1; i <= n; ++i) 
		if ( v[i] ) {
			sum = 0; 
			S.clear(); 
			dfs( i ); 
			int t = 0; 
			for (auto j : S) t = max( t, j.second ); 
			ans += sum - t; 
		}
	printf( "%d\n", ans ); 
}