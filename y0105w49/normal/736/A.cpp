#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
// typedef __int128 INT;
typedef long long INT;
typedef long long ll;
typedef unsigned long long ull;
const ld eps=1e-11;
typedef complex<ll> pt;
const ll inf=1e18+99;
#define fi first
#define se second
#define pb push_back

ll g(int x) {
	static ll dp[2000];
	if(dp[x]) return dp[x];
	if(!x) return 1;
	if(x==1) return 2;
	dp[x]=g(x-1)+g(x-2);
	if(dp[x]>inf) dp[x]=inf;
	return dp[x];
}

int main() {
	ll n; cin>>n;
	int L=0,R=100;
	for(;L!=R;) {
		int M=(L+R+1)/2;
		// cout<<M<<" "<<g(M)<<endl;
		if(g(M)<=n) L=M;
		else R=M-1;
	}
	cout<<L<<endl;

}