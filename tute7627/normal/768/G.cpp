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
    if(in[u]<in[v]&&in[v]<out[u])return child(u,v);
    else return par[u];
  }
  D dist(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
  }
  vector<int>rev_in;
  int climb(int u,int k){
    if(rev_in.empty()){
      rev_in.resize(n);
      for(int i=0;i<n;i++)rev_in[in[i]]=i;
    }
    int nd=max<int>(dep[u]-k, 0);
    while(dep[u]>nd){
      if(dep[head[u]]>nd){
        u=par[head[u]];
      }
      else{
        u=rev_in[in[head[u]]+nd-dep[head[u]]];
      }
    }
    return u;
  }
  template<typename I>
  Graph<T>lca_tree(vector<I>&v){
    auto compare=[&](int x,int y){return in[x]<in[y];};
    sort(v.begin(),v.end(),compare);
    int sz1=v.size();
    for(int i=0;i<sz1-1;i++)v.push_back(lca(v[i],v[i+1]));
    sort(v.begin(),v.end(),compare);
    v.erase(unique(v.begin(),v.end()),v.end());
    int sz2=v.size();
    Graph<T>ret(sz2);
    stack<int>st;
    for(int i=0;i<sz2;i++){
      while(!st.empty()&&out[v[st.top()]]<=in[v[i]])st.pop();
      if(!st.empty())ret[st.top()].emplace_back(i,dep[v[i]]-dep[v[st.top()]]);
      st.push(i);
    }
    return ret;
  }
};
struct SuccinctIndexableDictionary {
  size_t length;
  size_t blocks;
  vector< unsigned > bit, sum;

  SuccinctIndexableDictionary() {
  }

  SuccinctIndexableDictionary(size_t _length) {
    length = _length;
    blocks = (length + 31) >> 5;
    bit.assign(blocks, 0U);
    sum.assign(blocks, 0U);
  }

  void set(int k) {
    bit[k >> 5] |= 1U << (k & 31);
  }

  void build() {
    sum[0] = 0U;
    for(int i = 1; i < blocks; i++) {
      sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);
    }
  }

  bool operator[](int k) const {
    return (bool((bit[k >> 5] >> (k & 31)) & 1));
  }

  int rank(int k) {
    return (sum[k >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));
  }

  int rank(bool val, int k) {
    return (val ? rank(k) : k - rank(k));
  }

  int select(bool val, int k) {
    if(k < 0 || rank(val, length) <= k) return (-1);
    int low = 0, high = length;
    while(high - low > 1) {
      int mid = (low + high) >> 1;
      if(rank(val, mid) >= k + 1) high = mid;
      else low = mid;
    }
    return (high - 1);
  }

  int select(bool val, int i, int l) {
    return select(val, i + rank(val, l));
  }
};

/*
 * @brief Wavelet-Matrix()
 * @docs docs/wavelet-matrix.md
 */
template< typename T, int MAXLOG >
struct WaveletMatrix {
  size_t length;
  SuccinctIndexableDictionary matrix[MAXLOG];
  int mid[MAXLOG];

  WaveletMatrix() = default;

  WaveletMatrix(vector< T > v) : length(v.size()) {
    vector< T > l(length), r(length);
    for(int level = MAXLOG - 1; level >= 0; level--) {
      matrix[level] = SuccinctIndexableDictionary(length + 1);
      int left = 0, right = 0;
      for(int i = 0; i < length; i++) {
        if(((v[i] >> level) & 1)) {
          matrix[level].set(i);
          r[right++] = v[i];
        } else {
          l[left++] = v[i];
        }
      }
      mid[level] = left;
      matrix[level].build();
      v.swap(l);
      for(int i = 0; i < right; i++) {
        v[left + i] = r[i];
      }
    }
  }

  pair< int, int > succ(bool f, int l, int r, int level) {
    return {matrix[level].rank(f, l) + mid[level] * f, matrix[level].rank(f, r) + mid[level] * f};
  }

  // v[k]
  T access(int k) {
    T ret = 0;
    for(int level = MAXLOG - 1; level >= 0; level--) {
      bool f = matrix[level][k];
      if(f) ret |= T(1) << level;
      k = matrix[level].rank(f, k) + mid[level] * f;
    }
    return ret;
  }

  T operator[](const int &k) {
    return access(k);
  }

  // count i s.t. (0 <= i < r) && v[i] == x
  int rank(const T &x, int r) {
    int l = 0;
    for(int level = MAXLOG - 1; level >= 0; level--) {
      tie(l, r) = succ((x >> level) & 1, l, r, level);
    }
    return r - l;
  }

  // k-th(0-indexed) smallest number in v[l,r)
  T kth_smallest(int l, int r, int k) {
    assert(0 <= k && k < r - l);
    T ret = 0;
    for(int level = MAXLOG - 1; level >= 0; level--) {
      int cnt = matrix[level].rank(false, r) - matrix[level].rank(false, l);
      bool f = cnt <= k;
      if(f) {
        ret |= T(1) << level;
        k -= cnt;
      }
      tie(l, r) = succ(f, l, r, level);
    }
    return ret;
  }

  // k-th(0-indexed) largest number in v[l,r)
  T kth_largest(int l, int r, int k) {
    return kth_smallest(l, r, r - l - k - 1);
  }

