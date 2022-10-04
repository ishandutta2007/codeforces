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
template<typename T>void rearrange(vector<ll>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<ll>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
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
  edge(int to, T cost = 1, int id = 0):to(to), cost(cost), id(id){}
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

struct MergeTree{
  vector<int> data;
  vector<int>current;
  Graph<int> graph;
  vector<int>in, out;
  vector<int>ord;
  int num;
  int time;
  MergeTree(int size) : data(size, -1), current(size), graph(size),
  time(size - 1), num(size){    
    iota(current.begin(), current.end(), 0);
  }
  int unite(int x, int y) {
    x = root(x); y = root(y);
    if(x != y){
      graph.emplace_back();
      time++;
      graph[time].emplace_back(current[x]);
      graph[time].emplace_back(current[y]);
      if (data[y] < data[x]) swap(x, y);
      current[x] = time;
      data[x] += data[y]; data[y] = x;
      num--;
    }
    return time;
  }
  void build(){
    graph.emplace_back();
    in.resize(graph.size());
    out.resize(graph.size());
    time++;
    for(int i = 0; i < data.size(); i++){
      if(root(i) == i)graph[time].emplace_back(current[i]);
    }
    int t = 0;
    build_dfs(time, t);
  }
  void build_dfs(int pos, int &t){
    in[pos] = t;
    if(graph[pos].size() == 0){
      ord.push_back(pos);
      t++;
    }
    for(auto to:graph[pos]){
      build_dfs(to, t);
    }
    out[pos] = t;
  }
  int component(int x){
    return current[root(x)];
  }
  bool find(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

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
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m,q;cin>>n>>m>>q;
  MergeTree uf(n);
  auto ff=[&](P x,P y){return max(x,y);};
  SegmentTree<P,decltype(ff)>seg(n,ff,MP(0,-1));
  vector<ll>p(n);
  rep(i,0,n){
    cin>>p[i];
  }
  vector<ll>a(m),b(m);
  rep(i,0,m){
    cin>>a[i]>>b[i];
    a[i]--;b[i]--;
  }
  vector<bool>del(m);
  vector<ll>t(q),x(q);
  rep(i,0,q){
    cin>>t[i]>>x[i];x[i]--;
    if(t[i]==2)del[x[i]]=true;
  }
  rep(i,0,m)if(!del[i])uf.unite(a[i],b[i]);
  vector<ll>cm(q);
  rrep(i,0,q){
    if(t[i]==1)cm[i]=uf.component(x[i]);
    else uf.unite(a[x[i]],b[x[i]]);
  }
  uf.build();
  rep(i,0,n){
    seg.set(uf.in[i],MP(p[i],uf.in[i]));
  }
  seg.build();
  rep(i,0,q){
    if(t[i]==2)continue;
    auto tmp=seg.query(uf.in[cm[i]],uf.out[cm[i]]);
    cout<<tmp.fi<<endl;
    if(tmp.se!=-1)seg.update(tmp.se,MP(0,-1));
  }
  return 0;
}