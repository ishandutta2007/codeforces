#include<bits/stdc++.h>
using namespace std;
const int N=300,mod=998244353;
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
int dp[N][N][N],n,k;
int main(){
    init();
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)dp[1][i][1]=1;
    for(int i=2;i<n;i++){
        long long sum=0;
        for(int o=1;o<k;o++){
            for(int j=1;j<i;j++){
                sum+=dp[i-1][o][j]*C(n-i+j,j);
                sum%=mod;
            }
            dp[i][o+1][1]=sum*fp(k-o,i-1)%mod;
        }
        for(int o=1;o<=k;o++){
            for(int j=2;j<=i;j++){
                dp[i][o][j]+=dp[i-1][o][j-1]*fp(k-o+1,i-1)%mod;
                dp[i][o][j]%=mod;
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=k;i++){
        for(int o=1;o<=n;o++){
            ans+=dp[n-1][i][o];
            ans%=mod;
        }
    }
    printf("%lld",ans);
    return  0;
}