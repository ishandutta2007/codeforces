#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<cassert>
#include<algorithm>
#include<ctime>
#include<random>

using namespace std;
mt19937 rd(time(0));

#define ri int
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

ll mod;
ll add(ll x,ll y){return (x+=y)<mod?x:x-mod;}
ll dec(ll x,ll y){return (x-=y)<0?x+mod:x;}
ll ksm(ll d,ll t,ll res=1){for(;t;t>>=1,d=d*d%mod) if(t&1) res=res*d%mod;return res;}

ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0) return x=1,y=0,a;
    ll tmpx=y,tmpy;
    ll g=exgcd(b,a%b,tmpx,tmpy);
    x=tmpy;
    y=tmpx-(a/b)*x;
    return g;
}
ll inv(ll w){
    assert(__gcd(w,mod)==1);
    ll iv,tmp;
    exgcd(w,mod,iv,tmp);
    iv=(iv%mod+mod)%mod;
    // if(iv<0) 
    // printf("[%lld %lld %lld %lld]\n",w,mod,iv,tmp);
    assert(w*iv%mod==1);
    return iv;
}
const int MAXN=1e5+7;
vector<int> fac;
struct node{
    ll w,f[10];
    void init(){
        w=1;
        memset(f,0,sizeof(f));
    }
    bool check(){
        if(w!=1) return 1;
        for(ri i=0;i<fac.size();++i) if(f[i]!=0) return 1;
        return 0;
    }
};
node operator*(const node & a,const node &b){
    node c;c.w=a.w*b.w%mod;
    for(ri i=0;i<fac.size();++i) c.f[i]=a.f[i]+b.f[i];
    return c;
}
node operator/(const node &a,const node &b){
    node c;c.w=a.w*inv(b.w)%mod;
    for(ri i=0;i<fac.size();++i) c.f[i]=a.f[i]-b.f[i];
    return c;
}
void sieve(){
    fac.reserve(10);
    ll w=mod;
    for(ri i=2;i<=1e5;++i) if(w%i==0){
        while(w%i==0) w/=i;
        fac.push_back(i);
    }
    if(w!=1) fac.push_back(w);
    // for(auto x:fac) printf("%d ",x);
    // puts("");
}
node trans_node(ll x){
    node c;c.init();
    for(ri i=0;i<fac.size();++i) while(x%fac[i]==0) c.f[i]++,x/=fac[i];
    c.w=x;
    return c;
}
ll trans_num(const node &c){
    ll res=c.w;
    // printf("[%lld]\n",c.w);
    // for(ri i=0;i<fac.size();++i) printf("%lld ",c.f[i]);
    // puts("");
    for(ri i=0;i<fac.size();++i) res=res*ksm(fac[i],c.f[i])%mod;
    // printf("%lld\n",res);
    return res;
}
int n;
node a[MAXN];
struct segT{
    #define lc u<<1
    #define rc u<<1|1
    #define mid (L+R>>1)
    ll t[MAXN<<2];
    node tag[MAXN<<2];
    ll tagw[MAXN<<2];
    void update(int u){t[u]=add(t[lc],t[rc]);}
    void pushr(int u,ll v,const node &w){
        t[u]=t[u]*v%mod;
        tagw[u]=tagw[u]*v%mod;
        tag[u]=tag[u]*w;
    }
    void pushdown(int u){
        if(tag[u].check()){
            pushr(lc,tagw[u],tag[u]);
            pushr(rc,tagw[u],tag[u]);
            tag[u].init(),tagw[u]=1;
        }
    }
    void build(int u,int L=1,int R=n){
        tag[u].init(),tagw[u]=1;
        if(L==R) return t[u]=trans_num(a[L]),void();
        build(lc,L,mid),build(rc,mid+1,R);
        update(u);
    }
    void modify(int u,ll v,const node &w,int l,int r,int L=1,int R=n){
        if(l==L&&r==R) return pushr(u,v,w);
        pushdown(u);
        if(r<=mid) modify(lc,v,w,l,r,L,mid);else if(l>mid) modify(rc,v,w,l,r,mid+1,R);
        else modify(lc,v,w,l,mid,L,mid),modify(rc,v,w,mid+1,r,mid+1,R);
        update(u);
    }
    void div(int u,const node &w,int p,int L=1,int R=n){
        if(L==R){
            a[L]=a[L]*tag[u],tag[u].init();
            a[L]=a[L]/w;
            // printf("[%lld]:",a[L].w);
            // for(ri i=0;i<fac.size();++i) printf("%lld ",a[L].f[i]);puts("");
            t[u]=trans_num(a[L]);
            return;
        }
        pushdown(u);
        p<=mid?div(lc,w,p,L,mid):div(rc,w,p,mid+1,R);
        update(u);
    }
    ll query(int u,int l,int r,int L=1,int R=n){
        if(l==L&&r==R) return t[u];
        pushdown(u);
        if(r<=mid) return query(lc,l,r,L,mid);else if(l>mid) return query(rc,l,r,mid+1,R);
        else return add(query(lc,l,mid,L,mid),query(rc,mid+1,r,mid+1,R));
    }
}T;
int q;
int main(){
    // freopen("rand.in","r",stdin);
    scanf("%d%lld",&n,&mod);
    sieve();
    for(ri i=1;i<=n;++i){
        int w;scanf("%d",&w);
        a[i]=trans_node(w);
        // printf("[%lld]\n",a[i].w);
        // printf("%lld ",trans_num(a[i]));
    }
    T.build(1);
    // puts("");
    scanf("%d",&q);
    while(q--){
        int op,l,r;
        ll w;
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d%lld",&l,&r,&w);
            T.modify(1,w,trans_node(w),l,r);
            node tmp=trans_node(w);
            // printf("[%lld]:",tmp.w);for(ri i=0;i<fac.size();++i) printf("%lld ",tmp.f[i]);puts("");
        }
        if(op==2){
            scanf("%d%lld",&l,&w);
            node tmp=trans_node(w);
            // printf("[%lld]:",tmp.w);for(ri i=0;i<fac.size();++i) printf("%lld ",tmp.f[i]);puts("");
            T.div(1,trans_node(w),l);
        }
        if(op==3){
            scanf("%d%d",&l,&r);
            printf("%lld\n",T.query(1,l,r));
        }
    }
}