#include<bits/stdc++.h>
using namespace std;
#define K(x...){cerr<<"BEGIN    "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T,class... A>void Err(T a,A... x){cerr<<a<<',';Err(x...);}
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<')';Err(x...);}
template<template<class...> class T,class t,class...A>void Err(T<t>a,A...x){cerr<<a.size()<<":{";for(auto v:a)Err(v);cerr<<"},";Err(x...);}
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rng);}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#endif
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vl;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=6e5+10,M=500;
const ll mod=998244353;

int n;
pii mi[N<<2];
int ar[N],br[N],f[N],nxt[N];
vi edg[N];
void build(int o=1,int l=1,int r=n){
    if(l==r){
        mi[o]=(pii){max(0,l-ar[l]),l};
        return;
    }
    build(lo,l,mid);
    build(ro,mid+1,r);
    mi[o]=min(mi[lo],mi[ro]);
}
pii query(int ql,int qr,int o=1,int l=1,int r=n){
    if(ql<=l&&r<=qr){
        return mi[o];
    }
    pii ret={inf,inf};
    if(ql<=mid)Min(ret,query(ql,qr,lo,l,mid));
    if(qr>mid)Min(ret,query(ql,qr,ro,mid+1,r));
    return ret;
}
void modify(int p,pii v,int o=1,int l=1,int r=n){
    if(l==r){
        mi[o]=v;
        return;
    }
    if(p<=mid)modify(p,v,lo,l,mid);
    else modify(p,v,ro,mid+1,r);
    mi[o]=min(mi[lo],mi[ro]);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    memset(f,0x3f,sizeof(f));f[0]=0;
    memset(nxt,-1,sizeof(nxt));
    cin>>n;
    for(int i=1;i<=n;i++)cin>>ar[i];
    for(int i=1;i<=n;i++){
        cin>>br[i];
        edg[i+br[i]].push_back(i);
    }
    build();
    queue<int>q;q.push(0);
    while(!q.empty()){
        int u=q.front();q.pop();
        int ql=max(1,u),qr=n;
        while(1){
            pii tmp=query(ql,qr);
            if(tmp.fi>u)break;

            modify(tmp.se,{inf,inf});
            for(auto v:edg[tmp.se]){
                nxt[v]=u;
                f[v]=f[u]+1;
                q.push(v);
            }
        }
    }
    pii mi={inf,inf};
    for(int i=n-ar[n];i<=n;i++){
        Min(mi,(pii){f[i],i});
    }
    if(mi.fi==inf)cout<<-1;
    else{
        cout<<mi.fi+1<<endl;
        int a=mi.se;
        while(1){
            cout<<a<<' ';
            if(!a)return 0;
            a=nxt[a];
        }
    }
}