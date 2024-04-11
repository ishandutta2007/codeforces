#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
using pii = pair<int,int>;
#define pb push_back
#define fir first
#define sec second
const ll oo = 0x3f3f3f3f3f3f3f3f; 

ll n, k; 
vector<ll> q; 
int a[200]; 

int main() {
	cin>>n>>k; 
	for (int i = 1; i <= n; ++i) {
		scanf( "%d", &a[i] ); 
		k += a[i]; 
		a[i]--; 
		if (a[i] > 0) {
			for (int j = 1; ; j = a[i]/(a[i]/(j+1))) {
				q.pb(j); 
				if (j==a[i]) break; 
			}
		}
	}
	q.pb(k);
	sort(q.begin(), q.end()); 
	q.erase(unique(q.begin(),q.end()),q.end()); 
	ll ans = 0; ll pre = 0; 
	for (auto i : q) {
		ll x = 0; 
		for (int j = 1; j <= n; ++j) x += a[j] / i+1; 
		if (k / x > pre) ans = max(ans, min(i, k / x)); 
		pre = i; 
	}
	cout<<ans<<endl; 
}