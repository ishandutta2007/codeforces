#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
typedef long long ll;
typedef double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld TAU=2*acos(-1);


const int N=5<<10;
const int P=1e9+7;
ll F[N+N],iF[N+N];

ll C(ll n,ll k) {
	assert(0<=k && k<=n);
	return F[n]*iF[k]%P*iF[n-k]%P;
}
ll powq(ll x,int e) {
	if(!e) return 1;
	if(e&1) return x*powq(x,e-1)%P;
	x=powq(x,e>>1);
	return x*x%P;
}
ll inv(ll x) {
	return powq(x,P-2);
}
int main() {
	F[0]=1;
	for(int x=1;x<N+N;x++) F[x]=F[x-1]*x%P;
	for(int x=0;x<N+N;x++) iF[x]=inv(F[x]);

	int n; cin>>n;
	string s; cin>>s;
	s="#"+s;
	static int dp[N][N],pref[N][N];
	dp[0][0]=1;
	pref[1][0]=1;
	for(int i=1;i<=n;i++) {
		if(s[i]==s[i-1]) {
			for(int k=0;k<=n;k++) dp[i][k]=dp[i-1][k], dp[i-1][k]=0;
			for(int k=0;k<=n;k++) pref[i+1][k]=pref[i][k], pref[i][k]=pref[i-1][k];
			continue;
		}
		for(int k=1;k<=n;k++) dp[i][k]=pref[i][k-1];
		for(int j=i;--j>=0;) {
			if(s[j]==s[i]) {
				for(int k=1;k<=n;k++) dp[i][k]+=P-pref[j+1][k-1];
				break;
			}
			// for(int k=1;k<=n;k++) dp[i][k]+=dp[j][k-1];
		}
		for(int k=1;k<=n;k++) for(;dp[i][k]>=P;) dp[i][k]-=P;
		for(int k=0;k<=n;k++) pref[i+1][k]=pref[i][k]+dp[i][k];
		for(int k=0;k<=n;k++) if(pref[i+1][k]>=P) pref[i+1][k]-=P;
	}
	static ll Z[N];
	// for(int i=1;i<=n;i++) for(int k=1;k<=n;k++) Z[k]+=dp[i][k];
	// for(int k=1;k<=n;k++) Z[k]%=P;
	for(int k=1;k<=n;k++) Z[k]=pref[n+1][k];

	ll ans=0;
	// for(int k=1;k<=n;k++) cerr<<"Z["<<k<<"] = "<<Z[k]<<endl;
	// for(int k=1;k<=n;k++) cerr<<"pref["<<k<<"] = "<<pref[n+1][k]<<endl;
	// for(int k=1;k<=n;k++) cerr<<"dp["<<k<<"] = "<<dp[n+1][k]<<endl;
	for(int k=1;k<=n;k++) ans+=C(n-1,k-1)*Z[k]%P;
	cout<<ans%P<<endl;

}