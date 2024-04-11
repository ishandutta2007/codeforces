#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=1e9+7;
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
int n;
long long dp[N],ans[N];
long long sum(int l,int r){
    if(l>r)return 0;
    return (dp[l]-dp[r+1]+mod)%mod;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n+1;i++)dp[i]=0,ans[i]=0;
        dp[n]=2;
        for(int i=n-1;i>=1;i--){
            dp[i]=sum(i+1,min(n,i*2-1));
            (dp[i]+=dp[i+1])%=mod;
        }
        for(int i=1;i<=n;i++)(dp[i]+=mod-dp[i+1])%=mod;
        for(int i=1;i<=n;i++){
            // cout<<i<<' '<<dp[i]<<endl;
            ans[i]=fp(2,i/2)*dp[i]%mod;
        }
        long long inv=fp(fp(2,n),mod-2);
        for(int i=1;i<=n;i++)printf("%lld\n",ans[i]*inv%mod);
    }
    return 0;
}