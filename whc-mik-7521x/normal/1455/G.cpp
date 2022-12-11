#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2e5;
vector<int>ed[N];
struct seg{
    int root[N],ls[N<<5],rs[N<<5],cnt=0;
    long long t[N<<5],tag[N<<5];
    seg(){memset(t,63,sizeof t),memset(tag,0,sizeof tag);memset(root,0,sizeof root);}
    void add_tag(int rt,long long val){if(!rt)return;t[rt]+=val;tag[rt]+=val;}
    void pushup(int rt){t[rt]=min(t[ls[rt]],t[rs[rt]]);}
    void pushdown(int rt){add_tag(ls[rt],tag[rt]),add_tag(rs[rt],tag[rt]);tag[rt]=0;}
    void upd(int &rt,int l,int r,int L,int R,long long val){
        if(!rt)rt=++cnt;
        if(L<=l&&r<=R)return add_tag(rt,val);
        pushdown(rt);
        int mid=(l+r)>>1;
        if(mid>=L)upd(ls[rt],l,mid,L,R,val);
        if(mid<R)upd(rs[rt],mid+1,r,L,R,val);
        pushup(rt);
    }
    void modify(int &rt,int l,int r,int X,long long val){
        if(!rt)rt=++cnt;
        t[rt]=min(t[rt],val);
        if(l==r)return;
        pushdown(rt);
        int mid=(l+r)>>1;
        if(mid>=X)modify(ls[rt],l,mid,X,val);
        else modify(rs[rt],mid+1,r,X,val);
        pushup(rt);
    }
    void ch(int &rt,int l,int r,int X,long long val){
        if(!rt)rt=++cnt;
        if(l==r)return t[rt]=val,void();
        pushdown(rt);
        int mid=(l+r)>>1;
        if(mid>=X)ch(ls[rt],l,mid,X,val);
        else ch(rs[rt],mid+1,r,X,val);
        pushup(rt);
    }
    long long query(int rt,int l,int r,int L,int R){
        if(!rt)return 1e18;
        if(L<=l&&r<=R)return t[rt];
        pushdown(rt);
        int mid=(l+r)>>1;
        long long res=1e18;
        if(L<=mid)res=min(res,query(ls[rt],l,mid,L,R));
        if(R>mid)res=min(res,query(rs[rt],mid+1,r,L,R));
        return res;
    }
    void merge(int &rt1,int rt2,int l,int r){
        if(!rt1)return rt1=rt2,void();
        if(!rt2)return;
        t[rt1]=min(t[rt1],t[rt2]);
        if(l==r)return;
        pushdown(rt1);
        pushdown(rt2);
        int mid=(l+r)>>1;
        merge(ls[rt1],ls[rt2],l,mid);
        merge(rs[rt1],rs[rt2],mid+1,r);
    }
}tr;
int tp[N],val[N],co[N],st[N],n,S;
void dfs(int x){
    if(tp[x]==1)return;
    tr.modify(tr.root[x],0,M,val[x],0);
    for(int v:ed[x]){
        dfs(v);
        if(tp[v]==1){
            long long mi=tr.query(tr.root[x],0,M,0,M);
            tr.upd(tr.root[x],0,M,0,M,co[v]);
            if(st[v]!=S)tr.modify(tr.root[x],0,M,st[v],mi);
        }
        else{
            long long mi=tr.query(tr.root[x],0,M,val[v],val[v]);
            if(mi<1e18){
                tr.ch(tr.root[x],0,M,val[v],1e18);
                tr.upd(tr.root[v],0,M,0,M,mi);
                tr.merge(tr.root[x],tr.root[v],0,M);
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&S);
    stack<int>sta;
    sta.push(1);
    tp[1]=2,val[1]=0;
    for(int i=1;i<=n;i++){
        char s[100];
        int y,v;
        scanf("%s",s);
        if((string)s!="end")ed[sta.top()].push_back(i+1);
        if((string)s=="set"){
            scanf("%d%d",&y,&v);
            tp[i+1]=1;
            co[i+1]=v;
            st[i+1]=y;
        }
        else if((string)s=="if"){
            scanf("%d",&y);
            tp[i+1]=2;
            val[i+1]=y;
            sta.push(i+1);
        }
        else{
            sta.pop();
        }
    }
    dfs(1);
    printf("%lld",tr.query(tr.root[1],0,M,0,M));
    return  0;
}