#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
struct edge{
    int w,to,nxt;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et,int wi){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].w=wi;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
int n,q,dep[N],fa[N][21],a[N],ct;
long long dp[N],dis[N],eddis[N],vedis[N],fans[N],fc[N],lans[N],sdp[N];
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    int ste=dep[x]-dep[y];
    for(int i=20;i>=0;i--){
        if(ste>=(1<<i))ste-=(1<<i),x=fa[x][i];
    }
    if(x==y)return y;
    for(int i=20;i>=0;i--){
        if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
    }
    return fa[x][0];
} 
void lca_init(){
    for(int o=1;o<=20;o++)
    for(int i=1;i<=n;i++){
        fa[i][o]=fa[fa[i][o-1]][o-1];
    }
}
void dfs(int x,int f){
    dep[x]=dep[f]+1;
    fa[x][0]=f;
    dp[x]=a[x];
    vedis[x]+=a[x];
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==f)continue;
        fc[v]=ed[i].w;
        vedis[v]+=vedis[x];
        eddis[v]=eddis[x]+ed[i].w;
        dfs(v,x);
        if(dp[v]>=ed[i].w*2)dp[x]+=dp[v]-ed[i].w*2;
    }
}
void dfs2(int x,int f){
    vector<int>vec;
    vector<long long>per;
    vector<long long>suf;
    sdp[x]=sdp[f]+dp[x];
    lans[x]=max(fans[x]-2*fc[x],0ll);
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==f)continue;
        dis[v]=dis[x]+max(0ll,dp[v]-ed[i].w*2);
        vec.push_back(v);
        per.push_back(max(0ll,dp[v]-ed[i].w*2));
        suf.push_back(max(0ll,dp[v]-ed[i].w*2));
    }
    for(int i=1;i<(int)per.size();i++)per[i]+=per[i-1];
    for(int i=(int)suf.size()-2;i>=0;i--)suf[i]+=suf[i+1];
    for(int i=0;i<(int)vec.size();i++){
        fans[vec[i]]=max(fans[x]-2*fc[x],0ll)+(i?per[i-1]:0)+(i!=(int)suf.size()-1?suf[i+1]:0)+a[x];
        dfs2(vec[i],x);
    }
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        add(x,y,w);
        add(y,x,w);
    }
    dfs(1,0);
    dfs2(1,0);
    lca_init();
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        int lc=lca(x,y);
        long long ans=sdp[x]+sdp[y]-sdp[lc]-sdp[fa[lc][0]]-(dis[x]+dis[y]-2ll*dis[lc])+lans[lc]-eddis[x]-eddis[y]+2ll*eddis[lc];
        printf("%lld\n",ans);
    }
    return  0;
}