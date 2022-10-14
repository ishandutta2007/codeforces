#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
#define vt vector
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	while(n--){
		ll x;
		cin >> x;
		vt<ll> a(x), b(x);
		for(int i = 0; i < x; i++){
			cin >> a[i];
		}
		for(int i =0; i < x; i++) {
			cin >> b[i];
		}
		ll ans = 0;
		for(int i =0; i < x; ++i) {
			ans+=max(a[i]-*min_element(a.begin(), a.end()), b[i]-*min_element(b.begin(), b.end()));
		}
		cout << ans << '\n';
	}
		
}