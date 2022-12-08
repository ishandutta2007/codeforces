#include <bits/stdc++.h>
using namespace std; 

const int maxn = 1000007; 
const int maxm = 10000007; 
using ll = long long; 
const ll mod = 1000000007; 

int n, m; 
int g; 
int c[maxm], t[maxm], h[maxm]; 
int tot; 
int ut; 
ll ii[maxm]; 

void change(const vector<int> &a) {
	ut++; 
	//for (auto x : a) printf( "%d ", x); 
	//printf( "\n" ); 
	for (auto x : a) 
		if (t[c[x]] == ut) c[x] = h[c[x]]; 
		else {
			t[c[x]] = ut; 
			h[c[x]] = ++tot; 
			c[x] = h[c[x]]; 
		}
	//for (auto x : a) printf( "%d ", c[x]); 
	//printf( "\n" ); 
}

int main() {
	scanf( "%d%d", &n, &m ); 
	tot = 0; ut = 0; 
	memset(c, 0, sizeof(c) ); 
	memset(h, 0, sizeof(h) ); 
	for (int i = 1; i <= n; ++i) {
		map<int,int> S; 
		scanf( "%d", &g ); 
		for (int j = 1; j <= g; ++j) {
			int x; 
			scanf( "%d", &x ); 
			S[x]++; 
		}
		map<int,vector<int>> U; 
		for (auto p : S) 
			U[p.second].push_back( p.first ); 
		for (auto p : U) change( p.second ); 
	}
	map<int,int> S; 
	ii[0] = 1; 
	for (int i = 1; i <= m; ++i) ii[i] = ii[i-1] * i % mod; 
	for (int i = 1; i <= m; ++i) S[c[i]]++;
	ll ans = 1; 
	for (auto p : S) ans = ans * ii[p.second] % mod; 
	cout<<ans<<endl; 
}