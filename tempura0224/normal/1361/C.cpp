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


vector<set<int>> g;
void dfs(int u, vector<int> &trail) {
        while (!g[u].empty()) {
                int v = *g[u].begin();
                g[u].erase(v);
                g[v].erase(u);
                dfs(v, trail);
        }
        trail.push_back(u);
}

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
void solve(int n,int cur,vector<vector<int>>& v){
    int m=0;
    while((1<<m)!=cur)++m;
    cout<<m<<endl;
    g.resize(n+cur);
    rep(i,n+cur){
        for(auto e:v[i])g[i].insert(e);
    }
    g[0].erase(1);
    g[1].erase(0);
    vector<int> ans;
    dfs(1,ans);
    int cnt=0;
    rotate(ans.begin(),ans.begin()+1,ans.end());
    for(auto e:ans){
        if(e<n&&cnt<n){
            cout<<e+1<<" ";
            ++cnt;
        }
    }
    cout<<endl;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> a(2*n);
    rep(i,n)cin>>a[2*i]>>a[2*i+1];
    int cur=1<<20;
    vector<vector<int>> v(2*n+cur);
    rep(i,n){
            v[2*i].push_back(2*i+1);
            v[2*i+1].push_back(2*i);
        }
    while(1){
        UnionFind uf(n+cur);
        rep(i,2*n){
            v[i].push_back(2*n+a[i]%cur);
            v[2*n+a[i]%cur].push_back(i);
            uf.unite(i/2,n+a[i]%cur);
        }
        bool ok=true;
        int c=0;
        rep(i,cur){
            if(v[2*n+i].size()!=0)++c;
            if(v[2*n+i].size()%2==1){
                ok=false;
                break;
            }
        }
        if(uf.size(0)!=n+c)ok=false;
        if(ok){
            solve(2*n,cur,v);
            return 0;
        }
        rep(i,2*n)v[i].pop_back();
        rep(i,cur)v[2*n+i].clear();
        cur>>=1;
    }
    return 0;
}