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
template<typename T>void debug(const vector<vector<T>>&v){debug(v,v.size(),(v.empty()?0:v[0].size()));}
template<typename T>void debug(stack<T> st){while(!st.empty()){cout<<st.top();st.pop();while(!st.empty()){cout<<" "<<st.top();st.pop();}cout<<endl;}}
template<typename T>void debug(queue<T> st){while(!st.empty()){cout<<st.front();st.pop();while(!st.empty()){cout<<" "<<st.front();st.pop();}cout<<endl;}}
template<typename T>void debug(deque<T> st){while(!st.empty()){cout<<st.front();st.pop();while(!st.empty()){cout<<" "<<st.front();st.pop();}cout<<endl;}}
template<typename T>void debug(PQ<T> st){while(!st.empty()){cout<<st.top();st.pop();while(!st.empty()){cout<<" "<<st.top();st.pop();}cout<<endl;}}
template<typename T>void debug(QP<T> st){while(!st.empty()){cout<<st.top();st.pop();while(!st.empty()){cout<<" "<<st.top();st.pop();}cout<<endl;}}
template<typename T>void debug(const set<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T>void debug(const multiset<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T,typename V>void debug(const map<T,V>&v){for(auto z:v)cout<<"["<<z.first<<"]="<<z.second<<endl;}
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
template<typename T>
struct SCC{
  int n;
  const Graph<T>&G;
  vector<int>index;//
  vector<int>start,visited,low,ord;
  int now_ord,group_num;
  SCC(const Graph<T> &g):G(g),n(g.size()){
    index.assign(n,-1);
    build();
  }
  void build(){
    low.assign(n,0);ord.assign(n,-1);index.assign(n,0);
    visited.reserve(n);
    now_ord=0,group_num=0;
    for(int i=0;i<n;i++){
      if(ord[i]==-1)dfs(i);
    }
    for(auto& x:index)x=group_num-1-x;
  }
  void dfs(int v){
    low[v]=ord[v]=now_ord++;
    visited.push_back(v);
    for(auto to:G[v]){
      if(ord[to]==-1){
        dfs(to);
        low[v]=min(low[v],low[to]);
      }
      else{
        low[v]=min(low[v],ord[to]);
      }
    }
    if(low[v]==ord[v]){
      while(1){
        int u=visited.back();
        visited.pop_back();
        ord[u]=n;
        index[u]=group_num;
        if(u==v)break;
      }
      group_num++;
    }

  }
  Graph<T>scc_graph;
  void build_edges(){
    scc_graph.resize(*max_element(index.begin(),index.end())+1);
    for(int i=0;i<n;i++){
      for(int j=0;j<G[i].size();j++){
        if(index[i]!=index[G[i][j]]){
          scc_graph[index[i]].emplace_back(index[G[i][j]], G[i][j].cost, G[i][j].id);
        }
      }
    }
  }
  vector<int>output(){return index;};
};
template<typename T>
struct Compress{
	vector<T>v;
	Compress(){
	}
	Compress(const vector<T>&input){
		add(input);
    build();
	}
  template<typename... Args>
  Compress(Args&& ...input){
    add(input...);
    build();
  }
  void build(){
		sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
  }
	void add(const vector<T>&add){
		v.insert(v.end(),add.begin(), add.end());
	}
  template<typename Head, typename ...Tail>
  void add(const Head&& head, Tail&& ...tail){
    add(head);
    add(tail...);
  }
  int next(T val){
    return lower_bound(v.begin(), v.end(), val) - v.begin();
  }
  int prev(T val){
    return upper_bound(v.begin(), v.end(), val) - v.begin() - 1;
  }
  bool exist(T val){
    return binary_search(v.begin(), v.end(), val);
  }
  T val(int x){
    return v[x];
  }
  vector<int>compress(const vector<T>&input){
    vector<int>ret(input.size());
    for(int i=0;i<input.size();i++)ret[i]=next(input[i]);
    return ret;
  }
  int operator[](T val){
    return next(val);
  }
  int size(){
    return v.size();
  }
};
template<typename T>
vector<ll> dijkstra(Graph<T>&g,ll s = 0) {
  using PT=pair<ll,int>;
  priority_queue<PT, vector<PT>, greater<PT> > que;
  vector<ll>dist(g.size(),INF);
  dist[s] = 0;
  que.emplace(0, s);
  while (!que.empty()) {
    PT p = que.top();
    que.pop();
    int v = p.second;
    if (dist[v] < p.first) continue;
    for(auto e:g[v]) {
      if (dist[e.to] > dist[v] + e.cost) {
          dist[e.to] = dist[v] + e.cost;
          que.emplace(dist[e.to], e.to);
      }
    }
  }
  return dist;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  auto g=readGraph<ll>(n,m,1,true,true);
  SCC scc(g);
  auto &idx=scc.index;
  ll sz=max(idx)+1;
  vector<vector<ll>>v(sz);
  rep(i,0,n){
    v[idx[i]].PB(i);
  }
  vector<Compress<ll>>mp(sz);
  vector<Graph<ll>>gs(sz),gsr(sz);
  rep(i,0,sz){
    mp[i]=Compress(v[i]);
    gs[i].resize(mp[i].size());
    gsr[i].resize(mp[i].size());
  }
  rep(i,0,n){
    ll k=idx[i];
    for(auto e:g[i]){
      if(idx[i]!=idx[e.to])continue;
      gs[k][mp[k][i]].EB(mp[k][e.to],e.cost);
      gsr[k][mp[k][e.to]].EB(mp[k][i],e.cost);
    }
  }
  vector<ll>a(sz);
  rep(i,0,sz){
    auto d=dijkstra(gs[i],0);
    auto dr=dijkstra(gsr[i],0);
    //debug(v[i]);
    //debug(d);
    //debug(dr);
    //cout<<gs<<endl;
    //cout<<gsr<<endl;
    rep(j,0,gs[i].size()){
      for(auto e:gs[i][j]){
        a[i]=gcd(a[i],e.cost+d[j]+dr[e.to]);
      }
    }
  }
  //debug(a,sz);
  ll q;cin>>q;
  while(q--){
    ll v,s,t;cin>>v>>s>>t;v--;
    ll gt=gcd(t,a[idx[v]]);
    ans2((t-s)%gt==0);
  }
  return 0;
}