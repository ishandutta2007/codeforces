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
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>void debug(vector<vector<T>>&v,ll h,ll w){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>&v,ll h,ll w){for(ll i=0;i<h;i++){for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>void debug(vector<T>&v,ll n){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";cout<<"|"; return os;}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
template< typename Monoid >
struct PersistentSegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;
 
  struct Node {
    Monoid data;
    Node *l, *r;
 
    Node(const Monoid &data) : data(data), l(nullptr), r(nullptr) {}
  };
 
 
  int sz;
  const F f;
  const Monoid M1;
 
  PersistentSegmentTree(const F f, const Monoid &M1) : f(f), M1(M1) {}
 
  Node *build(vector< Monoid > &v) {
    sz = (int) v.size();
    return build(0, (int) v.size(), v);
  }
 
  Node *merge(Node *l, Node *r) {
    auto t = new Node(f(l->data, r->data));
    t->l = l;
    t->r = r;
    return t;
  }
 
  Node *build(int l, int r, vector< Monoid > &v) {
    if(l + 1 >= r) return new Node(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }
 
  Node *update(int a, const Monoid &x, Node *k, int l, int r) {
    if(r <= a || a + 1 <= l) {
      return k;
    } else if(a <= l && r <= a + 1) {
      return new Node(x);
    } else {
      return merge(update(a, x, k->l, l, (l + r) >> 1), update(a, x, k->r, (l + r) >> 1, r));
    }
  }
 
  Node *update(Node *t, int k, const Monoid &x) {
    return update(k, x, t, 0, sz);
  }
 
  Monoid query(int a, int b, Node *k, int l, int r) {
    if(r <= a || b <= l) {
      return M1;
    } else if(a <= l && r <= b) {
      return k->data;
    } else {
      return f(query(a, b, k->l, l, (l + r) >> 1),
               query(a, b, k->r, (l + r) >> 1, r));
    }
  }
 
  Monoid query(Node *t, int a, int b) {
    return query(a, b, t, 0, sz);
  }
  void print(Node *t){
    for(int i=0;i<sz;i++)cout<<query(t,i,i+1)<<" ";cout<<endl;
  }
};
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
//maxa=10^7150ms,78MB10^81800ms,780MB
struct osa_k{
  ll maxa;
  vector<ll>data;//data[i]:i
  osa_k(ll a):maxa(a){
    data.assign(maxa+1,1LL);
    build();
  }
  void build(){
    for(ll i=0;i<=maxa;i++)data[i] = i;
    for(ll i=2;i*i<=maxa;i++){
      if(data[i] < i)continue;
      for(ll j=i*i;j<=maxa;j+=i){
        if(data[j] == j)data[j] = i;
      }
    }
  }
  bool isPrime(ll x){
    return (x >= 2)&&(data[x] == x);
  }
  map<ll,ll>factoring(ll x){
    map<ll,ll>ret;
    while(x > 1){
      ret[data[x]]++;
      x /= data[x];
    }
    return ret;
  }
  vector<ll>divisor_enum(ll x){
    auto v = factoring(x);
    vector<ll>ret;
    ret.push_back(1);
    for(auto z:v){
      ll sz = ret.size();
      ll tmp = z.fi;
      for(ll i=0;i<z.se;i++){
        for(ll j=0;j<sz;j++){
          ret.push_back(ret[j] * tmp);
        }
        tmp *= z.fi;
      }
    }
    sort(ret.begin(),ret.end());//ok
    return ret;
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  auto f=[&](modint x,modint y){
    return x*y;
  };
  PersistentSegmentTree<modint>seg(f,1);
  map<ll,stack<P>>mp;
  ll n;cin>>n;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  osa_k osak(200005);
  using N=PersistentSegmentTree<modint>::Node;
  vector<N*>p;
  vector<modint>tmpppp(n,1);
  auto now=seg.build(tmpppp);
  rep(i,0,n){
    auto fac=osak.factoring(a[i]);
    map<ll,modint>upd;
    auto chm=[&](ll x,modint y){
      if(upd.count(x))upd[x]*=y;
      else upd[x]=y;
    };
    for(auto z:fac){
      auto &st=mp[z.fi];
      ll pre=0;
      while(!st.empty()&&st.top().se<=z.se){
        auto t=st.top();
        st.pop();
        chm(t.fi,modint(1)/pow(z.fi,t.se-pre));
        pre=t.se;
      }
      chm(i,pow(z.fi,z.se));
      if(!st.empty()){
        auto t=st.top();
        //cout<<z spa t spa pre spa tmp<<endl;
        chm(t.fi,modint(1)/pow(z.fi,t.se-pre));
        chm(t.fi,pow(z.fi,t.se-z.se));
      }
      st.emplace(i,z.se);
    }
    for(auto z:upd){
      auto tmp=seg.query(now,z.fi,z.fi+1);
      now=seg.update(now,z.fi,tmp*z.se);
    }
    //seg.print(now);
    p.push_back(now);
  }
  ll last=0;
  ll q;cin>>q;
  while(q--){
    ll x,y;cin>>x>>y;
    ll l=(x+last)%n+1,r=(y+last)%n+1;
    if(l>r)swap(l,r);
    l--;
    auto tmp=seg.query(p[r-1],l,r);
    last=tmp.x;
    cout<<last<<endl;
  }
  return 0;
}