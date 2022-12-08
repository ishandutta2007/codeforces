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
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


struct UnionFind{
   vector<int> par;
   vector<set<int>> st;
   UnionFind(int n):par(n,-1),st(n){}
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
           for(auto e : st[x])st[y].insert(e);
       }
       else{
           par[x]+=par[y];
           par[y]=x;
           for(auto e : st[y])st[x].insert(e);
       }
       return true;
   }

   bool same(int x,int y){
       if(find(x)==find(y))return true;
       if(st[find(x)].count(y))return true;
       return false;
   }
   int size(int x){
       return -par[find(x)];
   }
};
int main(){
    int n,m,c,q;
    cin>>n>>m>>c>>q;
    map<pair<int,int>,vector<int>> edge;
    UnionFind uf(n+1);
    rep(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        uf.st[x].insert(y);
        uf.st[y].insert(x);
        edge[{x,z}].push_back(y);
        edge[{y,z}].push_back(x);
    }
    for(auto e : edge){
        if(e.second.size()>=2){
            rep(i,e.second.size()){
                uf.unite(e.second[0],e.second[i]);
            }
        }
    }
    while(q--){
        char op;
        cin>>op;
        if(op=='+'){
            int x,y,z;
            cin>>x>>y>>z;
            edge[{x,z}].push_back(y);
            edge[{y,z}].push_back(x);
            uf.st[uf.find(y)].insert(x);
            uf.st[uf.find(x)].insert(y);
            uf.unite(y,edge[{x,z}][0]);
            uf.unite(x,edge[{y,z}][0]);
        }
        else {
            int x,y;
            cin>>x>>y;
            cout<<(uf.same(x,y)?"Yes\n" :"No\n");
        }
    }
    return 0;
}