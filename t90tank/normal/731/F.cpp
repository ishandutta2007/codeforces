#include <bits/stdc++.h>
using namespace std; 

const int maxn = 550000; 

typedef long long ll; 

int n; 
int a[maxn]; 
ll s[maxn]; 
bool v[maxn]; 

int main() {
	scanf( "%d", &n );
	memset( v, false, sizeof( v ) );
	for (int i = 1; i <= n; ++i) {
		scanf( "%d", &a[i] ); 
		 v[a[i]] = true; 
		 s[a[i]]++; 
	}
	for (int i = 1; i <= 530000; ++i) s[i] += s[i-1]; 
	ll ans = 0; 
	for (ll i = 1; i <= 210000; ++i) 
		if ( v[i] ) {
			ll tmp = 0; 
			for (int j = i; j <= 250000; j += i) {
				tmp += ( s[j+i-1] - s[j-1] ) * j; 
			}
			ans = max( ans, tmp ); 
		}
	cout<<ans<<endl; 
}