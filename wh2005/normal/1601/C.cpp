#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
const int N = 1e6+9;
int T,n,m,a[N],b[N];

struct pp{int id,val,col1,col0;}t[N<<2];
void pushup(int c){
    t[c].col0=t[ls(c)].col0+t[rs(c)].col0;
    t[c].col1=t[ls(c)].col1+t[rs(c)].col1;
    t[c].val=min(t[ls(c)].val+t[rs(c)].col0,t[rs(c)].val+t[ls(c)].col1);
    return ;
}
void build(int c,int l,int r){
    if(l==r){
        t[c].id=l,t[c].val=0;
        t[c].col1=1,t[c].col0=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(ls(c),l,mid);build(rs(c),mid+1,r);
    pushup(c);return ;
}
int quer(){
    return min(t[1].val,min(t[1].col0,t[1].col1));
}
void modify(int c,int l,int r,int x,int ca,int cb){
    if(l==r){
        t[c].col1=ca,t[c].col0=cb;
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) modify(ls(c),l,mid,x,ca,cb);
    if(x>mid) modify(rs(c),mid+1,r,x,ca,cb);
    pushup(c);return ;
}
struct qq{
    int id,x;
}p[N];
bool cmp(qq x,qq y){
    return x.x<y.x;
}

struct treearray{
    int tr[N];
    void clear(){for(int i=1;i<=n;i++) tr[i]=0;return ;}
    int lowbit(int x){return x&(-x);}
    void add(int x,int d){
        while(x<=n){
            tr[x]+=d;
            x+=lowbit(x);
        }
        return ;
    }
    int sum(int x){
        int y=0;
        while(x){
            y+=tr[x];
            x-=lowbit(x);
        }
        return y;
    }
}tp;

namespace LSH{
    int p[N],cnt;
    void LSH(int *a){
        for(int i=1;i<=n;i++) p[i]=a[i];
        sort(p+1,p+n+1);cnt=unique(p+1,p+n+1)-p-1;
        for(int i=1;i<=n;i++) a[i]=lower_bound(p+1,p+cnt+1,a[i])-p;
        return ;
    }
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);
        sort(b+1,b+m+1);
        build(1,1,n);
        for(int i=1;i<=n;i++) p[i].id=i,p[i].x=a[i];
        sort(p+1,p+n+1,cmp);
        int j=1,h=1;
        ll ans=0;
        for(int i=1;i<=m;i++){
            while(j<=n&&p[j].x<b[i]){
                modify(1,1,n,p[j].id,0,1);
                j++;
            }
            h=max(h,j);
            while(h<=n&&p[h].x==b[i]){
                modify(1,1,n,p[h].id,0,0);
                h++;
            }
            ans+=quer();
        }
        tp.clear();
        LSH::LSH(a);
        for(int i=1;i<=n;i++){
            ans+=tp.sum(n)-tp.sum(a[i]);
            tp.add(a[i],1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
 b  b  0
 a  b 

*/