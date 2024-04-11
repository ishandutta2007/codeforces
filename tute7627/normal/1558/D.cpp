//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define UNIQUE(a) (a).erase(unique((a).begin(),(a).end()),(a).end())
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
template< typename Monoid, typename OperatorMonoid,typename F, typename G, typename H>
struct LazySegmentTree {
  ll sz, height, n;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  Monoid M1;
  OperatorMonoid OM0;
  LazySegmentTree(ll n, const F &f,const G &g, const H &h, Monoid M1, OperatorMonoid OM0):n(n),f(f),g(g),h(h),M1(M1),OM0(OM0){
    sz = 1;
    height = 0;
    while(sz < n) sz <<= 1, height++;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(ll k, const Monoid &x) {
    data[k + sz] = x;
  }

  void build() {
    for(ll k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  inline void propagate(ll k) {
    if(lazy[k] != OM0) {
      lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
      lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      data[k] = reflect(k);
      lazy[k] = OM0;
    }
  }

  inline Monoid reflect(ll k) {
    return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
  }

  inline void recalc(ll k) {
    while(k >>= 1) data[k] = f(reflect(2 * k + 0), reflect(2 * k + 1));
  }

  inline void thrust(ll k) {
    for(ll i = height; i > 0; i--) propagate(k >> i);
  }

  void update(ll a, ll b, const OperatorMonoid &x) {
	if(a>=b)return;
    thrust(a += sz);
    thrust(b += sz - 1);
    for(ll l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) lazy[l] = h(lazy[l], x), ++l;
      if(r & 1) --r, lazy[r] = h(lazy[r], x);
    }
    recalc(a);
    recalc(b);
  }
  
  void update(ll a,const Monoid &x){
    thrust(a += sz);
    data[a] = x;
    lazy[a] = OM0;
    recalc(a);
  }

  Monoid query(ll a, ll b) {
	if(a>=b)return M1;
    thrust(a += sz);
    thrust(b += sz - 1);
    Monoid L = M1, R = M1;
    for(ll l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, reflect(l++));
      if(r & 1) R = f(reflect(--r), R);
    }
    return f(L, R);
  }

  Monoid operator[](const ll &k) {
    return query(k, k + 1);
  }

  template< typename C >
  ll find_subtree(ll a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      propagate(a);
      Monoid nxt = type ? f(reflect(2 * a + type), M) : f(M, reflect(2 * a + type));
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }

  template< typename C >
  ll find_first(ll a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, reflect(1)))) return find_subtree(1, check, L, false);
      return -1;
    }
    thrust(a + sz);
    ll b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, reflect(a));
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }


  template< typename C >
  ll find_last(ll b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(reflect(1), R))) return find_subtree(1, check, R, true);
      return -1;
    }
    thrust(b + sz - 1);
    ll a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(reflect(--b), R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
  void print(){
    for(ll i=0;i<n;i++)if((*this)[i]==M1)cout<<"x|";else cout<<(*this)[i]<<"|";
    cout<<endl;
  }
};
namespace add_min{
  using M=P;
  auto f=[](M x,M y){
    return min(x,y);
  };
  auto g=[](M x,ll y){
    return MP(x.fi + y,x.se);
  };
  auto h=[](ll x,ll y){
    return x + y;
  };
  LazySegmentTree<M,ll,decltype(f),decltype(g),decltype(h)>make(int n){
    return {n,f,g,h,MP(INF,1),0};
  }
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

template< typename T >
struct Combination {
  vector< T > _fact, _rfact, _inv;

