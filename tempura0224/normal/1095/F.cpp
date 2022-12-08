#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


struct UnionFind{
   vector<int> par;
   UnionFind(int n):par(n,-1){}
   int find(int x){
       if(par[x]<0)return x;
       return par[x]=find(par[x]);
   }
   bool unite(int x,int y){
       x=find(x);
       y=find(y);
       if(x==y)return false;
       if(par[x]>par[y]){
           par[y]+=par[x];
           par[x]=y;
       }
       else{
           par[x]+=par[y];
           par[y]=x;
       }
       return true;
   }

   bool same(int x,int y){
       return find(x)==find(y);
   }
};
int main(){
    int n,m;
    cin>>n>>m;
    ll a[n];
    int idx=0;
    rep(i,n){
        cin>>a[i];
        if(a[i]<a[idx])idx=i;
    }
    vector<pair<ll,pint>> edge;
    rep(i,n){
        if(i==idx)continue;
        edge.push_back({a[i]+a[idx],{idx,i}});
    }
    rep(i,m){
        ll x,y,z;
        cin>>x>>y>>z;
        edge.push_back({z,{--x,--y}});
    }
    sort(edge.begin(),edge.end());
    ll ans=0;
    UnionFind uf(n);
    for(auto e: edge){
        if(uf.unite(e.second.first,e.second.second))ans+=e.first;
    }
    cout<<ans<<endl;
}