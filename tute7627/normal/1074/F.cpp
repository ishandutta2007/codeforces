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
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
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

  Monoid query(ll a, ll b) {
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
struct edge{
  ll to=-1,cost=0;
  edge(){};
  edge(ll t,ll c):to(t),cost(c){};
};
struct HLD{
  ll n, root;
  ll cnt = 0;
  vector<ll>sz;//
  vector<ll>par,head;
  vector<vector<struct edge>>g;//
  vector<struct edge>edges;//edge
  vector<ll>in,out;//[in,out)[ina,inb]a~b(a)
  //inindexedge
  HLD(vector<vector<struct edge>>&G,ll r = -1)
      :g(G),n(G.size()),root(r){
    par.assign(n,-1),in.assign(n,-1);
    out.assign(n,-1),head.assign(n,-1),sz.assign(n,-1);
    edges.assign(n,edge());
    dfs_build();
  }
  void dfs_build(){
    if(root == -1){//()
      for(ll i=0;i<n;i++){
        if(sz[i] == -1){
          head[i] = i;
          dfs_sz(i);
          dfs_hld(i);
        }
      }
    }
    else{
      head[root] = root;
      dfs_sz(root);
      dfs_hld(root);
    }
  }
  void dfs_sz(ll k){
    sz[k] = 1;
    for(auto &e: g[k]){
      if(e.to == par[k])continue;
      par[e.to] = k;
      dfs_sz(e.to);
      sz[k] += sz[e.to];
      if(sz[e.to] > sz[g[k][0].to])swap(e, g[k][0]);
    }
  }
  void dfs_hld(ll k){
    in[k] = cnt++;
    for(auto e:g[k]){
      if(e.to == par[k])continue;
      head[e.to] = (e.to == g[k][0].to ? head[k]: e.to);
      edges[cnt] = e;
      dfs_hld(e.to);
    }
    out[k] = cnt;
  }
  ll lca(ll p,ll q){
    while(1){
      if(in[p] < in[q])swap(p,q);
      if(head[p] == head[q])return q;
      p = par[head[p]];
    }
  }
  vector<pair<ll,ll>>query_path(ll p,ll q,bool isEdge){
    ll r=lca(p,q);
    vector<pair<ll,ll>>ret;
    for(ll i=0;i<2;i++){
      if(i == 1)swap(p,q);
      while(1){
        if(isEdge&&p==r)break;
        if(head[p]==head[r]){
          ret.emplace_back(in[r]+(isEdge?1:i),in[p]+1);
          break;
        }
        ret.emplace_back(in[head[p]],in[p]+1);
        p = par[head[p]];
      }
    }
    return ret;
  }
  vector<vector<pair<ll,ll>>>query_order_path(ll p,ll q,bool isEdge){
	//01
    vector<vector<pair<ll,ll>>>ret(2);
    ll r=lca(p,q);
    for(ll i=0;i<2;i++){
      if(i == 1)swap(p,q);
      while(1){
        if(isEdge&&p==r)break;
        if(head[p]==head[r]){
          if(i==0) ret[i].emplace_back(n-(in[p]+1),n-(in[r]+(isEdge?1:i)));
          else ret[i].emplace_back(in[r]+(isEdge?1:i),in[p]+1);
          break;
        }
        if(i==0) ret[i].emplace_back(n-(in[p]+1),n-(in[head[p]]));
        else ret[i].emplace_back(in[head[p]],in[p]+1);
        p = par[head[p]];
      }
    }
    reverse(ret[1].begin(), ret[1].end());
    return ret;
  }
  pair<ll,ll>query_subtree(ll p,bool isEdge){
    return make_pair(in[p]+isEdge,out[p]);
  }
  //uv 
  ll child(ll u,ll v){
    while(1){
      if(head[u]==head[v]){
        v=g[u][0].to;
        break;
      }
      v=head[v];
      if(par[v]==u)break;
      v=par[v];
    }
    return v;
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  auto ff=[&](P x,P y){
    if(x.fi!=y.fi)return min(x,y);
    else return MP(x.fi,y.se+x.se);
  };
  auto gg=[&](P x,ll y){
    return MP(x.fi+y,x.se);
  };
  auto hh=[&](ll x,ll y){
    return x+y;
  };
  ll n,q;cin>>n>>q;
  LazySegmentTree<P,ll,decltype(ff),decltype(gg),decltype(hh)>seg(n,ff,gg,hh,MP(INF,0),0);
  rep(i,0,n)seg.set(i,MP(0,1));
  seg.build();
  vector<vector<edge>>g(n);
  rep(i,0,n-1){
    ll u,v;cin>>u>>v;u--;v--;
    g[u].EB(v,0);
    g[v].EB(u,0);
  }
  HLD hld(g,0);
  set<P>st;
  while(q--){
    //seg.print();
    ll u,v;cin>>u>>v;u--;v--;
    P p=minmax(u,v);
    ll add=0;
    if(st.count(p)){
      add=-1;
      st.erase(p);
    }
    else{
      add=1;
      st.insert(p);
    }
    if(hld.in[u]>hld.in[v])swap(u,v);
    if(hld.lca(u,v)==u){
      ll up=hld.child(u,v);
      //cout<<up spa v spa add spa hld.in[up] spa hld.in[v]<<endl;
      auto sub1=hld.query_subtree(up,false);
      auto sub2=hld.query_subtree(v,false);
      seg.update(sub1.fi,sub1.se,add);
      //seg.print();
      seg.update(sub2.fi,sub2.se,-add);
      //seg.print();
    }
    else{
      auto sub1=hld.query_subtree(u,false);
      auto sub2=hld.query_subtree(v,false);
      auto sub3=hld.query_subtree(0,false);
      seg.update(sub1.fi,sub1.se,-add);
      //seg.print();
      seg.update(sub2.fi,sub2.se,-add);
      //seg.print();
      seg.update(sub3.fi,sub3.se,add);
      //seg.print();
    }
    auto tmp=seg.query(0,n);
    ans(tmp.fi==0,tmp.se,0);
  }
  return 0;
}