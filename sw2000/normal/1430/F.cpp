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
const int N=2000+10,M=400;
const ll mod=1e9+7;

int n;
ll k,f[N][N],g[N][N],ff[N],gg[N],l[N],r[N],ar[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    cin>>n>>k;
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)f[i][j]=g[i][j]=linf;
    for(int i=1;i<=n;i++)cin>>l[i]>>r[i]>>ar[i];
    for(int i=1;i<=n;i++){
        ll left=k;
        for(int j=i;j<=n;j++){
            if(ar[j]<=left){
                left-=ar[j];
                f[i][j]=f[i][j-1]+ar[j];
                if(l[j]!=r[j]){
                    g[i][j]=f[i][j];
                }
            }
            else{
                ll a=ar[j]-left;
                left=0;

                if(a>(r[j]-l[j])*k)break;
                f[i][j]=f[i][j-1]+ar[j];
                if(a%k==0)left=0;
                else left=k-a%k;
                if(a<=(r[j]-l[j]-1)*k){
                    g[i][j]=f[i][j];
                }
            }
            K(i,j,f[i][j],g[i][j])
        }
    }
    for(int i=1;i<=n;i++){
        ff[i]=gg[i]=linf;
        for(int j=i-1;~j;j--){
            ll lst=(r[j]==l[j+1]?gg[j]:ff[j]);
            Min(ff[i],lst+(i==n?f[j+1][i]:((f[j+1][i]-1)/k+1)*k));
            Min(gg[i],lst+((g[j+1][i]-1)/k+1)*k);
        }
        K(ff[i],gg[i])
    }
    cout<<(ff[n]==linf?-1:ff[n]);
}