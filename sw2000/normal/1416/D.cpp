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
const int N=2e5+10,M=400;
const ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int n,m,q;cin>>n>>m>>q;
    vi belong(n);iota(belong.begin(),belong.end(),0);
    vector<set<pii>>s(n);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        s[i].insert({a,i});
    }
    vector<vector<pii>>he(q);
    vi head(q,-1);
    vector<pii>edg(m);
    for(int i=0;i<m;i++)cin>>edg[i].fi>>edg[i].se,edg[i].fi--,edg[i].se--;
    vector<pii>op(q);
    vector<bool>vis(m);
    for(int i=0;i<q;i++){
        cin>>op[i].fi>>op[i].se;op[i].se--;
        if(op[i].fi==2){
            vis[op[i].se]=1;
        }
    }
    for(int i=0;i<m;i++)if(!vis[i]){
        int a=edg[i].fi,b=edg[i].se;
        a=belong[a],b=belong[b];
        if(a!=b){
            if(s[a].size()<s[b].size())swap(a,b);
            for(auto j:s[b]){
                s[a].insert(j);
                belong[j.se]=belong[a];
            }
            s[b].clear();
        }
    }
    for(int i=q-1;~i;i--){
        if(op[i].fi==2){
            int a=edg[op[i].se].fi,b=edg[op[i].se].se;
            a=belong[a],b=belong[b];
            if(a!=b){
                if(s[a].size()<s[b].size())swap(a,b);
                head[i]=b;
                for(auto j:s[b]){
                    s[a].insert(j);
                    belong[j.se]=belong[a];
                    he[i].push_back(j);
                }
                s[b].clear();
            }
        }
    }
    for(int i=0;i<q;i++){
        if(op[i].fi==1){
            int a=belong[op[i].se];
            if(s[a].size()){
                auto it=--s[a].end();
                cout<<it->fi<<endl;
                s[a].erase(it);
            }
            else cout<<0<<endl;
        }
        else if(~head[i]){
            int u=belong[edg[op[i].se].fi],v=head[i];
            for(auto j:he[i]){
                belong[j.se]=v;
                if(s[u].count(j)){
                    s[u].erase(j);
                    s[v].insert(j);
                }

            }
        }
    }
}