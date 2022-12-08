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

struct LowLink {
    const vector<vector<int>> &g;
    vector< int > used, ord, low;
    vector< int > articulation;
    vector< pair< int, int > > bridge;
    LowLink(const vector<vector<int>> &g) : g(g) {}
    int dfs(int idx, int k, int par) {
        used[idx] = true;
        ord[idx] = k++;
        low[idx] = ord[idx];
        bool is_articulation = false;
        int cnt = 0;
        for(auto &to : g[idx]) {
            if(!used[to]) {
                ++cnt;
                k = dfs(to, k, idx);
                low[idx] = min(low[idx], low[to]);
                if(par!=-1&&low[to]>=ord[idx])is_articulation =true;
                if(ord[idx] < low[to]) bridge.emplace_back(minmax(idx, (int) to));
            }
            else if(to != par) {
                low[idx] = min(low[idx], ord[to]);
            }
        }
        if(par==-1&&cnt>1)is_articulation= true;
        if(is_articulation) articulation.push_back(idx);
        return k;
    }
    virtual void build() {
        used.assign(g.size(), 0);
        ord.assign(g.size(), 0);
        low.assign(g.size(), 0);
        int k = 0;
        for(int i = 0; i < g.size(); i++) {
            if(!used[i]) k = dfs(i, k, -1);
        }
    }
};
struct TwoEdgeConnectedComponents : LowLink {
    using LL = LowLink ;
    vector<int> comp;
    TwoEdgeConnectedComponents(const vector<vector<int>> &g) : LL(g) {} 
    int operator[](const int &k) {
        return comp[k];
    }
    void dfs(int idx, int par, int &k) {
        if(par!=-1 && this->ord[par] >= this->low[idx]) comp[idx] = comp[par];
        else comp[idx] = k++;
        for(auto &to : this->g[idx]) {
            if(comp[to] == -1) dfs(to, idx, k);
        }
    }
    void build(vector<vector<int>> &t) {
        LL::build();
        comp.assign(this->g.size(), -1);
        int k = 0;
        for(int i = 0; i < comp.size(); i++) {
            if(comp[i] == -1) dfs(i, -1, k);
        }
        t.resize(k);
        for(auto &e : this->bridge) {
            int x = comp[e.first], y = comp[e.second];
            t[x].push_back(y);
            t[y].push_back(x);
        }
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n);
    rep(i,m){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    TwoEdgeConnectedComponents t(v);
    vector<vector<int>> g;
    t.build(g);
    n = g.size();
    vector<int> d(n);
    auto dfs = [&](auto&& self, int x, int p) -> void {
        for(auto to: g[x]){
            if(to==p)continue;
            d[to]=d[x]+1;
            self(self, to, x);
        }
    };
    dfs(dfs,0,-1);
    int s = 0;
    rep(i,n)if(d[i]>d[s])s=i;
    d[s]=0;
    dfs(dfs,s,-1);
    int ans=0;
    rep(i,n)ans=max(ans,d[i]);
    cout<<ans<<endl;
    return 0;
}