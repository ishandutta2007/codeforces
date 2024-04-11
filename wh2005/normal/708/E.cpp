#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1e9+7;
const int N = 2e3+9;
const int M = 1e5+9;
int n,m,t;
ll a,b,fac[M],inv[M],mi[M],mj[M];
ll qpow(ll x,ll y){
    ll t=1;while(y){if(y&1) (t*=x)%=mod;(x*=x)%=mod,y>>=1;}
    return t;
}
ll C(int x,int y){
    if(x<0||x>y) return 0;
    return fac[y]*inv[x]%mod*inv[y-x]%mod;
}
ll f[M],ff[M],ft[M],g[N],pre[N][N],suf[N][N],dp[N];
ll F(int i,int j){return f[i]*f[m-j+1];}


int main(){
    scanf("%d%d%lld%lld%d",&n,&m,&a,&b,&t);
    ll invb=qpow(b,mod-2);
    mi[0]=1,mi[1]=a*invb%mod;
    mj[0]=1,mj[1]=(b-a)*invb%mod;
    for(int i=2;i<=M-9;i++) mi[i]=(mi[i-1]*mi[1])%mod;
    for(int i=2;i<=M-9;i++) mj[i]=(mj[i-1]*mj[1])%mod;
    fac[0]=1,inv[0]=inv[1]=1;
    for(int i=1;i<=M-9;i++) fac[i]=(fac[i-1]*i)%mod;
    for(int i=2;i<=M-9;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    for(int i=2;i<=M-9;i++) inv[i]=(inv[i]*inv[i-1])%mod;
    f[0]=1;
    for(int i=1;i<=t+1;i++) 
        f[i]=C(i-1,t)*mi[i-1]%mod*mj[t-i+1]%mod;
    pre[0][m]=1,suf[0][0]=1;
    ll sum=1;
    for(int r=1;r<=m;r++)
        for(int l=1;l<=r;l++) (ff[r]+=F(l,r))%=mod;
    for(int l=m;l>=1;l--)
        for(int r=l;r<=m;r++) (ft[l]+=F(l,r))%=mod;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) g[j]=f[j]*pre[i-1][j-1]%mod;
        for(int j=1;j<=m;j++) (g[j]+=g[j-1])%=mod;
        for(int r=1;r<=m;r++){
            dp[r]=sum*ff[r]%mod-g[r]*f[m-r+1]%mod-ff[r]*suf[i-1][r+1]%mod;
            dp[r]=(dp[r]%mod+mod)%mod;
        }
        for(int r=1;r<=m;r++) 
            pre[i][r]=(pre[i][r-1]+dp[r])%mod;
        for(int j=m;j>=1;j--) g[j]=f[m-j+1]*suf[i-1][j+1]%mod;
        for(int j=m;j>=1;j--) (g[j]+=g[j+1])%=mod;
        for(int l=m;l>=1;l--){
            dp[l]=sum*ft[l]%mod-g[l]*f[l]%mod-ft[l]*pre[i-1][l-1]%mod;
            dp[l]=(dp[l]%mod+mod)%mod;
        }
        for(int l=m;l>=1;l--)
            suf[i][l]=(suf[i][l+1]+dp[l])%mod;
        sum=pre[i][m];
    }
    printf("%lld\n",sum);
    return 0;
}
/*
1 2
1 2
1
*/