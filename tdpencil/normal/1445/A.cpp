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
		ll x, y;
		cin >> x >> y;
		vector<int> v(x);
		for(int i =0; i < x; i++) {
			cin >> v[i];
		}
		vector<int> w(x);
		for(int i =0; i <x; i++) {
			cin >> w[i];
		}
		sort(w.rbegin(), w.rend());
		bool c=1;
		for(int i=0; i <x&&c; i++) {
			if(w[i]+v[i]>y) {
				cout << "NO\n";
				c=0;
			}
		}
		if(c)print("YES");
	}
}