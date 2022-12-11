#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
struct edge{
    int to,nex;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nex=h[st];
    h[st]=cnt;
}
int n,m,col[N],ct[N],a[N],cn,st[N],en[N],dfn[N],ccnt[N],ans[N],d[N],siz[N],hs[N];
vector<pair<int,int>>q[N];
void dfs(int x,int fa){
    siz[x]=1;
    dfn[++cn]=x;
    st[x]=cn;
    int now=0;
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==fa)continue;
        dfs(v,x);
        siz[x]+=siz[v];
        if(siz[v]>now)hs[x]=v,now=siz[v];
    }
    en[x]=cn;
}
void inc(int x){
    ++ccnt[++ct[col[x]]];
}
void dec(int x){
    ccnt[ct[col[x]]--]--;
}
int query(int x){
    return ccnt[x];
}
void solve(int x,int fa,int kep){
    for(int i=h[x];i;i=ed[i].nex){
        if(ed[i].to!=fa&&ed[i].to!=hs[x]){
            solve(ed[i].to,x,0);
        }
    }
    if(hs[x])solve(hs[x],x,1);
    for(int i=h[x];i;i=ed[i].nex){
        if(ed[i].to!=fa&&ed[i].to!=hs[x]){
            for(int o=st[ed[i].to];o<=en[ed[i].to];o++){
                inc(dfn[o]);
            }
        }
    }
    inc(x);
    for(int i=0;i<(int)q[x].size();i++){
        ans[q[x][i].second]=query(q[x][i].first);
    }
    if(!kep){
        for(int i=st[x];i<=en[x];i++)dec(dfn[i]);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&col[i]);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }   
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        q[x].push_back({y,i});
    }
    dfs(1,0);
    solve(1,0,1);
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return  0;
}