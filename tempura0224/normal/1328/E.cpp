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
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

struct LCA{
   int n,h;
   vector<vector<int>> v,par;
   vector<int> depth;
   LCA(int sz):n(sz),v(n),depth(n){
       h=1;
       while((1<<h)<n)h++;
       par.assign(h,vector<int>(n,-1));
   }

   void add_edge(int x,int y){
       v[x].push_back(y);
       v[y].push_back(x);
   }

   void dfs(int x,int p,int d){
       par[0][x]=p;
       depth[x]=d;
       for(auto to:v[x])if(to!=p)dfs(to,x,d+1);
   }

   void build(){
       dfs(0,-1,0);
       rep(i,h-1){
           rep(j,n){
               if(par[i][j]<0)par[i+1][j]=-1;
               else par[i+1][j]=par[i][par[i][j]];
           }
       }
   }

   int lca(int u,int v){
       if(depth[u]>depth[v])swap(u,v);
       rep(i,h)if((depth[v]-depth[u])>>i &1)v=par[i][v];
       if(u==v)return u;
       for(int i=h-1;i>=0;i--){
           if(par[i][u]!=par[i][v]){
               u=par[i][u];
               v=par[i][v];
           }
       }
       return par[0][u];
   }

   int dist(int u,int v){
       return depth[u]+depth[v]-2*depth[lca(u,v)];
   }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin>>n>>q;
    LCA lca(n);
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        --x;--y;
        lca.add_edge(x, y);
    }
    lca.build();
    while(q--){
        int k;
        cin>>k;
        vector<int> a(k);
        rep(i,k){
            cin>>a[i];
            if(a[i]==1)a[i]=0;
            else a[i]=lca.par[0][a[i]-1];
        }
        sort(a.begin(),a.end(),[&](int x,int y){
            return lca.depth[x]<lca.depth[y];
        });
        bool ok=true;
        rep(i,k-1){
            if(lca.lca(a[i],a[i+1])!=a[i])ok=false;
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}