  Combination(ll sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
    _fact[0] = _rfact[sz] = _inv[0] = 1;
    for(ll i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
    _rfact[sz] /= _fact[sz];
    for(ll i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
    for(ll i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
  }

  inline T fact(ll k) const { return _fact[k]; }

  inline T rfact(ll k) const { return _rfact[k]; }

  inline T inv(ll k) const { return _inv[k]; }

  T P(ll n, ll r) const {
    if(r < 0 || n < r) return 0;
    return fact(n) * rfact(n - r);
  }

  T C(ll p, ll q) const {
    if(q < 0 || p < q) return 0;
    return fact(p) * rfact(q) * rfact(p - q);
  }
  
  T RC(ll p, ll q) const {
    if(q < 0 || p < q) return 0;
    return rfact(p) * fact(q) * fact(p - q);
  }

  T H(ll n, ll r) const {
    if(n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};
using modint = ModInt< MOD9 >;modint pow(ll n, ll x){return modint(n).pow(x);}modint pow(modint n, ll x){return n.pow(x);}
//using modint=ld;
using Comb=Combination<modint>;
template<typename Monoid, typename OM>
struct LazyReversibleTreap{
  mt19937 mt;
  struct Node{
    Node* ch[2];
    int pri, sz = 1;
    Monoid val, sum;
    OM lazy;
    bool rev;
    Node(){}
    Node(Monoid val,OM lazy,int pri):val(val),lazy(lazy),sum(val),pri(pri),ch{nullptr, nullptr}{};
  };
  int nxt = 0;
  Monoid M1 = -INF;
  //Monoid M1 = MP(-INF,0);
  OM OM0 = 0;
  Monoid f(Monoid x, Monoid y){
    return max(x,y);
  }
  Monoid g(Monoid x, OM y){
    return x+y;
    //return MP(x.fi+y,x.se);
  }
  OM h(OM x, OM y){
    return x+y;
  }
  Monoid flip(Monoid x){
    return x;
  }
  LazyReversibleTreap():mt(chrono::steady_clock::now().time_since_epoch().count()){
  }
  LazyReversibleTreap(int x):mt(x){
    cout<<"debug"<<endl;
  }
  int gen(){
    return uniform_int_distribution<int>(0,1<<30)(mt);
  }
  int count(Node *t){return !t ? 0 : t->sz;};
  Monoid sum(Node *t){return !t ? M1 : t->sum;};
  Node* update(Node* t){
    if(!t)return t;
    for(int i=0;i<2;i++)if(t->ch[i])push(t->ch[i]);
    t->sz = count(t->ch[0]) + count(t->ch[1]) + 1;
    t->sum = f(t->val, f(sum(t->ch[0]), sum(t->ch[1])));
    return t;
  }
  void push(Node* t){
    if(t && t->lazy != OM0){
      t->val = g(t->val, t->lazy);
      t->sum = g(t->sum, t->lazy);
      for(int i = 0; i < 2; i++){
        if(t->ch[i])t->ch[i]->lazy = h(t->ch[i]->lazy, t->lazy);
      }
      t->lazy = OM0;
    }
    /*if(t && t->rev){
      t->rev = false;
      swap(t->ch[0], t->ch[1]);
      t->sum = flip(t->sum);
      if(t->ch[0])t->ch[0]->rev ^= true;
      if(t->ch[1])t->ch[1]->rev ^= true;
    }*/
  }
  template<typename ... Args>
  Node* merge(Node *l, Args... rest){
    Node *r=merge(rest...);
    push(l);
    push(r);
    if(!l || !r)return !l ? r : l;
    if(l->pri > r->pri){
      l->ch[1] = merge(l->ch[1], r);
      return update(l);
    }
    else{
      r->ch[0] = merge(l, r->ch[0]);
      return update(r);
    }
  }
  Node *merge(Node *l){
    return l;
  }
  using PN = pair<Node*, Node*>;
  PN split(Node* t, int k){ //[0,k),[k,n)
    if(!t) return make_pair(nullptr, nullptr);
    push(t);
    if(k <= count(t->ch[0])){
      PN s = split(t->ch[0], k);
      t->ch[0] = s.second;
      return make_pair(s.first, update(t));
    }
    else{
      PN s = split(t->ch[1], k - count(t->ch[0]) - 1);
      t->ch[1] = s.first;
      return make_pair(update(t), s.second);
    }
  }
  tuple<Node*,Node*,Node*> split3(Node *&t, int l, int r){//[0,l),[l,r),[r,n)
    PN sp = split(t,r);
    PN sp2 = split(sp.first,l);
    return make_tuple(sp2.first, sp2.second, sp.second);
  }
  //k
  void insert(Node *&t, int k, Monoid val){
    PN sp = split(t,k);
    sp.first = merge(sp.first, new Node(val, OM0, gen()));
    t = merge(sp.first, sp.second);
  }
  //k
  void erase(Node *&t, int k){
    PN sp = split(t,k+1);
    PN sp2 = split(sp.first,k);
    t = merge(sp2.first,sp.second); 
  }
  int size(Node *t){
    return count(t);
  }
  Node* make_root(){
    return nullptr;
  }
  void set_propagate(Node *t,OM x){
    if(!t)return;
    t->lazy = h(t->lazy, x);
    push(t);
  }
  void set_propagate(Node *&t,int l,int r,OM x){
    PN sp = split(t,r);
    PN sp2 = split(sp.first,l);
    set_propagate(sp2.second, x);
    t = merge(sp2.first,sp2.second,sp.second);
  }
  void reverse(Node *t){
    if(!t)return;
    t->rev ^= true;
    push(t);
  }
  void reverse(Node *&t,int l,int r){
    PN sp = split(t,r);
    PN sp2 = split(sp.first,l);
    reverse(sp2.second);
    t = merge(sp2.first,sp2.second,sp.second);
  }
  Monoid query(Node *&t){
    if(!t)return M1;
    push(t);
    update(t);
    return t->sum;
  }
  Monoid query(Node *&t,int l,int r){
    PN sp = split(t,r);
    PN sp2 = split(sp.first,l);
    Monoid ret = query(sp2.second);
    t = merge(sp2.first,sp2.second,sp.second);
    return ret;
  }
  //tcheckt 
  //-1
  template<typename F>
  int find_first(Node *t, const F &check){
    int ret = 0;
    Monoid now = M1;
    if(!check(sum(t)))return -1;
    while(1){
      push(t);
      if(!t)return ret;
      push(t->ch[0]);
      if(check(f(now, sum(t->ch[0])))){
        t = t->ch[0];
      }
      else{
        now = f(now, sum(t->ch[0]));
        ret += count(t->ch[0]);
        now = f(now, t->val);
        if(check(now))return ret;
        ret++;
        t = t->ch[1];
      }
    }
  }
  //tcheckt 
  //-1
  template<typename F>
  int find_first(Node *t,int k,const F &check){
    PN sp = split(t,k);
    int ret = sp.find_first(sp.second,check);
    if(ret == -1)return ret;
    return k + ret;
  }
  vector<Node>enumerate(Node *t){
    vector<Node>ret;
    vector<Monoid>db;
    auto dfs=[&](auto &&f, Node *nt)->void{
      if(!nt)return;
      push(nt);
      for(int i=0;i<2;i++){
        if(i==1){
          db.push_back(nt->val);
          ret.push_back(*nt);
        }
        if(nt->ch[i])f(f, nt->ch[i]);
      }
      update(nt);
    };
    dfs(dfs, t);
    //debug(db,db.size(),"|");
    return ret;
  }
};

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll t;cin>>t;
  Comb comb(1000005);
  LazyReversibleTreap<ll,ll>seg;
  while(t--){
    ll n,m;cin>>n>>m;
    vector<ll>x(m),y(m);
    rep(i,0,m)cin>>x[i]>>y[i];
    auto r=seg.make_root();
    rep(i,0,m){
      auto check=[&](ll p){
        return p>=y[i];
      };
      ll k=seg.find_first(r,check);
      if(k==-1)k=seg.count(r);
      seg.set_propagate(r,k,seg.count(r),1);
      seg.insert(r,k,y[i]+1);
    }
    set<ll>st;
    auto v=seg.enumerate(r);
    for(auto z:v)st.insert(z.val);
    cout<<comb.H(n+1,n-1-st.size())<<endl;
  }
  return 0;
}