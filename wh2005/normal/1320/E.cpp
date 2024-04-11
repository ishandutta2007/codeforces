#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;

int n,q,k,m;
int d[N],s[N],w[N];

namespace frame{

    int head[N],tot;
    struct pp{int nxt,to,val;}g[N<<1];
    void add(int u,int v,int w){
        g[++tot].nxt=head[u],g[tot].to=v,g[tot].val=w,head[u]=tot;return ;
    }
    void E(int u,int v,int w){
        if(w<0) exit(0);
        add(u,v,w);add(v,u,w);return ;
    }
    struct S{
        int a,t,k,res;
        S(int aa=0,int tt=0,int kk=0,int rr=0){a=aa,t=tt,k=kk,res=rr;}
    }p[N];
    bool operator<(S a,S b){
        return (a.t==b.t)?(a.k>b.k):(a.t>b.t);
    }
    priority_queue<S> q;
    int c[N];
    void framework(){
        memset(head,-1,sizeof(head));tot=0;
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++) p[i].t=-1;
        return ;
    }
    void solve(){
        for(int i=1;i<=k;i++){
            q.push(S(d[i],0,i,0));
            p[d[i]]=S(0,0,i,0);c[d[i]]=i;
        }
        while(!q.empty()){
            S u=q.top();q.pop();
            if(c[u.a]&&u.t) continue;
            c[u.a]=u.k;
            for(int i=head[u.a];i!=-1;i=g[i].nxt){
                int v=g[i].to,tt=g[i].val-u.res;
                if(tt<0) tt=u.t;
                else{
                    tt=tt/s[u.k]+(tt%s[u.k]>0)+u.t;
                }
                if(p[v].t==-1||p[v].t>tt||(p[v].t==tt&&p[v].k>p[u.a].k)){
                    p[v].t=tt,p[v].k=p[u.a].k;
                    q.push(S(v,tt,p[v].k,(tt-u.t)*s[u.k]+u.res-g[i].val));
                }
            }
        }
        for(int i=1;i<=m;i++) printf("%d ",c[w[i]]);puts("");
        return ;
    }
}

namespace te{
    
    int head[N],tot;
    struct pp{int nxt,to;}g[N<<1];
    void add(int u,int v){
        g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
    }
    int dfn[N],dep[N],son[N],sz[N],pa[N],num;
    void dfs1(int u,int fa){
        sz[u]=1,dep[u]=dep[fa]+1,dfn[u]=++num,pa[u]=fa;
        for(int i=head[u];i!=-1;i=g[i].nxt){
            int v=g[i].to;if(v==fa) continue;dfs1(v,u);sz[u]+=sz[v];
            if(!son[u]||sz[v]>sz[son[u]]) son[u]=v;
        }
        return ;
    }
    int top[N];
    void dfs2(int u,int fa,int topf){
        top[u]=topf;
        if(son[u]) dfs2(son[u],u,topf);
        for(int i=head[u];i!=-1;i=g[i].nxt){
            int v=g[i].to;;if(v==fa||v==son[u]) continue;dfs2(v,u,v);
        }
        return ;
    }
    int lca(int u,int v){
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]]) swap(u,v);
            u=pa[top[u]];
        }
        return dep[u]>dep[v]?v:u;
    }
    void bl(){
        memset(head,-1,sizeof(head));tot=0;
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
        }
        m=0;
        dfs1(1,0);
        dfs2(1,0,1);
    }
    bool cmp(int x,int y){
        return dfn[x]<dfn[y];
    }
    int s[N],t,w[N],m,c[N],l;
    void foundation(){
        m=::m;
        for(int i=1;i<=m;i++) w[i]=::w[i];
        for(int i=1;i<=k;i++) w[++m]=d[i];
        sort(w+1,w+m+1,cmp);t=0;
        m=unique(w+1,w+m+1)-w-1;
        l=m;
        for(int i=1;i<=m;i++) c[i]=w[i];
        for(int i=1;i<=m;i++){
            if(t){
                int u=lca(s[t],w[i]),former=0;
                while(t&&dep[s[t]]>dep[u]){
                    if(former) frame::E(s[t],former,dep[former]-dep[s[t]]);
                    former=s[t];
                    s[t--]=0;
                }
                if(s[t]!=u) s[++t]=u,c[++l]=u;
                if(former) frame::E(u,former,dep[former]-dep[u]);
            }
            s[++t]=w[i];
        }
        while(t){
            if(t>1) frame::E(s[t-1],s[t],dep[s[t]]-dep[s[t-1]]);
            s[t--]=0;
        }
        return ;
    }
    void clear(){
        for(int i=1;i<=l;i++){
            frame::head[c[i]]=-1;
            frame::c[c[i]]=0,frame::p[c[i]]=frame::S(0,-1,0,0);
        }
        return ;
    }

}

int main(){
    te::bl();
    scanf("%d",&q);
    frame::framework();
    while(q--){
        scanf("%d%d",&k,&m);
        for(int i=1;i<=k;i++) scanf("%d%d",&d[i],&s[i]);
        for(int i=1;i<=m;i++) scanf("%d",&w[i]);
        te::tot=0;
        frame::tot=0;
        te::foundation();
        frame::solve();
        te::clear();   
    }
    return 0;
}