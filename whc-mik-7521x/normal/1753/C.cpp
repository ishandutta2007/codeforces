#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=998244353;
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
long long inv(int x){
    return fp(x,mod-2);
}
int t,n,a[N],ct,dp[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ct=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            ct+=a[i];
        }
        int m=min(n,n-ct),ctt=0;
        dp[0]=0;
        int kk=inv(1ll*n*(n-1)/2%mod);
        for(int i=1;i<=m;i++){
            int kp=1ll*i*i%mod;
            long long p=1ll*kk*kp%mod;
            dp[i]=(p*dp[i-1]%mod+1)*inv(p)%mod;
        }
        for(int i=n-ct+1;i<=n;i++)ctt+=a[i]==0;
        printf("%d\n",dp[ctt]);
    }
    return 0;
}