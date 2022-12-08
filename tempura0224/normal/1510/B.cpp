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

struct PrimalDual{
    struct edge{
        int to;ll cap, cost;int rev;
    };
    int n;
    const ll INF = numeric_limits<ll>::max();
    vector<vector<edge>> v;
    vector<ll> pot, dist;
    vector<pair<int,int>> par;
 
    PrimalDual(int n):n(n),v(n),pot(n){}
 
    void add_edge(int from, int to, ll cap, ll cost) {
        v[from].emplace_back((edge) {to, cap, cost, (int) v[to].size()});
        v[to].emplace_back((edge) {from, 0, -cost, (int) v[from].size() - 1});
    }
 
    pair<ll,ll> minimum_road(int s,int t){
        par.assign(n,{-1,-1});
        dist.assign(n,INF);
        dist[s] = 0;
        using P = pair<ll,ll>;
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.emplace(0,s);
        while(!pq.empty()){
            P p = pq.top();pq.pop();
            if(dist[p.second]<p.first)continue;
            rep(i,v[p.second].size()){
                edge& e = v[p.second][i];
                ll nd = dist[p.second]+e.cost+pot[p.second]-pot[e.to];
                if(e.cap>0 && dist[e.to]>nd){
                    dist[e.to] = nd;
                    par[e.to] = {p.second, i};
                    pq.emplace(dist[e.to],e.to);
                }
            }
        }
        if(dist[t]==INF)return {-1,-1};
        rep(i,n)pot[i] += dist[i];
        ll f = INF;
        int cur = t;
        while(cur != s){
            int p = par[cur].first, j = par[cur].second;
            f = min(f, v[p][j].cap);
            cur = p;
        }
        cur = t;
        while(cur != s){
            int p = par[cur].first, j = par[cur].second;
            v[p][j].cap -= f;
            v[cur][v[p][j].rev].cap += f;
            cur = p;
        }
        return {pot[t],f};
    }
 
    ll minimum_cost_flow(int s, int t, ll k){
        ll ret = 0;
        while(k){
            pair<ll,ll> z = minimum_road(s, t);
            if (z.first < 0)return -1;
            if (k<=z.second){
                ret+=z.first*k;
                break;
            }
            k -= z.second;
            ret += z.first*z.second;
        }
        return ret;
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int k;
    cin>>k;
    int n;
    cin>>n;
    vector<string> s(n);
    rep(i,n)cin>>s[i];
    vector<int> a(n);
    rep(i,n){
        rep(j,k){
            if(s[i][j]=='1'){
                a[i]|=(1<<j);
            }
        }
    }
    PrimalDual pd(2*n+2);
    int st = 2*n, en = 2*n+1;
    rep(i,n){
        pd.add_edge(st, i, 1, 0);
        pd.add_edge(i, en, 1, __builtin_popcount(a[i])+1);
    }
    rep(i,n)rep(j,n){
        if((a[i]&a[j])==a[i] && i != j)pd.add_edge(i,j+n,1,0);
    }
    rep(j,n){
        pd.add_edge(j+n,en,1,0);
    }
    int res = pd.minimum_cost_flow(st, en, n);
    vector<int> par(n, -1), ispar(n);
    rep(i,n){
        auto es = pd.v[i];
        for(auto to: es){
            if(to.to != st && to.cap == 0){
                par[i] = to.to-n;
                if(to.to != en) ispar[to.to-n]=1;
                break;
            }
        }
    }
    vector<char> ans;
    rep(i,n){
        if(ispar[i])continue;
        rep(j, k){
            if(a[i]>>j&1)ans.push_back('0'+j);
        }
        int cur = i;
        while(par[cur] != n + 1){
            rep(j, k){
                if(!(a[cur]>>j&1)&&(a[par[cur]]>>j&1)){
                    ans.push_back('0'+j);
                }
            }
            cur = par[cur];
        }
        ans.push_back('R');
    }
    ans.pop_back();
    cout<<ans.size()<<endl;
    for(auto c: ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}