  // count i s.t. (l <= i < r) && (v[i] < upper)
  int range_freq(int l, int r, T upper) {
    int ret = 0;
    for(int level = MAXLOG - 1; level >= 0; level--) {
      bool f = ((upper >> level) & 1);
      if(f) ret += matrix[level].rank(false, r) - matrix[level].rank(false, l);
      tie(l, r) = succ(f, l, r, level);
    }
    return ret;
  }

  // count i s.t. (l <= i < r) && (lower <= v[i] < upper)
  int range_freq(int l, int r, T lower, T upper) {
    return range_freq(l, r, upper) - range_freq(l, r, lower);
  }

  // max v[i] s.t. (l <= i < r) && (v[i] < upper)
  T prev_value(int l, int r, T upper) {
    int cnt = range_freq(l, r, upper);
    return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);
  }

  // min v[i] s.t. (l <= i < r) && (lower <= v[i])
  T next_value(int l, int r, T lower) {
    int cnt = range_freq(l, r, lower);
    return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);
  }
};

template< typename T, int MAXLOG >
struct CompressedWaveletMatrix {
  WaveletMatrix< int, MAXLOG > mat;
  vector< T > ys;

  CompressedWaveletMatrix(const vector< T > &v) : ys(v) {
    sort(begin(ys), end(ys));
    ys.erase(unique(begin(ys), end(ys)), end(ys));
    vector< int > t(v.size());
    for(int i = 0; i < v.size(); i++) t[i] = get(v[i]);
    mat = WaveletMatrix< int, MAXLOG >(t);
  }

  inline int get(const T& x) {
    return lower_bound(begin(ys), end(ys), x) - begin(ys);
  }

  T access(int k) {
    return ys[mat.access(k)];
  }

  T operator[](const int &k) {
    return access(k);
  }

  int rank(const T &x, int r) {
    auto pos = get(x);
    if(pos == ys.size() || ys[pos] != x) return 0;
    return mat.rank(pos, r);
  }

  T kth_smallest(int l, int r, int k) {
    return ys[mat.kth_smallest(l, r, k)];
  }

  T kth_largest(int l, int r, int k) {
    return ys[mat.kth_largest(l, r, k)];
  }

  int range_freq(int l, int r, T upper) {
    return mat.range_freq(l, r, get(upper));
  }

  int range_freq(int l, int r, T lower, T upper) {
    return mat.range_freq(l, r, get(lower), get(upper));
  }

  T prev_value(int l, int r, T upper) {
    auto ret = mat.prev_value(l, r, get(upper));
    return ret == -1 ? T(-1) : ys[ret];
  }

  T next_value(int l, int r, T lower) {
    auto ret = mat.next_value(l, r, get(lower));
    return ret == -1 ? T(-1) : ys[ret];
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  int n;cin>>n;
  Graph<int>g(n);
  ll r=-1;
  rep(i,0,n){
    ll u,v;cin>>u>>v;u--;v--;
    if(u==-1)r=v;
    else{
      g[u].EB(v);
      g[v].EB(u);
    }
  }
  HLD hld(g,r);
  vector<int>v(n);
  auto &sz=hld.sz;
  rep(i,0,n){
    sz[i]*=2;
    v[hld.in[i]]=sz[i];
  }
  //debug(v);
  WaveletMatrix<int,18>wm(v);
  auto lw=[&](int l,int r,int x){
    //cout<<l spa r spa x<<endl;
    if(l>=r)return 1000000;
    int mi=1e9;
    for(auto val:{wm.prev_value(l,r,x+1),wm.next_value(l,r,x)}){
      if(val!=-1)chmin(mi,abs(val-x));
    }
    return mi;
  };
  rep(i,0,n){
    if(g[i].size()<=1){
      cout<<n-1<<endl;
      continue;
    }
    int mx=0,mi=1e9,idx=-1,rem=2*(n-1);
    vector<int>szv;
    for(auto to:g[i]){
      if(to==hld.par[i])continue;
      if(chmax(mx,sz[to]))idx=to;
      rem-=sz[to];
      szv.PB(sz[to]);
    }
    if(rem>0){
      if(chmax(mx,rem))idx=-1;
      chmin(mi,rem);
      szv.PB(rem);
    }
    //debug(szv);
    sort(ALLR(szv));
    mi=szv.back();
    int ave=(mi+mx)/2,goal=(mx-mi)/2;
    int ret=mx;
    int lower=0;
    if(szv.size()>=3)lower=szv[1];
    if(idx==-1){
      vector<pair<int,int>>rv;
      rv.EB(0,0);
      rv.EB(n,n);
      rv.EB(hld.in[i],hld.out[i]);
      {
        auto tmp=hld.query_path(r,hld.par[i],false);
        for(auto z:tmp)rv.PB(z);
        //debug(tmp);cout<<hld.par[i]<<endl;
      }
      //{auto ord=ascend(hld.in);debug(ord);}
      //debug(hld.in);
      sort(ALL(rv));
      //debug(rv,rv.size(),",");
      rep(j,0,rv.size()){
        if(j+1<rv.size())chmin(ret,ave+lw(rv[j].se,rv[j+1].fi,goal));
        if(rv[j].fi!=hld.in[i])chmin(ret,ave+lw(rv[j].fi,rv[j].se,goal+sz[i]));
      }
    }
    else{
      chmin(ret,ave+lw(hld.in[idx],hld.out[idx],goal));
      //if(i==0)cout<<mi spa mx spa ave spa goal spa lw(hld.in[idx],hld.out[idx],goal)<<endl;
    }
    //cout<<"ans:";
    cout<<max(lower,ret)/2<<endl;
  }
  return 0;
}