#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 2e5+9;
int n,k,head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){
    g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
int f[N][9],p[N],dep[N];ll ans,sum;
int nxt(int x){
    return (x-1<0)?(k-1):(x-1);
}
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;f[u][0]++;
    if(u!=1) ans+=(dep[u]-1)/k+1;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;dfs(v,u);
        for(int j=0;j<k;j++) f[u][j]+=f[v][nxt(j)];
    }
    return ;
}
void dfs2(int u,int fa,ll cnt){
    sum+=cnt;int t[9];for(int i=0;i<k;i++) t[i]=0;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        ll tpy=cnt;
        for(int j=0;j<k;j++)
            t[j]=f[u][nxt(j)]-f[v][nxt(nxt(j))];
        tpy+=t[1]-f[v][0];
        for(int j=0;j<k;j++) f[v][j]+=t[j];
        dfs2(v,u,tpy);
    }
    return ;
}
int siz[N];
void dfs3(int u,int fa){
    dep[u]=dep[fa]+1,siz[u]=1,ans+=dep[u];
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;dfs3(v,u);siz[u]+=siz[v];
    }
    return ;
}
void dfs4(int u,int fa,ll cnt){
    sum+=cnt;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;dfs4(v,u,cnt+n-2*siz[v]);
    }
    return ;
}
int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
    }
    if(k==1){
        dep[0]=-1,ans=0,sum=0;dfs3(1,0);dfs4(1,0,ans);
        printf("%lld\n",sum/2ll);
        return 0;
    }
    dep[0]=-1,ans=0;dfs(1,0);
    sum=0;dfs2(1,0,ans);printf("%lld\n",sum/2ll);
    return 0;
}