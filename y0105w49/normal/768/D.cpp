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
	const int N=1024;
	static ld dp[2][N];
	int k,q; cin>>k>>q;
	dp[0][0]=1;
	vector<ld> Z={0};
	for(;Z.back()<.5;) {
		static int qq=0;
		auto ndp=dp[qq^1];
		auto odp=dp[qq];
		qq^=1;

		for(int i=0;i<=k;i++) ndp[i]=0;
		for(int i=0;i<=k;i++) {
			ndp[i]+=odp[i]*i/k;
			ndp[i+1]+=odp[i]*(k-i)/k;
		}


		Z.push_back(ndp[k]);
	}
	for(;q--;) {
		int p; cin>>p;
		ld need = (p-eps)/2e3;
		cout<<lower_bound(Z.begin(),Z.end(),need)-Z.begin()<<endl;
	}
}