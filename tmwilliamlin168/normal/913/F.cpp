#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=2000;
const ll M=998244353;

ll exp(ll b, int p) {
	if(p==0)
		return 1;
	return exp(b*b%M, p/2)*(p&1?b:1)%M;
}

inline ll inv(ll x) {
	return exp(x, M-2);
}

ll p1[mxN+1]={1}, p2[mxN+1]={1}, dp1[mxN+1][mxN+1], dp2[mxN+1], dp3[mxN+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	ll a, b;
	cin >> n >> a >> b;
	p1[1]=a*inv(b)%M;
	p2[1]=1-p1[1]+M;
	for(int i=2; i<=n; ++i) {
		p1[i]=p1[i-1]*p1[1]%M;
		p2[i]=p2[i-1]*p2[1]%M;
	}
	for(int i=0; i<=n; ++i)
		dp1[i][0]=1;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=i; ++j)
			dp1[i][j]=(dp1[i-1][j]*p2[j]+dp1[i-1][j-1]*p1[i-j])%M;
	dp2[1]=1;
	for(int i=2; i<=n; ++i) {
		for(int j=1; j<i; ++j)
			dp2[i]=(dp2[j]*dp1[i][j]+dp2[i])%M;
		dp2[i]=1-dp2[i];
		if(dp2[i]<0)
			dp2[i]+=M;
	}
	for(int i=2; i<=n; ++i) {
		for(int j=i; j>=1; --j)
			dp3[i]=(dp1[i][j]*dp2[j]%M*((ll)j*(2*i-j-1)/2+dp3[j]+dp3[i-j])+dp3[i])%M;
		dp3[i]=dp3[i]*inv((1-dp1[i][i]*dp2[i]%M)+M)%M;
	}
	cout << dp3[n];
}