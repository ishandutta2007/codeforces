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
using ll = int;
using ld = long double;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e9;
using P = pair<ll, ll>;
template<typename T>
void chmin(T &a,T b){if(a>b)a=b;}
template<typename T>
void chmax(T &a,T b){if(a<b)a=b;}
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
template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree {

  ll sz, height;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  Monoid f(Monoid x,Monoid y){
    return x<y?x:y;
  };
  Monoid g(Monoid x,OperatorMonoid y){
    return max(x,y);
  };
  OperatorMonoid h(OperatorMonoid x,OperatorMonoid y){
    return max(x,y);
  };
  const Monoid M1 = INF;
  const OperatorMonoid OM0 = 1;
  LazySegmentTree(ll n){
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
    for(ll i=0;i<sz;i++)cout<<(*this)[i]<<" ";
    cout<<endl;
  }
};
struct edge{
  ll to,cost,id;
  edge(ll t,ll i):to(t),id(i){};
};
struct HLD{
  ll n, root;
  vector<ll>sz;//
  vector<ll>depth,par,hv_chi;
  vector<ll>head;
  vector<vector<struct edge>>g;//
  vector<struct edge>edges;//edge
  vector<ll>idx;//edgeindexorindex
  vector<ll>subidx;//+1
  HLD(vector<vector<struct edge>>G,ll r)
      :g(G),n(G.size()),root(r){
    depth.assign(n,-1),par.assign(n,-1),hv_chi.assign(n,-1);
    sz.assign(n,-1),head.assign(n,-1),idx.assign(n,-1);
    subidx.assign(n,-1);
    edges.emplace_back(0,0);
    idx[root] = 0;
    dfs_sz(root,0);
    dfs_hl(root);
    subidx[root]=edges.size();
  }
  ll dfs_sz(ll k, ll d){
    depth[k] = d;
    ll sum_sz = 0;
    ll max_sz = 0,idx = -1;
    for(ll i=0;i<g[k].size();i++){
      if(depth[g[k][i].to] == -1){
        ll tmp_sz = dfs_sz(g[k][i].to, d+1); 
        sum_sz += tmp_sz;
        if(max_sz < tmp_sz)max_sz = tmp_sz,idx = g[k][i].to;
        par[g[k][i].to] = k;
      }
    }
    hv_chi[k] = idx;
    sz[k] = sum_sz + 1;
    return sz[k];
  }
  void dfs_hl(ll k){
    if(head[k]==-1)head[k]=k;
    for(ll i=0;i<g[k].size();i++){
      if(head[g[k][i].to]==-1&&hv_chi[k]==g[k][i].to){
        head[g[k][i].to] = head[k];
        idx[g[k][i].to]=edges.size();
        edges.push_back(g[k][i]);
        dfs_hl(g[k][i].to);
        subidx[g[k][i].to]=edges.size();
      }
    }
    for(ll i=0;i<g[k].size();i++){
      if(head[g[k][i].to]==-1&&hv_chi[k]!=g[k][i].to){
        idx[g[k][i].to]=edges.size();
        edges.push_back(g[k][i]);
        dfs_hl(g[k][i].to);
        subidx[g[k][i].to]=edges.size();
      }
    }
  }
  ll lca(ll p,ll q){
    while(1){
      if(depth[head[p]] > depth[head[q]])swap(p,q);
      if(head[p] == head[q])break;
      q = par[head[q]];
    }
    if(depth[p] > depth[q])swap(p,q);
    return p;
  }
  vector<pair<ll,ll>>query_path(ll p,ll q,bool isEdge){
    vector<ll>v = {p,q};
    ll r=lca(p,q);
    vector<pair<ll,ll>>ret;
    for(ll i=0;i<2;i++){
      while(1){
        if(isEdge&&v[i]==r)break;
        if(head[v[i]]==head[r]){
          ret.emplace_back(idx[r]+(isEdge?1:i),idx[v[i]]+1);
          break;
        }
        ret.emplace_back(idx[head[v[i]]],idx[v[i]]+1);
        v[i] = par[head[v[i]]];
      }
    }
    return ret;
  }

  pair<ll,ll>query_subtree(ll p,bool isEdge){
    return MP(idx[p]+isEdge,subidx[p]);
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  bool judge = true;
  int n;cin>>n;
  vector<vector<edge>>g(n);
  rep(i,0,n-1){
    int u,v;cin>>u>>v;u--;v--;
    g[u].EB(v,i);g[v].EB(u,i);
  }
  HLD hld(g,0);
  LazySegmentTree<ll>seg(n);
  rep(i,0,n)seg.set(i,1);
  seg.build();
  //seg.print();
  int m;cin>>m;
  vector<int>a(m),b(m),c(m);
  vector<int>mi(n-1,1);
  rep(i,0,m){
    cin>>a[i]>>b[i]>>c[i];a[i]--;b[i]--;
    auto v=hld.query_path(a[i],b[i],true);
    for(auto idx:v){
      seg.update(idx.fi,idx.se,c[i]);
    }
  }
  rep(i,0,m){
    int tmp=1e9;
    auto v=hld.query_path(a[i],b[i],true);
    for(auto idx:v)chmin(tmp,seg.query(idx.fi,idx.se));
    if(tmp!=c[i])judge=false;
  }
  //seg.print();
  if(!judge)cout<<-1<<endl;
  else{
    vector<ll>ret(n-1);
    rep(i,0,n){
      //cout<<hld.edges[i].id spa seg[i]<<endl;
      ret[hld.edges[i].id]=seg[i];
    }
    debug(ret,n-1);
  }
  return 0;
}