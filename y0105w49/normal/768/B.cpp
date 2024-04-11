#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ld TAU=2*acos(-1);
const ld eps=1e-7;
const int inf=1e9+99;
const ll linf=1e18+88;



int32_t main() {
	ll n,L,R; cin>>n>>L>>R;
	int Z=0;
	vector<int> bits;
	for(;n;) {
		bits.pb(n&1);
		n/=2;
	}
	reverse(bits.begin(),bits.end());
	for(;bits.size();) {
		n=n*2+bits.back();
		bits.pop_back();
	}
	for(int i=L;i<=R;i++) {
		int j=(i & (i-1));
		int k=i^j;
		// cerr<<i<<" gives "<<k<<endl;
		if(n&k) ++Z;
	}
	cout<<Z<<endl;
}