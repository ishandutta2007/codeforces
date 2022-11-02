#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+9;
#define ll long long
const ll mod = 1e9+7;
int n,m;
ll qpow(ll x,ll y){
	ll t=1;while(y){if(y&1) (t*=x)%=mod;y>>=1,(x*=x)%=mod;}
	return t;
}
ll inv2;
ll s2[N][N];

int main(){
	scanf("%lld%d",&n,&m);inv2=qpow(2,mod-2);
	memset(s2,0,sizeof(0));s2[0][0]=1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=i;j++)
			s2[i][j]=(s2[i-1][j-1]+s2[i-1][j]*j%mod)%mod;
	ll ans=0,mi=qpow(2,n),fac=1;
	for(int i=0;i<=min(n,m);i++){
		ll area=s2[m][i]*fac%mod*mi%mod;
		(ans+=area)%=mod;(mi*=inv2)%=mod;(fac*=(n-i))%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}