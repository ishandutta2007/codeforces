#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ls(x) x<<1
#define rs(x) x<<1|1
const int N = 200009;
int n,tot,len;ll p[N<<1];
struct pp{ll A,B;int C;}q[N];
struct segment{ll ans;int sum;}t[N*8];
ll min(ll x,ll y){return x>y?y:x;}

void init(){
    scanf("%d",&n);tot=0;
    for(int i=1;i<=n;i++){
        scanf("%d%lld%lld",&q[i].C,&q[i].A,&q[i].B);
        p[++tot]=q[i].A,p[++tot]=q[i].B,p[++tot]=q[i].A+1,p[++tot]=q[i].B+1;
    }
    p[++tot]=1;
    sort(p+1,p+tot+1);
    len=unique(p+1,p+tot+1)-p-1;
    for(int i=1;i<=n;i++){
        q[i].A=lower_bound(p+1,p+len+1,q[i].A)-p;
        q[i].B=lower_bound(p+1,p+len+1,q[i].B)-p;
    }
    return ;
}

void build(int c,int l,int r){
    if(l==r){t[c].ans=p[l],t[c].sum=1;return ;}
    int mid=(l+r)>>1;
    build(ls(c),l,mid);
    build(rs(c),mid+1,r);
    t[c].ans=min(t[ls(c)].ans,t[rs(c)].ans);t[c].sum=1;
    return ;
}

void downdate(int c,int x,int l){
    if(x!=0) t[c].sum=x; if(x==-1) t[c].ans=p[len]+1; if(x==1) t[c].ans=p[l];return ;
}

void update(int c){
    if(t[ls(c)].sum==t[rs(c)].sum) t[c].sum=t[ls(c)].sum;
    else t[c].sum=0;
    t[c].ans=min(t[ls(c)].ans,t[rs(c)].ans);
    return ;
}

void down(int c,int l,int r){
    downdate(ls(c),t[c].sum,l);downdate(rs(c),t[c].sum,(l+r)/2+1);t[c].sum=0;
}

void modify(int c,int l,int r,int L,int R,int k){
    if(L<=l&&r<=R){
        t[c].sum=k;
        if(k==-1) t[c].ans=p[len]+1;
        if(k==1) t[c].ans=p[l];
        return ;
    }
    down(c,l,r);
    int mid=(l+r)>>1;
    if(L<=mid) modify(ls(c),l,mid,L,R,k);
    if(R>mid) modify(rs(c),mid+1,r,L,R,k);
    t[c].ans=min(t[ls(c)].ans,t[rs(c)].ans);
    update(c);
    return ;
}

void redeem(int c,int l,int r,int L,int R){
    if(L<=l&&r<=R){
        if(t[c].sum==1) t[c].sum=-1;
        else if(t[c].sum==-1) t[c].sum=1;
        else goto part;
        if(t[c].sum==-1) t[c].ans=p[len]+1;
        if(t[c].sum==1) t[c].ans=p[l];
        return ;
    }
    part:;
    down(c,l,r);
    int mid=(l+r)/2;
    if(L<=mid) redeem(ls(c),l,mid,L,R);
    if(R>mid) redeem(rs(c),mid+1,r,L,R);
    update(c);
    return ;
}
void solve(int c,int l,int r){
    if(c==1) modify(1,1,len,l,r,-1);
    if(c==2) modify(1,1,len,l,r,1);
    if(c==3) redeem(1,1,len,l,r);
}
int main(){
    init();
    build(1,1,len);
    for(int i=1;i<=n;i++){
        solve(q[i].C,q[i].A,q[i].B);
        printf("%lld\n",t[1].ans);
    }
    return 0;
}