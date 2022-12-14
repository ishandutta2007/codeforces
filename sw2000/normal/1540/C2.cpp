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
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#endif
typedef pair<int,int>pii;
typedef vector<int>vi;
typedef vector<ll>vl;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=1e4+10;
const ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int n;cin>>n;
    vi cr(n),br(n-1);
    for(auto &i:cr)cin>>i;
    for(auto &i:br)cin>>i;
    map<int,ll>ans;
    auto solve=[&](){
        int x;cin>>x;
        vi ar(n);
        ar[0]=x;
        for(int i=1;i<n;i++)ar[i]=ar[i-1]+br[i-1];
        int a=0,b=0;
        for(int i=0;i<n;i++){
            a+=ar[i];
            b+=cr[i];
            if(a>b)return 0ll;
        }
        if(a<=0){
            ll ret=1;
            for(auto i:cr)(ret*=i+1)%=mod;
            return ret;
        }
        if(ans.find(x)!=ans.end())return ans[x];
        vl f(N);f[0]=1;
        int c=0;
        for(int i=0;i<n;i++){
            c+=ar[i];
            vl ff(N,0);
            for(int k=0;k<N;k++)if(k+cr[i]>=c){
                int l=max(c,k),r=k+cr[i]+1;
                ff[l]+=f[k];
                if(r<ff.size())ff[r]-=f[k];
            }
            for(auto &k:ff)((k%=mod)+=mod)%=mod;
            for(int k=1;k<N;k++)ff[k]=(ff[k-1]+ff[k])%mod;
            f=ff;
        }
        ll ret=0;
        for(auto i:f)(ret+=i)%=mod;
        return ans[x]=ret;
    };
    int q;cin>>q;
    while(q--){
        cout<<solve()<<endl;
    }
}