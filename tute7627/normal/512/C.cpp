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
template< typename flow_t >
struct Dinic {
  const flow_t INF;

  struct edge {
    ll to;
    flow_t cap;
    ll rev;
    bool isrev;
  };

  vector< vector< edge > > graph;
  vector< ll > min_cost, iter;

  Dinic(ll V) : INF(numeric_limits< flow_t >::max()), graph(V) {}

  void add_edge(ll from, ll to, flow_t cap) {
    graph[from].emplace_back((edge) {to, cap, (ll) graph[to].size(), false});
    graph[to].emplace_back((edge) {from, 0, (ll) graph[from].size() - 1, true});
  }

  bool bfs(ll s, ll t) {
    min_cost.assign(graph.size(), -1);
    queue< ll > que;
    min_cost[s] = 0;
    que.push(s);
    while(!que.empty() && min_cost[t] == -1) {
      ll p = que.front();
      que.pop();
      for(auto &e : graph[p]) {
        if(e.cap > 0 && min_cost[e.to] == -1) {
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return min_cost[t] != -1;
  }

  flow_t dfs(ll idx, const ll t, flow_t flow) {
    if(idx == t) return flow;
    for(ll &i = iter[idx]; i < graph[idx].size(); i++) {
      edge &e = graph[idx][i];
      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
        flow_t d = dfs(e.to, t, min(flow, e.cap));
        if(d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  flow_t max_flow(ll s, ll t) {
    flow_t flow = 0;
    while(bfs(s, t)) {
      iter.assign(graph.size(), 0);
      flow_t f = 0;
      while((f = dfs(s, t, INF)) > 0) flow += f;
    }
    return flow;
  }

  void output() {
    for(ll i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }
  //<(from->to),flow>
  using R=vector<pair<pair<ll,ll>,flow_t>>;
  R restore() {
    R ret;
    for(ll i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        ret.emplace_back(make_pair(i,e.to),rev_e.cap);
      }
    }
    return ret;
  }
};
vector< bool > prime_table(ll n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(ll i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(ll j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}
template<typename T>
struct Namori{
  const Graph<T>&g;
  int n;
  int edge_num=0;
  bool directed_forest = false;
  Namori(const Graph<T>&g, bool directed):g(g),n(g.size()){
    directed_forest = directed;
    int edge_num=0;
    for(auto &v:g)edge_num+=v.size();
    build();
  }
  vector<vector<int>>cycle;// 
  vector<int>vn,en;//
  Graph<T>forest;
  vector<int>root;
  vector<int>cycle_number;// -1
  void build(){
    dfs_used.assign(n,false);
    dfs_now.assign(n,false);
    dfs_ver.clear();
    root.assign(n,-1);
    for(int i=0;i<n;i++){
      if(dfs_used[i])continue;
      cycle.emplace_back();
      vn.push_back(0);
      en.push_back(0);
      build_dfs(i,-1,cycle.back());
      if(cycle.back().empty()){
        cycle.back().push_back(i);
      }
    }
    forest.resize(n);
    cycle_number.assign(n,-1);
    for(int i=0;i<cycle.size();i++){
      for(auto v:cycle[i])cycle_number[v]=i;
    }
    dfs_used.assign(n,false);
    for(int i=0;i<n;i++){
      if(cycle_number[i]!=-1)tree_dfs(i,vn[cycle_number[i]],en[cycle_number[i]],i);
    }
    for(int i=0;i<cycle.size();i++)en[i]>>=1;
  }
  void tree_dfs(int pos,int &vn,int &en,int r){
    vn++;
    dfs_used[pos]=true;
    root[pos]=r;
    for(auto e:g[pos]){
      en++;
      if(pos!=r&&dfs_used[e.to]&&!directed_forest)forest[pos].push_back(e);
      if(dfs_used[e.to]||cycle_number[e.to]!=-1)continue;
      forest[pos].push_back(e);
      tree_dfs(e.to,vn,en,r);
    }
  }
  vector<bool>dfs_used;
  vector<int>dfs_ver;
  vector<bool>dfs_now;
  void build_dfs(int pos, int par,vector<int>&cycle){
    dfs_used[pos]=true;
    dfs_now[pos]=true;
    dfs_ver.push_back(pos);
    bool multiple_par=false;
    for(auto to:g[pos]){
      if(dfs_now[to]&&cycle.empty()&&(to!=par||multiple_par)){
        for(auto v:dfs_ver){
          if(!cycle.empty()||v==to)cycle.push_back(v);
        }
      }
      if(to==par)multiple_par=true;
      if(dfs_used[to])continue;
      build_dfs(to,pos,cycle);
    }
    dfs_now[pos]=false;
    dfs_ver.pop_back();
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  auto pt=prime_table(100000);
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  Dinic<ll>dinic(n+2);
  ll S=n,T=n+1;
  rep(i,0,n){
    if(a[i]%2==0){
      dinic.add_edge(S,i,2);
      rep(j,0,n){
        if(pt[a[i]+a[j]]){
          dinic.add_edge(i,j,1);
        }
      }
    }
    else{
      dinic.add_edge(i,T,2);
    }
  }
  auto mx=dinic.max_flow(S,T);
  if(mx!=n)cout<<"Impossible"<<endl;
  else{
    auto r=dinic.restore();
    Graph<int>g(n);
    for(auto [e,f]:r){
      if(e.fi==S||e.se==T||f==0)continue;
      g[e.fi].EB(e.se);
      g[e.se].EB(e.fi);
    }
    Namori namori(g,false);
    auto &c=namori.cycle;
    cout<<c.size()<<endl;
    for(auto z:c){
      cout<<z.size();
      for(auto zz:z){
        cout spa zz+1;
      }
      cout<<endl;
    }
  }
  return 0;
}