#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=998244353;
ll f[3000001],rf[3000001];
ll n;
int main() {
	cin>>n;
	f[1]=1ll;
	for(ll i=2;i<=n+1;i++) {
		f[i]=(1ll*f[i-1]*i)%MOD;
	}
	rf[n]=n;
	ll ans=n;
	for(ll i=n-1;i>=1;i--) {
		rf[i]=(1ll*rf[i+1]*i)%MOD;
		ans=(ans+rf[i])%MOD;
	}
	ll b=((f[n+1]-ans+MOD)%MOD);
	cout<<b;
}