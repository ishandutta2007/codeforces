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


struct PrimalDual{
    struct edge{
        int to,id;ll cap, cost;int rev;
    };
    int n;
    const ll INF = numeric_limits<ll>::max();
    vector<vector<edge>> v;
    vector<ll> pot, dist;
    vector<pair<int,int>> par;
 
    PrimalDual(int n):n(n),v(n),pot(n){}
 
    void add_edge(int from, int to, ll cap, ll cost,int id = -1) {
        v[from].emplace_back((edge) {to, id, cap, cost, (int) v[to].size()});
        v[to].emplace_back((edge) {from, id, 0, -cost, (int) v[from].size() - 1});
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
    int a,b,m,x,y;
    cin>>a>>b>>m>>x>>y;
    string s,t;
    cin>>s>>t;
    PrimalDual pd(a+b+4);
    int s1 = a+b, t1 = a+b+1, s2 = a+b+2, t2 = a+b+3;
    int sc = 0, tc = 0;
    map<pair<int,int>,int> R, B; 
    rep(i,a){
        if(s[i]=='R'){
            pd.add_edge(s1, i, 1, 0);
            pd.add_edge(s2, i, inf, 0);
            ++sc;
        }
        else if(s[i]=='B'){
            pd.add_edge(i, t1, 1, 0);
            pd.add_edge(i, t2, inf, 0);
            ++tc;
        }
        else {
            pd.add_edge(s2, i, inf, 0);
            pd.add_edge(i, t2, inf, 0);
        }
    }
    rep(i,b){
        if(t[i]=='B'){
            pd.add_edge(s1, a+i, 1, 0);
            pd.add_edge(s2, a+i, inf, 0);
            ++sc;
        }
        else if(t[i]=='R'){
            pd.add_edge(a+i, t1, 1, 0);
            pd.add_edge(a+i, t2, inf, 0);
            ++tc;
        }
        else {
            pd.add_edge(s2, a+i, inf, 0);
            pd.add_edge(a+i, t2, inf, 0);
        }
    }
    rep(i,m){
        int u,v;
        cin>>u>>v;
        --u;--v;
        v+=a;
        pd.add_edge(u, v, 1, x, i);
        pd.add_edge(v, u, 1, y, i);
        R[{u,v}]=i;
        B[{v,u}]=i;
    }
    pd.add_edge(s2, t1, sc, 0);
    pd.add_edge(s1, t2, tc, 0);
    pd.add_edge(t2, s2, inf, 0);
    ll ret = pd.minimum_cost_flow(s1, t1, sc+tc);
    cout<<ret<<endl;
    if(ret==-1)return 0;
    string ans(m,'U');
    rep(i,a){
        for(auto e:pd.v[i]){
            if(e.cost>0 && e.cap == 0){
                ans[e.id]='R';
            }
        }
    }
    REP(i,a,a+b){
        for(auto e:pd.v[i]){
            if(e.cost>0 && e.cap == 0){
                ans[e.id]='B';
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}