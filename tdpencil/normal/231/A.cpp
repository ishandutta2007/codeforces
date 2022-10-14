#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pll pair<ll, ll>
#define read(t) cin>>t;
#define fast_io cin.tie(0);ios::sync_with_stdio(0);cout.tie(0)
#define print(n) cout<<n<<'\n';

int main() {
	ll ans=0;
	ll a;
	cin>>a;
	while(a--){
		ll x, y, z;
		cin >> x >> y >> z;
		ans+=x+y+z>=2;
	}
	print(ans);
	
}