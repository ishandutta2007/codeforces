#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int kk[N];
struct Splay{
    int siz[N],son[N][2],fa[N],val[N],num[N],mx[N],rt,tot,lazy[N];
    void upd(int x){if(!x)return;siz[x]=siz[son[x][0]]+siz[son[x][1]]+1;mx[x]=max(val[x],max(mx[son[x][0]],mx[son[x][1]]));}
    bool get(int x){return x==son[fa[x]][1];}
    void clear(int x){son[x][0]=son[x][1]=fa[x]=val[x]=siz[x]=0;}
    void rotate(int x){
        int y=fa[x],z=fa[y],chk=get(x);
        son[y][chk]=son[x][chk^1];
        if(son[x][chk^1])fa[son[x][chk^1]]=y;
        son[x][chk^1]=y;
        fa[y]=x,fa[x]=z;
        if(z)son[z][y==son[z][1]]=x;
        upd(y),upd(x);
    }
    void splay(int x,int goal){
        for(int f;(f=fa[x])!=goal;rotate(x))
            if(fa[f]!=goal)rotate(get(x)==get(f)?f:x);
        if(!goal)rt=x;
    }
    void add_tag(int x,int d){
        if(!x)return;
        lazy[x]+=d;
        val[x]+=d;
        mx[x]+=d;
    }
    void pushdown(int x){
        if(lazy[x]){
            add_tag(son[x][0],lazy[x]);
            add_tag(son[x][1],lazy[x]);
            lazy[x]=0;
        }
    }
    int ne(int f,int d,int nu){
        int now=++tot;
        fa[now]=f,val[now]=d,siz[now]=1,num[now]=nu,mx[now]=d;
        return now;
    }
    int find(int k){
        int cur=rt;
        while(1){
            pushdown(cur);
            if(siz[son[cur][0]]>=k)cur=son[cur][0];
            else{
                k-=siz[son[cur][0]]+1;
                if(k<=0)return cur;
                cur=son[cur][1];
            }
        }
    }
    int split(int l,int r){
        splay(find(l),0);
        splay(find(r+2),rt);
        return son[son[rt][1]][0];
    }
    void add(int l,int r,int d){
        add_tag(split(l,r),d);
    }
    int build(int l,int r,int f){
        if(l>r)return 0;
        int mid=(l+r)>>1,now=ne(f,kk[mid],-1);
        son[now][0]=build(l,mid-1,now);
        son[now][1]=build(mid+1,r,now);
        upd(now);
        return now;
    }
    int query(int len,int vl){
        int cur=split(1,len),tot=0;
        while(1){
            if(!cur)return tot;
            pushdown(cur);
            if(mx[son[cur][0]]>vl){
                cur=son[cur][0];
            }
            else{
                tot+=siz[son[cur][0]];
                if(val[cur]>vl)return tot;
                else tot+=1,cur=son[cur][1];
            }
        }
    }
    void insert(int l,int r,int d,int nu){
        split(l,r);
        son[son[rt][1]][0]=ne(son[rt][1],d,nu);
        upd(son[rt][1]),upd(rt);
    }
    void print(int x){
        if(!x)return;
        print(son[x][1]);
        printf("%d ",num[x]);
        print(son[x][0]);
    }
}tr;
int n,a,c;
int main(){
    tr.rt=tr.build(1,2,0);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a,&c);
        int now=tr.query(min(c,i-1),a);
        // tr.add(now+1,i-1,1);
        tr.insert(now+1,now,a,i);
    }
    tr.print(tr.split(1,n));
    return  0;
}