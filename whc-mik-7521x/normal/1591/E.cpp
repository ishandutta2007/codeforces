#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
set<int>st[N],exi;
struct que{
    int l,k,num;
};
vector<que>v[N];
int t,n,q,ans[N],val[N],tim[N];
struct edge{
    int to,nex;
};
edge ed[N<<1];
int cnt,h[N];
inline void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nex=h[st];
    h[st]=cnt;
}
int sum[N<<2];
inline void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
inline void upd(int rt,int l,int r,int L,int d)
{
    if(l==r)
    {
        sum[rt]+=(r-l+1)*d;
        return;
    }
    int mid=(l+r)>>1;
    if(L<=mid) upd(rt<<1,l,mid,L,d);
    if(L>mid) upd(rt<<1|1,mid+1,r,L,d);
    pushup(rt);
}
inline int query(int rt,int l,int r,int L,int R)
{
    if(L<=l && r<=R)
    {
        return sum[rt];
    }
    int mid=(l+r)>>1,res=0;
    if(L<=mid) res += query(rt<<1,l,mid,L,R);
    if(R>mid) res += query(rt<<1|1,mid+1,r,L,R);
    return res;
}
inline int getval(int rt,int l,int r,int now){
    if(l==r)return l;
    int mid=(l+r)>>1;
    if(sum[rt<<1]<now)return getval(rt<<1|1,mid+1,r,now-sum[rt<<1]);
    else return getval(rt<<1,l,mid,now);
}
inline void dfs(int u){
    if(st[tim[val[u]]].find(val[u])!=st[tim[val[u]]].end())st[tim[val[u]]].erase(val[u]);
    upd(1,0,n,tim[val[u]],-1);
    tim[val[u]]++;
    st[tim[val[u]]].insert(val[u]);
    upd(1,0,n,tim[val[u]],1);
    for(int i=0;i<(int)v[u].size();i++){
        int now=v[u][i].k,l=v[u][i].l,nu=v[u][i].num;
        now+=query(1,0,n,0,l-1);
        if(query(1,0,n,0,n)<now)ans[nu]=-1;
        else ans[nu]=*st[getval(1,0,n,now)].begin();
    }
    for(int i=h[u];i;i=ed[i].nex)dfs(ed[i].to);
    if(st[tim[val[u]]].find(val[u])!=st[tim[val[u]]].end())st[tim[val[u]]].erase(val[u]);
    upd(1,0,n,tim[val[u]],-1);
    tim[val[u]]--;
    st[tim[val[u]]].insert(val[u]);
    upd(1,0,n,tim[val[u]],1);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        cnt=0;
        upd(1,0,n,0,n);
        for(int i=1;i<=n;i++)scanf("%d",&val[i]),v[i].clear(),h[i]=0;
        for(int i=2;i<=n;i++){
            int x;
            scanf("%d",&x);
            add(x,i);
        }
        for(int i=1;i<=q;i++){ 
            int x,l,k;
            scanf("%d%d%d",&x,&l,&k);
            v[x].push_back((que){l,k,i});
        }
        dfs(1);
        for(int i=1;i<=q;i++){
            printf("%d ",ans[i]);
        }
        puts("");
        upd(1,0,n,0,-n);
    }
    return  0;
}