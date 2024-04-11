#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll mod = 998244353;
const int N = 2e5+9;
int n,head[N],tot;
ll fac[N],mi[N],f[N],ans;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){
    g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
void dfs(int u,int fa){
    int son=0;f[u]=1;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        dfs(v,u);son++;(f[u]*=f[v])%=mod;
    }
    if(u!=1) son++;
    (f[u]*=fac[son])%=mod;
    return ;
}
signed main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%lld",&n);
    for(int i=1;i<n;i++){
        int u,v;scanf("%lld%lld",&u,&v);add(u,v);add(v,u);
    }
    fac[0]=1,mi[0]=1;
    for(int i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%mod;
    for(int i=1;i<=n;i++) mi[i]=(mi[i-1]*2)%mod;
    dfs(1,0);
    printf("%lld\n",f[1]*n%mod);
    return 0;
}