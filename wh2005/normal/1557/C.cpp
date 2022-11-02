#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1e9+7;
const int N = 1e6+9;
ll fac[N],inv[N];
ll C(int x,int y){
	if(x<0||y<x) return 0;
	return fac[y]*inv[x]%mod*inv[y-x]%mod;
}
ll qpow(ll x,ll y){
	if(y==-1) return 1;
	ll t=1;
	while(y){
		if(y&1) (t*=x)%=mod;
		(x*=x)%=mod,y>>=1;
	}
	return t;
}
int T,n,k;


int main(){
	fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<=N-9;i++) fac[i]=fac[i-1]*i%mod;
	for(int i=2;i<=N-9;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	for(int i=1;i<=N-9;i++) (inv[i]*=inv[i-1])%=mod;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		if(k==0){
			printf("1\n");
			continue;
		}
		if(n&1){
			ll ans=0,t=1;
			for(int i=k-1;i>=0;i--){
				ll res=t;
				(res*=(qpow(2,n-1)-1))%=mod;
				t=t*(qpow(2,n-1)+1)%mod;
				(res*=qpow(qpow(2,n),i))%=mod;
				(ans+=res)%=mod;
			}
			ans=qpow(qpow(2,n),k)-ans;
			ans=(ans%mod+mod)%mod;
			printf("%lld\n",ans);
		}
		else{
			ll ans=0,t=1;
			for(int i=k-1;i>=0;i--){
				ll res=t;
				(res*=qpow(qpow(2,i),n))%=mod;
				(ans+=res)%=mod;
				(t*=(qpow(2,n-1)-1))%=mod;
				if(!i) (ans+=t)%=mod;
			}
			printf("%lld\n",ans);
		}
	}	
	return 0;
}
/*
3
2 2

*/