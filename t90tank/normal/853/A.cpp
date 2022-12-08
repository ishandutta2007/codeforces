#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second
const int maxn = 400000; 

int c[maxn]; 
int n, k; 
ll ans; 
int t[maxn]; 
multiset<pair<int,int>> S; 

int main() {
	scanf( "%d%d", &n, &k ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &c[i] ); 
	for (int i = 1; i <= min(n,k); ++i) S.insert({c[i], i}); 
	for (int i = k+1; i <= k+n; ++i) {
		if (i <= n) S.insert({c[i], i}); 
		auto u = prev(S.end()); 
		t[u->sec] = i; 
		S.erase(u); 
	}
	ans = 0; 
	for (int i = 1; i <= n; ++i) ans += ll(t[i]-i) * c[i]; 
	cout<<ans<<endl;
	for (int i = 1; i <= n; ++i) printf( "%d ", t[i] ); 
	puts( "" );  
	return 0;
}