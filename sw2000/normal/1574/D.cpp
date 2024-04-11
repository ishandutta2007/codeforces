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
const int N=2e5+10,M=500;
const ll mod=1e9+7;

int n,m,c[10];
int a[10][N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c[i];
        for(int j=1;j<=c[i];j++)cin>>a[i][j];
    }
    set<vi>s;
    cin>>m;
    for(int i=0;i<m;i++){
        vi v(n);
        for(auto &i:v)cin>>i;
        s.insert(v);
    }
    priority_queue<pair<int,vi>>q;
    pair<int,vi>st{};
    set<vi>vis;
    for(int i=0;i<n;i++){
        st.fi+=a[i][c[i]];
        st.se.push_back(c[i]);
    }
    q.push(st);vis.insert(st.se);
    while(!q.empty()){
        int sum=q.top().fi;vi u=q.top().se;q.pop();
        if(!s.count(u)){
            for(auto i:u)cout<<i<<' ';
            return 0;
        }
        for(int i=0;i<n;i++)if(u[i]!=1){
            sum-=a[i][u[i]];
            u[i]--;
            sum+=a[i][u[i]];
            if(!vis.count(u)){
                vis.insert(u);
                q.push({sum,u});
            }
            sum-=a[i][u[i]];
            u[i]++;
            sum+=a[i][u[i]];
        }
    }
}