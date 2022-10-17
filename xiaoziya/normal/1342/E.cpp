#include<stdio.h>
const int maxn=200005,mod=998244353;
int n,ans;
long long k;
int fac[maxn],nfac[maxn];
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
inline int C(int a,int b){
	return a<b? 0:1ll*fac[a]*nfac[b]%mod*nfac[a-b]%mod;
}
int main(){
	scanf("%d%lld",&n,&k);
	if(k>=n){
		puts("0");
		return 0;
	}
	fac[0]=nfac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%mod,nfac[i]=ksm(fac[i],mod-2);
	if(k==0){
		printf("%d\n",fac[n]);
		return 0;
	}
	k=n-1-k+1;
	for(int i=0;i<=k;i++)
		ans=(ans+1ll*C(k,i)*ksm(i,n)%mod*((k-i)&1? (mod-1):1))%mod;
	ans=2ll*ans*C(n,k)%mod;
	printf("%lld\n",ans);
	return 0;
}