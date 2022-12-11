
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,N=1e4+10;
long long fac[N],inv[N];
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
void init(){
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
    inv[N-1]=fp(fac[N-1],mod-2);
    for(int i=N-2;i>=1;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
long long C(long long x,long long y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
long long A(long long x,long long y){
    return fac[x]*inv[x-y]%mod;
}
long long dp[70][1100];
long long solve(int n,long long kk,long long z){
	dp[60][0]=1;
	for(int i=1;i<=n;i++)dp[60][i]=0;
	for(int i=59;i>=0;i--){
		for(int j=0;j<=n;j++){
			dp[i][j]=0;
			for(int k=((z>>i)&1ll);k<=n;k+=2){
                if(j+k<=(kk>>i))dp[i][j]=(dp[i][j]+1ll*dp[i+1][(kk>>(i+1))-(((kk>>i)-j-k)>>1)]*C(n,k))%mod;
            }
		}
	}
	return dp[0][0];
}
int n;
long long l,r,z;
int main(){
    init();
    scanf("%d%lld%lld%lld",&n,&l,&r,&z);
	printf("%lld",((solve(n,r,z)-solve(n,l-1,z))%mod+mod)%mod);
	return 0;
}