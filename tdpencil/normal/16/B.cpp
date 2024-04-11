#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vt vector
#define ar array

int main() {
	ll n, m;
	cin >> n >> m;

	vt<pair<ll, ll>> a(m);
	for(int i=0; i < m; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end(), [](const auto a, const auto b) {
			return a.second == b.second ? a.first < b.first : a.second < b.second;
			});
	reverse(a.begin(), a.end());
	ll ans=0;
	for(int i=0;i<m;++i){
		if(n < a[i].first) {
			ll d=n;
			ans += d * a[i].second;
			n=0;
		} else {
			n -= a[i].first;
			ans += a[i].first * a[i].second;
		}
		
		if(n <= 0) break;
	}

	cout << ans << "\n";
}