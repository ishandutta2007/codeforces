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
template<typename Head, typename... Tail>void rearrange(vector<ll>&ord,Head&& head, Tail&&... tail){
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
template< typename Monoid ,typename F>
struct SegmentTree {
  int sz, n;
  vector< Monoid > seg;
  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1), n(n){
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
	  if(a>=b)return M1;
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }
  //[a,x]x,-1
  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, seg[a]);
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }
  //[x,b)x,-1
  template< typename C >
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(seg[--b], R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
  void print(){
    for(ll i=0;i<n;i++)if((*this)[i]==M1)cout<<"x ";else cout<<(*this)[i]<<" ";
    cout<<endl;
  }
};
namespace range_xor{
  using M=ll;
  auto f=[](M x,M y){
    return x^y;
  };
  SegmentTree<M,decltype(f)>make(int n){
    return {n,f,0LL};
  }
}
template<typename T>
struct HLD{
  using D=long long;
  int n;
  vector<int>sz;//
  vector<D>dep;
  vector<int>par;
  vector<int>head;
  Graph<T> &g;//
  vector<edge<T>>edges;//edge
  vector<int>in,out;//[in,out)[ina,inb]a~b(a)
  vector<int>comp;//
  //inindexedge
  HLD(Graph<T> &g,int r=-1):g(g),n(g.size()){
    hld_build(r);
  }
  void hld_build(int root = -1){
    in.assign(n,-1);out.assign(n,-1);dep.assign(n,0);
    par.assign(n,-1);head.assign(n,-1);sz.assign(n,-1);comp.assign(n,-1);
    edges.assign(n,edge<T>());
    if(root == -1){//()
      for(int i=0;i<n;i++){
        if(sz[i] == -1){
          head[i] = i;
          dfs_sz(i, 0, i);
          dfs_hld(i);
        }
      }
    }
    else{
      head[root] = root;
      dfs_sz(root, 0, root);
      dfs_hld(root);
    }
  }
  void dfs_sz(int k, D d,int r){
    sz[k] = 1;
    comp[k] = r;
	dep[k] = d;
    for(auto &e: g[k]){
      if(e.to == par[k])continue;
      par[e.to] = k;
      dfs_sz(e.to, d+e.cost, r);
      sz[k] += sz[e.to];
      if(sz[e.to] > sz[g[k][0].to])swap(e, g[k][0]);
    }
  }
  int time = 0;
  void dfs_hld(int k){
    in[k] = time++;
    for(auto e:g[k]){
      if(e.to == par[k])continue;
      head[e.to] = (e.to == g[k][0].to ? head[k]: e.to);
      edges[time] = e;
      dfs_hld(e.to);
    }
    out[k] = time;
  }
  int lca(int p,int q){
    while(1){
      if(in[p] < in[q])swap(p,q);
      if(head[p] == head[q])return q;
      p = par[head[p]];
    }
  }
  vector<pair<int,int>>query_path(int p,int q,bool isEdge){
    int r=lca(p,q);
    vector<pair<int,int>>ret;
    for(int i=0;i<2;i++){
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
  vector<vector<pair<int,int>>>query_order_path(int p,int q,bool isEdge){
	//01
    vector<vector<pair<int,int>>>ret(2);
    int r=lca(p,q);
    for(int i=0;i<2;i++){
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
  pair<int,int>query_subtree(int p,bool isEdge){
    return make_pair(in[p]+isEdge,out[p]);
  }
  //uv (in,out)
  int child(int u,int v){
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
  //uv
  int move(int u,int v){
    assert(u!=v);
    if(in[u]<in[v]&&in[v]<out[v])return child(u,v);
    else return par[u];
  }
  D dist(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
  }
};
struct RandomNumberGenerator {
  mt19937_64 mt;

  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  RandomNumberGenerator(int x) : mt(x){
    cout<<"-----debug-----"<<endl;
  }
  ll operator()(ll a, ll b) { // [a, b)
    uniform_int_distribution< ll > dist(a, b - 1);
    return dist(mt);
  }

  ll operator()(ll b) { // [0, b)
    return (*this)(0, b);
  }
};

template<typename T>
struct EulertourVertex{
  int n;
  const Graph<T>&g;
  vector<int>in, out;
  EulertourVertex(const Graph<T>&g,int root = -1):n(g.size()),g(g){
    in.assign(n, -1);
    out.assign(n, -1);
    build(root);
  }
  void build(int root){
    int time = 0;
    if(root == -1){
      for(int i = 0; i < n; i++){
        if(in[i] == -1){
          dfs(i, -1, time);
        }
      }
    }
    else{
      dfs(root, -1, time);
    }
  }
  void dfs(int k, int par, int &time){
    in[k] = time++;
    for(auto to:g[k]){
      if(to != par)dfs(to, k, time);
    }
    out[k] = time++;
  }
};
template<typename T>
struct BIT{
  ll n;
  ll k=1;
  vector<T>data;
  BIT() = default;
  BIT(ll size):n(size){
    data.assign(n,0);
    while(k*2<=n)k*=2;
  }
  void add(ll a,T w){
    for(ll i=a+1;i<=n;i+=i&-i)data[i-1]^=w;
  }
  T sum(ll a){
	if(a<0)return 0;
    T ret = 0;
    for(ll i=a+1;i>0;i-=i&-i)ret^=data[i-1];
    return ret;
  }
  T sum(ll a,ll b){return a>b?0:sum(b)^sum(a-1);}
  T operator[](ll pos){
    return sum(pos,pos);
  }
  void print(){
    for(ll i=0;i<n;i++){
      if(i!=0)cout<<" ";
      cout<<(*this)[i];
    }
    cout<<endl;
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,q;cin>>n>>q;
  vector<ll>h(n);
  map<ll,ll>mp;
  RandomNumberGenerator rng;
  rep(i,0,n){
    h[i]=rng(1,1LL<<60);
    mp[h[i]]=i;
  }
  vector<int>a(n);
  vector<vector<int>>ga(n);
  rep(i,0,n){
    cin>>a[i],a[i]--;
    ga[a[i]].PB(i);
  }
  auto g=readGraph<int>(n,n-1);
  vector<int>u(q),v(q),l(q),r(q);
  vector<int>lca(q);
  vector<vector<int>>gl(n);
  HLD hld(g,0);
  rep(i,0,q){
    cin>>u[i]>>v[i]>>l[i]>>r[i];
    u[i]--;v[i]--;l[i]--;r[i]--;
    gl[l[i]].PB(i);
  }
  EulertourVertex et(g);
  vector<int>ok(q,n),ng(q,-1);
  vector<ll>last(q);
  rep(i,0,q){
    ng[i]=l[i]-1;
    ok[i]=r[i]+1;
  }
  bool init=false;
  vector<ll>pre(q);
  while(1){
    bool upd=false;
    vector<vector<int>>gm(n);
    rep(i,0,q){
      if(ok[i]-ng[i]<=1)continue;
      int mid=(ok[i]+ng[i])/2;
      gm[mid].PB(i);
      upd=true;
    }
    if(!upd)break;
    BIT<ll>seg(2*n);
    auto path=[&](int p){
      ll ret=seg.sum(0,et.in[u[p]])^seg.sum(0,et.in[v[p]])^seg[et.in[lca[p]]];
      return ret;
    };
    rep(i,0,n){
      if(!init){
        for(auto z:gl[i]){
          //cout<<i spa z<<endl;
          lca[z]=hld.lca(u[z],v[z]);
          pre[z]=path(z);
        }
      }
      for(auto z:ga[i]){
        seg.add(et.in[z],h[i]);
        seg.add(et.out[z],h[i]);
      }
      for(auto z:gm[i]){
        auto p=path(z);
        //cout<<p spa pre[z]<<endl;
        if(p^pre[z]){
          ok[z]=i;
          last[z]=p^pre[z];
        }
        else ng[z]=i;
      }
    }
    init=true;
  }
  //debug(h,n);
  //debug(last,n);
  //debug(pre,q);
  rep(i,0,q){
    ans(last[i],mp[last[i]]+1,-1);
  }
  return 0;
}