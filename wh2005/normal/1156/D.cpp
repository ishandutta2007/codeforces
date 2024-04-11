#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 200009;
int n,head[N],tot;
struct pp{int nxt,to,val;}g[N<<1];
void add(int u,int v,int w){
    g[++tot].nxt=head[u],g[tot].to=v,g[tot].val=w,head[u]=tot;
}
ll f[N][4],ans;
void dfs(int u,int fa){
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        dfs(v,u);
        if(g[i].val==1){
            ans+=f[v][1]*(f[u][2]+f[u][0]);
            ans+=(f[v][2]+f[v][0]-1)*f[u][1];
        }
        if(g[i].val==0){
            ans+=f[v][0]*(f[u][3]+f[u][1]);
            ans+=(f[v][3]+f[v][1]-1)*f[u][0];
        }
        f[u][g[i].val]+=f[v][g[i].val];
        if(g[i].val==1) f[u][2]+=f[v][0]+f[v][2]-1;
        if(g[i].val==0) f[u][3]+=f[v][1]+f[v][3]-1;
    }
    ans+=(f[u][0]+f[u][1])*2+f[u][2]-f[u][1]+f[u][3]-f[u][0];
    f[u][0]+=1,f[u][1]+=1,f[u][2]+=1,f[u][3]+=1;
}
int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    memset(f,0,sizeof(f));
    ans=0;dfs(1,0);
    printf("%lld\n",ans);
    return 0;
}