#include<bits/stdc++.h>
#define dbg puts("?");
using namespace std;
const int N=4e5+10;
struct node{
    int c,q;
    bool operator<(const node b)const{
        return q==b.q?c<b.c:q>b.q;
    }
}a[N];
int ans[N];
struct nou{
    int mon,num;
    bool operator<(const nou b)const{
        return mon<b.mon;
    } 
}kk[N];
struct Splay{
    int son[N][2],fa[N],val[N],num[N],res[N],lazy1[N],lazy2[N],rt;
    queue<int>q;
    void init(){for(int i=1;i<N;i++)q.push(i);}
    bool get(int x){return x==son[fa[x]][1];}
    void discon(int x){son[fa[x]][get(x)]=0;fa[x]=0;}
    void clear(int x){discon(x);son[x][0]=son[x][1]=fa[x]=val[x]=0;q.push(x);}
    void rotate(int x){
        int y=fa[x],z=fa[y],chk=get(x);
        son[y][chk]=son[x][chk^1];
        if(son[x][chk^1])fa[son[x][chk^1]]=y;
        son[x][chk^1]=y;
        fa[y]=x,fa[x]=z;
        if(z)son[z][y==son[z][1]]=x;
    }
    void splay(int x,int goal){
        for(int f;(f=fa[x])!=goal;rotate(x))
            if(fa[f]!=goal)rotate(get(x)==get(f)?f:x);
        if(!goal)rt=x;
    }
    void add_tag(int x,int vl,int ct){
        if(!x)return;
        val[x]+=vl,res[x]+=ct;
        lazy1[x]+=vl,lazy2[x]+=ct;
    }
    int ne(int vle,int nu,int re,int f){
        int x=q.front();q.pop();
        son[x][0]=son[x][1]=0,fa[x]=f,val[x]=vle,num[x]=nu,res[x]=re,lazy1[x]=lazy2[x]=0;
        return x;
    }
    int build(int f,int l,int r){
        if(l>r)return 0;
        int mid=(l+r)>>1,x=ne(kk[mid].mon,kk[mid].num,0,f);
        son[x][0]=build(x,l,mid-1),son[x][1]=build(x,mid+1,r);
        return x;
    }
    void pushdown(int x){
        add_tag(son[x][0],lazy1[x],lazy2[x]);
        add_tag(son[x][1],lazy1[x],lazy2[x]);
        lazy1[x]=lazy2[x]=0;
    }
    int nxt(int k){
        int x=rt,resu=0;
        while(1){
            if(!x)return resu;
            pushdown(x);
            if(val[x]<=k)x=son[x][1];
            else{
                resu=x;
                x=son[x][0];
            }
        }
    }
    int pre(int k){
        int x=rt,resu=0;
        while(1){
            if(!x)return resu;
            pushdown(x);
            if(val[x]>=k)x=son[x][0];
            else{
                resu=x;
                x=son[x][1];
            }
        }
    }
    int split(int l,int r){
        // cout<<l<<' '<<r<<' '<<val[pre(l)]<<' '<<val[nxt(r)]<<endl;
        splay(pre(l),0),splay(nxt(r),rt);
        return son[son[rt][1]][0];
    }
    void insert(int vl,int nu,int re,int &x,int f){
        if(!x)return x=ne(vl,nu,re,f),splay(x,0);
        pushdown(x);
        if(val[x]<=vl)insert(vl,nu,re,son[x][1],x);
        else insert(vl,nu,re,son[x][0],x);
    }
    void dfs_insert(int x){
        if(!x)return;
        pushdown(x);
        insert(val[x],num[x],res[x],rt,0);
        dfs_insert(son[x][0]);
        dfs_insert(son[x][1]);
        clear(x);
    }
    void ope(int c){
        int now=split(c,c<<1);
        add_tag(now,-c,1);
        discon(now);
        add_tag(split((c<<1)+1,1e9+7),-c,1);
        dfs_insert(now);
    }
    void query(int x){
        if(!x)return;
        pushdown(x);
        ans[num[x]]=res[x];
        query(son[x][0]),query(son[x][1]);
    }
}tr;
int n;
int main(){
    tr.init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].c,&a[i].q);
    }
    stable_sort(a+1,a+n+1);
    int k;
    scanf("%d",&k);
    tr.insert(-1e9,0,0,tr.rt,0);
    tr.insert(2e9+7,k+1,0,tr.rt,0);
    int mon;
    for(int i=1;i<=k;i++)scanf("%d",&mon),tr.insert(mon,i,0,tr.rt,0);
    for(int i=1;i<=n;i++){
        tr.ope(a[i].c);
    }
    tr.query(tr.rt);
    for(int i=1;i<=k;i++)printf("%d ",ans[i]);
    return  0;
}