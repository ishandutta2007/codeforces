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
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vl;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=5e5+10;
const ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    auto solve=[&](){
        int n;cin>>n;
        vi ar(n);
        int cnt=0;
        for(auto &i:ar){
            cin>>i;
            cnt+=i;
        }
        if(cnt%2){cout<<"NO"<<endl;return;}
        int f=-1;
        for(int i=0;i<n;i++){
            if(ar[i]==1)cnt--;
            else{
                if(cnt%2==0)f=i;
            }
        }
        vi ans;
        if(f==-1){
            for(int i=0;i+2<ar.size();i++){
                if(ar[i]==1&&ar[i+1]==0&&ar[i+2]==0){
                    ans.push_back(i);
                    ar[i+1]=ar[i+2]=1;
                }
                if(ar[i]==1&&ar[i+1]==0){
                    f=i+1;
                    ans.push_back(i);
                    ar[i]=ar[i+2]=0;
                    break;
                }
            }
            if(f==-1){cout<<"NO"<<endl;return;}
        }
        cout<<"YES"<<endl;
        for(int i=f+1;i<n;i++)if(ar[i]==1){
            if(ar[i+1]==1){
                ans.push_back(i-1);
                ar[i]=ar[i+1]=0;
            }
            else if(ar[i+2]==0){
                ans.push_back(i);
                ans.push_back(i-1);
                ar[i]=0;ar[i+2]=1;
            }
            else if(ar[i+2]==1){
                ans.push_back(i);
                ar[i]=ar[i+2]=0;
            }
        }
        for(int i=f-1;~i;i--)if(ar[i]==1){
            if(ar[i-1]==1){
                ans.push_back(i-1);
                ar[i-1]=ar[i]=0;
            }
            else if(ar[i-2]==0){
                ans.push_back(i-2);
                ans.push_back(i-1);
                ar[i]=0;ar[i-2]=1;
            }
            else if(ar[i-2]==1){
                ans.push_back(i-2);
                ar[i]=ar[i-2]=0;
            }
        }
        cout<<ans.size()<<endl;
        if(ans.size()){for(auto i:ans)cout<<i+1<<' ';cout<<endl;}
    };
    int _;cin>>_;
    while(_--){
        solve();
    }
}