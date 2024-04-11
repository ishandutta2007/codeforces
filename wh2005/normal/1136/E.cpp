#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ls(x) x<<1
#define rs(x) x<<1|1
const int N = 100009;
ll n,m,a[N],k[N];
struct pp{ll sum,val,siz,flag;}t[N*8];
void pushdown(ll c){
    if(!t[c].flag) return ;
    t[c].flag=0,t[ls(c)].flag=1,t[rs(c)].flag=1;
    t[ls(c)].val=t[c].val,t[ls(c)].sum=t[ls(c)].siz*t[ls(c)].val;
    t[rs(c)].val=t[c].val,t[rs(c)].sum=t[rs(c)].siz*t[rs(c)].val;
    return ;
}
void update(ll c){
    t[c].sum=t[ls(c)].sum+t[rs(c)].sum;
    t[c].siz=t[ls(c)].siz+t[rs(c)].siz;
}
void build(ll c,ll l,ll r){
    if(l==r){t[c].sum=a[l]-k[l-1],t[c].siz=1,t[c].flag=0;return ;}
    ll mid=(l+r)>>1;
    build(ls(c),l,mid);build(rs(c),mid+1,r);
    update(c);return ;
}
ll query(ll c,ll l,ll r,ll x){
    if(l==r) return t[c].sum;
    pushdown(c);
    ll mid=(l+r)>>1,ans;
    if(x<=mid) ans=query(ls(c),l,mid,x);
    if(x>mid) ans=query(rs(c),mid+1,r,x);
    update(c);
    return ans;
}
void modify(ll c,ll l,ll r,ll x,ll y,ll p){
    if(x<=l&&r<=y){
        t[c].flag=1,t[c].val=p,t[c].sum=t[c].siz*p;
        return ;
    }
    pushdown(c);
    ll mid=(l+r)>>1;
    if(x<=mid) modify(ls(c),l,mid,x,y,p);
    if(y>mid) modify(rs(c),mid+1,r,x,y,p);
    update(c);
    return ;
}
ll sum(ll c,ll l,ll r,ll x,ll y){
    if(x<=l&&r<=y) return t[c].sum;
    pushdown(c);
    ll mid=(l+r)>>1,ans=0;
    if(x<=mid) ans+=sum(ls(c),l,mid,x,y);
    if(y>mid) ans+=sum(rs(c),mid+1,r,x,y);
    update(c);
    return ans;
}
int main(){
    scanf("%lld",&n);k[0]=0;
    for(ll i=1ll;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1ll;i<n;i++) scanf("%lld",&k[i]);
    for(ll i=1ll;i<n;i++) k[i]=k[i-1]+k[i];
    build(1,1,n);
    for(ll i=1ll;i<n;i++) k[i]=k[i-1]+k[i];
    scanf("%lld",&m);
    for(ll i=1ll;i<=m;i++){
        char c;ll x,y;
        cin>>c>>x>>y;
        if(c=='+') {
            ll l=1,r=n,p=query(1,1,n,x)+y,pos=x;
            while(l<=r){
                ll mid=(l+r)>>1;
                if(query(1,1,n,mid)<=p) l=mid+1,pos=mid;
                else r=mid-1;
            }
            modify(1,1,n,x,pos,p);
        }
        if(c=='s') {
            printf("%lld\n",sum(1,1,n,x,y)+k[y-1]-k[max(x-2,0ll)]);
        }
    }
    return 0;
}