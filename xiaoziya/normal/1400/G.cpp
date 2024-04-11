#include<stdio.h>
#include<vector>
using namespace std;
const int maxn=300005,maxm=21,mod=998244353;
int n,m,ans;
int l[maxn],r[maxn],ok[maxn],xx[maxm],yy[maxm],fac[maxn],nfac[maxn],inv[maxn],f[maxn][2*maxm];
inline int C(int a,int b){
	return (a<0||b<0||a<b)? 0:1ll*fac[a]*nfac[b]%mod*nfac[a-b]%mod;
}
int main(){
	scanf("%d%d",&n,&m);
	fac[0]=nfac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%mod,inv[i]=i==1? 1:(mod-1ll*(mod/i)*inv[mod%i]%mod),nfac[i]=1ll*nfac[i-1]*inv[i]%mod;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]),ok[l[i]]++,ok[r[i]+1]--;
	for(int i=1;i<=n;i++)
		ok[i]+=ok[i-1];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=2*m;j++)
			f[i][j]=(f[i-1][j]+C(ok[i]-j,i-j))%mod;
	for(int i=1;i<=n;i++)
		ok[i]=0;
	for(int i=1;i<=m;i++)
		scanf("%d%d",&xx[i],&yy[i]);
	for(int i=0;i<(1<<m);i++){
		int L=1,R=n,tot=0,cnt=0;
		for(int j=1;j<=m;j++)
			if((i>>(j-1))&1)
				cnt++,tot+=(ok[xx[j]]==0)+(ok[yy[j]]==0),ok[xx[j]]=ok[yy[j]]=1,L=max(L,max(l[xx[j]],l[yy[j]])),R=min(R,min(r[xx[j]],r[yy[j]]));
		if(L<=R)
			ans=(ans+1ll*(f[R][tot]-f[L-1][tot]+mod)%mod*((cnt&1)? (mod-1):1))%mod;
		for(int j=1;j<=m;j++)
			if((i>>(j-1))&1)
				ok[xx[j]]=ok[yy[j]]=0;
	}
	printf("%d\n",ans);
	return 0;
}