#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int ,int >
#define mcp(x,y) make_pair(x,y)
#define fi first
#define se second
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
const int N = 3e5+9;
int n,m,p,k,a[N];
struct seg{
    pi v[5];
    int tag,tot;
    void ins(int x,int y){
        for(int i=0;i<tot;i++)
            if(v[i].fi==x){v[i].se+=y;return ;}
        if(tot<k){
            v[tot].fi=x,v[tot].se=y;tot++;
            return ;
        }
        for(int i=0;i<tot;i++)
            if(v[i].se<y){
                swap(v[i].fi,x);
                swap(v[i].se,y);
            }
        for(int i=0;i<tot;i++) v[i].se-=y;
        return ;
    }
}t[N<<2];

seg operator+(seg x,seg y){
    seg z=x;z.tag=0;
    for(int i=0;i<y.tot;i++)
        z.ins(y.v[i].fi,y.v[i].se);
    return z;
}

void pushup(int c){t[c]=t[ls(c)]+t[rs(c)];return ;}
void update(int c,int l,int r,int z){
    t[c].tot=1;
    t[c].v[0]=mcp(z,r-l+1);
    t[c].tag=z;
    return ;
}
void pushdown(int c,int l,int r){
    if(!t[c].tag) return ;
    int mid=(l+r)>>1;
    update(ls(c),l,mid,t[c].tag);
    update(rs(c),mid+1,r,t[c].tag);
    t[c].tag=0;
    return ;
}

void build(int c,int l,int r){
    t[c].tag=0;
    if(l==r){t[c].tot=1,t[c].v[0]=mcp(a[l],1);return ;}
    int mid=(l+r)>>1;build(ls(c),l,mid);build(rs(c),mid+1,r);
    pushup(c);return ;
}

void modify(int c,int l,int r,int x,int y,int z){
    if(x<=l&&r<=y){update(c,l,r,z);return ;}
    pushdown(c,l,r);
    int mid=(l+r)>>1;
    if(x<=mid) modify(ls(c),l,mid,x,y,z);
    if(y>mid) modify(rs(c),mid+1,r,x,y,z);
    pushup(c);return ;
}

seg query(int c,int l,int r,int x,int y){
    if(x<=l&&r<=y) return t[c];
    pushdown(c,l,r);
    int mid=(l+r)>>1;
    seg ans;ans.tot=0;
    if(x<=mid) ans=ans+query(ls(c),l,mid,x,y);
    if(y>mid) ans=ans+query(rs(c),mid+1,r,x,y);
    pushup(c);return ans;
}

int main(){
    scanf("%d%d%d",&n,&m,&p);k=(100/p);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    while(m--){
        int op,l,r,x;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1){
            scanf("%d",&x);
            modify(1,1,n,l,r,x);
        }
        if(op==2){
            seg ans=query(1,1,n,l,r);
            printf("%d ",ans.tot);
            for(int i=0;i<ans.tot;i++) printf("%d ",ans.v[i].fi);
            puts("");
        }
    }
    return 0;
}