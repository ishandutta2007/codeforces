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
#define rrep(i,n,m) for(ll i = (m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T>
bool chmin(T &a,T b){if(a>b){a=b;return true;}else return false;}
template<typename T>
bool chmax(T &a,T b){if(a<b){a=b;return true;}else return false;}
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
ostream &operator<<(ostream &os, pair<ll, ll>&p){
  return os << p.first << " " << p.second;
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
  const sum_t ident;
  const F f;
  const G gg;

  ReRooting(int V, const F f, const G g, const sum_t &ident)
      : g(V), f(f), gg(g), ident(ident), subdp(V, ident), dp(V, ident) {}

  void add_edge(int u, int v, const key_t &d) {
    g[u].emplace_back((Edge) {v, d, ident, ident});
    g[v].emplace_back((Edge) {u, d, ident, ident});
  }

  void add_edge_bi(int u, int v, const key_t &d, const key_t &e) {
    g[u].emplace_back((Edge) {v, d, ident, ident});
    g[v].emplace_back((Edge) {u, e, ident, ident});
  }

  void dfs_sub(int idx, int par) {
    for(auto &e : g[idx]) {
      if(e.to == par) continue;
      dfs_sub(e.to, idx);
      subdp[idx] = f(subdp[idx], gg(subdp[e.to], e.data));
    }
  }

  void dfs_all(int idx, int par, const sum_t &top) {
    sum_t buff{ident};
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
  ll n;cin>>n;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  auto f1=[&](ll x,ll y){
    return max(0LL,x)+max(0LL,y);
  };
  auto f2=[&](ll x,ll c){
    return max(0LL,x+c);
  };
  ReRooting<ll,ll>reroot(n,f1,f2,0LL);
  rep(i,0,n-1){
    ll u,v;cin>>u>>v;u--;v--;
    ll ku=a[u]*2-1;
    ll kv=a[v]*2-1;
    //cout<<ku spa kv<<endl;
    reroot.add_edge_bi(v,u,ku,kv);
  }
  auto v=reroot.build();
  //debug(v,n);
  rep(i,0,n)v[i]+=a[i]*2-1;
  debug(v,n);
  return 0;
}