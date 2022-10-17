#include<stdio.h>
#include<string.h>
const int maxn=205,maxv=33;
int n,mod,ans;
int fac[maxn],nfac[maxn],inv[maxn],f[maxn][maxv][maxn];
inline int max(int a,int b){
	return a>b? a:b;
}
int dfs(int len,int val,int sum,int a1){
	if(a1+val==n+1)
		return len<n? nfac[n-len]:0;
	if(val>len)
		return 0;
	if(f[len][val][sum]!=-1)
		return f[len][val][sum];
	int res=0;
	for(int i=0;len+i<=n&&sum+(n+1-a1-val)*i<=a1;i++)
		res=(res+1ll*dfs(len+i,val+1,sum+(n+1-a1-val)*i,a1)*nfac[i])%mod;
	return f[len][val][sum]=res;
}
int main(){
	scanf("%d%d",&n,&mod);
	fac[0]=fac[1]=nfac[0]=nfac[1]=inv[1]=1;
	for(int i=2;i<=n+1;i++)
		fac[i]=1ll*fac[i-1]*i%mod,inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod,nfac[i]=1ll*nfac[i-1]*inv[i]%mod;
	for(int i=max(n+1-32,0);i<=n+1;i++)
		memset(f,-1,sizeof(f)),ans=(ans+dfs(0,0,0,i))%mod;
	printf("%d\n",(int)(1ll*ans*fac[n]%mod));
	return 0;
}