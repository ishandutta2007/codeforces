#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int ans=0;
struct node{
    int x,y,w;
    bool operator<(const node b)const{
        return w>b.w;
    }
};
vector<node>cjx;
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unnion(int x,int y){fa[y]=x;}
struct edge{
    int w,to,nex;
};
edge ed[N<<1];
int cnt=1,h[N];
void add(int st,int et,int wi){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].w=wi;
    ed[cnt].nex=h[st];
    h[st]=cnt;
}
namespace GHT{
    int tot=0;
    struct edge{
        int w,to,nex;
    };
    edge ed[N<<1];
    int cnt=1,h[N];
    void add(int st,int et,int wi){
        cnt++;
        ed[cnt].to=et;
        ed[cnt].w=wi;
        ed[cnt].nex=h[st];
        h[st]=cnt;
    }
    int dfn[N],s,t,col[N],num[N],numm[N];
    bool bfs(){
        memset(dfn,0,sizeof dfn);
        queue<int>q;
        q.push(s);
        dfn[s]=1;
        while(q.size()){
            int u=q.front();
            q.pop();
            for(int i=h[u];i;i=ed[i].nex){
                int v=ed[i].to;
                if(ed[i].w&&!dfn[v]){q.push(v),dfn[v]=dfn[u]+1;if(v==t)return 1;}
            }
        }
        return 0;
    }
    int dinic(int u,int flow){
        if(u==t)return flow;
        int rest=flow;
        for(int i=h[u];i&&rest;i=ed[i].nex){
            int v=ed[i].to;
            if(ed[i].w&&dfn[v]==dfn[u]+1){
                int k=dinic(v,min(ed[i].w,rest));
                if(!k)dfn[v]=0;
                ed[i].w-=k;
                ed[i^1].w+=k;
                rest-=k;
            }
        }
        return flow-rest;
    }
    void init(){
        for(int i=2;i<=cnt;i+=2){
            ed[i].w+=ed[i^1].w;
            ed[i^1].w=0;
        }
    }
    int solve(int x,int y){
        s=x,t=y;
        init();
        int res=0;
        while(bfs())res+=dinic(s,1e9);
        return res;
    }
    void ad(int x,int y,int w){
        add(x,y,w);
        add(y,x,0);
    }
    void dfs(int x,int cl){
        col[x]=cl;
        for(int i=h[x];i;i=ed[i].nex){
            int v=ed[i].to;
            if(col[v]==cl||!ed[i].w)continue;
            dfs(v,cl);
        }
    }
    void build(int l,int r){
        if(l==r)return;
        int x=num[l],y=num[r];
        int res=solve(x,y);
        dfs(x,++tot);
        int L=l,R=r;
        for(int i=l;i<=r;i++){
            if(col[num[i]]==tot)numm[L++]=num[i];
            else numm[R--]=num[i];
        }
        for(int i=l;i<=r;i++)num[i]=numm[i];
        ::ans+=res;
        ::cjx.push_back({x,y,res});
        build(l,L-1);
        build(R+1,r);
    }
}
int n,m;
vector<int>poi[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        GHT::ad(x,y,w);
        GHT::ad(y,x,w);
    }
    for(int i=1;i<=n;i++){
        GHT::num[i]=i;
    }
    GHT::build(1,n);
    printf("%d\n",ans);
    stable_sort(cjx.begin(),cjx.end());
    for(int i=1;i<=n;i++)poi[i].push_back(i);
    for(node it:cjx){
        int x=find(it.x),y=find(it.y);
        fa[y]=x;
        poi[x].insert(poi[x].end(),poi[y].begin(),poi[y].end());
        poi[y].clear();
    }
    for(int it:poi[find(1)]){
        printf("%d ",it);
    }
    return  0;
}