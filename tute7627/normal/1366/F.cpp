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
vector<ll>dx={1,-1,0,0,1,1,-1,-1};
vector<ll>dy={0,0,1,-1,1,-1,1,-1};
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
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};
using modint = ModInt< MOD1 >;modint pow(ll n, ll x){return modint(n).pow(x);}modint pow(modint n, ll x){return n.pow(x);}
//using modint=ld;
struct edge {
  ll to,id,cost;
  edge(ll to,ll id,ll cost):to(to),id(id),cost(cost){};
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m,q;cin>>n>>m>>q;
  vector<vector<edge>>g(n);
  vector<ll>w(m);
  rep(i,0,m){
    ll u,v,c;cin>>u>>v>>c;u--;v--;
    w[i]=c;
    g[u].EB(v,i,c);
    g[v].EB(u,i,c);
  }
  auto dp=make_v(n+1,n,-INF);
  vector<ll>b(m,-INF);
  dp[0][0]=0;
  rep(i,0,n){
    rep(j,0,n){
      for(auto e:g[j]){
        chmax(dp[i+1][e.to],dp[i][j]+e.cost);
        chmax(b[e.id],dp[i][j]-w[e.id]*i);
      }
    }
  }
  modint ret=0;
  rep(i,1,min(n,q+1))ret+=*max_element(ALL(dp[i]));
  if(q<n){
    cout<<ret<<endl;
    return 0;
  }
  vector<ll>order(m);
  iota(ALL(order),0);
  sort(ALL(order),[&](ll x,ll y){
    if(w[x]==w[y])return b[x]>b[y];
    else return w[x]<w[y];
  });
  vector<P>v;
  auto f=[&](ll x,ll y){
    //w[x]<w[y]
    //w[y]*t+b[y]<w[x]*t+b[x]t
    //(w[y]-w[x])t<b[x]-b[y]
    ll t=(b[x]-b[y])/(w[y]-w[x]);
    t-=1;
    while((w[y]-w[x])*t<b[x]-b[y])t++;
    return t;
  };
  for(auto i:order){
    while(!v.empty()){
      ll k=v.back().fi;
      ll id=v.back().se;
      if(w[id]==w[i])break;
      ll nxt=f(id,i);
      if(k>nxt)v.pop_back();
      else break;
    }
    if(!v.empty()&&w[v.back().se]==w[i])continue;
    if(v.empty())v.EB(n,i);
    else v.EB(f(v.back().se,i),i);
  }
  while(v.back().fi>q)v.pop_back();
  v.EB(q+1,-1);
  auto sum=[&](ll x,ll k){
    return modint(w[x])*((k*(k+1))>>1)+modint(b[x])*k;
  };
  rep(i,0,(ll)v.size()-1){
    ret+=sum(v[i].se,v[i+1].fi-1)-sum(v[i].se,v[i].fi-1);
  }
  cout<<ret<<endl;
  return 0;
}