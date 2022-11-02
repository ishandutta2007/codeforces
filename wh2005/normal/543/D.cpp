#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+9;
const ll mod = 1e9+7;
int n,head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){
    g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
ll f[N][2],p[N][2],ans[N];
void dfs(int u,int fa){
    int flag=0;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        dfs(v,u);flag++;
    }
    if(!flag){f[u][0]=1;return ;}
    f[u][0]=1,f[u][1]=1;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        (f[u][0]*=f[v][0])%=mod;
        (f[u][1]*=((2ll*f[v][0]%mod+f[v][1])%mod))%=mod;
    }
    f[u][1]=(f[u][1]-f[u][0])%mod;
    f[u][1]=(f[u][1]+mod)%mod;
}
int son[N];ll pre[N],lst[N];
void dfs2(int u,int fa){
    if(u!=1) ans[u]=((f[u][1]+f[u][0])%mod)*((p[u][1]+p[u][0])%mod)%mod;
    int cnt=0;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        son[++cnt]=v;
    }
    pre[0]=1;
    for(int i=1;i<=cnt;i++)
        pre[i]=pre[i-1]*f[son[i]][0]%mod;
    lst[cnt+1]=1;
    for(int i=cnt;i>=1;i--)
        lst[i]=lst[i+1]*f[son[i]][0]%mod;
    for(int i=1;i<=cnt;i++)
        p[son[i]][0]=(pre[i-1]*lst[i+1])%mod*p[u][0]%mod;
    
    pre[0]=1;
    for(int i=1;i<=cnt;i++)
        pre[i]=(2ll*f[son[i]][0]%mod+f[son[i]][1])%mod*pre[i-1]%mod;
    lst[cnt+1]=1;
    for(int i=cnt;i>=1;i--)
        lst[i]=(2ll*f[son[i]][0]%mod+f[son[i]][1])%mod*lst[i+1]%mod;
    for(int i=1;i<=cnt;i++){
        p[son[i]][1]=pre[i-1]*lst[i+1]%mod*(p[u][0]+p[u][1])%mod;
    }

    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        dfs2(v,u);
    }
}
int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int u;scanf("%d",&u);add(u,i);add(i,u);
    }
    memset(f,0,sizeof(f));
    dfs(1,0);ans[1]=(f[1][0]+f[1][1])%mod,p[1][1]=0,p[1][0]=1;
    dfs2(1,0);
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    puts("");
    return 0;
}