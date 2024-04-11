#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define test cout<<"test"<<endl;
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
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T>
void chmin(T &a,T b){if(a>b)a=b;}
template<typename T>
void chmax(T &a,T b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void pmod(ll &a,ll b,ll c){a=(b+c)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void qmod(ll &a,ll b,ll c){a=(b*c)%MOD;}
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
  int n;cin>>n;
  using pi=pair<int,int>;
  auto f1=[](pi x,pi y){
    return max(x,y);
  };
  auto f2=[](pi x,int w){
    return MP(x.fi+w,x.se);
  };
  ReRooting<pi,int>reroot(n,f1,f2,MP(0,0));
  rep(i,0,n){
    reroot.subdp[i]=MP(0,i);
  }
  rep(i,0,n-1){
    int u,v;cin>>u>>v;u--;v--;
    reroot.add_edge(u,v,1);
  }
  pair<int,vector<int>>ret;
  auto v=reroot.build();
  rep(i,0,n){
    pair<int,vector<int>>tmp;
    tmp.fi=0;
    vector<int>order(reroot.g[i].size());
    iota(ALL(order),0);
    sort(ALL(order),[&](int x,int y){
      return reroot.g[i][x].dp>reroot.g[i][y].dp;
    });
    ll cnt=0;
    /*cout<<i<<endl;
    for(auto idx:order){
      auto tmp=reroot.g[i][idx];
      cout<<idx spa tmp.dp.fi spa tmp.dp.se spa tmp.to<<endl;
    }*/
    for(auto idx:order){
      if(cnt>=3)break;
      tmp.fi+=reroot.g[i][idx].dp.fi;
      tmp.se.PB(reroot.g[i][idx].dp.se);
      cnt++;
    }
    while(tmp.se.size()<3)tmp.se.PB(0);
    chmax(ret,tmp);
  }
  cout<<ret.fi<<endl;
  rep(i,1,3){
    bool tmp=false;
    while(!tmp){
      tmp=true;
      rep(j,0,i)if(ret.se[i]==ret.se[j])tmp=false;
      if(!tmp)ret.se[i]=(ret.se[i]+1)%n;
    }
  }
  rep(i,0,3)ret.se[i]++;
  debug(ret.se,3);
  return 0;
}