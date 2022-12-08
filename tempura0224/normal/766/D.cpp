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

struct pUF{
   vector<ll> r, par;
   pUF(int n):r(n),par(n,-1){};

   int find(int x){
      if(par[x]<0)
         return x;
      int y = find(par[x]);
      r[x] += r[par[x]];
      return par[x] = y;
   }

   bool same(int x,int y){
        return find(x)==find(y);
   }
   
   ll weight(int x){
      find(x);
      return r[x];
   }

   ll diff(int x,int y){//weigth(y)-weight(x)
       return weight(y)-weight(x);
   }
   
   bool unite(ll c,int x, int y){//weight(y)-weight(x)=c
       c -= weight(y);
       c += weight(x);
       x = find(x);
       y = find(y);
       if(x!=y){
          par[y] = x;
          r[y] = c;
          return true;
        }
      return false;
   }
};


int main(){
    int n,m,q;
    cin>>n>>m>>q;
    map<string,int> mp;
    rep(i,n){
      string s;
      cin>>s;
      mp[s]=i;
    }
    pUF uf(n);
    while(m--){
      int type;
      string s,t;
      cin>>type>>s>>t;
      int x=mp[s],y=mp[t];
      if(type==1){
        if(!uf.same(x,y)){
          printf("YES\n");
          uf.unite(0,x,y);
        }
        else{
          cout<<(uf.diff(x,y)%2 ? "NO\n" : "YES\n");
        }
      }
      else {
        if(!uf.same(x,y)){
          printf("YES\n");
          uf.unite(1,x,y);
        }
        else{
          cout<<(uf.diff(x,y)%2 ? "YES\n" : "NO\n");
        }
      }
    }
    while(q--){
      string s,t;
      cin>>s>>t;
      int x=mp[s],y=mp[t];
      if(!uf.same(x,y))printf("3\n");
      else if(uf.diff(x,y)%2)printf("2\n");
      else printf("1\n");
    }
    return 0;
}