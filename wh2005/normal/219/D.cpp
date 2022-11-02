#include<bits/stdc++.h>
using namespace std;
int n;
int head[200009],tot;
struct pp{int nxt,to,val;}g[500009];
void add(int u,int v,int w){
    g[++tot].nxt=head[u],g[tot].to=v,g[tot].val=w,head[u]=tot;
}
int sum;
void dfs(int u,int fa){
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        sum+=g[i].val;dfs(v,u);
    }
}
int ans[200009];
void Dfs(int u,int fa){
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        if(g[i].val==1) ans[v]=ans[u]-1;
        else ans[v]=ans[u]+1;
        Dfs(v,u);
    }
}
int main(){
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);add(u,v,0);add(v,u,1);
    }
    sum=0;
    dfs(1,0);
    ans[1]=sum;
    Dfs(1,0);
    int mn=n+1;
    for(int i=1;i<=n;i++) mn=min(mn,ans[i]);
    printf("%d\n",mn);
    for(int i=1;i<=n;i++) if(mn==ans[i]) printf("%d ",i);
    return 0;
}