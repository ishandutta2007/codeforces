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
//#define mid (l+r>>1)
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
const int N=1e5+10,M=500;
const ll mod=998244353;
int n,k,id[N],rk[N],dfs_tot,fa[N][20],dep[N];
vi edg[N];
void dfs(int u=1,int f=0){
    id[u]=++dfs_tot;
    rk[dfs_tot]=u;
    for(int i=1;i<20;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
    for(auto v:edg[u])if(v!=f){
        dep[v]=dep[u]+1;
        fa[v][0]=u;
        dfs(v,u);
    }
}
int dis(int a,int b){
    a=rk[a],b=rk[b];
    int ret=0;
    if(dep[a]<dep[b])swap(a,b);
    while(dep[a]>dep[b]){
        for(int i=19;~i;i--){
            if(dep[a]-(1<<i)>=dep[b]){
                a=fa[a][i];
                ret+=1<<i;
            }
        }
    }
    if(a==b)return ret;
    for(int i=19;~i;i--){
        if(fa[a][i]!=fa[b][i]){
            a=fa[a][i];
            b=fa[b][i];
            ret+=1<<i+1;
        }
    }
    return ret+2;
}
bool ok(int d){
    set<int>s;
    for(int i=1;i<=d;i++)s.insert(id[i]);
    int sum=0,lst=*(--s.end());
    for(auto i:s){
        sum+=dis(lst,i);
        lst=i;
    }
    if(sum/2<k)return 1;
    for(int l=1,r=d+1;r<=n;l++,r++){
        auto it=s.find(id[l]);
        auto lit=it,rit=it;
        if(lit==s.begin())lit=--s.end();
        else lit--;
        if(rit==--s.end())rit=s.begin();
        else rit++;
        sum-=dis(*it,*lit)+dis(*it,*rit);
        sum+=dis(*lit,*rit);
        s.erase(id[l]);

        s.insert(id[r]);
        it=s.find(id[r]);
        lit=it,rit=it;
        if(lit==s.begin())lit=--s.end();
        else lit--;
        if(rit==--s.end())rit=s.begin();
        else rit++;
        sum-=dis(*lit,*rit);
        sum+=dis(*it,*lit)+dis(*it,*rit);
        if(sum/2<k)return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    dfs();
    int l=1,r=n;
    while(l!=r){
        int mid=l+r+1>>1;
        if(ok(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
}