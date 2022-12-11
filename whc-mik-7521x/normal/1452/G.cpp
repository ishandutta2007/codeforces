#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,k,siz[N],mx[N],vis[N],del[N],zxw,zx,cnt1,dis[N<<3],kk,resu[N];
struct edge{
    int to,nxt;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
struct node{
    int belong,dep,len;
    bool operator<(const node b)const{
        return dep<b.dep;
    }
}ve[N];
void find_zx(int x,int S){
    siz[x]=1;
    mx[x]=0;
    vis[x]=kk;
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(vis[v]==kk||del[v])continue;
        find_zx(v,S);
        siz[x]+=siz[v];
        mx[x]=max(mx[x],siz[v]);
    }
    mx[x]=max(mx[x],S-siz[x]);
    if(mx[x]<zxw)zxw=mx[x],zx=x;
}
vector<int>vl;
int tsz;
void dfs(int x,int dep){
    siz[x]=1;
    vis[x]=kk;
    if(dis[x]>dep)vl[min(tsz-1,dis[x]-dep-1)]=max(vl[min(tsz-1,dis[x]-dep-1)],dis[x]);
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(vis[v]==kk||del[v])continue;
        dfs(v,dep+1);
        siz[x]+=siz[v];
    }
}
void upd(int x,int dep){
    vis[x]=kk;
    resu[x]=max(resu[x],vl[dep]);
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(vis[v]==kk||del[v])continue;
        upd(v,dep+1);
    }
}
void solve(int x,int S){
    tsz=S;
    zxw=1e9,zx=-1;
    kk++;
    find_zx(x,S);
    x=zx;
    kk++;
    vl.clear();
    vl.resize(S);
    dfs(x,0);
    for(int i=S-2;i>=0;i--)vl[i]=max(vl[i],vl[i+1]);
    kk++;
    upd(x,0);
    del[x]=1;
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(del[v])continue;
        solve(v,siz[v]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    memset(dis,-1,sizeof dis);
    queue<int>q;
    scanf("%d",&k);
    while(k--){
        int x;
        scanf("%d",&x);
        q.push(x);
        dis[x]=0;
    }
    while(q.size()){
        int x=q.front();
        q.pop();
        for(int i=h[x];i;i=ed[i].nxt){
            int v=ed[i].to;
            if(dis[v]!=-1)continue;
            dis[v]=dis[x]+1;
            q.push(v);
        }
    }
    solve(1,n);
    for(int i=1;i<=n;i++)printf("%d ",resu[i]);
    return  0;
}