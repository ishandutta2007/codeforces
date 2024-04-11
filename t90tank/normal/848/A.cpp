#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 200000; 
const ll oo = 0x3f3f3f3f; 

int n; 
ll f[maxn]; 
ll a[maxn]; 
ll g[maxn]; 

int main() {
	cin>>n; 
	if (n == 0) {
		puts( "a" ); 
		return 0; 
	}
	int m = 0; 
	for (ll i = 2; i*(i-1)/2 <= n; ++i) 
		a[++m] = i*(i-1)/2; 
	fill(f, f+n+1, oo); 
	f[0] = 0; 
	for (ll i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) 
			if (i >= a[j] && f[i-a[j]] + 1 < f[i]) {
				f[i] = f[i-a[j]] + 1; 
				g[i] = j; 
			}
			
	int x = n; 
	char c = 'a'; 
	while (x != 0) {
		for (int i = 1; i <= g[x]+1; ++i) printf( "%c", c ); 
		c++; 
		x -= a[g[x]]; 
	}
	
	puts( "" ); 
	return 0;
}