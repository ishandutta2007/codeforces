#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,hei[N],s[N],ans=1e9+10;
struct seg{
    int t[N<<2],tag[N<<2];
    void add_tag(int rt,int d){t[rt]+=d,tag[rt]+=d;}
    void pushdown(int rt){
        add_tag(rt<<1,tag[rt]);
        add_tag(rt<<1|1,tag[rt]);
        tag[rt]=0;
    }
    void upd(int rt,int l,int r,int L,int R,int d){
        if(L>R)return;
        if(L<=l&&r<=R)return add_tag(rt,d);
        int mid=(l+r)>>1;
        pushdown(rt);
        if(L<=mid)upd(rt<<1,l,mid,L,R,d);
        if(R>mid)upd(rt<<1|1,mid+1,r,L,R,d);
        t[rt]=min(t[rt<<1],t[rt<<1|1]);
    }
    int query(int rt,int l,int r){
        if(l==r)return l;
        pushdown(rt);
        int mid=(l+r)>>1;
        if(t[rt<<1]<0)return query(rt<<1,l,mid);
        return query(rt<<1|1,mid+1,r);
    }
}tr;
struct ope{
    int l,r,d;
};
struct edge{
    int to,nxt;
};
multiset<int>st[N];
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
stack<ope>stk;
void clear(int x){
    while(stk.size()&&x)x--,tr.upd(1,1,k,stk.top().l,stk.top().r,-stk.top().d),stk.pop();
}
int find(int x){
    int l=1,r=k,mid,res=k+1;
    while(l<=r){
        mid=(l+r)>>1;
        if(s[mid]<=x)res=mid,r=mid-1;
        else l=mid+1;
    }
    return res;
}
void dfs(int x,int fa,int mx,int sx){
    tr.upd(1,1,k,find(hei[mx]),k,1);
    st[mx].insert(hei[sx]);
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa)continue;
        if(hei[v]<hei[mx])dfs(v,x,v,mx);
        else if(hei[v]<hei[sx])dfs(v,x,mx,v);
        else dfs(v,x,mx,sx);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&hei[i]);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    hei[0]=1e9;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)scanf("%d",&s[i]);
    stable_sort(s+1,s+k+1);
    reverse(s+1,s+k+1);
    dfs(1,0,1,0);
    for(int i=1;i<=k;i++)tr.upd(1,1,k,i,i,-i);
    if(tr.t[1]>=0)return puts("0"),0;
    for(int i=1;i<=n;i++){
        auto now=st[i];
        int last=0,ct=now.size(),R=find(hei[i]);
        // cout<<i<<' '<<tr.t[1]<<endl;
        while(now.size()){
            last=*now.begin();
            int kk=find(last);
            tr.upd(1,1,k,kk,R-1,ct);
            stk.push({kk,R-1,ct});
            R=kk;
            while(now.size()&&*now.begin()<=last)ct--,now.erase(now.begin());
            if(tr.t[1]>=0)break;
        }
        // cout<<i<<' '<<tr.t[1]<<endl;
        if(tr.t[1]>=0){
            clear(1);
            ans=min(ans,s[tr.query(1,1,k)]-hei[i]);
        }
        // cout<<i<<' '<<ans<<endl;
        clear(1e9);
    }
    printf("%d",ans<=1e9?ans:-1);
    return 0;
}