#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;
const ll mod2 = 1e6;
const int N = 2e5+9;
int n,head[N],tot;ll f[N][2];
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){
    g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
ll mul(ll x,ll y){
    ll p=x,q=y%mod2;
    ll ans=p*q%mod;ans+=(p*(y/mod2)%mod*mod2%mod);
    ans%=mod;return ans;
}
void dfs(int u,int fa){
    ll cnt0=1,cnt1=0,cnt2=0,cnt3=1;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        dfs(v,u);
        cnt2=(mul(cnt1,f[v][0])+mul(cnt2,(f[v][0]+f[v][1])%mod))%mod;
        cnt1=(mul(cnt0,f[v][0])+mul(cnt1,f[v][1]))%mod;
        cnt0=mul(cnt0,f[v][1]);
    }
    f[u][0]=(cnt1+cnt2)%mod,f[u][1]=(cnt2+cnt0)%mod;
    if(head[u]==-1){f[u][1]=1,f[u][0]=1;return ;}
}
int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){int u;scanf("%d",&u);add(u,i);}
    memset(f,0,sizeof(f));
    dfs(1,0);
    printf("%lld\n",f[1][1]);
    return 0;
}