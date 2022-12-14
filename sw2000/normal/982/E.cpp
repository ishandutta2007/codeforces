#include<bits/stdc++.h>
using namespace std;
#define K(x...){cerr<<"BEGIN    "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T,class... A>void Err(T a,A... x){cerr<<a<<',';Err(x...);}
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<"),";Err(x...);}
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
typedef long double ld;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=1e3+10,M=500;
const ll mod=1e9+7;

struct CRT{
    vector<ll>mod,r;
    ll exgcd(ll a,ll b,ll &x,ll &y){
        if(!b){
            x=1,y=0;
            return a;
        }
        ll gcd=exgcd(b,a%b,y,x);
        y-=a/b*x;
        return gcd;
    }
    ll EXCRT(){
        ll lcm=mod[0],last_r=r[0];
        ll lcm_a,x,y,k;
        for(int i=1;i<mod.size();i++){
            lcm_a=((r[i]-last_r)%mod[i]+mod[i]);
            k=lcm;
            ll gcd=exgcd(lcm,mod[i],x,y);
            x=(x*lcm_a/gcd%(mod[i]/gcd)+(mod[i]/gcd))%(mod[i]/gcd);
            lcm=lcm*mod[i]/gcd;
            last_r=(last_r+k*x)%lcm;
        }
        return (last_r%lcm+lcm)%lcm;
    }
}sw;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    ll n,m,x,y,vx,vy;cin>>n>>m>>x>>y>>vx>>vy;
    ll dx=x+vx*inf,dy=y+vy*inf;
    Min(dx,n),Min(dy,m),Max(dx,0ll),Max(dy,0ll);
    if(vx==0){
        if(x==0||x==n)cout<<dx<<' '<<dy;
        else cout<<-1;
        return 0;
    }
    else if(vy==0){
        if(y==0||y==m)cout<<dx<<' '<<dy;
        else cout<<-1;
        return 0;
    }
    ll a,b,ansx,ansy;
    if(vx==1){
        a=n-x;
        ansx=n;
    }
    else{
        a=x;
        ansx=0;
    }
    if(vy==1){
        b=m-y;
        ansy=m;
    }
    else{
        b=y;
        ansy=0;
    }
    ll gc=__gcd(n,m);
    if((a-b)%gc)return cout<<-1,0;
//    a/=gc,b/=gc,n/=gc,m/=gc;
    sw.r.push_back(a),sw.r.push_back(b);
    sw.mod.push_back(n),sw.mod.push_back(m);
    ll all=sw.EXCRT();
    K(all)
    if((all-a)%(2*n))ansx=n-ansx;
    if((all-b)%(2*m))ansy=m-ansy;
    cout<<ansx<<' '<<ansy;
}