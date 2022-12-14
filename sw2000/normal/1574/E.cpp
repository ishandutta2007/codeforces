#include<bits/stdc++.h>
using namespace std;
#define K(x...){cerr<<"BEGIN     "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T,class... A>void Err(T a,A... x){cerr<<a<<',';Err(x...);}
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<')';Err(x...);}
template<template<class...> class T,class t,class...A>void Err(T<t>a,A...x){cerr<<a.size()<<":{";for(auto v:a)Err(v);cerr<<"},";Err(x...);}
typedef long long ll;
typedef long double ld;
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
const int N=1e6+10,M=400;
const ll mod=998244353;

int ar[N][2],br[N][2],ca,cb,lefta,leftb,two[N]{1},all[2];
int main(){
    for(int i=1;i<N;i++)two[i]=two[i-1]*2%mod;
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
//    memset(ar,-1,sizeof(ar));
//    memset(br,-1,sizeof(br));
    int n,m,k;cin>>n>>m>>k;
    lefta=n,leftb=m;
    map<pii,int>mp;
    auto add=[&](int x,int y,int t){
        ar[x][y%2^t]++;
        if(ar[x][0]&&ar[x][1]&&ar[x][y%2^t]==1)ca++;
        if(ar[x][0]+ar[x][1]==1)lefta--;
        br[y][x%2^t]++;
        if(br[y][0]&&br[y][1]&&br[y][x%2^t]==1)cb++;
        if(br[y][0]+br[y][1]==1)leftb--;
        all[(x+y)%2^t]++;
    };
    auto sub=[&](int x,int y,int t){
        ar[x][y%2^t]--;
        if(ar[x][0]+ar[x][1]&&ar[x][y%2^t]==0)ca--;
        if(ar[x][0]+ar[x][1]==0)lefta++;
        br[y][x%2^t]--;
        if(br[y][0]+br[y][1]&&br[y][x%2^t]==0)cb--;
        if(br[y][0]+br[y][1]==0)leftb++;
        all[(x+y)%2^t]--;
    };
    for(int i=0;i<k;i++){
        int x,y,t;cin>>x>>y>>t;
        if(mp.find({x,y})!=mp.end()){
            sub(x,y,mp[{x,y}]);
            mp.erase({x,y});
        }

        if(t!=-1){
            add(x,y,t);
            mp[{x,y}]=t;
        }

        ll ans=0;
        if(!ca)ans+=two[lefta];
        if(!cb)ans+=two[leftb];
        if(!all[0]&&!all[1])ans-=2;
        else if(!all[0]||!all[1])ans-=1;
        ans=(ans+mod)%mod;
        K(lefta,leftb,ca,cb)
        cout<<ans<<endl;
    }
}