#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

const int maxn = 3006; 

int n; 
int a[maxn]; 
int b[maxn]; 
ll f[maxn][maxn]; 
vector<pair<int,int>> S; 

ll Dist( int x, int y ) {
	ll tmp = S[x].first - S[y].first; 
	return max( tmp, -tmp ); 
}

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) 
	{ scanf( "%d", &a[i] ); a[i] -= i; S.push_back(make_pair(a[i],i)); }
	sort( S.begin(), S.end() ); 
	for (int i = 0; i < n; ++i) b[S[i].second] = i; 
	for (int i = 0; i < n; ++i) f[1][i] = Dist(i,b[1]); 
	for (int i = 2; i <= n; ++i) {
		ll best = f[i-1][0]; 
		for (int j = 0; j < n; ++j) { 
			best = min( best, f[i-1][j] ); 
			f[i][j] = best + Dist(j,b[i]); 
		}
	}
	ll best = f[n][0]; 
	for (int i = 1; i < n; ++i) best = min( best, f[n][i] ); 
	cout<<best<<endl; 
}