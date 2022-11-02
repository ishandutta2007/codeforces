#include<bits/stdc++.h>
using namespace std;
#define pi pair<int ,int >
#define mcp(x,y) make_pair(x,y)
#define fi first
#define se second
const int N = 1e6+9;
int n,m,head[N],tot;
struct pp{int nxt,to,val;}g[N<<1];
void add(int u,int v,int w){g[++tot].nxt=head[u],g[tot].to=v,g[tot].val=w,head[u]=tot;}

priority_queue<pi >q;
struct tree{
    int rt,d[N],f[N][21],mxd[N],son[N],ans[N],cnt;
    void dfs(int u,int fa){
        f[u][0]=fa,mxd[u]=0;
        for(int i=head[u];i!=-1;i=g[i].nxt){
            int v=g[i].to;if(v==fa) continue;d[v]=d[u]+g[i].val;dfs(v,u);
            if(mxd[v]+g[i].val>mxd[u]) son[u]=v;
            mxd[u]=max(mxd[v]+g[i].val,mxd[u]);
        }
        return ;
    }
    int tim[N];
    void upd(int u){
        if(!u) return ;
        tim[u]=cnt;
        for(int i=head[u];i!=-1;i=g[i].nxt){
            int v=g[i].to;if(v==son[u]||tim[v]) continue;q.push(mcp(g[i].val+mxd[v],v));
        }
        upd(son[u]);
        return ;
    }
    void build(){
        dfs(rt,0);
        for(int j=1;j<=20;j++)
            for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
        q.push(mcp(mxd[rt],rt));cnt=0;
        while(!q.empty()){
            int u=q.top().se;++cnt;
            ans[cnt]=ans[cnt-1]+q.top().fi;
            q.pop();
            upd(u);
        }
        return ;
    }
    int ask(int x,int y){
        if(2*y-1>=cnt) return ans[cnt];
        if(tim[x]<=2*y-1) return ans[2*y-1];
        int u=x,lst=0;
        for(int i=20;i>=0;i--)
            if(tim[f[u][i]]>2*y-2) u=f[u][i];
        u=f[u][0];
        lst=max(lst,ans[2*y-2]+d[x]-d[u]+mxd[x]);
        u=x;
        for(int i=20;i>=0;i--)
            if(tim[f[u][i]]>2*y-1) u=f[u][i];
        u=f[u][0];
        lst=max(lst,ans[2*y-1]-mxd[u]+d[x]-d[u]+mxd[x]);
        return lst;
    }
}t1,t2;

int d[N];
void dfs(int u,int fa){
    for(int i=head[u];i!=-1;i=g[i].nxt){int v=g[i].to;if(v==fa) continue;d[v]=d[u]+g[i].val;dfs(v,u);}return ;
}


int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);add(u,v,w);add(v,u,w);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) if(!t1.rt||d[t1.rt]<d[i]) t1.rt=i;
    dfs(t1.rt,0);
    for(int i=1;i<=n;i++) if(!t2.rt||d[t2.rt]<d[i]) t2.rt=i;
    t1.build();t2.build();
    int lst=0;
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        x=(x+lst-1)%n+1,y=(y+lst-1)%n+1;
        lst=max(t1.d[x]+t1.mxd[x],t2.d[x]+t2.mxd[x]);
        if(y==1){
            printf("%d\n",lst);
            continue;
        }
        lst=max(lst,max(t1.ask(x,y),t2.ask(x,y)));
        printf("%d\n",lst);
    }
    return 0;
}