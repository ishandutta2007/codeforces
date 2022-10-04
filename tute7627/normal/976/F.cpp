//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (ll)(m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>
void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>
void debug(vector<vector<T>>&v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>&v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>
void debug(vector<T>&v,ll n){if(n!=0)cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>
vector<vector<T>>vec(ll x, ll y, T w){
  vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,0,-1,0,1,1,-1,-1};
vector<ll>dy={0,1,0,-1,1,-1,1,-1};
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>&p){
  return os << p.first << " " << p.second;
}  
template< typename flow_t >
struct FordFulkerson {
  struct edge {
    ll to;
    flow_t cap;
    ll rev;
    bool isrev;
    ll idx;
  };

  vector< vector< edge > > graph;
  vector< ll > used;
  const flow_t INF;
  ll timestamp;

  FordFulkerson(ll n) : INF(numeric_limits< flow_t >::max()), timestamp(0) {
    graph.resize(n);
    used.assign(n, -1);
  }

  void add_edge(ll from, ll to, flow_t cap, ll idx = -1) {
    graph[from].emplace_back((edge) {to, cap, (ll) graph[to].size(), false, idx});
    graph[to].emplace_back((edge) {from, 0, (ll) graph[from].size() - 1, true, idx});
  }

  flow_t dfs(ll idx, const ll t, flow_t flow) {
    if(idx == t) return flow;
    used[idx] = timestamp;
    for(auto &e : graph[idx]) {
      if(e.cap > 0 && used[e.to] != timestamp) {
        flow_t d = dfs(e.to, t, min(flow, e.cap));
        if(d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  flow_t max_flow(ll s, ll t) {
    fill(ALL(used),-1);
    timestamp=0;
    flow_t flow = 0;
    for(flow_t f; (f = dfs(s, t, INF)) > 0; timestamp++) {
      flow += f;
    }
    return flow;
  }

  vector<ll> output(ll m){
    vector<ll>ret;
    vector<bool>t(m,true);
    for(ll i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        //cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
        if(rev_e.cap==1&&e.idx!=-1)t[e.idx]=false;
      }
    }
    rep(i,0,m)if(t[i])ret.EB(i+1);
    for(ll i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev||e.idx!=-1) continue;
        //auto &rev_e = graph[e.to][e.rev];
        e.cap++;
      }
    }
    return ret;
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n1,n2,m;cin>>n1>>n2>>m;
  FordFulkerson<ll>flow(n1+n2+2);
  ll n=n1+n2;
  vector<ll>d(n);
  rep(i,0,m){
    ll u,v;cin>>u>>v;u--;v--;
    flow.add_edge(u,n1+v,1,i);
    d[u]++;
    d[n1+v]++;
  }
  ll k=INF;
  rep(i,0,n)chmin(k,d[i]);
  //debug(d,n);
  rep(i,0,n1)flow.add_edge(n,i,d[i]-k);
  rep(i,n1,n)flow.add_edge(i,n+1,d[i]-k);
  vector<vector<ll>>ret(k+1);
  rrep(i,0,k+1){
    flow.max_flow(n,n+1);

    ret[i]=flow.output(m);
  }
  rep(i,0,k+1){
    cout<<ret[i].size()<<" ";
    debug(ret[i],ret[i].size());
  }
  return 0;
}