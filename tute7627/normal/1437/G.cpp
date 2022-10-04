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


template<int iden, int size>
struct Trie{
  struct Node{
    array<int, size>nxt;
    vector<int>idx;
    int fail, len;
    Node(int l):fail(0), len(l){
      fill(nxt.begin(), nxt.end(), -1);
    }
  };
  vector<Node>data;
  Trie(){
    data.emplace_back(0);
  }
  int add(const string &s, int id=0){
    int pos=0;
    for(int i=0;i<s.size();i++){
      int c = s[i] - iden;
      if(data[pos].nxt[c]==-1){
        data[pos].nxt[c]=data.size();
        data.emplace_back(i+1);
      }
      pos = data[pos].nxt[c];
    }
    data[pos].idx.push_back(id);
		return pos;
  }
  int append(int pos,char cc){
		int c = cc - iden;
		if(data[pos].nxt[c]==-1){
			data[pos].nxt[c]=data.size();
      data.emplace_back(0);
		}
		pos=data[pos].nxt[c];
		return pos;
	}
  vector<string>str;
  void build_str(int pos=0,string s=""){
    while(str.size()<=pos)str.push_back("");
    str[pos]=s;
    for(int i=0;i<size;i++){
      if(data[pos].nxt[i]!=-1){
        build_str(data[pos].nxt[i],s+char(i+iden));
      }
    }
  }
  void build_Ahocorasick(){
    queue<int>que;
    for(int i=0;i<size;i++){
      if(data[0].nxt[i]!=-1){
        data[data[0].nxt[i]].fail=0;
        que.push(data[0].nxt[i]);
      }
      else{
        data[0].nxt[i]=0;
      }
    }
    while(!que.empty()){
      int pos = que.front();
      que.pop();
      for(int i=0;i<size;i++){
        if(data[pos].nxt[i]!=-1){
          data[data[pos].nxt[i]].fail = data[data[pos].fail].nxt[i];
          que.push(data[pos].nxt[i]);
        }
        else{
          data[pos].nxt[i]=data[data[pos].fail].nxt[i];
        }
      }
    }
  }
  vector<int> aho_search(const string &s){
    int now=0;
    vector<int>cnt(data.size());
    for(int i=0;i<s.size();i++){
      int c = s[i] - iden;
      now=data[now].nxt[c];
      cnt[now]++;
    }
    if(sg.empty())suffix_link();
    auto dfs=[&](auto &&f,int k)->void{
      for(auto to:sg[k]){
        f(f,to);
        cnt[k]+=cnt[to];
      }
    };
    dfs(dfs,0);
    return cnt;
  }
  Graph<int> sg;
  void suffix_link(){
    assert(sg.empty());
    sg.resize(data.size());
    for(int i=1;i<data.size();i++){
      sg[data[i].fail].emplace_back(i);
    }
  }
};
using trie = Trie<'a',26>;
template<typename T>
struct HLD{
  int n;
  vector<int>sz;//
  vector<long long>dep;
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
  void dfs_sz(int k, long long d,int r){
    sz[k] = 1;
    comp[k] = r;
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
  long long dist(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
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
  trie tri;
  ll n,m;cin>>n>>m;
  vector<ll>id(n);
  vector<ll>sus(n);
  rep(i,0,n){
    string s;cin>>s;
    id[i]=tri.add(s);
  }
  tri.build_Ahocorasick();
  ll sz=tri.data.size();
  vector<multiset<ll>>mst(sz);
  rep(i,0,n)mst[id[i]].insert(0);
  tri.suffix_link();
  auto &g=tri.sg;
  HLD hld(g);
  auto ff=[&](ll x,ll y){return max(x,y);};
  SegmentTree<ll,decltype(ff)>seg(sz,ff,-1);
  rep(i,0,n)seg.set(hld.in[id[i]],0);
  seg.build();
  //tri.build_str();
  while(m--){
    ll type;cin>>type;
    if(type==1){
      ll i,x;cin>>i>>x;i--;
      mst[id[i]].erase(mst[id[i]].find(sus[i]));
      sus[i]=x;
      mst[id[i]].insert(x);
      seg.update(hld.in[id[i]],*mst[id[i]].rbegin());
    }
    else{
      string s;cin>>s;
      ll pos=0;
      ll mx=-1;
      for(auto cc:s){
        ll c=cc-'a';
        pos=tri.data[pos].nxt[c];
        auto pp=hld.query_path(0,pos,false);
        for(auto z:pp)chmax(mx,seg.query(z.fi,z.se));
      }
      cout<<mx<<endl;
    }
    //seg.print();
  }
  return 0;
}