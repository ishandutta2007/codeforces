#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back

const ll mod = (ll)1e9+7; 

int n; 
int a[500000]; 
ll a2[500000]; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] ); 
	sort(a+1, a+n+1); 
	a2[0] = 1; 
	for (int i = 1; i <= n; ++i) a2[i] = a2[i-1] * 2 % mod; 
	ll ans = 0; 
	for (int i = 1; i <= n; ++i) 
		(ans += (a2[i-1]-a2[n-i]) * a[i]) %= mod; 
	cout<<ans<<endl; 
	return 0;
}