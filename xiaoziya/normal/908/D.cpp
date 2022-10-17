#include<bits/stdc++.h>
using namespace std;
const int maxn=2005,mod=1000000007;
int n,a,b,p,ans;
int f[maxn][maxn],mul[maxn];
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
int main(){
	scanf("%d%d%d",&n,&a,&b),p=1ll*a*ksm(a+b,mod-2)%mod;
	mul[0]=1;
	for(int i=1;i<=n;i++)
		mul[i]=1ll*mul[i-1]*p%mod;
	f[1][0]=1;
	for(int i=1;i<n;i++)
		for(int j=0;j<n;j++)
			if(f[i][j]){
				f[i][j+i]=(f[i][j+i]+1ll*f[i][j]*(1-p+mod))%mod;
				f[i+1][j]=(f[i+1][j]+1ll*f[i][j]*p)%mod;
			}
	for(int i=1;i<=n;i++)
		for(int j=n;j<=n+n;j++)
			if(f[i][j])
				ans=(ans+1ll*j*f[i][j])%mod;
	for(int i=0;i<n;i++)
		if(f[n][i]){
			int res=(i+n+1ll*p*ksm(1-p+mod,mod-2))%mod;
			ans=(ans+1ll*f[n][i]*res)%mod;
		}
	printf("%d\n",ans);
	return 0;
}