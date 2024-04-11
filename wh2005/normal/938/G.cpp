#include<bits/stdc++.h>
using namespace std;
#define vi vector<node >
#define pi pair<int ,int >
#define mcp(x,y) make_pair(x,y)
#define vii vector<int >
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
const int N = 1e6+9;
int n,m,q;
struct node{
    int u,v,w;
    node(int uu=0,int vv=0,int ww=0){u=uu,v=vv,w=ww;}
};
map<pi ,int >mp,mp2;
vi e[N<<2];
struct que{int u,v,ans;}qp[N];
struct mod{int l,r;node x;}md[N];
set<pi >s;
void modify(int c,int l,int r,int x,int y,node el){
    if(x<=l&&r<=y){e[c].push_back(el);return ;}
    int mid=(l+r)>>1;
    if(x<=mid) modify(ls(c),l,mid,x,y,el);if(y>mid) modify(rs(c),mid+1,r,x,y,el);
    return ;
}
int f[N],xr[N],siz[N];
int find(int x){return f[x]==x?x:find(f[x]);}
int sum(int x){int sum=0;while(f[x]!=x) sum^=xr[x],x=f[x];sum^=xr[x];return sum;}
void add(vii &a,int x){
    for(int i=30;i>=0;i--)
        if((x>>i)&1){
            if(!a[i]){a[i]=x;return ;}
            else x^=a[i];
        }
    return ;
}
int query(vii a,int x){
    int res=x;
    for(int i=30;i>=0;i--) res=min(res,res^a[i]);
    return res;
}
void dfs(int c,int l,int r,vii a){
    vi st;
    for(int i=0;i<e[c].size();i++){
        int u=e[c][i].u,v=e[c][i].v,w=e[c][i].w;
        int fu=find(u),fv=find(v);
        if(fu!=fv){
            if(siz[fu]>siz[fv]) swap(fu,fv);
            st.push_back((node){fu,fv,xr[fu]});
            f[fu]=fv,siz[fv]+=siz[fu],xr[fu]=sum(u)^w^sum(v);
        }
        else{int su=sum(u),sv=sum(v);add(a,su^sv^w);}
    }
    if(l==r){
        int u=qp[l].u,v=qp[l].v;
        int su=sum(u),sv=sum(v);qp[l].ans=query(a,su^sv);   
    }
    if(l<r){
        int mid=(l+r)>>1;
        dfs(ls(c),l,mid,a);dfs(rs(c),mid+1,r,a);
    }
    for(int i=st.size()-1;i>=0;i--){
        int u=st[i].u,v=st[i].v,w=st[i].w;
        f[u]=u,siz[v]-=siz[u],xr[u]=0;
    }
    return ;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        mp[mcp(u,v)]=1,mp[mcp(v,u)]=1;
        mp2[mcp(u,v)]=w,mp2[mcp(v,u)]=w;
        if(u>v) swap(u,v);
        s.insert(mcp(u,v));
    }
    scanf("%d",&q);int tim=1,tot=0;
    while(q--){
        int op,u,v,w;scanf("%d%d%d",&op,&u,&v);
        if(op==1){
            scanf("%d",&w);
            mp[mcp(u,v)]=tim,mp[mcp(v,u)]=tim;
            mp2[mcp(u,v)]=w,mp2[mcp(v,u)]=w;
            if(u>v) swap(u,v);
            s.insert(mcp(u,v));
        }
        if(op==2){
            int l=mp[mcp(u,v)],r=tim-1,w=mp2[mcp(u,v)];
            if(u>v) swap(u,v);s.erase(mcp(u,v));
            if(l>r) continue;node x(u,v,w);
            md[++tot]=(mod){l,r,x};
        }
        if(op==3){
            qp[tim].u=u,qp[tim].v=v;tim++;
        }
    }
    tim--;
    for(set<pi >::iterator it=s.begin();it!=s.end();++it){
        int l=mp[(*it)],r=tim;node x((*it).first,(*it).second,mp2[(*it)]);
        if(l<=r) md[++tot]=(mod){l,r,x};
    }
    for(int i=1;i<=tot;i++) 
        modify(1,1,tim,md[i].l,md[i].r,md[i].x);
    for(int i=1;i<=n;i++) f[i]=i,xr[i]=0,siz[i]=1;
    vii a;a.resize(32);
    dfs(1,1,tim,a);
    for(int i=1;i<=tim;i++) printf("%d\n",qp[i].ans);
    return 0;
}
/*
g++ CF938G.cpp -o A
*/