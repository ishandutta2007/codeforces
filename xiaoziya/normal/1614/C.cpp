#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=200005,mod=1000000007;
int T,n,m,ans;
int cnt[2],l[maxn],r[maxn],v[maxn],sum[maxn],mul[maxn],fac[maxn],nfac[maxn],inv[maxn];
inline int C(int a,int b){
	return a<b? 0:1ll*fac[a]*nfac[b]%mod*nfac[a-b]%mod;
}
int main(){
	fac[0]=nfac[0]=mul[0]=1;
	for(int i=1;i<maxn;i++)
		fac[i]=1ll*fac[i-1]*i%mod,inv[i]=i==1? 1:(mod-1ll*(mod/i)*inv[mod%i]%mod),nfac[i]=1ll*nfac[i-1]*inv[i]%mod,mul[i]=(mul[i-1]+mul[i-1])%mod;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),ans=0;
		for(int i=1;i<=m;i++)
			scanf("%d%d%d",&l[i],&r[i],&v[i]);
		for(int i=0;i<=30;i++){
			cnt[0]=cnt[1]=0;
			for(int j=1;j<=m;j++)
				if(((v[j]>>i)&1)==0)
					sum[l[j]]++,sum[r[j]+1]--;
			for(int j=1;j<=n;j++)
				sum[j]+=sum[j-1],cnt[sum[j]==0]++;
			for(int j=1;j<=cnt[1];j+=2)
				ans=(ans+1ll*C(cnt[1],j)*mul[cnt[0]]%mod*mul[i])%mod;
			for(int j=0;j<=n+1;j++)
				sum[j]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}