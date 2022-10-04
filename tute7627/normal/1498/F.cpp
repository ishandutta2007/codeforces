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
using ll = int;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e9;
using P = pair<ll, ll>;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using QP = priority_queue<T,vector<T>,greater<T>>;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>void debug(const T &v,ll h,ll w,string sv=" "){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void debug(const T &v,ll n,string sv=" "){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";cout<<"|"; return os;}
template<typename T>void rearrange(vector<int>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<int>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
template<typename T> vector<int> ascend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]<v[j];});
  return ord;
}
template<typename T> vector<int> descend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]>v[j];});
  return ord;
}
ll FLOOR(ll n,ll div){return n>=0?n/div:(n-div+1)/div;}
ll CEIL(ll n,ll div){return n>=0?(n+div-1)/div:n/div;}
template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T reverse(const T &v){return T(v.rbegin(),v.rend());};
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
template<typename T>T poll(queue<T> &q){auto ret=q.front();q.pop();return ret;};
template<typename T>T poll(priority_queue<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(QP<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(stack<T> &s){auto ret=s.top();s.pop();return ret;};
template< typename T = int >
struct edge {
  int to;
  T cost;
  int id;
  edge() = default;
  edge(int to, T cost = 1, int id = -1):to(to), cost(cost), id(id){}
  operator int() const { return to; }
};

template<typename T>
using Graph = vector<vector<edge<T>>>;
template<typename T>
Graph<T> readGraph(int n,int m,int indexed=1,bool directed=false,bool weighted=false){
  Graph<T> ret(n);
  for(int es = 0; es < m; es++){
    int u,v,w=1;
    cin>>u>>v;u-=indexed,v-=indexed;
    if(weighted)cin>>w;
    ret[u].emplace_back(v,w,es);
    if(!directed)ret[v].emplace_back(u,w,es);
  }
  return ret;
}
template<typename T>
Graph<T> readParent(int n,int indexed=1,bool directed=true){
  Graph<T>ret(n);
  for(int i=1;i<n;i++){
    int p;cin>>p;
    p-=indexed;
    ret[p].emplace_back(i);
    if(!directed)ret[i].emplace_back(p);
  }
  return ret;
}
template< typename sum_t, typename key_t >
struct ReRooting {
  struct Edge {
    int to;
    key_t data;
    sum_t dp, ndp;
  };

  using F = function< sum_t(sum_t, sum_t) >;
  using G = function< sum_t(sum_t, key_t) >;

  vector< vector< Edge > > g;
  vector< sum_t > subdp, dp;
  vector< sum_t > init;
  const sum_t ident;
  const F f;
  const G gg;

  ReRooting(int V, const F f, const G g, const sum_t &ident)
      : g(V), f(f), gg(g), ident(ident), subdp(V, ident), dp(V, ident), init(V, ident) {}

  void add_edge(int u, int v, const key_t &d) {
    g[u].emplace_back((Edge) {v, d, ident, ident});
    g[v].emplace_back((Edge) {u, d, ident, ident});
  }

  void add_edge_bi(int u, int v, const key_t &d, const key_t &e) {
    g[u].emplace_back((Edge) {v, d, ident, ident});
    g[v].emplace_back((Edge) {u, e, ident, ident});
  }

  void set(int idx, sum_t s){
    subdp[idx] = s;
    init[idx] = s;
  }
  void dfs_sub(int idx, int par) {
    for(auto &e : g[idx]) {
      if(e.to == par) continue;
      dfs_sub(e.to, idx);
      subdp[idx] = f(subdp[idx], gg(subdp[e.to], e.data));
    }
  }

  void dfs_all(int idx, int par, const sum_t &top) {
    sum_t buff{init[idx]};
    for(int i = 0; i < (int) g[idx].size(); i++) {
      auto &e = g[idx][i];
      e.ndp = buff;
      e.dp = gg(par == e.to ? top : subdp[e.to], e.data);
      buff = f(buff, e.dp);
    }
    dp[idx] = buff;
    buff = ident;
    for(int i = (int) g[idx].size() - 1; i >= 0; i--) {
      auto &e = g[idx][i];
      if(e.to != par) dfs_all(e.to, idx, f(e.ndp, buff));
      e.ndp = f(e.ndp, buff);
      buff = f(buff, e.dp);
    }
  }

  vector< sum_t > build() {
    dfs_sub(0, -1);
    dfs_all(0, -1, ident);
    return dp;
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,k;cin>>n>>k;
  auto f1=[&](vector<ll>x,vector<ll>y){
    rep(i,0,x.size())x[i]^=y[i];
    return x;
  };
  auto f2=[&](vector<ll>x,ll y){
    rotate(x.begin(),x.end()-1,x.end());
    return x;
  };
  vector<ll>init(2*k);
  ReRooting<vector<ll>,ll> rer(n,f1,f2,init);
  rep(i,0,n-1){
    ll u,v;cin>>u>>v;u--;v--;
    rer.add_edge(u,v,0);
  }
  vector<ll>a(n);
  rep(i,0,n){
    cin>>a[i];
    auto tmp=init;
    tmp[0]=a[i];
    rer.set(i,tmp);
  }
  auto v=rer.build();
  rep(i,0,n){
    ll g=0;
    rep(j,k,2*k)g^=v[i][j];
    cout<<bool(g);
    if(i==n-1)cout<<endl;
    else cout<<" ";
  }
  return 0;
}