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

vector<vector<int>> v;

void dfs(int x,int p, int& j, vector<int>& a){
    a[x]=j;
    for(auto to:v[x]){
        if(to==p)continue;
        dfs(to,x,++j,a);
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    LCA lca(n);
    v.resize(n);
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].push_back(y);
        v[y].push_back(x);
        lca.add_edge(x, y);
    }
    lca.build();
    vector<int> a(n);
    int j=0;
    dfs(0,-1,j,a);
    int ok = 1, ng=k+1;
    while(ng-ok>1){
        int mid=(ok+ng)/2;
        set<pair<int,int>> st;
        st.emplace(a[0],0);
        int sum=0;
        REP(i,1,mid){
            st.emplace(a[i],i);
            auto itr=st.lower_bound({a[i],i});
            auto nx=next(itr);if(nx==st.end())nx=st.begin();
            auto pre=(itr==st.begin()?st.end():itr);--pre;
            sum-=lca.dist(nx->second,pre->second);
            sum+=lca.dist(nx->second,itr->second);
            sum+=lca.dist(itr->second,pre->second);
        }
        int res=sum;
        REP(i,mid,n){
            st.emplace(a[i],i);
            auto itr=st.lower_bound({a[i],i});
            auto nx=next(itr);if(nx==st.end())nx=st.begin();
            auto pre=(itr==st.begin()?st.end():itr);--pre;
            sum-=lca.dist(nx->second,pre->second);
            sum+=lca.dist(nx->second,itr->second);
            sum+=lca.dist(itr->second,pre->second);

            itr=st.lower_bound({a[i-mid],i-mid});
            nx=next(itr);if(nx==st.end())nx=st.begin();
            pre=(itr==st.begin()?st.end():itr);--pre;
            sum+=lca.dist(nx->second,pre->second);
            sum-=lca.dist(nx->second,itr->second);
            sum-=lca.dist(itr->second,pre->second);
            st.erase({a[i-mid],i-mid});
            res=min(sum,res);
        }
        if(res/2+1<=k)ok=mid;
        else ng=mid;
    }
    cout<<ok<<endl;
    return 0;
}