#include<bits/stdc++.h>
using namespace std;
const int N=720720,mod=998244353;
long long dp[20][N],n,a,x,y,k,m;;
long long ans=0,np[20];
int main(){
    scanf("%lld%lld%lld%lld%lld%lld",&n,&a,&x,&y,&k,&m);
    np[0]=1;
    for(int i=1;i<20;i++)np[i]=np[i-1]*n%mod;
    for(int i=1;i<=n;i++){
        dp[0][a%N]++;
        ans+=1ll*k%mod*np[k-1]%mod*(a/N*N)%mod;
        ans%=mod;
        a=(a*x+y)%m;
    }
    for(int i=0;i<k;i++){
        for(int o=0;o<N;o++){
            ans+=dp[i][o]*o%mod*np[k-i-1]%mod;
            ans%=mod;
            dp[i+1][o]+=dp[i][o]*(n-1);
            dp[i+1][o]%=mod;
            dp[i+1][o-o%(i+1)]+=dp[i][o];
            dp[i+1][o-o%(i+1)]%=mod;
        }
    }
    printf("%lld",ans);
    return  0;
}