#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mod=998244353;
long long fp(long long x,long long y){
	long long res=1;
	while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
	return res;
}
int p[N],cnt,mu[N],vis[N],n,m,ct[N],f[N];
void solve(){
	mu[1]=1;
	for(int i=2;i<N;++i){
		if(!vis[i]){
			p[++cnt]=i;
			mu[i]=-1;
		}
		for(int o=1;o<=cnt&&p[o]*i<=N;++o){
			vis[i*p[o]]=1;
			if(i%p[o]==0)break;
			mu[i*p[o]]=-mu[i];
		}
	}
}
int main(){
	solve();
	scanf("%d",&m);
	for(int i=1,x;i<=m;++i){
		scanf("%d",&x);
		scanf("%d",&ct[x]);
		n=max(x,n);
	}
	for(int i=1;i<=n;++i){
		long long tot=0;
		for(int o=i;o<=n;o+=i){
			tot+=ct[o];
		}
		if(tot<2)continue;
		int kk,kp;
		kp=fp(2,(tot-2)%(mod-1));
		kk=1ll*(tot-1)%mod*kp%mod;
		if(tot>=3)kp=(1ll*kp+1ll*(tot-2)%mod*fp(2,(tot-3)%(mod-1)))%mod;
		for(int o=i;o<=n;o+=i){
			if(ct[o]){
				f[i]=(1ll*f[i]+1ll*o*o%mod*kk%mod*ct[o])%mod;
				if(ct[o]>=2){
					f[i]=(1ll*f[i]+1ll*o*o%mod*kp%mod*ct[o]%mod*(ct[o]-1))%mod;
				}
			}
		}
		int sum=0;
		for(int o=i;o<=n;o+=i){
			if(ct[o]){
				sum=(1ll*sum+1ll*o*ct[o])%mod;
			}
		}
		for(int o=i;o<=n;o+=i){
			if(ct[o]){
				int now=((sum-1ll*o*ct[o]%mod)%mod+mod)%mod;
				f[i]=(1ll*f[i]+1ll*o*ct[o]%mod*now%mod*kp)%mod;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)(ans+=f[i]*mu[i])%=mod;
	printf("%d",(ans+mod)%mod);
	return 0;
}