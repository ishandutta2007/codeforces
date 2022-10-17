#include<stdio.h>
const int maxn=200005,mod=1000000007;
int T,n,l,r,ans;
int f[maxn],fac[maxn],nfac[maxn],inv[maxn];
inline int C(int a,int b){
	return (b<0||a<b)? 0:1ll*fac[a]*nfac[b]%mod*nfac[a-b]%mod;
}
inline int min(int a,int b){
	return a<b? a:b;
}
int main(){
	fac[0]=fac[1]=nfac[0]=nfac[1]=inv[1]=1;
	for(int i=2;i<=200000;i++){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
		nfac[i]=1ll*nfac[i-1]*inv[i]%mod;
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&l,&r);
		//f(n)=ceil(n/2)floor(n/2)
		//floor(n/2) positive ceil(n/2) negative
		int ans=C(n,n/2),k=min(1-l,r-n);
		if(n%2)
			ans=(ans+ans)%mod;
		ans=1ll*ans*k%mod;
		for(int i=k+1;;i++){
			int x=min(n-l-i+1,n),y=min(r-i,n);
			if(x<0||y<0)
				break;
			ans=(ans+C(x+y-n,n/2-(n-y)))%mod;
			if(n%2)
				ans=(ans+C(x+y-n,n/2-(n-x)))%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}