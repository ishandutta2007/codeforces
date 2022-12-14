#include<bits/stdc++.h>
using namespace std;
#define K(x...){cerr<<"BEGIN     "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T,class... A>void Err(T a,A... x){cerr<<a<<',';Err(x...);}
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<')';Err(x...);}
template<template<class...> class T,class t,class...A>void Err(T<t>a,A...x){cerr<<a.size()<<":{";for(auto v:a)Err(v);cerr<<"}";Err(x...);}
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
const int N=100+10,M=400;
const ll mod=998244353;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int n,m,k;cin>>n>>m>>k;
    vi cnt(1<<k);
    for(int i=1;i<1<<k;i++)cnt[i]=cnt[i/2]^i%2;
    vector<vi>f(n*2+1,vi(1<<k,0));
    vector<pii>ar(n),br;
    for(auto &i:ar){
        cin>>i.fi>>i.se;
    }
    for(int i=0;i<n;i++){
        br.push_back({ar[i].fi,n+i});
        br.push_back({ar[i].se+1,i});
    }
    sort(br.begin(),br.end());
    vi v(k,-1);
    int lst=0;
    for(int i=0;i<br.size();i++){
        int now,id;tie(now,id)=br[i];
        if(id>=n){
            id-=n;
            int S=0;
            for(int j=0;j<k;j++)if(v[j]!=-1){
                S|=1<<j;
            }
            int pos;
            for(int j=0;j<k;j++)if(v[j]==-1){
                pos=j;
                v[j]=id;
                break;
            }
            for(int s=S;;s=S&s-1){
                f[i+1][s|1<<pos]=f[i+1][s]=f[i][s]+(now-lst)*cnt[s];
                if(s==0)break;
            }
        }
        else{
            int S=0,pos;
            for(int j=0;j<k;j++)if(v[j]!=-1){
                S|=1<<j;
                if(v[j]==id)pos=j,v[j]=-1;
            }
            for(int s=S;;s=S&s-1){
                if(s&1<<pos){
                    Max(f[i+1][s^1<<pos],f[i][s]+(now-lst)*cnt[s]);
                }
                else{
                    Max(f[i+1][s],f[i][s]+(now-lst)*cnt[s]);
                }
                if(s==0)break;
            }
        }
        lst=now;
        K(f[i+1])
    }
    cout<<f.back()[0];
}