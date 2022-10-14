#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pll pair<ll, ll>
#define read(t) cin>>t;
#define fast_io cin.tie(0);ios::sync_with_stdio(0);cout.tie(0)
#define print(n) cout<<n<<'\n';

int main() {
	ll a;
	cin >> a;
	while(a--) {
		ll i, j, w, x;
		cin >> i  >> j >>  w >> x;
		cout << max(i+j,  w+x) << '\n';
	}
}