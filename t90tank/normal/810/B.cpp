#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back

const int maxn = 200006; 

ll a[maxn]; 
int n, f; 

int main() {
	cin>>n>>f; 
	ll ans = 0; 
	for (int i = 0; i < n; ++i) {
		int k, l; 
		scanf( "%d%d", &k, &l ); 
		ll x = min(k, l); 
		ll y = min(2*k, l); 
		ans += x; 
		a[i] = y-x; 
	}
	sort(a, a+n); 
	reverse(a, a+n); 
	for (int i = 0; i < f; ++i) ans += a[i]; 
	cout<<ans<<endl; 
	return 0;
}