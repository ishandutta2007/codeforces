#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n,mod,dp[N][N],s[N][N],per[N][N],suf[N][N];
namespace Math{
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
};
using namespace Math;
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
int dfs(int x,int fa){
    vector<int>son;
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa)continue;
        dfs(v,x);
        son.push_back(v);
    }
    for(int i=1;i<=n;i++)per[0][i]=1,suf[son.size()+1][i]=1;
    for(int i=0;i<(int)son.size();i++)for(int o=1;o<=n;o++)per[i+1][o]=1ll*per[i][o]*s[son[i]][o]%mod;
    for(int i=son.size()-1;~i;i--)for(int o=1;o<=n;o++)suf[i+1][o]=1ll*suf[i+2][o]*s[son[i]][o]%mod;
    for(int i=1;i<=n;i++)dp[x][i]=per[son.size()][i];
    for(int i=0;i<(int)son.size();i++){
        int kk=0;
        for(int o=1;o<=n;o++){
            (dp[x][o]+=1ll*kk*dp[son[i]][o]%mod)%=mod;
            (kk+=1ll*suf[i+2][o]%mod*per[i][o]%mod)%=mod;
        }
    }
    for(int i=1;i<=n;i++)s[x][i]=(s[x][i-1]+dp[x][i])%mod;
    return son.size();
}
int main(){
    scanf("%d%d",&n,&mod);
    init();
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    int kk=dfs(1,0);
    for(int i=1;i<n;i++){
        int ans=0;
        for(int o=1;o<=i;o++){
            ans+=((i-o)&1)?mod-1ll*per[kk][o]*C(i,o)%mod:1ll*per[kk][o]*C(i,o)%mod;
            ans%=mod;
        }
        printf("%d ",ans);
    }
    return 0;
}