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
template<typename T> using PQ = priority_queue<T>;
template<typename T> using QP = priority_queue<T,vector<T>,greater<T>>;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T1,typename T2,typename T3>void anss(T1 x,T2 y,T3 z){ans(x!=y,x,z);};  
template<typename T>void debug(const T &v,ll h,ll w,string sv=" "){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void debug(const T &v,ll n,string sv=" "){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
template<typename T>void debug(const vector<T>&v){debug(v,v.size());}
template<typename T>void debug(const vector<vector<T>>&v){for(auto &vv:v)debug(vv,vv.size());}
template<typename T>void debug(stack<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(queue<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(deque<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop_front();}cout<<endl;}
template<typename T>void debug(PQ<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(QP<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(const set<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T>void debug(const multiset<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T,size_t size>void debug(const array<T, size> &a){for(auto z:a)cout<<z<<" ";cout<<endl;}
template<typename T,typename V>void debug(const map<T,V>&v){for(auto z:v)cout<<"["<<z.first<<"]="<<z.second<<",";cout<<endl;}
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
ll digitsum(ll n){ll ret=0;while(n){ret+=n%10;n/=10;}return ret;}
template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T acc(const vector<T>&v){return accumulate(v.begin(),v.end(),T(0));};
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
  edge():id(-1){};
  edge(int to, T cost = 1, int id = -1):to(to), cost(cost), id(id){}
  operator int() const { return to; }
};

template<typename T>
using Graph = vector<vector<edge<T>>>;
template<typename T>
Graph<T>revgraph(const Graph<T> &g){
  Graph<T>ret(g.size());
  for(int i=0;i<g.size();i++){
    for(auto e:g[i]){
      int to = e.to;
      e.to = i;
      ret[to].push_back(e);
    }
  }
  return ret;
}
template<typename T>
Graph<T> readGraph(int n,int m,int indexed=1,bool directed=false,bool weighted=false){
  Graph<T> ret(n);
  for(int es = 0; es < m; es++){
    int u,v;
    T w=1;
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

  friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) += rhs;
  }
  friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) -= rhs;
  }
  friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) *= rhs;
  }
  friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) /= rhs;
  }

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
namespace SubsetConvolution{
  using T = modint;
  const int max_size = 17;
  T fa[1<<max_size][max_size + 1];
  T fb[1<<max_size][max_size + 1];
  vector<T>subset_conv(const vector<T> &a, const vector<T> &b){
    int sz = 0;
    while(a.size() > 1<<sz)sz++;
    for(int i = 0; i < a.size(); i++){
      int pk = __builtin_popcount(i);
      for(int j = 0; j <= sz; j++){
        fa[i][j] = (j == pk ? a[i] : 0);
        fb[i][j] = (j == pk ? b[i] : 0);
      }
    }
    for(int i = 1; i < a.size(); i <<= 1){
      for(int j = 0; j < a.size(); j++){
        if(i & j){
          for(int k = 0; k <= sz; k++){
            fa[j][k] += fa[j^i][k];
            fb[j][k] += fb[j^i][k];
          }
        }
      }
    }
    for(int i = 0; i < a.size(); i++){
      for(int j = sz; j >= 0; j--){
        for(int k = 1; k <= sz - j; k++){
          fa[i][j + k] += fa[i][j] * fb[i][k];
        }
        fa[i][j] *= fb[i][0];
      }
    }
    for(int i = 1; i < a.size(); i <<= 1){
      for(int j = 0; j < a.size(); j++){
        if(i & j){
          for(int k = 0; k <= sz; k++){
            fa[j][k] -= fa[j^i][k];
            fb[j][k] -= fb[j^i][k];
          }
        }
      }
    }
    vector<T>ret(a.size());
    for(int i = 0; i < a.size();i++){
      ret[i] = fa[i][__builtin_popcount(i)];
    }
    return ret;
  }
}
namespace BitConvolution{
  template<typename T>
  vector<T> or_zeta(const vector<T> &v){
    vector<T> ret = v;
    for(int i = 1; i < v.size(); i <<= 1){
      for(int j = 0; j < v.size(); j++){
        if(i & j)ret[j] += ret[j^i];
      }
    }
    return ret;
  }
  template<typename T>
  vector<T> or_meb(const vector<T> &v){
    vector<T> ret = v;
    for(int i = 1; i < v.size(); i <<= 1){
      for(int j = 0; j < v.size(); j++){
        if(i & j)ret[j] -= ret[j^i];
      }
    }
    return ret;
  }
  template<typename T>
  vector<T> and_zeta(const vector<T> &v){
    vector<T> ret = v;
    for(int i = 1; i < v.size(); i <<= 1){
      for(int j = 0; j < v.size(); j++){
        if(i & j)ret[j^i] += ret[j];
      }
    }
    return ret;
  }
  template<typename T>
  vector<T> or_conv(const vector<T> &a, const vector<T> &b){
    auto az = or_zeta(a);
    auto bz = or_zeta(b);
    for(int i = 0; i < az.size(); i++){
      az[i] *= bz[i];
    }
    return or_meb(az);
  }
  template<typename T>
  vector<T> and_meb(const vector<T> &v){
    vector<T> ret = v;
    for(int i = 1; i < v.size(); i <<= 1){
      for(int j = 0; j < v.size(); j++){
        if(i & j)ret[j^i] -= ret[j];
      }
    }
    return ret;
  }
  template<typename T>
  vector<T> xor_zeta(const vector<T> &v){
    vector<T> ret = v;
    for(int i = 1; i < v.size(); i <<= 1){
      for(int j = 0; j < v.size(); j++){
        if((i & j) == 0){
          T x = ret[j], y = ret[j | i];
          ret[j] = x + y, ret[j | i] = x - y;
        }
      }
    }
    return ret;
  }
  template<typename T>
  vector<T> and_conv(const vector<T> &a, const vector<T> &b){
    auto az = and_zeta(a);
    auto bz = and_zeta(b);
    for(int i = 0; i < az.size(); i++){
      az[i] *= bz[i];
    }
    return and_meb(az);
  }
  template<typename T>
  vector<T> xor_meb(const vector<T> &v){
    vector<T> ret = v;
    auto inv=modint(1)/2;
    for(int i = 1; i < v.size(); i <<= 1){
      for(int j = 0; j < v.size(); j++){
        if((i & j) == 0){
          T x = ret[j], y = ret[j | i];
          ret[j] = (x + y) *inv, ret[j | i] = (x - y) *inv;
        }
      }
    }
    return ret;
  }
  template<typename T>
  vector<T> xor_conv(const vector<T> &a, const vector<T> &b){
    auto az = xor_zeta(a);
    auto bz = xor_zeta(b);
    for(int i = 0; i < az.size(); i++){
      az[i] *= bz[i];
    }
    return xor_meb(az);
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  ll k=17;
  vector<modint>v(1<<k);
  rep(i,0,n){
    ll s;cin>>s;
    v[s]+=1;
  }
  vector<modint>f((1<<k)+1);
  f[1]=1;
  rep(i,2,f.size())f[i]=f[i-1]+f[i-2];
  auto x=SubsetConvolution::subset_conv(v,v);
  rep(i,0,1<<k)x[i]*=f[i];
  auto y=v;
  rep(i,0,1<<k)y[i]*=f[i];
  auto z=BitConvolution::xor_conv(v,v);
  rep(i,0,1<<k)z[i]*=f[i];
  x=BitConvolution::and_zeta(x);
  y=BitConvolution::and_zeta(y);
  z=BitConvolution::and_zeta(z);
  rep(i,0,1<<k)x[i]=x[i]*y[i]*z[i];
  x=BitConvolution::and_meb(x);
  modint ret=0;
  rep(i,0,k)ret+=x[1<<i];
  cout<<ret<<endl;
  return 0;
}