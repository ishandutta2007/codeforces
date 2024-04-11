#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n,mod,dp[N][N],sum[N<<2],s[N<<2],kk[N<<2],pw[N<<2];
int main(){
    pw[0]=1;
    scanf("%d%d",&n,&mod);
    for(int i=1;i<N;i++)pw[i]=pw[i-1]*2%mod;
    for(int i=1;i<=n;i++){
        for(int o=1;o<i;o++){
            if(i-o-o-1>0)dp[i][o]=1ll*kk[(i-o-o-1)>>1]*s[o]%mod;
            if(i-2*o>0)(dp[i][o]+=1ll*sum[i-2*o-1]*s[o]%mod)%=mod;
        }
        for(int o=1,kp=0;o<=n;o++){
            (kp+=dp[i][o])%=mod;
            (sum[i+o]+=kp)%=mod;
        }
        if(i!=1){
            s[i]=pw[i-2];
            for(int o=1;o<i;o++)(s[i]+=mod-dp[i][o])%=mod;
        }
        else s[i]=1;
        kk[i]=(kk[i-1]+s[i])%mod;
    }
    printf("%d",s[n]);
    return 0;
}