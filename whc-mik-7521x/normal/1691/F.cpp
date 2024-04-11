#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=1e9+7;
long long dp[N],fdp[N],ans;
struct edge{
    int to,nxt;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
int n,k;
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
int siz[N];
void dfs(int x,int fa){
    siz[x]=1;
    long long sum=0;
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa)continue;
        dfs(v,x);
        dp[x]+=dp[v];
        siz[x]+=siz[v];
        if(siz[v]>=k)sum+=mod-C(siz[v],k);
        sum%=mod;
    }
    if(siz[x]>=k)sum+=C(siz[x],k);
    dp[x]+=sum*siz[x]%mod;
    dp[x]%=mod;
}
void solve(int x,int fa){
    long long res=fdp[x];
    long long sum=0;
    if(n-siz[x]>=k)sum+=mod-C(n-siz[x],k);
    sum%=mod;
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa)continue;
        if(siz[v]>=k)sum+=mod-C(siz[v],k);
        sum%=mod;
        res+=dp[v];
    }
    sum+=C(n,k);
    sum%=mod;
    ans+=res+sum*n%mod;
    ans%=mod;
    sum+=mod-C(n,k);
    sum%=mod;
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa)continue;
        if(siz[v]>=k)sum+=C(siz[v],k);
        if(n-siz[v]>=k)sum+=C(n-siz[v],k);
        sum%=mod;
        res+=mod-dp[v];
        fdp[v]=res+sum*(n-siz[v])%mod;
        fdp[v]%=mod;
        solve(v,x);
        if(siz[v]>=k)sum+=mod-C(siz[v],k);
        sum%=mod;
        res+=dp[v];
        if(n-siz[v]>=k)sum+=mod-C(n-siz[v],k);
        sum%=mod;
    }
}
int main(){
    init();
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    solve(1,0);
    printf("%lld",ans);
    return  0;
}