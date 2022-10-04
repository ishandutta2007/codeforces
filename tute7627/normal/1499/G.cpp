//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

//#define endl '\n'
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
template<typename T>void debug(T &v,ll h,ll w,string sv=" "){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void debug(T &v,ll n,string sv=" "){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
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
using modint = ModInt< MOD9 >;modint pow(ll n, ll x){return modint(n).pow(x);}modint pow(modint n, ll x){return n.pow(x);}
//using modint=ld;
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n1,n2,m;cin>>n1>>n2>>m;
  ll lim=500005;
  vector<deque<ll>>es;
  vector<P>p;
  vector<ll>h;
  vector<ll>a(n1+n2,-1);
  vector<modint>two(lim,1);
  rep(i,0,two.size()-1)two[i+1]=two[i]*2;
  modint hash=0;
  auto push=[&](ll i,ll e,bool back){
    //cout<<"add" spa i spa e spa back spa h[i]<<endl;
    assert(es.size()>i);
    if(back){
      if(es[i].size()%2!=h[i])hash+=two[e];
      es[i].push_back(e);
    }
    else{
      if(!h[i])hash+=two[e];
      es[i].push_front(e);
      h[i]^=1;
    }
  };
  auto add=[&](ll i,ll u,ll v){
    v+=n1;
    //cout<<"add" spa i spa u spa v spa a[u] spa a[v]<<endl;
    if(a[u]==-1&&a[v]==-1){
      p.EB(u,v);
      h.PB(0);
      a[u]=es.size(),a[v]=es.size();
      es.EB();
      es[a[u]].push_back(i);
    }
    else if(a[u]==a[v]){
      push(a[u],i,true);
      a[u]=-1;
      a[v]=-1;
    }
    else if(a[u]!=-1&&a[v]!=-1){
      if(es[a[u]].size()<es[a[v]].size())swap(u,v);
      rep(j,0,es[a[v]].size()){
        if(j%2!=h[a[v]])hash-=two[es[a[v]][j]];
      }
      if(p[a[v]].fi!=v){
        swap(p[a[v]].fi,p[a[v]].se);
        reverse(ALL(es[a[v]]));
      }
      push(a[u],i,p[a[u]].se==u);
      for(auto z:es[a[v]])push(a[u],z,p[a[u]].se==u);
      if(p[a[u]].se==u)p[a[u]].se=p[a[v]].se;
      else p[a[u]].fi=p[a[v]].se;
      a[p[a[u]].fi]=a[u],a[p[a[u]].se]=a[u];
      es[a[v]].clear();
      a[u]=-1,a[v]=-1;

    }
    else{
      if(a[u]==-1)swap(u,v);
      //cout<<"tmp" spa i spa u spa v spa p[a[u]]<<endl;
      push(a[u],i,p[a[u]].se==u);
      if(p[a[u]].se==u)p[a[u]].se=v;
      else p[a[u]].fi=v;
      a[p[a[u]].fi]=a[u],a[p[a[u]].se]=a[u];
      //cout<<p[a[u]]<<endl;
      a[u]=-1;
    }
  };
  rep(i,1,m+1){
    ll x,y;cin>>x>>y;x--;y--;
    add(i,x,y);
  }
  ll q;cin>>q;
  cout<<endl;
  auto print=[&](){
    cout<<"deque"<<endl;
    rep(i,0,es.size()){
      rep(j,0,es[i].size()){
        cout<<es[i][j]<<" ";
      }
      cout<<endl;
    }
    debug(a,n1+n2);
  };
  ll cnt=m+1;
  rep(i,m+1,m+q+1){
    ll type;cin>>type;
    if(type==1){
      ll u,v;cin>>u>>v;u--;v--;
      add(cnt++,u,v);
      cout<<hash<<endl;
    }
    else{
      vector<ll>ret;
      rep(o,0,es.size()){
        rep(j,0,es[o].size()){
          if(j%2!=h[o])ret.PB(es[o][j]);
        }
      }
      //cout<<"recover"<<endl;
      cout<<ret.size()<<" ";debug(ret,ret.size());
    }
    //print();
  }
  return 0;
}