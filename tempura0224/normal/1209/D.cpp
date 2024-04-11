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
   int size(int x){
       return -par[find(x)];
   }
};
int main(){
    int n,k;
    cin>>n>>k;
    UnionFind uf(n+1);
    int ans = 0;
    rep(i,k){
        int x,y;
        cin>>x>>y;
        ans += !uf.unite(x,y);
    }
    cout<<ans<<endl;
    return 0;
}