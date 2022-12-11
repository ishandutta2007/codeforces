#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
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
int cn,n,a[N],b[N],siz[N],hs[N],dfn[N],ct,st[N],en[N],xx[N],yy[N],p[N];
long long dp[N];
struct node{
    int to,iss;
}q[N];
void init(int x,int fa){
    siz[x]=1;
    dfn[++ct]=x;
    st[x]=ct;
    int now=0;
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==fa)continue;
        init(v,x);
        if(siz[v]>now)now=siz[v],hs[x]=v;
        siz[x]+=siz[v];
    }
    en[x]=ct;
}
bool cmp1(int x,int y){
    return xx[q[x].to]==xx[q[y].to]?dp[q[x].to]<dp[q[y].to]:xx[q[x].to]<xx[q[y].to];
}
bool cmp2(int x,int y){
    return a[q[x].to]<a[q[y].to];
}
long double slope(int x,int y){
    return (long double)(dp[x]-dp[y])/(xx[x]-xx[y]);
}
inline void solve(int l,int r){
    if(l==r)return;
    int mid=(l+r)>>1;
    solve(l,mid);
    stable_sort(p+l,p+mid+1,cmp1);
    stable_sort(p+mid+1,p+r+1,cmp2);
    int qq[N],head=0,tail=1;
    for(int i=l;i<=mid;i++){
        if(i!=l&&xx[q[p[i]].to]==xx[qq[head]])continue;
        while(head>tail&&slope(qq[head],q[p[i]].to)<=slope(qq[head-1],qq[head]))head--;
        qq[++head]=q[p[i]].to;
    }
    for(int i=mid+1;i<=r;i++){
        if(!q[p[i]].iss)continue;
        while(head>tail&&(a[q[p[i]].to]>=slope(qq[tail],qq[tail+1])))tail++;
        int now=qq[tail];
        dp[q[p[i]].to]=min(dp[q[p[i]].to],dp[now]+1ll*a[q[p[i]].to]*b[now]);
    }
    stable_sort(p+mid+1,p+r+1);
    solve(mid+1,r);
}
void dfs2(int x,int fa,int calc){
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==fa||v==hs[x])continue;
        dfs2(v,x,0);
    }
    if(!hs[x])dp[x]=0;
    else dfs2(hs[x],x,1);
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==fa||v==hs[x])continue;
        for(int o=st[v];o<=en[v];o++)q[++cn]={dfn[o],0};
    }
    q[++cn]={x,!!hs[x]};
    if(!calc){for(int i=1;i<=cn;i++)p[i]=i;solve(1,cn),cn=0;}
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]),xx[i]=-b[i];
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    memset(dp,127,sizeof dp);
    init(1,0);
    dfs2(1,0,0);
    for(int i=1;i<=n;i++)printf("%lld ",dp[i]);
    return  0;
}