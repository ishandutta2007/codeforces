#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+10;
int ct;
struct line{
    int k,b;
    void add(int kk,int bb){
        k=kk;
        b=bb;
    }
    int calc(int x){
        return k*x+b;
    }
}li[N];
struct Li_Chao_Segment_Tree{
    int s[N<<2];
    void build(int rt,int l,int r){
        if(l>r)return;
        s[rt]=0;
        if(l==r)return;
        int mid=(l+r)>>1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
    }
    void upd(int rt,int l,int r,int L,int R,int u){
        if(l>r)return;
        if(R<l||r<L)return;
        int &v=s[rt],mid=(l+r)>>1;
        if(L<=l&&r<=R){
            if(li[v].calc(mid)<li[u].calc(mid))swap(v,u);
            if(li[u].calc(l)>li[v].calc(l))upd(rt<<1,l,mid,L,R,u);
            if(li[u].calc(r)>li[v].calc(r))upd(rt<<1|1,mid+1,r,L,R,u);
            return;
        }
        upd(rt<<1,l,mid,L,R,u);
        upd(rt<<1|1,mid+1,r,L,R,u);
    }
    int query(int rt,int l,int r,int d){
        if(l>r)return 0;
        if(r<d||d<l)return 0;
        int mid=(l+r)>>1;
        int res=li[s[rt]].calc(d);
        if(l==r)return res;
        return max(res,max(query(rt<<1,l,mid,d),query(rt<<1|1,mid+1,r,d)));
    }
}tr;
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
int n,a[N],siz[N],mig,g,w[N];
void getG(int x,int fa,int S){
    siz[x]=1;
    int now=0;
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==fa||w[v])continue;
        getG(v,x,S);
        siz[x]+=siz[v];
        now=max(now,siz[v]);
    }
    now=max(now,S-siz[x]);
    if(now<mig)mig=now,g=x;
}
struct node{
    int len,sum,ssum;
};
vector<node>ty;
int pans=0,height;
void dfs(int x,int fa,int dep,int sum1,int sum2){
    pans=max(pans,tr.query(1,1,height,dep)+sum2);
    ty.push_back({dep,sum1,sum2});
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(w[v]||v==fa)continue;
        dfs(v,x,dep+1,sum1+a[v],sum2+sum1+a[v]);
    }
}
int qhei(int x,int fa){
    int res=1;
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(w[v]||v==fa)continue;
        res=max(res,qhei(v,x)+1);
    }
    return res;
}
void solve(int x,int S){
    mig=1e9;
    getG(x,0,S);
    x=g;
    w[x]=1;
    pans=max(pans,a[x]);
    height=qhei(x,0);
    stack<int>ss;
    ct=0;
    li[++ct].add(a[x],a[x]);
    tr.build(1,1,height);
    tr.upd(1,1,height,1,height,ct);
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(w[v])continue;
        ss.push(v);
        ty.clear();
        dfs(v,x,1,a[v],a[v]);
        for(int o=0;o<(int)ty.size();o++){
            int sum=ty[o].sum+a[x],ssum=ty[o].sum*(ty[o].len+2)-ty[o].ssum+a[x];
            pans=max(pans,ssum);
            li[++ct].add(sum,ssum);
            tr.upd(1,1,height,1,height,ct);
        }
    }
    ct=0;
    tr.build(1,1,height);
    while(ss.size()){
        int v=ss.top();ss.pop();
        ty.clear();
        dfs(v,x,1,a[v],a[v]);
        for(int o=0;o<(int)ty.size();o++){
            int sum=ty[o].sum+a[x],ssum=ty[o].sum*(ty[o].len+2)-ty[o].ssum+a[x];
            pans=max(pans,ssum);
            li[++ct].add(sum,ssum);
            tr.upd(1,1,height,1,height,ct);
        }
    }
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(w[v])continue;
        solve(v,siz[v]>siz[x]?S-siz[x]:siz[v]);
    }
}
signed main(){
    scanf("%lld",&n);
    li[0].add(0,0);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    printf("%lld\n",(solve(1,n),pans));
    return  0;
}